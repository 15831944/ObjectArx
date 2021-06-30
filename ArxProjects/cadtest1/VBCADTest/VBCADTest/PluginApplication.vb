Imports System
#If ZRX Then
Imports ZwSoft.ZwCAD.Runtime
Imports ZwSoft.ZwCAD.ApplicationServices
Imports ZwSoft.ZwCAD.DatabaseServices
Imports ZwSoft.ZwCAD.Geometry
Imports ZwSoft.ZwCAD.EditorInput
#Else
Imports Autodesk.AutoCAD.Runtime
Imports Autodesk.AutoCAD.ApplicationServices
Imports Autodesk.AutoCAD.DatabaseServices
Imports Autodesk.AutoCAD.Geometry
Imports Autodesk.AutoCAD.EditorInput
#End If


<Assembly: ExtensionApplication(GetType(VBCADTest.PluginApplication))>

Namespace VBCADTest
    Public Class PluginApplication
        Implements IExtensionApplication

        Public Sub Initialize() Implements IExtensionApplication.Initialize
            'Add your initialize code here.

        End Sub

        Public Sub Terminate() Implements IExtensionApplication.Terminate
            'Add your uninitialize code here.

        End Sub

    End Class

End Namespace
