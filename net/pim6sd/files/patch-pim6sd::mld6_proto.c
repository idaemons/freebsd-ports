--- pim6sd/mld6_proto.c	Tue Nov 19 03:15:12 2002
+++ pim6sd/mld6_proto.c	Wed Oct 30 09:53:17 2002
@@ -120,7 +120,7 @@
 
 #include "mld6_proto.h"
 
-extern struct in6_addr in6addr_any;
+//extern struct in6_addr in6addr_any;
 
 
 /*
@@ -316,12 +316,14 @@
 		    inet6_fmt(group), v->uv_name);
 		return;
 	}
+#ifdef MLDV2_LISTENER_REPORT
 	if (v->uv_mld_version & MLDv2) {
 		log(LOG_DEBUG, 0,
 		    "shift to MLDv1 compat-mode for %s on Mif %s",
 		    inet6_fmt(group), v->uv_name);
 		mld_shift_to_v1mode(mifi, src, &group_sa);
 	}
+#endif
 
 	IF_DEBUG(DEBUG_MLD)
 		log(LOG_DEBUG, 0,
@@ -519,6 +517,7 @@
 				  v->uv_ifindex,
 				  MLD6_LAST_LISTENER_QUERY_INTERVAL, 0, 1);
 			break;
+#ifdef MLDV2_LISTENER_REPORT
 		case MLDv2:
 		default:
 			send_mld6v2(MLD_LISTENER_QUERY, 0,
@@ -529,6 +526,7 @@
 				    MLD6_QUERY_RESPONSE_INTERVAL,
 				    0, TRUE, SFLAGNO, v->uv_mld_robustness,
 				    v->uv_mld_query_interval);
+#endif
 			break;
 		}
 		v->uv_out_mld_query++;
