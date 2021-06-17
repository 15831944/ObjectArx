using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

#if ZRX
using ZwSoft.ZwCAD.EditorInput;
using ZwSoft.ZwCAD.ApplicationServices;
using Application = ZwSoft.ZwCAD.ApplicationServices.Application;
using ZwSoft.ZwCAD.Runtime;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.Windows;
#else
using Autodesk.AutoCAD.EditorInput;
using Autodesk.AutoCAD.ApplicationServices;
using Application = Autodesk.AutoCAD.ApplicationServices.Application;
using Autodesk.AutoCAD.Runtime;
using Autodesk.AutoCAD.DatabaseServices;
using Autodesk.AutoCAD.Geometry;
using Autodesk.AutoCAD.Windows;
#endif

namespace NETCAD
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public ObjectId AppendEntity(Entity ent)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blkTbl = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                BlockTableRecord blkTblRec = (BlockTableRecord)trans.GetObject(db.CurrentSpaceId, OpenMode.ForWrite);
                ObjectId objId = blkTblRec.AppendEntity(ent);
                trans.AddNewlyCreatedDBObject(ent, true);
                trans.Commit();
                return objId;
            }
        }
        public ObjectId AddText(Point3d position, string textString, double height, double oblique1)
        {
            DBText dbtext = new DBText();
            dbtext.Position = position;
            dbtext.TextString = textString;
            dbtext.Height = height;
            ObjectId objId = AppendEntity((Entity)dbtext);
            Database db = HostApplicationServices.WorkingDatabase;
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                dbtext = (DBText)trans.GetObject(objId, OpenMode.ForWrite);
                dbtext.Rotation = oblique1;
                trans.Commit();
            }
            return objId;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            using (DocumentLock doclock = Application.DocumentManager.MdiActiveDocument.LockDocument())
            {
                //SetFocus(Application.DocumentManager.MdiActiveDocument.Window.Handle);
                ObjectId objId = AddText(new Point3d(0, 0, 0), "111", 200, 0);
                Application.UpdateScreen();
                //命令结束后无刷新屏幕的时机导致鼠标需要在绘图区移动，实体才显示，需要手动刷新
                //ZwSoft::ZwCAD::ApplicationServices::Application::UpdateScreen
                //ZwSoft::ZwCAD::EditorInput::Editor::UpdateScreen
            }
        }
    }
}
