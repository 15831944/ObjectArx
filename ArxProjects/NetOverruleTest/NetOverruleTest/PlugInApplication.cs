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
#else
using Autodesk.AutoCAD.ApplicationServices;
using Autodesk.AutoCAD.DatabaseServices;
using Autodesk.AutoCAD.EditorInput;
using Autodesk.AutoCAD.Runtime;
#endif

[assembly: ExtensionApplication(typeof(NetOverruleTest.PlugInApplication))]

namespace NetOverruleTest
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
