Imports System
Imports Autodesk.AutoCAD.GraphicsInterface

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

<Assembly: CommandClass(GetType(OverruleTest.Commands))>

Namespace OverruleTest

    Public Class MyHighlightStateOverrule
        Inherits HighlightStateOverrule
#If ARX Then
        Public Overrides Sub PushHighlight(entity As Entity, subId As FullSubentityPath, highlightStyle As HighlightStyle)
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            ed.WriteMessage(vbLf + "{0} PushHighlight...", entity.GetType().Name)
            MyBase.PushHighlight(entity, subId, highlightStyle)
        End Sub

        Public Overrides Sub PopHighlight(entity As Entity, subId As FullSubentityPath)
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            ed.WriteMessage(vbLf + "{0} PopHighlight...", entity.GetType().Name)
            MyBase.PopHighlight(entity, subId)
        End Sub

        Public Overrides Function HighlightState(entity As Entity, subId As FullSubentityPath) As HighlightStyle
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            ed.WriteMessage(vbLf + "{0} HighlightState...", entity.GetType().Name)
            Return MyBase.HighlightState(entity, subId)
        End Function
#End If
        Public Overrides Function IsApplicable(overruledSubject As RXObject) As Boolean
            Return overruledSubject.GetType() = GetType(Line) Or overruledSubject.GetType() = GetType(Circle)
        End Function
    End Class

    Public Class MyHighlightOverrule
        Inherits HighlightOverrule

        Public Overrides Sub Highlight(entity As Entity, subId As FullSubentityPath, highlightAll As Boolean)
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            If IsApplicable(entity) Then
                If entity.GetType() = GetType(Line) Then
                    ed.WriteMessage(vbLf + "AcDbLine highlight invalid...")
                    Return
                ElseIf entity.GetType() = GetType(Circle) Then
                    ed.WriteMessage(vbLf + "AcDbCircle highlight...")
                End If
            End If

            MyBase.Highlight(entity, subId, highlightAll)
        End Sub

        Public Overrides Sub Unhighlight(entity As Entity, subId As FullSubentityPath, highlightAll As Boolean)
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            If IsApplicable(entity) Then
                If entity.GetType() = GetType(Line) Then
                    ed.WriteMessage(vbLf + "AcDbLine UnHighlight...")
                ElseIf entity.GetType() = GetType(Circle) Then
                    ed.WriteMessage(vbLf + "AcDbCircle UnHighlight invalid...")
                    'Return  ' bug.crash
                End If
            End If

            MyBase.Unhighlight(entity, subId, highlightAll)
        End Sub

        Public Overrides Function IsApplicable(overruledSubject As RXObject) As Boolean
            Return overruledSubject.GetType() = GetType(Line) Or overruledSubject.GetType() = GetType(Circle)
        End Function
    End Class

    Public Class MyVisibilityOverrule
        Inherits VisibilityOverrule

        Public Overrides Function Visibility(entity As Entity) As Visibility
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            ed.WriteMessage(vbLf + "MyVisibilityOverrule::visibility()<pSubject: {0}>...", entity.GetType().Name)

            Return MyBase.Visibility(entity)
        End Function

        Public Overrides Sub SetVisibility(entity As Entity, newVal As Visibility, doSubents As Boolean)
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            ed.WriteMessage("\nMyVisibilityOverrule::SetVisibility()<pSubject: {0}>...", entity.GetType().Name)
            If (entity.GetType() = GetType(Circle)) Then
#If ARX Then
                MyBase.SetVisibility(entity, Autodesk.AutoCAD.DatabaseServices.Visibility.Invisible, doSubents)
#Else
                MyBase.SetVisibility(entity, ZwSoft.ZwCAD.DatabaseServices.Visibility.Invisible, doSubents)
#End If
                Return
            End If

            MyBase.SetVisibility(entity, newVal, doSubents)
        End Sub

        Public Overrides Function IsApplicable(overruledSubject As RXObject) As Boolean
            'Return MyBase.IsApplicable(overruledSubject)
            Return True
        End Function
    End Class

    Public Class Commands

        Shared g_highlightOverrule As MyHighlightOverrule
        <CommandMethod("TestVBGroup", "HighlightOverruleTest", CommandFlags.Modal)>
        Public Sub HighlightOverruleTest()
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            If g_highlightOverrule Is Nothing Then
                g_highlightOverrule = New MyHighlightOverrule()

                Overrule.AddOverrule(RXObject.GetClass(GetType(Line)), g_highlightOverrule, False)
                Overrule.AddOverrule(RXObject.GetClass(GetType(Circle)), g_highlightOverrule, False)
                Overrule.Overruling = True

                ed.WriteMessage(vbLf + "HighlightOverrule is ON...")
            Else
                Overrule.RemoveOverrule(RXObject.GetClass(GetType(Line)), g_highlightOverrule)
                Overrule.RemoveOverrule(RXObject.GetClass(GetType(Circle)), g_highlightOverrule)
                Overrule.Overruling = False
                g_highlightOverrule = Nothing

                ed.WriteMessage(vbLf + "HighlightOverrule is OFF...")
            End If
        End Sub

        Shared g_highlightStateOverrule As MyHighlightStateOverrule
        <CommandMethod("TestVBGroup", "HighlightStateOverruleTest", CommandFlags.Modal)>
        Public Sub HighlightStateOverruleTest()
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            If g_highlightStateOverrule Is Nothing Then
                g_highlightStateOverrule = New MyHighlightStateOverrule()

                Overrule.AddOverrule(RXObject.GetClass(GetType(Line)), g_highlightStateOverrule, False)
                Overrule.AddOverrule(RXObject.GetClass(GetType(Circle)), g_highlightStateOverrule, False)
                Overrule.Overruling = True

                ed.WriteMessage(vbLf + "HighlightStateOverrule is ON...")
            Else
                Overrule.RemoveOverrule(RXObject.GetClass(GetType(Line)), g_highlightStateOverrule)
                Overrule.RemoveOverrule(RXObject.GetClass(GetType(Circle)), g_highlightStateOverrule)
                Overrule.Overruling = False
                g_highlightStateOverrule = Nothing

                ed.WriteMessage(vbLf + "HighlightStateOverrule is OFF...")
            End If
        End Sub

        Shared g_visibilityOverrule As MyVisibilityOverrule
        <CommandMethod("TestVBGroup", "VisibilityOverruleTest", CommandFlags.Modal)>
        Public Sub VisibilityOverruleTest()
            Dim doc As Document = Application.DocumentManager.MdiActiveDocument
            Dim ed As Editor = doc.Editor

            If g_visibilityOverrule Is Nothing Then
                g_visibilityOverrule = New MyVisibilityOverrule()

                Overrule.AddOverrule(RXObject.GetClass(GetType(Line)), g_visibilityOverrule, False)
                Overrule.AddOverrule(RXObject.GetClass(GetType(Circle)), g_visibilityOverrule, False)
                Overrule.Overruling = True

                ed.WriteMessage(vbLf + "VisibilityOverrule is ON...")
            Else
                Overrule.RemoveOverrule(RXObject.GetClass(GetType(Line)), g_visibilityOverrule)
                Overrule.RemoveOverrule(RXObject.GetClass(GetType(Circle)), g_visibilityOverrule)
                Overrule.Overruling = False
                g_visibilityOverrule = Nothing

                ed.WriteMessage(vbLf + "VisibilityOverrule is OFF...")
            End If
        End Sub

    End Class

End Namespace
