 (C) Copyright 2004 by Autodesk, Inc.

		VBNetArx - .NET API Sample

This sample demonstrates some extra basics of using the .NET API with AutoCAD.  It defines three commands:

COMINTEROP - Demonstrates the basics of accessing objects exposed in the ActiveX COM object model.  In this case it is the AcadApplication, AcadDocuments and AcadDocument objects.  The function then goes on to modify the description of each layer listed in the layer table.

HYPER - Demonstrates how to add a HyperLink object to a Line added to Model Space.

XRECORD - Demonstrates how to create an XRecord, and populate it using the .NET equivalent of resbufs, called 'ResultBuffer'.

To run the sample.  Build the application, and load it into AutoCAD using the NETLOAD command.  You will find the VBNetArx.dll module in the \bin subfolder.

