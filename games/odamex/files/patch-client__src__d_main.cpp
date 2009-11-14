--- ./client/src/d_main.cpp.orig	2009-03-08 00:28:16.000000000 -0500
+++ ./client/src/d_main.cpp	2009-05-16 18:23:51.000000000 -0400
@@ -807,6 +807,8 @@
 	AddSearchDir(dirs, Args.CheckValue("-waddir"), separator);
 	AddSearchDir(dirs, getenv("DOOMWADDIR"), separator);
 	AddSearchDir(dirs, getenv("DOOMWADPATH"), separator);
+    AddSearchDir(dirs, "%%DATADIR%%", separator);
+    AddSearchDir(dirs, "%%DMDIR%%", separator);
     AddSearchDir(dirs, getenv("HOME"), separator);
 
     dirs.erase(std::unique(dirs.begin(), dirs.end()), dirs.end());
