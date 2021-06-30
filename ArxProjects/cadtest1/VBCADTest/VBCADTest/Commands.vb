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

<Assembly: CommandClass(GetType(VBCADTest.Commands))>

Namespace VBCADTest
    Public Class Commands
        <CommandMethod("TestVBGroup", "HelloVB", CommandFlags.Modal)>
        Public Sub HelloVB()
            Dim db As Database = HostApplicationServices.WorkingDatabase
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            ed.WriteMessage(vbLf + "Hello World!")
        End Sub
    End Class

End Namespace
