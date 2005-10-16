--- srclib/apr-util/xml/expat/buildconf.sh	Tue Jun 17 20:51:47 2003
+++ srclib/apr-util/xml/expat/buildconf.sh	Tue Mar  9 07:52:57 2004
@@ -3,13 +3,13 @@
 #
 # Build aclocal.m4 from libtool's libtool.m4
 #
-libtoolize=`conftools/PrintPath glibtoolize libtoolize`
+libtoolize=${LIBTOOLIZE}
 if [ "x$libtoolize" = "x" ]; then
     echo "libtoolize not found in path"
     exit 1
 fi
 ltpath=`dirname $libtoolize`
-ltfile=${LIBTOOL_M4-`cd $ltpath/../share/aclocal ; pwd`/libtool.m4}
+ltfile=${LIBTOOL_M4-`cd $ltpath/../../share/aclocal ; pwd`/libtool${LIBTOOL_VERSION}.m4}
 echo "Incorporating $ltfile into aclocal.m4 ..."
 echo "dnl THIS FILE IS AUTOMATICALLY GENERATED BY buildconf.sh" > aclocal.m4
 echo "dnl edits here will be lost" >> aclocal.m4
