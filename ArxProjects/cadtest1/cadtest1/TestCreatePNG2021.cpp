//
#include "stdafx.h"
#include <axlock.h>
#include <dbrender.h>
#include <dbobjptr.h>
#include "dbsymtb.h"
#include "AcGsManager.h"
#include "acgs.h"
#include "gs.h"
#include "rxmfcapi.h"
#include "afxwin.h"

// others no env
#if ARX == 2020 || ZRX
#include <TiffCustomProperties.h>
#include <Image.h>
#include <RgbColor.h>
#include <RgbModel.h>
#include <FileWriteDescriptor.h>
#include <FormatCodecIntProperty.h>
#include <FileSpecifier.h>
#include <RowProviderInterface.h>
#include <JfifFormatCodec.h>
#include <PngFormatCodec.h>
#include <PngCustomProperties.h>
#include <BmpFormatCodec.h>
#endif

void AsObjectIdArray(AcDbObjectIdArray& objids, const ads_name ss)
{
	Adesk::Int32 len = 0;

	if (acedSSLength(ss, &len) != RTNORM)
	{
		return;
	}

	int ret;
	AcDbObjectId objId;
	ads_name ent;

	for (long i = 0L; i < len; i++)
	{
		ret = acedSSName(ss, i, ent);
		ASSERT(ret == RTNORM);
		if (acdbGetObjectId(objId, ent) == Acad::eOk)
			objids.append(objId);
	}
}

Acad::ErrorStatus GetBigExt( const AcDbObjectId & blckId , AcDbExtents & ext )
{
	Acad::ErrorStatus es  =  Acad::eInvalidInput ;
	if(blckId == AcDbObjectId::kNull)
	{
		return es;
	}

	AcDbObject* pObj = NULL;
	es = acdbOpenAcDbObject(pObj , blckId , AcDb::kForRead); 
	if ( es != Acad::eOk )
	{
		return es ; 
	}
	
	AcDbBlockTableRecord *pBlkDefRcd = AcDbBlockTableRecord::cast(pObj);
	if (pBlkDefRcd == NULL)
	{
		pObj->close();
		return es;
	}

	AcDbBlockTableRecordIterator *pItr; 
	pBlkDefRcd->newIterator(pItr); 
	AcDbEntity *pEnt = NULL ; 
	for (pItr->start(); !pItr->done(); pItr->step()) 
	{ 
		pItr->getEntity(pEnt, AcDb::kForRead); 
		if ( pEnt == NULL )
		{
			continue;
		}

		/// 
		AcDbExtents extTemp ; 
		pEnt->getGeomExtents( extTemp ) ; 

		//// 
		if ( pEnt->isKindOf( AcDbPolyline::desc() ) )
		{
			AcDbPolyline * pPoly = (AcDbPolyline * )pEnt ; 

			if ( pPoly->numVerts() > 0 )
			{
				/// 
				double dStartWidth = 0; 
				double dEndWidth = 0 ; 

				/// 
				pPoly->getWidthsAt( 0 , dStartWidth , dEndWidth ) ;

				if ( dStartWidth > 1 )
				{
					/// 
					AcGePoint3d extMin = extTemp.minPoint() ; 
					AcGePoint3d extMax = extTemp.maxPoint() ; 

					/// 
					double dOffValue = dStartWidth / 2  ; 
					extMin.x -= dOffValue ; 
					extMin.y -= dOffValue ; 

					extMax.x += dOffValue ; 
					extMax.y += dOffValue ; 

					extTemp.set( extMin , extMax ) ; 
				}
			}

		}

		/// 
		ext.addExt( extTemp ) ; 
		pEnt->close();
	}

	delete pItr;

	//dbAction.CloseAction() ; 
	pObj->close();
	return es ;
}

void refreshView(AcGsView *pView)
{
	if (pView != NULL)
	{
		pView->invalidate();
		pView->update();
	}
}

AcDbObjectId SetViewTo(AcGsView *pView, AcDbDatabase *pDb, AcGeMatrix3d& viewMat, const AcDbExtents& extAnonBlock)
{
	AcGePoint3d extMax = extAnonBlock.maxPoint();
	AcGePoint3d extMin = extAnonBlock.minPoint();

	if (extMin.distanceTo(extMax) > 1e20)
	{
		extMin.set(0, 0, 0);
		extMax.set(100, 100, 100);
	}

	ads_real height = 0.0, width = 0.0, viewTwist = 0.0;
	AcDbObjectId currentVsId;
	//AcGeVector3d viewDir = AcGeVector3d(0 , 0 , 1) ;
	AcGeVector3d viewDir = AcGeVector3d(1 , 1 , 1) ;   // add for test: a new view direction

	AcGeVector3d viewXDir = viewDir.perpVector ().normal();
	viewXDir = viewXDir.rotateBy (viewTwist, -viewDir);
	AcGeVector3d viewYDir = viewDir.crossProduct (viewXDir);

	AcGePoint3d boxCenter = extMin + 0.5 * ( extMax - extMin );

	viewMat = AcGeMatrix3d::alignCoordSys (boxCenter, AcGeVector3d::kXAxis, AcGeVector3d::kYAxis, AcGeVector3d::kZAxis,  
		boxCenter, viewXDir, viewYDir, viewDir).inverse();

	AcDbExtents wcsExtents(extMin, extMax);
	AcDbExtents viewExtents = wcsExtents;
	viewExtents.transformBy (viewMat);

	double xMax = fabs(viewExtents.maxPoint ().x - viewExtents.minPoint ().x);
	double yMax = fabs(viewExtents.maxPoint ().y - viewExtents.minPoint ().y);

	AcGePoint3d eye = boxCenter + viewDir;

	pView->setView(eye, boxCenter, viewYDir, xMax, yMax);

	pView->zoomExtents(extMin, extMax);

	refreshView(pView);

	return currentVsId;
}

#if ZRX || ARX >= 2020
bool CreateAtilImage(AcGsView *pView, int width, int height,int colorDepth, int paletteSize, const TCHAR *pFileName)
{
	bool done = false;

	AcGsDCRect screenRect(0,width,0, height);

	// get the screen rect from the gsview
	pView->getViewport(screenRect);

	try
	{
		// we want colorDepth to be either 24 or 32
		if (colorDepth < 24)
			colorDepth = 24;
		if (colorDepth > 24)
			colorDepth = 32;

		// create rbgmodel 32 bit true color
		Atil::RgbModel rgbModel(colorDepth);
		Atil::ImagePixel initialColor(rgbModel.pixelType());
		// create the Atil image on the stack
		Atil::Image imgSource(Atil::Size(width, height), &rgbModel, initialColor);

		// get a snapshot of the GsView
		pView->getSnapShot(&imgSource, screenRect.m_min);

		// if ok
		if (imgSource.isValid())
		{
			Atil::RowProviderInterface *pPipe = imgSource.read(imgSource.size(), Atil::Offset(0,0),Atil::kBottomUpLeftRight);
			if(pPipe != NULL)
			{
				TCHAR drive[_MAX_DRIVE];
				TCHAR dir[_MAX_DIR];
				TCHAR fname[_MAX_FNAME];
				TCHAR ext[_MAX_EXT];	
				// find out what extension we have
				_tsplitpath_s(pFileName, drive, dir, fname, ext);

				Atil::ImageFormatCodec *pCodec = NULL;
				// create the codec depending on what the user chose

				if (CString(ext) == _T(".jpg"))
					pCodec = new JfifFormatCodec();
				else if (CString(ext) == _T(".png"))
					pCodec = new PngFormatCodec();
				else if (CString(ext) == _T(".tif"))
					pCodec = new TiffFormatCodec();
				else if (CString(ext) == _T(".bmp"))
					pCodec = new BmpFormatCodec();

				// if we have a new codec
				if (pCodec != NULL)
				{
					// and it is compatible
					if (Atil::FileWriteDescriptor::isCompatibleFormatCodec(pCodec, &(pPipe->dataModel()), pPipe->size()))
					{
						// create a new file output object
						Atil::FileWriteDescriptor fileWriter(pCodec);
						Atil::FileSpecifier fs(Atil::StringBuffer((lstrlen(pFileName) + 1) * sizeof(TCHAR), 
							(const Atil::Byte *)pFileName, Atil::StringBuffer::kUTF_16), Atil::FileSpecifier::kFilePath);

						// if the file already exists
						// we better delete it because setFileSpecifier will fail otherwise
						_tremove(pFileName);

						if (fileWriter.setFileSpecifier(fs))
						{
							fileWriter.createImageFrame(pPipe->dataModel(), pPipe->size());

							// At any rate you want to fetch the property from the write file descriptor then alter it and set it in…
							Atil::FormatCodecPropertyInterface *pProp = fileWriter.getProperty(Atil::FormatCodecPropertyInterface::kCompression);
							if (pProp != NULL) 
							{
								if (CString(ext) == _T(".jpg"))
								{
									Atil::FormatCodecIntProperty *pComp = dynamic_cast<Atil::FormatCodecIntProperty*>(pProp);
									if (pComp != NULL) 
									{ 
										int min=0, max=0;
										pComp->getPropertyLimits(min, max);
										// set the quality to 90%
										pComp->setValue((int)((double)max * .9));

										// apply any changes we have made
										fileWriter.setProperty(pComp);
									}
								}                  
								else if (CString(ext) == _T(".png"))
								{
									PngCompression *pComp = dynamic_cast<PngCompression*>(pProp);
									if (pComp != NULL)
									{
										// Why not compress all we can? 
										pComp->selectCompression(PngCompressionType::kHigh);

										// apply any changes we have made
										fileWriter.setProperty(pComp);
									}
								}
								else if (CString(ext) == _T(".tif"))
								{
									// All image types can be compressed using kNone, kLZW, and kDeflate.
									// If it is 8 bit (palette'd or gray scale) the kPackbits is available. 
									// If it is 1 bit (bi-tonal) then the CCITT family of kCCITT_* compression of which the kCCITT_FAX4 is the best are available.
									// If it is 24 bit (3 channel RGB) then kJPEG is available which will use JPEG DCT compression in the TIFF file. 
									TiffCompression *pComp = dynamic_cast<TiffCompression*>(pProp);
									if (pComp != NULL)
									{
										// G4 is only valid for 1 bit images. 
										if (pComp->selectCompression(TiffCompressionType::kCCITT_FAX4) == false)
										{
											// So if that fails, resort to LZW now that it is patent free
											if (pComp->selectCompression(TiffCompressionType::kLZW) == false)
											{
												// If that fails (and is shouldn’t, be) then set none.
												pComp->selectCompression(TiffCompressionType::kNone);
											}
										}
										// apply any changes we have made
										fileWriter.setProperty(pComp);
									}
								}

								// clean up
								delete pProp; 
								pProp = NULL;
							}
						}

						// be sure that the format has all the information it needs to write the file. 
						// In ATIL every property is required to have a valid default value. 
						// So if a certain property is REQUIRED by the codec to save the file, then it is safe 
						// and proper to simply loop over all the possible properties, enquire if it is required 
						// and simply set it with it’s default value
						Atil::FormatCodecPropertySetIterator* pPropsIter = fileWriter.newPropertySetIterator();
						// if ok
						if (pPropsIter)
						{
							for (pPropsIter->start(); !pPropsIter->endOfList(); pPropsIter->step())
							{
								Atil::FormatCodecPropertyInterface* pProp = pPropsIter->openProperty();
								if (pProp->isRequired())
								{
									fileWriter.setProperty(pProp);
								}
								pPropsIter->closeProperty();
							}
							delete pPropsIter;
						}

						// ok - ready to write it
						fileWriter.writeImageFrame(pPipe);
						done = true;
					}
				}
				delete pCodec;
			}
		}
	}
	catch ( Atil::ATILException e )
	{
		const Atil::StringBuffer *pStringMsg =e.getMessage();
	}

	return done;
}

void CreatePNG(const AcDbObjectId& idBlkTabRcd)
{
	///生成PNG图片
	int iWidth = 150;
	int iHeight = 98;

	AcGsManager *gsManager = acgsGetGsManager();
	
#if ARX == 2020
	AcGsKernelDescriptor keyDescriptor;
	keyDescriptor.addRequirement(AcGsKernelDescriptor::k3DDrawing);
	//keyDescriptor.addSupport(AcGsKernelDescriptor::k2DDrawing);
	AcGsGraphicsKernel *pGsKernal = AcGsManager::acquireGraphicsKernel(keyDescriptor);
	AcGsDevice *offDevice = gsManager->createAutoCADOffScreenDevice(*pGsKernal);
	AcGsModel *pModel = gsManager->createAutoCADModel(*pGsKernal);
#else
#if ZRX == 2021
	AcGsGraphicsKernel *pGsKernal = gsManager->getGSClassFactory(); 
	AcGsDevice *offDevice = gsManager->createAutoCADOffScreenDevice(*pGsKernal);
	AcGsModel *pModel = gsManager->createAutoCADModel(*pGsKernal);
#else
	//z2020/a2013
	//AcGsClassFactory *pGSFactory = gsManager->getGSClassFactory();
	AcGsClassFactory *pGsKernal = gsManager->getGSClassFactory();
	AcGsDevice *offDevice = gsManager->createAutoCADOffScreenDevice();
	AcGsModel *pModel = gsManager->createAutoCADModel();
#endif
#endif

	AcGsColor color = offDevice->getBackgroundColor();
	color.m_red   = 230;
	color.m_green = 239;
	color.m_blue  = 215;
	color.m_filler = 255; 
	offDevice->setBackgroundColor(color);

	offDevice->onSize(iWidth, iHeight);
	AcGsView *pView = pGsKernal->createView();
	
	// add for test
#if ARX
	//pView->setVisualStyle(AcGiVisualStyle::k3DWireframe);
	//pView->setVisualStyle(AcGiVisualStyle::kGouraud);  // The default in autoCad is kGouraud ?
	//pView->setVisualStyle(AcGiVisualStyle::k3DWireframe);
#else
	//pView->setVisualStyle(AcGiVisualStyle::kGouraud);
	//pView->setMode(AcGsView::kGouraudShaded);
	pView->setMode(AcGsView::kWireframe);
#endif

	offDevice->add(pView);

	AcDbBlockTableRecordPointer annonblk(idBlkTabRcd, AcDb::kForRead);
	if (annonblk.openStatus() == Acad::eOk)
	{
		AcDbExtents extAnonBlock;
		GetBigExt(idBlkTabRcd, extAnonBlock); 

		AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
		AcGeMatrix3d viewMat;
		SetViewTo(pView, pDb, viewMat, extAnonBlock);
		
		pView->add(annonblk, pModel);  ////Diff_2
	}

	refreshView(pView);
	offDevice->update(); 

	AcGsDCRect screenRect(0, iWidth, 0, iHeight);
	pView->getViewport(screenRect);

	static int sPos = 1;
	CString strTempPng;	
	//strTempPng.Format(_T("C:\\tl%d.png"), sPos);

	/// 临时文件保存到临时目录
	//CString strFilePath = _T("E:");
	CString strFilePath = _T("D:");
	strTempPng = strFilePath + _T("\\Temp\\tl1.png");

	int colorDepth = 32;
	int paletteSize = 0;

	if(CreateAtilImage(pView, iWidth, iHeight, colorDepth, paletteSize, strTempPng))
	{
		/// 及时删除临时文件
		///_tremove(strTempPng);
	}

	pView->eraseAll();
	offDevice->erase(pView);
	offDevice->eraseAll();

	pGsKernal->deleteView(pView);
	pGsKernal->deleteModel(pModel);

#if ZRX !=2020 && ARX != 2013
	AcGsManager::releaseGraphicsKernel(pGsKernal);
	pGsKernal = NULL;
#endif
}

AcDbExtents GetAllExtent(const AcDbObjectIdArray& idArrSel)
{
	AcDbExtents extRet;
	int iLen = idArrSel.length();
	if (iLen < 1)
	{
		return extRet;
	}

	AcAxDocLock DbLock(idArrSel.first().database());

	AcDbEntity* pCurEnt = NULL;
	for ( int i=0;i<iLen;++i )
	{
		AcDbObjectId idCur = idArrSel.at(i);
		Acad::ErrorStatus esOpen = acdbOpenAcDbEntity(pCurEnt, idCur, AcDb::kForRead);
		if (esOpen != Acad::eOk)
		{
			continue;
		}
		pCurEnt->close();

		AcDbExtents extCur;
		if(pCurEnt->getGeomExtents(extCur) != Acad::eOk)
		{
			continue;
		}

		extRet.addExt(extCur);
	}

	return extRet;
}

Acad::ErrorStatus CreateAnonBlock(const AcDbObjectIdArray& idArrSel, AcDbObjectId& idNewBlkRcd)
{
	Acad::ErrorStatus es = Acad::eInvalidInput;
	if(idArrSel.length() == 0)
	{
		return es;
	}

	AcAxDocLock DbLock(idArrSel.first().database());
	AcGeMatrix3d matTrans;
	{
		AcDbExtents extAll = GetAllExtent(idArrSel);

		AcGePoint3d ptSrcExtCent;
		ptSrcExtCent.x = (extAll.maxPoint().x + extAll.minPoint().x) / 2.0;
		ptSrcExtCent.y = (extAll.maxPoint().y + extAll.minPoint().y) / 2.0;

		AcGeVector3d vecMove = AcGePoint3d::kOrigin - ptSrcExtCent;
		matTrans.setToTranslation(vecMove);
	}

	AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
	if (pDb == NULL)
	{
		return es;
	}

	AcCmColor EntColor;
	EntColor.setRGB(227, 126, 58);

	/// 
	AcDbBlockTable *pBlockTable = NULL;
	AcDbBlockTableRecord *pAnonBlock = NULL;
	if( idNewBlkRcd == AcDbObjectId::kNull )
	{
		if ((es = pDb->getBlockTable(pBlockTable, AcDb::kForWrite)) != Acad::eOk) 
		{
			return es;
		}

		pAnonBlock = new AcDbBlockTableRecord;
		if(!pAnonBlock)
		{
			pBlockTable->close();
			return Acad::eNullObjectPointer;
		}

		if((es = pAnonBlock->setName(_T("*U"))) != Acad::eOk)
		{
			delete pAnonBlock;
			pBlockTable->close();
			return es;
		}

		es = pBlockTable->add(idNewBlkRcd, pAnonBlock);
		pBlockTable->close();
		if(es != Acad::eOk)
		{
			return es;
		}

		if((es = pAnonBlock->close()) != Acad::eOk)
		{
			return es;
		}
	}

	AcDbObjectPointer<AcDbBlockTableRecord> pAnonBlockObjectPtr(idNewBlkRcd, AcDb::kForWrite);
	if((es = pAnonBlockObjectPtr.openStatus()) != Acad::eOk)
	{
		return es;
	}

	for(int cnt = 0; cnt < idArrSel.length(); cnt++)
	{
		AcDbObjectId entId = idArrSel.at(cnt);

		AcDbObjectPointer<AcDbEntity> pEntity(entId, AcDb::kForRead);
		if(Acad::eOk == pEntity.openStatus())
		{
			if(pEntity->isKindOf(AcDbBlockReference::desc()))
			{
				AcDbVoidPtrArray subEntPtrArr;
				AcDbBlockReference* pBlock = (AcDbBlockReference*)(pEntity.object());

				pBlock->explode(subEntPtrArr);
				AcDbObjectId layerId = pBlock->layerId();

				for(int j=0; j<subEntPtrArr.length(); j++)
				{
					AcDbEntity* pSubEnt = (AcDbEntity*)(subEntPtrArr[j]);
					AcDbEntity *pCloneEnt = (AcDbEntity *) (pSubEnt->clone());

					{
						pCloneEnt->setColor(EntColor);

						//CPmAzReSetBlockEntOpr::ResetEnt( pCloneEnt ) ; 
					}

					pCloneEnt->setLayer(layerId);
					pCloneEnt->transformBy(matTrans);

					if((es = pAnonBlockObjectPtr->appendAcDbEntity(pCloneEnt)) != Acad::eOk)
					{
						break;
					}

					if((es = pCloneEnt->close()) != Acad::eOk)
					{
						break;
					}
				}

				for(int j=0; j<subEntPtrArr.length(); j++)
				{
					AcRxObject* pObj = (AcRxObject*)subEntPtrArr[j] ; 
					delete pObj;
					pObj = NULL;
				}
			}
			else
			{
				AcDbEntity *pCloneEnt = (AcDbEntity *) pEntity->clone();
				pCloneEnt->setColor(EntColor);
				//CPmAzReSetBlockEntOpr::ResetEnt( pCloneEnt ) ; 
				pCloneEnt->transformBy(matTrans);

				if((es = pAnonBlockObjectPtr->appendAcDbEntity(pCloneEnt)) != Acad::eOk)
				{
					break;
				}

				if((es = pCloneEnt->close()) != Acad::eOk)
				{
					break;
				}
			}
		}
	}

	return es;
}

//通用命令之删除(LOGI_TEST)
ARXCMD3(TestCreatePNG)
{
	ads_name adssetSingle;
	struct resbuf* pFilter = acutBuildList(RTDXF0, _T("INSERT"), RTNONE);
	int result = acedSSGet(_T(":S"), NULL, NULL, pFilter, adssetSingle);
	if (result != RTNORM)
	{
		return;
	}
	acutRelRb(pFilter);

	AcDbObjectIdArray idArrSingleSel;
	AsObjectIdArray(idArrSingleSel, adssetSingle);
	acedSSFree(adssetSingle);
	if (idArrSingleSel.length() < 1)
	{
		return;
	}

	AcDbObjectId idSel = idArrSingleSel.first();
	if (!idSel.isValid())
	{
		return;
	}

	AcDbEntity* pSelEnt = NULL;
	Acad::ErrorStatus esOpen = acdbOpenAcDbEntity(pSelEnt, idSel, AcDb::kForRead);
	if (esOpen != Acad::eOk || pSelEnt == NULL)
	{
		return;
	}

	AcDbBlockReference* pSelBlk = AcDbBlockReference::cast(pSelEnt);
	if (pSelBlk == NULL)
	{
		return;
	}

	AcDbObjectIdArray idArrSel;
	idArrSel.append(idSel);

	AcDbObjectId idBlkRcd;
	CreateAnonBlock(idArrSel, idBlkRcd);
	//AcDbObjectId idBlkRcd = pSelBlk->blockTableRecord();

	CreatePNG(idBlkRcd);
}
#endif