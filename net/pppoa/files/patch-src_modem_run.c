--- src/modem_run.c.orig	2007-10-09 02:38:11.000000000 +0200
+++ src/modem_run.c	2007-10-09 02:38:24.000000000 +0200
@@ -91,7 +91,7 @@
 * Global variables
 ******************************************************************************/
 
-static int verbose = 0;
+int verbose = 0;
 FILE *flog = NULL;
 
 /*****************************************************************************
