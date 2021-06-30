using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Win32;
using RegistryKey = Microsoft.Win32.RegistryKey;
using Registry = Microsoft.Win32.Registry;
#if ZRX
using ZWCAD;
using ZwSoft.ZwCAD.EditorInput;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.Runtime;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.Windows;
using TransactionManager = ZwSoft.ZwCAD.DatabaseServices.TransactionManager;
#else
using Autodesk.AutoCAD.EditorInput;
using Autodesk.AutoCAD.ApplicationServices;
using Autodesk.AutoCAD.Runtime;
using Autodesk.AutoCAD.DatabaseServices;
using Autodesk.AutoCAD.Geometry;
using Autodesk.AutoCAD.Windows;
using Autodesk.AutoCAD.Internal;
using TransactionManager = Autodesk.AutoCAD.DatabaseServices.TransactionManager;
#endif

[assembly: CommandClass(typeof(NETCAD.Class1))]

namespace NETCAD
{
    public class Class1
    {
        [CommandMethod("Test_Line")]
        public static void Test_Line()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                Polyline line = new Polyline();
                line.AddVertexAt(0, new Point2d(0, 0), 0, 0, 0);
                line.AddVertexAt(1, new Point2d(500, 500), 0, 0, 0);
                line.ColorIndex = 1;
                line.LineWeight = LineWeight.LineWeight050;

                BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForWrite);
                btr.AppendEntity(line);

                trans.AddNewlyCreatedDBObject(line, true);
                trans.Commit();
            }
        }
        [CommandMethod("TEST_Select")]
        public void Test()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;//获取当前活动文档
            Database db = doc.Database;
            Editor ed = doc.Editor;

            Entity entity = null;
            DBObjectCollection entCol = new DBObjectCollection();
            PromptSelectionResult proSelRes = ed.GetSelection();//获取用户框选集合
            if (proSelRes.Status == PromptStatus.OK)
            {
                using (Transaction trans = db.TransactionManager.StartTransaction())
                {
                    SelectionSet ss = proSelRes.Value;
                    foreach (ObjectId id in ss.GetObjectIds())
                    {
                        entity = (Entity)trans.GetObject(id, OpenMode.ForRead, true);
                        if (entity != null)
                        {
                            entCol.Add(entity);
                        }

                    }
                    trans.Commit();
                }
            }
        }
        [CommandMethod("TEST_ScreenUpdate")]
        public static void TEST_ScreenUpdate()
        {
            Form1 form1 = new Form1();
            form1.Show();
        }
        [CommandMethod("Test_CloseAndSave", CommandFlags.Session)]
        public void Test_CloseAndSave()
        {
#if ZRX
            DocumentCollection acDocMgr = ZwSoft.ZwCAD.ApplicationServices.Application.DocumentManager;
            ZwSoft.ZwCAD.ApplicationServices.Document dc = acDocMgr.MdiActiveDocument;
            //Document dc = Application.DocumentManager.Open("D:\\1.dwg", false);
            dc.CloseAndSave(dc.Name);
#else
            DocumentCollection acDocMgr = Autodesk.AutoCAD.ApplicationServices.Application.DocumentManager;
            Autodesk.AutoCAD.ApplicationServices.Document dc = acDocMgr.MdiActiveDocument;
            //Document dc = Application.DocumentManager.Open("D:\\1.dwg", false);
            //Autodesk.AutoCAD.ApplicationServices.DocumentExtension.CloseAndSave(dc, dc.Name);
            dc.CloseAndSave(dc.Name);
#endif
        }
        [CommandMethod("Test_save", CommandFlags.Session)]
        public void Test_save()
        {
            DocumentCollection acDocMgr = Application.DocumentManager;
            acDocMgr.MdiActiveDocument.CloseAndSave(acDocMgr.MdiActiveDocument.Name);
        }
        private static void AutoLoad(string dname, string desc, string dpath)
        {
            RegistryKey LocalMachine = Registry.LocalMachine;
            RegistryKey Applications = LocalMachine.OpenSubKey("SOFTWARE\\ZWSOFT\\ZWCAD\\2021\\zh-CN\\Applications", true);
            RegistryKey MyPrograrm = Applications.CreateSubKey(dname);
            MyPrograrm.SetValue("DESCRIPTION", desc, RegistryValueKind.String);
            MyPrograrm.SetValue("LOADCTRLS", 13, RegistryValueKind.DWord);
            MyPrograrm.SetValue("LOADER", dpath, RegistryValueKind.String);
            MyPrograrm.SetValue("MANAGED", 1, RegistryValueKind.DWord);
            MyPrograrm.Close();
        }
        public static void Test_AutoLoadDLL()
        {
            AutoLoad("MyPrograrm", "NewDLL", "D:\\a.dll");
        }
        //关闭zwcad会重新写注册表，所以应该在启动zwcad读取注册表之前修改注册表的值，避免被覆盖
        public static void Test_AddSearchPath()
        {
            RegistryKey CurrentUser = Registry.CurrentUser;
            RegistryKey Config = CurrentUser.OpenSubKey("Software\\ZWSOFT\\ZWCAD\\2021\\zh-CN\\Profiles\\Default\\Config", true);
            Config.SetValue("ZWCADSEARCHPATH", "E:\\", RegistryValueKind.String);
        }
        [CommandMethod("Test_AssemblyLoad")]
        public static void Test_AssemblyLoad()
        {
            System.Reflection.Assembly.LoadFrom("E:\\aaa.dll");
        }

        void GetObjectCollection(string prompt, ObjectIdCollection objCol)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
#if ZRX
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
#else
            Autodesk.AutoCAD.EditorInput.Editor ed = doc.Editor;
#endif

            PromptSelectionOptions selectionOpts = new PromptSelectionOptions();
            selectionOpts.MessageForAdding = prompt;
            PromptSelectionResult proSelRes = ed.GetSelection(selectionOpts);
            if (proSelRes.Status != PromptStatus.OK)
            {
                return;
            }
            foreach (ObjectId objId in proSelRes.Value.GetObjectIds())
            {
                objCol.Add(objId);
            }
        }

        [CommandMethod("DraworderCSExample")]
        public void DraworderCSExample()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
#if ZRX
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
#else
            Autodesk.AutoCAD.EditorInput.Editor ed = doc.Editor;
#endif

            ObjectIdCollection objCol = new ObjectIdCollection();
            GetObjectCollection("\n选择要改变绘制顺序的对象：", objCol);
            if (objCol.Count == 0)
                return;

            PromptKeywordOptions kwordsOpts = new PromptKeywordOptions("\n输入选项 : ");

            kwordsOpts.Keywords.Add("A", "A", "对象上(A)", true, true);
            kwordsOpts.Keywords.Add("U", "U", "对象下(U)", true, true);
            kwordsOpts.Keywords.Add("F", "F", "最前(F)", true, true);
            kwordsOpts.Keywords.Add("B", "B", "最后(B)", true, true);
            kwordsOpts.Keywords.Default = "B";
            PromptResult proRes = doc.Editor.GetKeywords(kwordsOpts);
            if (proRes.Status == PromptStatus.OK)
            {
                switch (proRes.StringResult)
                {
                    case "A":
                        ObjectIdCollection tarObjCol = new ObjectIdCollection();
                        GetObjectCollection("\n选择参照对象：", tarObjCol);

                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            for (int i = tarObjCol.Count - 1; i >= 0; i--)
                            {
                                dot.MoveAbove(objCol, tarObjCol[i]);
                            }
                            trans.Commit();
                        }
                        break;
                    case "U":
                        ObjectIdCollection tarObjCol1 = new ObjectIdCollection();
                        GetObjectCollection("\n选择参照对象：", tarObjCol1);

                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            foreach (ObjectId id in tarObjCol1)
                            {
                                dot.MoveBelow(objCol, id);
                            }
                            trans.Commit();
                        }
                        break;
                    case "F":
                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            dot.MoveToTop(objCol);
                            trans.Commit();
                        }
                        break;
                    case "B":
                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            dot.MoveToBottom(objCol);
                            trans.Commit();
                        }
                        break;
                }
            }
            else if (proRes.Status == PromptStatus.Cancel)
                return;
        }

        [CommandMethod("TestGetKeyWord")]
        public void TestGetKeyWord()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;

            PromptKeywordOptions kwOpts = new PromptKeywordOptions("Input KeyWord ");

            kwOpts.Keywords.Add("A", "A", "Branch A(A)", true, true);
            kwOpts.Keywords.Add("B", "B", "Branch B(B)", true, true);
            kwOpts.Keywords.Add("C", "C", "Branch C(C)", true, true);
            kwOpts.Keywords.Add("D", "D", "Branch D(D)", true, true);
            kwOpts.Keywords.Default = "D";

            PromptResult kwordRes = ed.GetKeywords(kwOpts);

            if (kwordRes.Status == PromptStatus.OK)
            {
                switch (kwordRes.StringResult)
                {
                    case "A":
                        {
                            ed.WriteMessage("This is Branch A");
                            break;
                        }
                    case "B":
                        {
                            ed.WriteMessage("This is Branch B");
                            break;
                        }
                    case "C":
                        {
                            ed.WriteMessage("This is Branch C");
                            break;
                        }
                    case "D":
                        {
                            ed.WriteMessage("This is Branch D");
                            break;
                        }
                }
            }
            else
            {
                ed.WriteMessage("Other Status: " + kwordRes.Status.ToString());
            }

        }

        [CommandMethod("Getentity")]
        public void EntityTest()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            PromptEntityOptions entopts = new PromptEntityOptions("Pick an entity of your choice from the drawing");
            entopts.Message = "Pick an entity of your choice from the drawing";
            PromptEntityResult ent = null;

            try
            {
                ent = ed.GetEntity(entopts);
            }
            catch
            {
                ed.WriteMessage("You did not select a valid entity");
            }

            if (ent.Status != PromptStatus.Error)
            {
                ObjectId entid = ent.ObjectId;
                Database db = Application.DocumentManager.MdiActiveDocument.Database;
#if ZRX
                ZwSoft.ZwCAD.DatabaseServices.TransactionManager tm = db.TransactionManager;
#else
                Autodesk.AutoCAD.DatabaseServices.TransactionManager tm = db.TransactionManager;
#endif
                using (Transaction myT = tm.StartTransaction())
                {
                    Entity entity = (Entity)tm.GetObject(entid, OpenMode.ForRead, true);
                    ed.WriteMessage("You selected: " + entity.GetType().FullName);
                    myT.Commit();
                }
            }
        }

        [CommandMethod("TestMoveAbove")]
        public void TestMoveAbove()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            ObjectIdCollection objCol = new ObjectIdCollection();
            GetObjectCollection("\n选择要改变绘制顺序的对象：", objCol);
            if (objCol.Count == 0)
                return;

            ObjectIdCollection tarObjCol = new ObjectIdCollection();
            GetObjectCollection("\n选择参照对象：", tarObjCol);
            if (tarObjCol.Count == 0)
                return;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                for (int i = tarObjCol.Count - 1; i >= 0; i--)
                {
                    dot.MoveAbove(objCol, tarObjCol[i]);
                }
                trans.Commit();
            }
        }

        [CommandMethod("SSetModeless")]
        static public void SSetModeless()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();

            PromptSelectionResult selRes = ed.GetSelection(selOpts);
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet SSet = selRes.Value;
            ObjectId[] objIdIds = SSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIdIds.Count());
        }
        [CommandMethod("SelectAll")]
        static public void SelectAll()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionResult selRes = ed.SelectAll();
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet SSet = selRes.Value;
            ObjectId[] objIdIds = SSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIdIds.Count());
        }
        [CommandMethod("Select_Single")]
        static public void SelectSingle()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();
            selOpts.SingleOnly = true;

            PromptSelectionResult selRes = ed.GetSelection();
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Count());

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                foreach (ObjectId objId in objIds)
                {
                    Entity entity = (Entity)objId.GetObject(OpenMode.ForWrite);

                    ed.WriteMessage("\nThe Entity you select is " + entity.GetType().FullName);

                    if (entity.GetType() == typeof(Line) || entity.GetType() == typeof(Circle))
                        entity.ColorIndex = 1;
                }
                trans.Commit();
            }
        }

        public static Dictionary<string, object> oldSysVar = new Dictionary<string, object>();

        [CommandMethod("SetSysVarInt")]
        static public void SetSysVarInt()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            object obj = Application.GetSystemVariable("CURSORSIZE");
            if (!oldSysVar.ContainsKey("CURSORSIZE"))
                oldSysVar.Add("CURSORSIZE", obj);

            PromptIntegerOptions intOpts = new PromptIntegerOptions("设置光标大小(整数1-100)：");
            intOpts.AllowNegative = false;
            intOpts.AllowZero = false;
            PromptIntegerResult IntRes = ed.GetInteger(intOpts);
            if (IntRes.Status == PromptStatus.OK)
            {
                Application.SetSystemVariable("CURSORSIZE", IntRes.Value);
            }
        }
        [CommandMethod("SetSysVarStr")]
        static public void SetSysVarStr()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            object obj = Application.GetSystemVariable("CECOLOR");
            if (!oldSysVar.ContainsKey("CECOLOR"))
                oldSysVar.Add("CECOLOR", obj);

            PromptStringOptions strOpts = new PromptStringOptions("设置颜色(BYLAYER/BYBLOCK/1-255)：");
            strOpts.AllowSpaces = false;

            PromptResult StrRes = ed.GetString(strOpts);
            if (StrRes.Status == PromptStatus.OK)
            {
                Application.SetSystemVariable("CECOLOR", StrRes.StringResult);
            }
        }
        [CommandMethod("SetSysVarReal")]
        static public void SetSysVarReal()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            object obj = Application.GetSystemVariable("CIRCLERAD");
            if (!oldSysVar.ContainsKey("CIRCLERAD"))
                oldSysVar.Add("CIRCLERAD", obj);

            PromptDoubleOptions DblOpts = new PromptDoubleOptions("设置圆默认半径(实数)：");
            DblOpts.AllowNegative = false;
            DblOpts.AllowNone = false;

            PromptDoubleResult DblRes = ed.GetDouble(DblOpts);
            if (DblRes.Status == PromptStatus.OK)
            {
                Application.SetSystemVariable("CIRCLERAD", DblRes.Value);
            }
        }
        [CommandMethod("GetSysVarPoint")]
        static public void GetSysVarPoint()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            Point3d pt3d = (Point3d)Application.GetSystemVariable("VIEWCTR");
            ed.WriteMessage("VIEWCTR = ({0}, {1}, {2})", pt3d.X, pt3d.Y, pt3d.Z);
        }
        public static void resetSysVar()
        {
            foreach (var item in oldSysVar)
            {
                Application.SetSystemVariable(item.Key, item.Value);
            }
        }

        [CommandMethod("AddingAttributeToABlock")]
        public void AddingAttributeToABlock()
        {
            // Get the current database and start a transaction
            Database acCurDb;
            acCurDb = Application.DocumentManager.MdiActiveDocument.Database;

            using (Transaction acTrans = acCurDb.TransactionManager.StartTransaction())
            {
                // Open the Block table for read
                BlockTable acBlkTbl;
                acBlkTbl = acTrans.GetObject(acCurDb.BlockTableId, OpenMode.ForRead) as BlockTable;

                if (!acBlkTbl.Has("CircleBlockWithAttributes"))
                {
                    using (BlockTableRecord acBlkTblRec = new BlockTableRecord())
                    {
                        acBlkTblRec.Name = "CircleBlockWithAttributes";

                        // Set the insertion point for the block
                        acBlkTblRec.Origin = new Point3d(0, 0, 0);

                        // Add a circle to the block
                        using (Circle acCirc = new Circle())
                        {
                            acCirc.Center = new Point3d(0, 0, 0);
                            acCirc.Radius = 2;

                            acBlkTblRec.AppendEntity(acCirc);

                            // Add an attribute definition to the block
                            using (AttributeDefinition acAttDef = new AttributeDefinition())
                            {
                                acAttDef.Position = new Point3d(0, 0, 0);
                                acAttDef.Verifiable = true;
                                acAttDef.Prompt = "Door #: ";
                                acAttDef.Tag = "Door#";
                                acAttDef.TextString = "DXX";
                                acAttDef.Height = 1;
                                acAttDef.Justify = AttachmentPoint.MiddleCenter;

                                acBlkTblRec.AppendEntity(acAttDef);

                                acTrans.GetObject(acCurDb.BlockTableId, OpenMode.ForWrite);
                                acBlkTbl.Add(acBlkTblRec);
                                acTrans.AddNewlyCreatedDBObject(acBlkTblRec, true);
                            }
                        }
                    }
                }

                // Save the new object to the database
                acTrans.Commit();

                // Dispose of the transaction
            }
        }


        [CommandMethod("CreateBlockTest1")]
        static public void CreateBlockTest1()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            DocumentLock docLock = doc.LockDocument();
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);

                BlockTableRecord newBlkRec = new BlockTableRecord();
                newBlkRec.Name = "szBlock1";
                newBlkRec.Origin = new Point3d(1000, 1000, 0);

                if (blockTable.Has(newBlkRec.Name))
                {
                    ed.WriteMessage("\nThe block already exists!");
                    return;
                }
                blockTable.UpgradeOpen();
                ObjectId newBlkRecId = blockTable.Add(newBlkRec);
                trans.AddNewlyCreatedDBObject(newBlkRec, true);

                DBObjectCollection ents = new DBObjectCollection();
                Point3d ptCtr = new Point3d(1000, 1000, 0);
                Circle circle = new Circle(ptCtr, Vector3d.ZAxis, 200.0);
                ents.Add(circle);
                Point3d ptSt1 = new Point3d(1000, 750, 0);
                Point3d ptEd1 = new Point3d(1000, 1250, 0);
                Line line1 = new Line(ptSt1, ptEd1);
                ents.Add(line1);
                Point3d ptSt2 = new Point3d(750, 1000, 0);
                Point3d ptEd2 = new Point3d(1250, 1000, 0);
                Line line2 = new Line(ptSt2, ptEd2);
                ents.Add(line2);

                foreach (Entity ent in ents)
                {
                    newBlkRec.AppendEntity(ent);
                    trans.AddNewlyCreatedDBObject(ent, true);
                }

                BlockTableRecord msBlkRec = (BlockTableRecord)trans.GetObject(blockTable[BlockTableRecord.ModelSpace], OpenMode.ForWrite);
                BlockReference blockRef = new BlockReference(ptCtr, newBlkRecId);
                msBlkRec.AppendEntity(blockRef);
                trans.AddNewlyCreatedDBObject(blockRef, true);

                trans.Commit();
            }
            docLock.Dispose();
        }
        [CommandMethod("CreateBlockTest2")]
        static public void CreateBlockTest2()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();
            selOpts.MessageForAdding = "Select some entities:";
            PromptSelectionResult selRes = ed.GetSelection(selOpts);
            if (selRes.Status != PromptStatus.OK)
            {
                ed.WriteMessage("\nNo entity selected!");
                return;
            }
            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            BlockReferenceParam blkRefParam = new BlockReferenceParam();
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);

                BlockTableRecord newBlkRec = new BlockTableRecord();
                newBlkRec.Name = "szBlock2";
                newBlkRec.Origin = new Point3d(1000, 1000, 0);

                if (blockTable.Has(newBlkRec.Name))
                {
                    ed.WriteMessage("\nThe block already exists!");
                    return;
                }
                blockTable.UpgradeOpen();
                ObjectId newBlkRecId = blockTable.Add(newBlkRec);
                trans.AddNewlyCreatedDBObject(newBlkRec, true);

                Extents3d extAll = new Extents3d();
                foreach (ObjectId objId in objIds)
                {
                    Entity subEnt = (Entity)objId.GetObject(OpenMode.ForWrite);
                    Extents3d extCur = subEnt.GeometricExtents;
                    extAll.AddExtents(extCur);

                    Entity ent = (Entity)subEnt.Clone();
                    subEnt.Erase();
                    newBlkRec.AppendEntity(ent);
                    trans.AddNewlyCreatedDBObject(ent, true);
                }

                Point3d ptMin = extAll.MinPoint;
                Point3d ptMax = extAll.MaxPoint;
                Point3d ptCtr = new Point3d(ptMin.X / 2 + ptMax.X / 2, ptMin.Y / 2 + ptMax.Y / 2, ptMin.Z / 2 + ptMax.Z / 2);
                newBlkRec.Origin = ptMin;

                AttributeDefinition attDef = new AttributeDefinition();
                attDef.Position = ptCtr;
                //attDef.AlignmentPoint = ptMin;
                attDef.Verifiable = true;
                attDef.Tag = "AttTag";
                attDef.TextString = "AAAAA";
                attDef.ColorIndex = 1;
                attDef.Height = ptMin.DistanceTo(ptMax) / 10;


                newBlkRec.AppendEntity(attDef);
                trans.AddNewlyCreatedDBObject(attDef, true);

                blkRefParam.BlockName = newBlkRec.Name;
                blkRefParam.Position = newBlkRec.Origin;
                blkRefParam.Rotation = 0.0;
                blkRefParam.Scale = 1.0;

                trans.Commit();
            }

            InsertBlock(blkRefParam);
        }

        static public void InsertBlock(BlockReferenceParam blkRefParam)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);


                if (!blockTable.Has(blkRefParam.BlockName))
                {
                    ed.WriteMessage("\nThe Block doesn't exist!");
                    return;
                }
                else
                {
                    BlockTableRecord newBlkRec = (BlockTableRecord)trans.GetObject(blockTable[blkRefParam.BlockName], OpenMode.ForRead);

                    BlockTableRecord msBlkRec = (BlockTableRecord)trans.GetObject(blockTable[BlockTableRecord.ModelSpace], OpenMode.ForWrite);
                    BlockReference blockRef = new BlockReference(newBlkRec.Origin, newBlkRec.ObjectId);
                    blockRef.SetDatabaseDefaults();
                    blockRef.Position = blkRefParam.Position;
                    blockRef.ScaleFactors = new Scale3d(blkRefParam.Scale);
                    blockRef.Rotation = blkRefParam.Rotation;

                    msBlkRec.AppendEntity(blockRef);
                    trans.AddNewlyCreatedDBObject(blockRef, true);

                    if (newBlkRec.HasAttributeDefinitions)
                    {
                        foreach (ObjectId objId in newBlkRec)
                        {
                            DBObject dbObj = trans.GetObject(objId, OpenMode.ForRead) as DBObject;

                            if (dbObj is AttributeDefinition)
                            {
                                AttributeDefinition attDef = dbObj as AttributeDefinition;

                                using (AttributeReference attRef = new AttributeReference())
                                {
                                    attRef.SetAttributeFromBlock(attDef, blockRef.BlockTransform);
                                    //attRef.Position = attDef.Position.TransformBy(blockRef.BlockTransform);
                                    //attRef.TextString = attDef.TextString;
                                    blockRef.AttributeCollection.AppendAttribute(attRef);
                                    trans.AddNewlyCreatedDBObject(attRef, true);
                                }
                            }
                        }
                    }
                }
                trans.Commit();
            }
        }

        [CommandMethod("InsertBlockTest")]
        static public void InsertBlockTest()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            BlockReferenceParam blkRefParam = new BlockReferenceParam();
            blkRefParam.BlockName = null;
            blkRefParam.Position = new Point3d(0, 0, 0);
            blkRefParam.Rotation = 0.0;
            blkRefParam.Scale = 1.0;

            PromptStringOptions strOpts = new PromptStringOptions("Enter block name");
            strOpts.AllowSpaces = false;
            PromptResult strRes = ed.GetString(strOpts);
            if (strRes.Status == PromptStatus.OK)
                blkRefParam.BlockName = strRes.StringResult;

            PromptPointOptions ptOpts = new PromptPointOptions("Pick insert position");
            ptOpts.AllowNone = false;
            PromptPointResult ptRes = ed.GetPoint(ptOpts);
            if (ptRes.Status == PromptStatus.OK)
                blkRefParam.Position = ptRes.Value;

            PromptDoubleOptions dblOptsRt = new PromptDoubleOptions("Enter the Rotation");
            dblOptsRt.AllowNone = false;
            PromptDoubleResult dblResRt = ed.GetDouble(dblOptsRt);
            if (dblResRt.Status == PromptStatus.OK)
                blkRefParam.Rotation = dblResRt.Value;

            PromptDoubleOptions dblOptsScale = new PromptDoubleOptions("Enter the ScaleFactor");
            dblOptsScale.AllowNone = false;
            PromptDoubleResult dblResScale = ed.GetDouble(dblOptsScale);
            if (dblResScale.Status == PromptStatus.OK)
                blkRefParam.Scale = dblResScale.Value;

            InsertBlock(blkRefParam);
        }

        [CommandMethod("Test_DbTextExtents")]
        static public void Test_DbTextExtents()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                DBText attText = new DBText();
                attText.TextString = "Text";
                BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForWrite);
                btr.AppendEntity(attText);
                trans.AddNewlyCreatedDBObject(attText, true);
                trans.Commit();

                try
                {
                    double x = attText.GeometricExtents.MinPoint.X;
                }
                catch (System.Exception)
                {
                    throw;    //zwcad2021中若dbtext为空或者先捕捉异常后入库均会捕捉到eNullExtents；acad2020中dbtext为空捕捉到异常
                }

            }
        }

        [LispFunction("RectArea")]
        static public void RectArea(ResultBuffer rbArgs)
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            if (rbArgs != null)
            {
                Point3d[] pt3dArr = new Point3d[2];
                int i = 0;
                foreach (TypedValue rb in rbArgs)
                {
                    if (rb.TypeCode == (int)LispDataType.Point3d)
                    {
                        pt3dArr[i] = (Point3d)rb.Value;
                    }
                    else if (rb.TypeCode == (int)LispDataType.Point2d)
                    {
                        Point2d pt2dTmp = (Point2d)rb.Value;
                        pt3dArr[i] = new Point3d(pt2dTmp.X, pt2dTmp.Y, 0);
                    }
                    else
                    {
                        ed.WriteMessage("\nerror parameter");
                    }
                    i++;
                }
                if (i < 2)
                {
                    ed.WriteMessage("\nnot whole");

                }
                ed.WriteMessage("\n({0},{1},{2}) ({3},{4},{5}) {6}", pt3dArr[0].X, pt3dArr[0].Y, pt3dArr[0].Z, pt3dArr[1].X, pt3dArr[1].Y, pt3dArr[1].Z, i);
            }
            else
            {
                ed.WriteMessage("\nNULL");
            }
        }

        [CommandMethod("CreateCompositeRegions")]
        public static void CreateCompositeRegions()
        {
            // Get the current document and database
            Document acDoc = Application.DocumentManager.MdiActiveDocument;
            Database acCurDb = acDoc.Database;

            // Start a transaction
            using (Transaction acTrans = acCurDb.TransactionManager.StartTransaction())
            {
                // Open the Block table for read
                BlockTable acBlkTbl;
                acBlkTbl = acTrans.GetObject(acCurDb.BlockTableId,
                                                OpenMode.ForRead) as BlockTable;

                // Open the Block table record Model space for write
                BlockTableRecord acBlkTblRec;
                acBlkTblRec = acTrans.GetObject(acBlkTbl[BlockTableRecord.ModelSpace],
                                                OpenMode.ForWrite) as BlockTableRecord;

                // Create two in memory circles
                using (Circle acCirc1 = new Circle())
                {
                    acCirc1.Center = new Point3d(4, 4, 0);
                    acCirc1.Radius = 2;

                    using (Circle acCirc2 = new Circle())
                    {
                        acCirc2.Center = new Point3d(4, 4, 0);
                        acCirc2.Radius = 1;

                        // Adds the circle to an object array
                        DBObjectCollection acDBObjColl = new DBObjectCollection();
                        acDBObjColl.Add(acCirc1);
                        acDBObjColl.Add(acCirc2);

                        // Calculate the regions based on each closed loop
                        DBObjectCollection myRegionColl = new DBObjectCollection();
                        myRegionColl = Region.CreateFromCurves(acDBObjColl);
                        Region acRegion1 = myRegionColl[0] as Region;
                        Region acRegion2 = myRegionColl[1] as Region;

                        // Subtract region 1 from region 2
                        if (acRegion1.Area > acRegion2.Area)
                        {
                            // Subtract the smaller region from the larger one
                            acRegion1.BooleanOperation(BooleanOperationType.BoolSubtract, acRegion2);
                            acRegion2.Dispose();

                            // Add the final region to the database
                            acBlkTblRec.AppendEntity(acRegion1);
                            acTrans.AddNewlyCreatedDBObject(acRegion1, true);
                        }
                        else
                        {
                            // Subtract the smaller region from the larger one
                            acRegion2.BooleanOperation(BooleanOperationType.BoolSubtract, acRegion1);
                            acRegion1.Dispose();

                            // Add the final region to the database
                            acBlkTblRec.AppendEntity(acRegion2);
                            acTrans.AddNewlyCreatedDBObject(acRegion2, true);
                        }

                        // Dispose of the in memory objects not appended to the database
                    }
                }

                // Save the new object to the database
                acTrans.Commit();
            }
        }

        [CommandMethod("ASD")]
        public void DeleteAll()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            ObjectContextManager ocm = db.ObjectContextManager;

            if (ocm != null)
            {
                // Now get the Annotation Scaling context collection
                // (named ACDB_ANNOTATIONSCALES_COLLECTION)
                ObjectContextCollection occ = ocm.GetContextCollection("ACDB_ANNOTATIONSCALES");

                PromptEntityOptions entOpts = new PromptEntityOptions("Select a Entity:");
                entOpts.SetRejectMessage("\n实体必须支持注释比例.");
                entOpts.AddAllowedClass(typeof(DBText), false);
                entOpts.AddAllowedClass(typeof(MText), false);
                entOpts.AddAllowedClass(typeof(Dimension), false);
                entOpts.AddAllowedClass(typeof(Leader), false);
                entOpts.AddAllowedClass(typeof(Hatch), false);
                PromptEntityResult entRes = ed.GetEntity(entOpts);

                if (entRes.Status == PromptStatus.OK)
                {
                    ObjectId objId = entRes.ObjectId;
                    TransactionManager trManager = db.TransactionManager;
                    using (Transaction trans = trManager.StartTransaction())
                    {
                        DBObject obj = trans.GetObject(objId, OpenMode.ForWrite, true);
                        string scalename = "1:100";
                        ObjectContext ct = occ.GetContext(scalename);
                        if (ct == null)
                        {
                            ed.WriteMessage("\n没获取到");
                        }
#if ARX
                        ObjectContexts.AddContext(obj, ct);
#endif
                        trans.Commit();
                    }
                }

                //if (occ != null)
                //{
                //    // Create a collection to collect the IDs
                //    ObjectIdCollection oic = new ObjectIdCollection();
                //    foreach (ObjectContext oc in occ)
                //    {
                //        if (oc is AnnotationScale)
                //            oic.Add( new ObjectId(oc.UniqueIdentifier));

                //    }

                //    // Check the object references using Purge
                //    // (this does NOT purge the objects, it only
                //    // filters the objects that are not purgable)
                //    db.Purge(oic);

                //    // Now let's erase each of the objects left
                //    Transaction tr = db.TransactionManager.StartTransaction();
                //    using (tr)
                //    {
                //        // Maintain a count which we decrement for
                //        // each error we receive on open/erase
                //        int count = oic.Count;

                //        foreach (ObjectId id in oic)
                //        {
                //            try
                //            {
                //                DBObject obj = tr.GetObject(id, OpenMode.ForWrite);
                //                obj.Erase();
                //            }
                //            catch
                //            {
                //                count--;
                //            }
                //        }
                //        tr.Commit();

                //        // Inform the user of the results
                //        ed.WriteMessage("\n{0} annotation scale{1} removed.", count, count == 1 ? "" : "s");

                //    }

                //}

            }

        }

        [CommandMethod("testSendCmd")]
        public void testSendCmd()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            doc.SendStringToExecute("._CIRCLE 0,0 500 ._ZOOM Extents ",true, false, false);
#if ARX
            //ed.Command("._CIRCLE 0,0 500 ._ZOOM Extents ");
#endif
            Application.ShowAlertDialog("Circle created!");
        }

    }


    public class BlockReferenceParam
    {
        public string BlockName { get; set; }
        public Point3d Position { get; set; }
        public double Rotation { get; set; }
        public double Scale { get; set; }
    }
}


namespace NETCAD
{
    public class PlugInApplication : IExtensionApplication
    {
        public void Initialize()
        {
            // Add your initialize code here.
        }

        public void Terminate()
        {
            // Add your uninitialize code here.
        }
    }
}
