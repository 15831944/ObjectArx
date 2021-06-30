using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
#if ZRX
using ZwSoft.ZwCAD.Runtime;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.EditorInput;
using ZwSoft.ZwCAD.GraphicsInterface;
#else
using Autodesk.AutoCAD.ApplicationServices;
using Autodesk.AutoCAD.DatabaseServices;
using Autodesk.AutoCAD.EditorInput;
using Autodesk.AutoCAD.Geometry;
using Autodesk.AutoCAD.GraphicsInterface;
using Autodesk.AutoCAD.Runtime;
#endif

[assembly: CommandClass(typeof(NetOverruleTest.MyDrawOverrule))]
[assembly: CommandClass(typeof(NetOverruleTest.GripVectorOverrule))]
[assembly: CommandClass(typeof(NetOverruleTest.MyHighlightOverrule))]
[assembly: CommandClass(typeof(NetOverruleTest.MyHighlightStateOverrule))]

namespace NetOverruleTest
{
    #region MyHighlightOverrule
    public class MyHighlightOverrule : HighlightOverrule
    {
        public override void Highlight(Entity entity, FullSubentityPath subId, bool highlightAll)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            if (IsApplicable(entity))
            {
                if (entity.GetType() == typeof(Line))
                {
                    ed.WriteMessage("\nAcDbLine highlight invalid...");
                    return;
                }
                else if (entity.GetType() == typeof(Circle))
                {
                    ed.WriteMessage("\nAcDbCircle highlight...");
                }
            }

            base.Highlight(entity, subId, highlightAll);
        }

        public override void Unhighlight(Entity entity, FullSubentityPath subId, bool highlightAll)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            if (IsApplicable(entity))
            {
                if (entity.GetType() == typeof(Line))
                {
                    ed.WriteMessage("\nAcDbLine UnHighlight...");
                }
                else if (entity.GetType() == typeof(Circle))
                {
                    ed.WriteMessage("\nAcDbCircle UnHighlight invalid...");
                    return;
                }
            }

            base.Unhighlight(entity, subId, highlightAll);
        }

        public override bool IsApplicable(RXObject overruledSubject)
        {
            return overruledSubject.GetType() == typeof(Line) || overruledSubject.GetType() == typeof(Circle);
        }

        static MyHighlightOverrule g_highlightOverrule = null;
        [CommandMethod("HighlightOverruleTest")]
        static public void HighlightOverruleTest()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            if (g_highlightOverrule == null)
            {
                g_highlightOverrule = new MyHighlightOverrule();

                Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), g_highlightOverrule, false);
                Overrule.AddOverrule(RXObject.GetClass(typeof(Circle)), g_highlightOverrule, false);
                Overrule.Overruling = true;

                ed.WriteMessage("\nHighlightOverrule is ON...");
            }
            else
            {
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), g_highlightOverrule);
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Circle)), g_highlightOverrule);
                Overrule.Overruling = false;
                g_highlightOverrule = null;

                ed.WriteMessage("\nHighlightOverrule is OFF...");
            }

        }
    }
    #endregion

#region MyHighlightStateOverrule
#if true
    public class MyHighlightStateOverrule : HighlightStateOverrule
    {
        private static MyHighlightStateOverrule g_HighlightStateOverrule;
#if ARX
        public override void PushHighlight(Entity entity, FullSubentityPath subId, HighlightStyle highlightStyle)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            ed.WriteMessage("\n{0} PushHighlight...", entity.GetType().Name);

            base.PushHighlight(entity, subId, highlightStyle);
        }

        public override void PopHighlight(Entity entity, FullSubentityPath subId)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            ed.WriteMessage("\n{0} PopHighlight...", entity.GetType().Name);

            base.PopHighlight(entity, subId);
        }

        public override HighlightStyle HighlightState(Entity entity, FullSubentityPath subId)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            ed.WriteMessage("\n{0} HighlightState...", entity.GetType().Name);

            return base.HighlightState(entity, subId);
        }
#else
        //public override void PushHighlight(Entity entity, ValueType subId, HighlightStyle highlightStyle)
        //{
        //    Document doc = Application.DocumentManager.MdiActiveDocument;
        //    Editor ed = doc.Editor;

        //    ed.WriteMessage("\n{0} PushHighlight...", entity.GetType().Name);

        //    base.PushHighlight(entity, subId, highlightStyle);
        //}

        public override void PopHighlight(Entity entity, ValueType subId)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            ed.WriteMessage("\n{0} PopHighlight...", entity.GetType().Name);

            base.PopHighlight(entity, subId);
        }

        //public override HighlightStyle HighlightState(Entity entity, ValueType subId)
        //{
        //    Document doc = Application.DocumentManager.MdiActiveDocument;
        //    Editor ed = doc.Editor;

        //    ed.WriteMessage("\n{0} HighlightState...", entity.GetType().Name);

        //    return base.HighlightState(entity, subId);
        //}
#endif
        public override bool IsApplicable(RXObject overruledSubject)
        {
            //return base.IsApplicable(overruledSubject);
            return overruledSubject.GetType() == typeof(Line) || overruledSubject.GetType() == typeof(Circle);
        }

        [CommandMethod("ToggleHighlightStateOverrule")]
        public static void ToggleHighlightStateOverrule()            
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            // Initialize Overrule if first time run
            if (g_HighlightStateOverrule == null)
            {
                // Toggle Overruling on
                g_HighlightStateOverrule = new MyHighlightStateOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), g_HighlightStateOverrule, false);
                Overrule.AddOverrule(RXObject.GetClass(typeof(Circle)), g_HighlightStateOverrule, false);
                Overrule.Overruling = true;

                ed.WriteMessage("\nMyHighlightStateOverrule is on...\n");
            }
            else
            {
                // Toggle Overruling off
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), g_HighlightStateOverrule);
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Circle)), g_HighlightStateOverrule);
                g_HighlightStateOverrule.Dispose();
                g_HighlightStateOverrule = null;

                ed.WriteMessage("\nMyHighlightStateOverrule is off...\n");
            }
        }
    }
#endif
#endregion

    // This is our custom DrawableOverrule class. In this case we're just overruling WorldDraw
    public class MyDrawOverrule : DrawableOverrule
    {
        //Shared member variable to store our Overrule instance
        private static MyDrawOverrule _drawOverrule;

        public override bool WorldDraw(Drawable drawable, WorldDraw wd)
        {
            // Cast Drawable to Line so we can access its methods and properties
            Line ln = (Line)drawable;

            // Draw some graphics primitives
            wd.Geometry.Circle(ln.StartPoint + 0.5 * ln.Delta, ln.Length / 5, ln.Normal);

            // In this case we don't want the line to draw itself, nor do we want ViewportDraw called
            return true;
        }

        [CommandMethod("ToggleDrawableOverrule")]
        public static void ToggleDrawableOverrule()              // 切换overrule
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            // Initialize Overrule if first time run
            if (_drawOverrule == null)
            {
                // Toggle Overruling on
                _drawOverrule = new MyDrawOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), _drawOverrule, false);
                Overrule.Overruling = true;

                ed.WriteMessage("\nMyDrawOverrule is on...\n");
            }
            else
            {
                // Toggle Overruling off
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), _drawOverrule);
                _drawOverrule.Dispose();
                _drawOverrule = null;

                ed.WriteMessage("\nMyDrawOverrule is off...\n");
            }

            // Regen is required to update changes on screen
            Application.DocumentManager.MdiActiveDocument.Editor.Regen();
        }

    }

    public class GripVectorOverrule : GripOverrule
    {
        // A static pointer to our overrule instance
        static public GripVectorOverrule theOverrule = new GripVectorOverrule();
        // A flag to indicate whether we're overruling
        static bool overruling = false;
        // A single set of grips would not have worked in
        // the case where multiple objects were selected.
        static Dictionary<string, Point3dCollection> _gripDict = new Dictionary<string, Point3dCollection>();

        public GripVectorOverrule()
        {

        }
        private string GetKey(Entity e)
        {
            // Generate a key based on the name of the object's type
            // and its geometric extents
            // (We cannot use the ObjectId, as this is null during
            // grip-stretch operations.)
            return e.GetType().Name + ":" + e.GeometricExtents.ToString();
        }

        // Save the locations of the grips for a particular entity
        private void StoreGripInfo(Entity e, Point3dCollection grips)
        {
            string key = GetKey(e);
            if (_gripDict.ContainsKey(key))
            {
                // Clear the grips if any already associated
                Point3dCollection grps = _gripDict[key];
                using (grps)
                {
                    grps.Clear();
                }
                _gripDict.Remove(key);
            }
            // Now we add our grips
            Point3d[] pts = new Point3d[grips.Count];
            grips.CopyTo(pts, 0);
            Point3dCollection gps = new Point3dCollection(pts);
            _gripDict.Add(key, gps);
        }

        // Get the locations of the grips for an entity
        private Point3dCollection RetrieveGripInfo(Entity e)
        {
            Point3dCollection grips = null;
            string key = GetKey(e);
            if (_gripDict.ContainsKey(key))
            {
                grips = _gripDict[key];
            }
            return grips;
        }

        public override void GetGripPoints(Entity e, Point3dCollection grips, IntegerCollection snaps, IntegerCollection geomIds)
        {

            base.GetGripPoints(e, grips, snaps, geomIds);
            StoreGripInfo(e, grips);
        }

        public override void MoveGripPointsAt(Entity e, IntegerCollection indices, Vector3d offset)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;
            Point3dCollection grips = RetrieveGripInfo(e);

            if (grips != null)
            {
                // Could get multiple points moved at once,
                // hence the integer collection
                foreach (int i in indices)
                {
                    // Get the grip point from our internal state
                    Point3d pt = grips[i];
                    // Draw a vector from the grip point to the newly
                    // offset location, using the index into the
                    // grip array as the color (excluding colours 0 and 7).
                    // These vectors don't getting cleared, which makes
                    // for a fun effect.

                    ed.DrawVector(pt, pt + offset, (i >= 6 ? i + 2 : i + 1), // exclude colours 0 and 7
                    false
                    );
                }
            }

            base.MoveGripPointsAt(e, indices, offset);
        }

        [CommandMethod("GOO")]
        public void GripOverruleOnOff()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            if (overruling)
            {
                ObjectOverrule.RemoveOverrule(RXClass.GetClass(typeof(Entity)), GripVectorOverrule.theOverrule);
            }
            else
            {
                ObjectOverrule.AddOverrule(RXClass.GetClass(typeof(Entity)), GripVectorOverrule.theOverrule, true);
            }

            overruling = !overruling;
            GripOverrule.Overruling = overruling;

            ed.WriteMessage("\nGrip overruling turned {0}.", (overruling ? "on" : "off"));
        }
    }
}
