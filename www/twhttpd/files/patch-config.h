--- config.h.orig	Sat Aug 31 05:40:23 2002
+++ config.h	Wed Sep 25 12:01:58 2002
@@ -31,7 +31,7 @@
 #define CURRENT_DIR           "./"
 #define DEFAULT_CACHE_DIR     ".cache"
 #define DEFAULT_COOKIE_DIR    ".cookie"
-#define DEFAULT_CONFIG_FILE   "/etc/twhttpd.cfg"
+#define DEFAULT_CONFIG_FILE   "%%PREFIX%%/etc/twhttpd.cfg"
 
 #define SOCKET_TIMEOUT    45      /* socket timeout value */
 #define CONNECT_TIMEOUT   15      /* connect timeout value */
