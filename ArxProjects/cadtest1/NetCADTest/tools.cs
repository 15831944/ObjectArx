using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

[assembly: CommandClass(typeof(NetCADTest.Tools))]

namespace NetCADTest
{
    public class Tools
    {
        // 获取实体的包围盒
        [CommandMethod("getGeoExtentsOfThisEntity")]
        public void getGeoExtentsOfThisEntity()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            PromptEntityOptions entOpts = new PromptEntityOptions("选择对象: ");
            PromptEntityResult entRes = entRes = ed.GetEntity(entOpts);

            if (entRes.Status == PromptStatus.OK)
            {
                ObjectId objId = entRes.ObjectId;

                using (Transaction trans = db.TransactionManager.StartTransaction())
                {
                    Entity entity = (Entity)trans.GetObject(objId, OpenMode.ForRead, true);

                    Extents3d ext = entity.GeometricExtents;
                    ed.WriteMessage("\next.minPoint({0}, {1}, {2}) ext.maxPoint({3}, {4}, {5})",
                       ext.MinPoint.X, ext.MinPoint.Y, ext.MinPoint.Z, ext.MaxPoint.X, ext.MaxPoint.Y, ext.MaxPoint.Z);

                    trans.Commit();
                }
            }
        }

        // 获取两个实体的交点
        [CommandMethod("getIntersectionOfTwoEntities")]
        public void getIntersectionOfTwoEntities()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            PromptEntityOptions entOpts1 = new PromptEntityOptions("Select Entity 1:");
            PromptEntityResult entRes1  = ed.GetEntity(entOpts1);

            PromptEntityOptions entOpts2 = new PromptEntityOptions("Select Entity 2:");
            PromptEntityResult entRes2 = ed.GetEntity(entOpts2);

            if (entRes1.Status == PromptStatus.OK && entRes2.Status == PromptStatus.OK)
            {
                ObjectId objId1 = entRes1.ObjectId;
                ObjectId objId2 = entRes2.ObjectId;

                using (Transaction trans = db.TransactionManager.StartTransaction())
                {
                    Entity entity1 = (Entity)trans.GetObject(objId1, OpenMode.ForRead, true);
                    Entity entity2 = (Entity)trans.GetObject(objId2, OpenMode.ForRead, true);

                    Point3dCollection points = new Point3dCollection();
                    entity1.IntersectWith(entity2, Intersect.OnBothOperands, points, IntPtr.Zero, IntPtr.Zero);

                    ed.WriteMessage("\npoints length: {0}", points.Count);
                    for (int i = 0; i < points.Count; i++)
                    {
                        ed.WriteMessage("\nptInsec[{0}]: ({1}, {2}, {3})", i, points[i].X, points[i].Y, points[i].Z);
                    }

                    trans.Commit();
                }
            }
        }
    }
}
