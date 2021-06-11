#ifndef ZD_ZCADSTRC_H
#define ZD_ZCADSTRC_H 1

#pragma pack (push, 8)

#define eNotImplemented eNotImplementedYet

struct Zcad
{
    enum ErrorStatus       { eOk                        =  0,

                             eNotImplementedYet         =  1,
                             eNotApplicable             =  2,
                             eInvalidInput              =  3,
                             eAmbiguousInput            =  4,
                             eAmbiguousOutput           =  5,
                             eOutOfMemory               =  6,
                             eBufferTooSmall            =  7,
                             eInvalidOpenState          =  8,
                             eEntityInInactiveLayout    =  9,

                             eHandleExists              = 10,
                             eNullHandle                = 11,
                             eBrokenHandle              = 12,
                             eUnknownHandle             = 13,
                             eHandleInUse               = 14,
                             eNullObjectPointer         = 15,
                             eNullObjectId              = 16,
                             eNullBlockName             = 17,
                             eContainerNotEmpty         = 18,

                             eNullEntityPointer         = 20,
                             eIllegalEntityType         = 21,
                             eKeyNotFound               = 22,
                             eDuplicateKey              = 23,
                             eInvalidIndex              = 24,
                             eDuplicateIndex            = 25,
                             eAlreadyInDb               = 26,
                             eOutOfDisk                 = 27,
                             eDeletedEntry              = 28,
                             eNegativeValueNotAllowed   = 29,
                             eInvalidExtents            = 30,
                             eInvalidAdsName            = 31,
                             eInvalidSymbolTableName    = 32,
                             eInvalidKey                = 33,
                             eWrongObjectType           = 34,
                             eWrongDatabase             = 35,
                             eObjectToBeDeleted         = 36,
                             eInvalidDwgVersion         = 37,
                             eAnonymousEntry            = 38,
                             eIllegalReplacement        = 39,

                             eEndOfObject               = 40,
                             eEndOfFile                 = 41,
                             eIsReading                 = 42,
                             eIsWriting                 = 43,
                             eNotOpenForRead            = 44,
                             eNotOpenForWrite           = 45,
                             eNotThatKindOfClass        = 46,
                             eInvalidBlockName          = 47,
                             eMissingDxfField           = 48,
                             eDuplicateDxfField         = 49,

                             eInvalidDxfCode            = 50,
                             eInvalidResBuf             = 51,
                             eBadDxfSequence            = 52,
                             eFilerError                = 53,
                             eVertexAfterFace           = 54,
                             eInvalidFaceVertexIndex    = 55,
                             eInvalidMeshVertexIndex    = 56,
                             eOtherObjectsBusy          = 57,
                             eMustFirstAddBlockToDb     = 58,
                             eCannotNestBlockDefs       = 59,

                             eDwgRecoveredOK            = 60,
                             eDwgNotRecoverable         = 61,
                             eDxfPartiallyRead          = 62,
                             eDxfReadAborted            = 63,
                             eDxbPartiallyRead          = 64,
                             eDwgCRCDoesNotMatch        = 65,
                             eDwgSentinelDoesNotMatch   = 66,
                             eDwgObjectImproperlyRead   = 67,
                             eNoInputFiler              = 68,
                             eDwgNeedsAFullSave         = 69,

                             eDxbReadAborted            = 70,
                             eFileLockedByZCAD          = 71,
                             eFileAccessErr             = 72,
                             eFileSystemErr             = 73,
                             eFileInternalErr           = 74,
                             eFileTooManyOpen           = 75,
                             eFileNotFound              = 76,
                             eDwkLockFileFound          = 77,

                             eWasErased                 = 80,
                             ePermanentlyErased         = 81,
                             eWasOpenForRead            = 82,
                             eWasOpenForWrite           = 83,
                             eWasOpenForUndo            = 84,
                             eWasNotifying              = 85,
                             eWasOpenForNotify          = 86,
                             eOnLockedLayer             = 87,
                             eMustOpenThruOwner         = 88,
                             eSubentitiesStillOpen      = 89,

                             eAtMaxReaders              = 90,
                             eIsWriteProtected          = 91,
                             eIsXRefObject              = 92,
                             eNotAnEntity               = 93,
                             eHadMultipleReaders        = 94,
                             eDuplicateRecordName       = 95,
                             eXRefDependent             = 96,
                             eSelfReference             = 97,
                             eMissingSymbolTable        = 98,
                             eMissingSymbolTableRec     = 99,

                             eWasNotOpenForWrite        = 100,
                             eCloseWasNotifying         = 101,
                             eCloseModifyAborted        = 102,
                             eClosePartialFailure       = 103,
                             eCloseFailObjectDamaged    = 104,
                             eCannotBeErasedByCaller    = 105,
                             eCannotBeResurrected       = 106,
                             eWasNotErased              = 107,

                             eInsertAfter               = 110,

                             eFixedAllErrors            = 120,
                             eLeftErrorsUnfixed         = 122,
                             eUnrecoverableErrors       = 123,
                             eNoDatabase                = 124,
                             eXdataSizeExceeded         = 125,
                             eRegappIdNotFound          = 126,
                             eRepeatEntity              = 127,
                             eRecordNotInTable          = 128,
                             eIteratorDone              = 129,
                             eNullIterator              = 130,
                             eNotInBlock                = 131,
                             eOwnerNotInDatabase        = 132,
                             eOwnerNotOpenForRead       = 133,
                             eOwnerNotOpenForWrite      = 134,
                             eExplodeBeforeTransform    = 135,
                             eCannotScaleNonUniformly   = 136,
                             eNotInDatabase             = 137,
                             eNotCurrentDatabase        = 138,
                             eIsAnEntity                = 139,

                             eCannotChangeActiveViewport = 140,
                             eNotInPaperspace           = 141,
                             eCommandWasInProgress      = 142,

                             eGeneralModelingFailure    = 150,
                             eOutOfRange                = 151,
                             eNonCoplanarGeometry       = 152,
                             eDegenerateGeometry        = 153,
                             eInvalidAxis               = 154,
                             ePointNotOnEntity          = 155,
                             eSingularPoint             = 156,
                             eInvalidOffset             = 157,
                             eNonPlanarEntity           = 158,
                             eCannotExplodeEntity       = 159,

                             eStringTooLong             = 160,
                             eInvalidSymTableFlag       = 161,
                             eUndefinedLineType         = 162,
                             eInvalidTextStyle          = 163,
                             eTooFewLineTypeElements    = 164,
                             eTooManyLineTypeElements   = 165,
                             eExcessiveItemCount        = 166,
                             eIgnoredLinetypeRedef      = 167,
                             eBadUCS                    = 168,
                             eBadPaperspaceView         = 169,

                             eSomeInputDataLeftUnread   = 170,
                             eNoInternalSpace           = 171,
                             eInvalidDimStyle           = 172,
                             eInvalidLayer              = 173,

                             eUserBreak                 = 180,
                             eUserUnloaded              = 181,

                             eDwgNeedsRecovery          = 190,
                             eDeleteEntity              = 191,
                             eInvalidFix                = 192,
                             eFSMError                  = 193,

                             eBadLayerName              = 200,
                             eLayerGroupCodeMissing     = 201,
                             eBadColorIndex             = 202,
                             eBadLinetypeName           = 203,
                             eBadLinetypeScale          = 204,
                             eBadVisibilityValue        = 205,
                             eProperClassSeparatorExpected = 206,
                             eBadLineWeightValue        = 207,
                             eBadColor                  = 208,
                             eBadMaterialName           = 209,

                             ePagerError                = 210,
                             eOutOfPagerMemory          = 211,
                             ePagerWriteError           = 212,
                             eWasNotForwarding          = 213,

                             eInvalidIdMap              = 220,
                             eInvalidOwnerObject        = 221,
                             eOwnerNotSet               = 222,

                             eWrongSubentityType        = 230,
                             eTooManyVertices           = 231,
                             eTooFewVertices            = 232,

                             eNoActiveTransactions      = 250,
                             eNotTopTransaction         = 251,
                             eTransactionOpenWhileCommandEnded =  252,
                             eInProcessOfCommitting     = 253,
                             eNotNewlyCreated           = 254,
                             eLongTransReferenceError   = 255,
                             eNoWorkSet                 = 256,

                             eAlreadyInGroup            = 260,
                             eNotInGroup                = 261,
							 eAlreadyInferred           = 262,

                             eInvalidREFIID             = 290,
                             eInvalidNormal             = 291,
                             eInvalidStyle              = 292,

                             eCannotRestoreFromAcisFile = 300,
                             eMakeMeProxy               = 301,
                             eNLSFileNotAvailable       = 302,
                             eNotAllowedForThisProxy    = 303,
                             eNotClonedPrimaryProxy     = 304,

                             eNotSupportedInDwgApi      = 310,
                             ePolyWidthLost             = 311,
                             eNullExtents               = 312,
                             eBadDwgHeader              = 314,

                             eLockViolation             = 320,
                             eLockConflict              = 321,
                             eDatabaseObjectsOpen       = 322,
                             eLockChangeInProgress      = 323,

                             eVetoed                    = 325,

                             eNoDocument                = 330,
                             eNotFromThisDocument       = 331,
                             eLISPActive                = 332,
                             eTargetDocNotQuiescent     = 333,
                             eDocumentSwitchDisabled    = 334,
                             eInvalidContext            = 335,

                             eCreateFailed              = 337,
                             eCreateInvalidName         = 338,
                             eSetFailed                 = 340,
                             eDelDoesNotExist           = 342,
                             eDelIsModelSpace           = 343,
                             eDelLastLayout             = 344,
                             eDelUnableToSetCurrent     = 345,
                             eDelUnableToFind           = 346,
                             eRenameDoesNotExist        = 348,
                             eRenameIsModelSpace        = 349,
                             eRenameInvalidLayoutName   = 350,
                             eRenameLayoutAlreadyExists = 351,
                             eRenameInvalidName         = 352,
                             eCopyDoesNotExist          = 354,
                             eCopyIsModelSpace          = 355,
                             eCopyFailed                = 356,
                             eCopyInvalidName           = 357,
                             eCopyNameExists            = 358,

                             eProfileDoesNotExist       = 359,
                             eInvalidFileExtension      = 360,
                             eInvalidProfileName        = 361,
                             eFileExists                = 362,
                             eProfileIsInUse            = 363,
                             eCantOpenFile              = 364,
                             eNoFileName                = 365,
                             eRegistryAccessError       = 366,
                             eRegistryCreateError       = 367,

                             eBadDxfFile                = 368,
                             eUnknownDxfFileFormat      = 369,
                             eMissingDxfSection         = 370,
                             eInvalidDxfSectionName     = 371,
                             eNotDxfHeaderGroupCode     = 372,
                             eUndefinedDxfGroupCode     = 373,
                             eNotInitializedYet         = 374,
                             eInvalidDxf2dPoint         = 375,
                             eInvalidDxf3dPoint         = 376,
                             eBadlyNestedAppData        = 378,
                             eIncompleteBlockDefinition = 379,
                             eIncompleteComplexObject   = 380,
                             eBlockDefInEntitySection   = 381,
                             eNoBlockBegin              = 382,
                             eDuplicateLayerName        = 383,
                             eBadPlotStyleName          = 384,
                             eDuplicateBlockName        = 385,
                             eBadPlotStyleType          = 386,
                             eBadPlotStyleNameHandle    = 387,
                             eUndefineShapeName         = 388,
                             eDuplicateBlockDefinition  = 389,
                             eMissingBlockName          = 390,
                             eBinaryDataSizeExceeded    = 391,
                             eObjectIsReferenced        = 392,
                             eNoThumbnailBitmap         = 393,
                             eGuidNoAddress             = 394,

                             eMustBe0to2                = 395,
                             eMustBe0to3                = 396,
                             eMustBe0to4                = 397,
                             eMustBe0to5                = 398,
                             eMustBe0to8                = 399,
                             eMustBe1to8                = 400,
                             eMustBe1to15               = 401,
                             eMustBePositive            = 402,
                             eMustBeNonNegative         = 403,
                             eMustBeNonZero             = 404,
                             eMustBe1to6                = 405,

                             eNoPlotStyleTranslationTable   = 406,
                             ePlotStyleInColorDependentMode = 407,
                             eMaxLayouts                = 408,
                             eNoClassId                 = 409,

                             eUndoOperationNotAvailable = 410,
                             eUndoNoGroupBegin          = 411,

                             eHatchTooDense             = 420,

                             eOpenFileCancelled         = 430,
                             eNotHandled                = 431,
                             eMakeMeProxyAndResurrect   = 432,
                             eFileSharingViolation      = 433,
                             eUnsupportedFileFormat     = 434,
                             eObsoleteFileFormat        = 435,
                             eFileMissingSections       = 436,
                             eRepeatedDwgRead           = 437,
							 eSilentOpenFileCancelled   = 438,

                             eWrongCellType             = 440,
                             eCannotChangeColumnType    = 441,
                             eRowsMustMatchColumns      = 442,

                             eNullNodeId                = 450,
                             eNoNodeActive              = 451,
                             eGraphContainsProxies      = 452,

                             eDwgShareDemandLoad        = 500,
                             eDwgShareReadAccess        = 501,
                             eDwgShareWriteAccess       = 502,
                             eLoadFailed                = 503,
                             eDeviceNotFound            = 504,
                             eNoCurrentConfig           = 505,
                             eNullPtr                   = 506,
                             eNoLayout                  = 507,
                             eIncompatiblePlotSettings  = 508,
                             eNonePlotDevice            = 509,
                             eNoMatchingMedia           = 510,
                             eInvalidView               = 511,
                             eInvalidWindowArea         = 512,
                             eInvalidPlotArea           = 513,
                             eCustomSizeNotPossible     = 514,
                             ePageCancelled             = 515,
                             ePlotCancelled             = 516,
                             eInvalidEngineState        = 517,
                             ePlotAlreadyStarted        = 518,
                             eNoErrorHandler            = 519,
                             eInvalidPlotInfo           = 520,
                             eNumberOfCopiesNotSupported = 521,
                             eLayoutNotCurrent          = 522,
                             eGraphicsNotGenerated      = 523,
                             eCannotPlotToFile          = 524,
                             eMustPlotToFile            = 525,
                             eNotMultiPageCapable       = 526,
                             eBackgroundPlotInProgress   = 527,
                             eNotShownInPropertyPalette  = 528,
                             eSubSelectionSetEmpty      = 550,
                             eNoIntersections           = 551,
                             eEmbeddedIntersections     = 552,
                             eNoOverride                = 570,
                             eNoStoredOverrides         = 571,
                             eUnableToRetrieveOverrides = 572,
                             eUnableToStoreOverrides    = 573,
                             eUnableToRemoveOverrides   = 574,
                             eNoStoredReconcileStatus         = 580,
                             eUnableToStoreReconcileStatus    = 581,
                             eInvalidObjectId               = 600,
                             eInvalidXrefObjectId           = 601,
                             eNoViewAssociation             = 602,
                             eNoLabelBlock                  = 603,
                             eUnableToSetViewAssociation    = 604,
                             eUnableToGetViewAssociation    = 605,
                             eUnableToSetLabelBlock         = 606,
                             eUnableToGetLabelBlock         = 607,
                             eUnableToRemoveAssociation     = 608,
                             eUnableToSyncModelView         = 609,
                             eDataLinkAdapterNotFound           = 650,
                             eDataLinkInvalidAdapterId          = 651,
                             eDataLinkNotFound                  = 652,
                             eDataLinkBadConnectionString       = 653,
                             eDataLinkNotUpdatedYet             = 654,
                             eDataLinkSourceNotFound            = 655,
                             eDataLinkConnectionFailed          = 656,
                             eDataLinkSourceUpdateNotAllowed    = 657,
                             eDataLinkSourceIsWriteProtected    = 658,
                             eDataLinkExcelNotFound             = 659,
                             eDataLinkOtherError                = 660,
                             eXrefReloaded                  = 700,
							 eXrefReloadImpossibleAtThisTime = 701,
                             eSecInitializationFailure      = 1001,
                             eSecErrorReadingFile           = 1002,
                             eSecErrorWritingFile           = 1003,
                             eSecInvalidDigitalID           = 1101,
                             eSecErrorGeneratingTimestamp   = 1102,
                             eSecErrorComputingSignature    = 1103,
                             eSecErrorWritingSignature      = 1104,
                             eSecErrorEncryptingData        = 1201,
                             eSecErrorCipherNotSupported    = 1202,
                             eSecErrorDecryptingData        = 1203,

                             eNoZcDbHostApplication         = 1300,
                             eNoUnderlayHost                = 1301,
							 ePCUnknown                     = 1400,
							 ePCLargeData                   = 1401,
							 ePCUnknownFileType             = 1402,
							 ePCFileNotFound                = 1403,
							 ePCFileNotCreated              = 1404,
							 ePCFileNotOpened               = 1405,
							 ePCFileNotClosed               = 1406,
							 ePCFileNotWritten              = 1407,
							 ePCFileWrongFormat             = 1408,
							 ePCFileDataSelectorInvalid     = 1409,
							 ePCCoordSysReprojectFail       = 1410,
							 ePCDiskSpaceTooSmall           = 1411,
							 ePCThreadTerminated            = 1412,
							 ePCFileNotErased               = 1413,
							 ePCCoordSysAssignFail          = 1414,
							 ePCLastImporterUnfinished      = 1415,
							 ePCNoEngineInfo                = 1416,
							 ePCInProgress                  = 1417,

                             eInetBase                  = 20000,
                             eInetOk                    = eInetBase,
                             eInetInCache,
                             eInetFileNotFound,
                             eInetBadPath,
                             eInetTooManyOpenFiles,
                             eInetFileAccessDenied,
                             eInetInvalidFileHandle,
                             eInetDirectoryFull,
                             eInetHardwareError,
                             eInetSharingViolation,
                             eInetDiskFull,
                             eInetFileGenericError,
                             eInetValidURL,
                             eInetNotAnURL,
                             eInetNoWinInet,
                             eInetOldWinInet,
                             eInetNoZcadInet,
                             eInetNotImplemented,
                             eInetProtocolNotSupported,

                             eInetCreateInternetSessionFailed,
                             eInetInternetSessionConnectFailed,
                             eInetInternetSessionOpenFailed,

                             eInetInvalidAccessType,
                             eInetFileOpenFailed,
                             eInetHttpOpenRequestFailed,
                             eInetUserCancelledTransfer,
                             eInetHttpBadRequest,
                             eInetHttpAccessDenied,
                             eInetHttpPaymentRequired,
                             eInetHttpRequestForbidden,
                             eInetHttpObjectNotFound,
                             eInetHttpBadMethod,
                             eInetHttpNoAcceptableResponse,
                             eInetHttpProxyAuthorizationRequired,
                             eInetHttpTimedOut,
                             eInetHttpConflict,
                             eInetHttpResourceGone,
                             eInetHttpLengthRequired,
                             eInetHttpPreconditionFailure,
                             eInetHttpRequestTooLarge,
                             eInetHttpUriTooLong,
                             eInetHttpUnsupportedMedia,

                             eInetHttpServerError,
                             eInetHttpNotSupported,
                             eInetHttpBadGateway,
                             eInetHttpServiceUnavailable,
                             eInetHttpGatewayTimeout,
                             eInetHttpVersionNotSupported,

                             eInetInternetError,
                             eInetGenericException,
                             eInetUnknownError,
                             eAlreadyActive,
                             eAlreadyInactive,
                             eGraphEdgeNotFound,
                             eGraphNodeNotFound,
                             eGraphNodeAlreadyExists,
                             eGraphEdgeAlreadyExists,
                             eGraphCyclesFound,
                             eAlreadyHasRepresentation,
                             eNoRepresentation,
                             eFailedToSetEdgeChamfers,
                             eNoConnectedBlendSet,
                             eFailedToBlend,
                             eFailedToSetEdgeRounds,
                             eFailedToSetVertexRounds,
                             eVSNotFound,
                             eVSTrue,
                             eVSFalse,
                             eVSAlreadyExists,
                             eVSOneOffCreated,
                             eVSAPIOnlyValues,
                             eVSIsInUse,
                             eVSIsZcadDefault,
                             eEmptyOperand,
                             eNoEntitiesFromPersistentIds,
                             eFailedCurveCheck,
							 eMaxNodes,

							 eFailedToEvaluate,
							 eFailedToEvaluateDependents,
							 eInvalidExpression,
							 eCyclicDependency,
							 eInconsistentConstraint,
							 eOverDefinedConstraint,
							 eAllInSameRigidSet,
							 eInvalidParameterName,
							 eReferencedInEquation,
							 eEntityRestricedInDOF,

							 eDataTooLarge,
							 eNearSizeLimit,

							 eStringNotAllowedInExpression,
							 eTooManyActiveCommands,

							 eUnableToTrimLastPiece,
							 eUnableToTrimSurface,

							 eModifyingAssociativeEntity,
							 eModifyingDimensionWithExpression,

							 eDependentOnObjectErased,
							 eSelfIntersecting,
							 eNotOnBoundary,
							 eNotConnected,
							 eNoInputPath,
							 eNotAssociative,

							 eNotG1Continuous,
							 eOwnerToBeTransformed,
							 eMustBeInteger,
							 eMustBePositiveInteger,

							 eChangedAgainstAssociativity,
							 eItemCountChanged,

							 eGetZdIntImgServicesFailed,

							 eReadImageBufferFailed,
							 eWriteImageBufferFailed,
							 eGetImageBytesFailed,
							 eGetImageDIBFailed,
							 eConvertImageFormatFailed,

							 eGetPreviewImageFailed,
							 eInvalidPreviewImage,

							 eDelayMore,
							 ePreviewFailed,
							 eAbortPreview,
							 eEndPreview,
							 eNoPreviewContext,

							 eFileNotInCloud,
            };

    enum PointHistory     {   eTablet      = 0x0001,
                              eNotDigitizer= 0x0002,
                              eLastPt     = 0x0004,

                              eGripped    = 0x008,
                              eCartSnapped= 0x0010,

                              eOrtho      = 0x0020,
                              eCyclingPt  = 0x0040,
                              eOsnapped   = 0x0080,
                              ePolarAngle = 0x0100,
                              eAligned    = 0x0400,

                              eAppFiltered = 0x0800,
                              eForcedPick = 0x1000,
                              ePickMask   = 0xE000,

                              eDidNotPick = 0x0000,

                              eUsedPickBox = 0x2000, 

                              eUsedOsnapBox = 0x4000,

                              ePickAborted  = 0x8000,
                              eXPending   = 0x10000,
                              eYPending   = 0x20000,
                              eZPending   = 0x40000,
                              eCoordPending = 0x70000,

                              eFromKeyboard = 0x80000,

                              eNotInteractive = 0x100000,
							  eDirectDistance = 0x200000,
							  eGizmoConstrainted = 0x400000,
    };

    enum PromptStatus {
        eNone     =  5000,
		eModeless =  5027,
        eNormal   =  5100,
        eError    = -5001,
        eCancel   = -5002,
        eRejected = -5003,
        eFailed   = -5004,
        eKeyword  = -5005,
        eDirect   = -5999
    };

};

#pragma pack (pop)
#endif
