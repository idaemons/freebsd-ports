--- lib/direct/log.c
+++ lib/direct/log.c
@@ -335,10 +335,12 @@ parse_host_addr( const char       *hostport,
                     D_ERROR( "Direct/Log: Port %s is unreachable!\n", portstr );
                     return DR_FAILURE;
                
+/*
                case EAI_ADDRFAMILY:
                case EAI_NODATA:
                     D_ERROR( "Direct/Log: Host found, but has no address!\n" );
                     return DR_FAILURE;
+*/
                     
                case EAI_MEMORY:
                     return D_OOM();
