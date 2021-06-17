﻿using System;
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

[assembly: CommandClass(typeof(NetOverruleTest.Commands))]
[assembly: CommandClass(typeof(NetOverruleTest.MyDrawOverrule))]
[assembly: CommandClass(typeof(NetOverruleTest.GripVectorOverrule))]

namespace NetOverruleTest
{
    class Commands
    {
        [CommandMethod("HelloCS")]
        static public void HelloCS()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            ed.WriteMessage("\nHello World!");
        }
    }

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

        [CommandMethod("TOG")]
        public static void ToggleOverrule()
        {
            // Initialize Overrule if first time run
            if (_drawOverrule == null)
            {
                // Toggle Overruling on
                _drawOverrule = new MyDrawOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), _drawOverrule, false);
                Overrule.Overruling = true;
            }
            else
            {
                // Toggle Overruling off
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), _drawOverrule);
                _drawOverrule.Dispose();
                _drawOverrule = null;
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