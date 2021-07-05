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

<Assembly: CommandClass(GetType(VBCADTest.Tools))>

Namespace VBCADTest
    Public Class Tools
        '获取实体的包围盒
        <CommandMethod("TestVBGroup", "getGeoExtentsOfThisEntity", CommandFlags.Modal)>
        Public Sub getGeoExtentsOfThisEntity()
            Dim db As Database = HostApplicationServices.WorkingDatabase
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            Dim entOpts As PromptEntityOptions = New PromptEntityOptions("选择对象: ")
            Dim entRes As PromptEntityResult = ed.GetEntity(entOpts)

            If entRes.Status = PromptStatus.OK Then
                Dim objId As ObjectId = entRes.ObjectId

                Using trans As Transaction = db.TransactionManager.StartTransaction()
                    Dim entity As Entity = trans.GetObject(objId, OpenMode.ForRead, True)

                    Dim ext As Extents3d = entity.GeometricExtents
                    ed.WriteMessage(vbLf + "ext.minPoint({0}, {1}, {2}) ext.maxPoint({3}, {4}, {5})",
                       ext.MinPoint.X, ext.MinPoint.Y, ext.MinPoint.Z, ext.MaxPoint.X, ext.MaxPoint.Y, ext.MaxPoint.Z)

                    trans.Commit()
                End Using
            End If
        End Sub

        '获取两个实体的交点
        <CommandMethod("TestVBGroup", "getIntersectionOfTwoEntities", CommandFlags.Modal)>
        Public Sub getIntersectionOfTwoEntities()
            Dim db As Database = HostApplicationServices.WorkingDatabase
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            Dim entOpts1 As PromptEntityOptions = New PromptEntityOptions("Select Entity 1:")
            Dim entRes1 As PromptEntityResult = ed.GetEntity(entOpts1)

            Dim entOpts2 As PromptEntityOptions = New PromptEntityOptions("Select Entity 2:")
            Dim entRes2 As PromptEntityResult = ed.GetEntity(entOpts2)

            If entRes1.Status = PromptStatus.OK And entRes2.Status = PromptStatus.OK Then
                Dim objId1 As ObjectId = entRes1.ObjectId
                Dim objId2 As ObjectId = entRes2.ObjectId

                Using trans As Transaction = db.TransactionManager.StartTransaction()
                    Dim entity1 As Entity = trans.GetObject(objId1, OpenMode.ForRead, True)
                    Dim entity2 As Entity = trans.GetObject(objId2, OpenMode.ForRead, True)

                    Dim points As Point3dCollection = New Point3dCollection()
                    entity1.IntersectWith(entity2, Intersect.OnBothOperands, points, IntPtr.Zero, IntPtr.Zero)

                    ed.WriteMessage(vbLf + "points length: {0}", points.Count)

                    For i As Integer = 0 To points.Count - 1
                        ed.WriteMessage(vbLf + "ptInsec[{0}]: ({1}, {2}, {3})", i, points(i).X, points(i).Y, points(i).Z)
                    Next

                    trans.Commit()
                End Using
            End If
        End Sub
    End Class
End Namespace
