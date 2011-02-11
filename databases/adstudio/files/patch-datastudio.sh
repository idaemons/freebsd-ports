--- datastudio.sh.orig	2008-08-19 21:22:43.000000000 +0200
+++ datastudio.sh	2008-10-17 11:43:18.000000000 +0200
@@ -1,7 +1,7 @@
-#!/bin/bash
+#! /bin/sh
 #SET ADS_HOME to the root installation directory for DataStudio
 
-ADS_HOME=`dirname $0`
+ADS_HOME=%%ADS_HOME%%
 
 CLASSES=$ADS_HOME/lib/activation.jar
 CLASSES=$ADS_HOME/lib/ads.jar:$CLASSES
