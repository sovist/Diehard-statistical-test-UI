How do I use GSL on Visual C++ 2010 express?
Requested and Answered by Vanna on 26-Nov-2010 13:12 (22028 reads)
DOWNLOAD AND INSTALL GSL SOFTWARE

Note: The GSL version described below (1.8) is missing some new but useful functions on eigen analysis. In case you want the latest versio (1.14)n, please see http://www.quantcode.com/modules/mydownloads/singlefile.php?cid=10&lid=594

1.Download gsl-src-zip from http://gnuwin32.sourceforge.net/downlinks/gsl-src-zip.php 
2. Unzip the file in a folder C:\downloads


INSTALL VISUAL C++ 2010 EXPRESS
If you have not installed Visual C++ 2010 express, use this link :
http://www.microsoft.com/express/Downloads/#2010-Visual-CPP 
select visual C++ 2010 express

BUILD GSL LIBRARIES FOR Visual studio
1. Launch Visual C++ Studio
2. Open project C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8\VC8\libgsl.sln
3. Continue with convert, and do a build all
4.Verify that after build is complete, new dll files are generated in subfolders in 
C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8\VC8\libgsl\Debug-DLL
and
C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8\VC8\libgslcblas\Debug-DLL


HOW DO I USE GSL LIBRARY IN MY VC++ PROJECT?
1.Launch Visual studio
2.Open your VC++ project.
3.Select menu Project -> properties
4.On the tree display in your project properties dialog box, select branch for Configuration Properties->VC++ directories
5.On the right side of the dialog, click on the field for "Executable Directories". When you choose Edit, a dialog for "Executable directories" will be launched. Click on button for new line. Paste these into the field (one at a time):
C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8\VC8\libgsl\Debug-DLL
C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8\VC8\libgslcblas\Debug-DLL
6.On the right side of the dialog, click on the field for "Include Directories". When you choose Edit, a dialog for "Include directories" will be launched. Click on button for new line. Paste this into the field:
C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8
7.On the right side of the dialog, click on the field for "Library Directories". When you choose Edit, a dialog for "Library directories" will be launched. Click on button for new line. Paste these entries into the field (one at a time):
C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8\VC8\libgsl\Debug-DLL
C:\downloads\gsl-1.8-src\src\gsl\1.8\gsl-1.8\VC8\libgslcblas\Debug-DLL
8.In the property pages dialog, select tree item "configuration properties->Linker->Input
9.On the right hand side details, choose the field "Additional Dependencies" and append the following entries by clicking the ... button:
libgsl_dll_d.lib
libgslcblas_dll_d.lib
10.In the property pages dialog, select tree item "configuration properties->C++->Preprocessor
11. Click on edit field for preprocessor definitions. Clikc on dropdown button. Choose edit. In the "Preprocessor definitions" dialog, insert the following entry :
GSL_DLL
12. You want want to copy libgslcblas_d.dll and libgsl_d.dll to the current folder of your new project executable, or else visual studio will throw an error that the dll is not found


TO REDUCE DEPENDENCIES DURING DEPLOYMENT
--------------------------------------------------------
Follow these steps if you get errors during deployment of steps, as they reduce dependencies on other dlls
1. Right click libgsl project
2.Choose properties->Cofiguration Properties->C/C++->Code generation
3. Select Runtime library setting. Change it to use "Multi-threaded Debug (/MTd)" instead of the earlier "Multi-threaded Debug DLL (/MDd)"

4.Repeat the steps for project libgslcblas
5.Do a rebuild all, and use the new dlls shich are statically built
