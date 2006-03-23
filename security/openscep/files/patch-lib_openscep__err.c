--- lib/openscep_err.c.orig	Thu May 19 16:26:46 2005
+++ lib/openscep_err.c	Thu May 19 16:26:46 2005
@@ -0,0 +1,136 @@
+/* openscep_err.c */
+/* ====================================================================
+ * Copyright (c) 1999-2003 The OpenSSL Project.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ *
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer. 
+ *
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in
+ *    the documentation and/or other materials provided with the
+ *    distribution.
+ *
+ * 3. All advertising materials mentioning features or use of this
+ *    software must display the following acknowledgment:
+ *    "This product includes software developed by the OpenSSL Project
+ *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"
+ *
+ * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
+ *    endorse or promote products derived from this software without
+ *    prior written permission. For written permission, please contact
+ *    openssl-core@OpenSSL.org.
+ *
+ * 5. Products derived from this software may not be called "OpenSSL"
+ *    nor may "OpenSSL" appear in their names without prior written
+ *    permission of the OpenSSL Project.
+ *
+ * 6. Redistributions of any form whatsoever must retain the following
+ *    acknowledgment:
+ *    "This product includes software developed by the OpenSSL Project
+ *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
+ * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
+ * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
+ * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
+ * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
+ * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
+ * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
+ * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
+ * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
+ * OF THE POSSIBILITY OF SUCH DAMAGE.
+ * ====================================================================
+ *
+ * This product includes cryptographic software written by Eric Young
+ * (eay@cryptsoft.com).  This product includes software written by Tim
+ * Hudson (tjh@cryptsoft.com).
+ *
+ */
+
+/* NOTE: this file was auto generated by the mkerr.pl script: any changes
+ * made to it will be overwritten when the script next updates this file,
+ * only reason strings will be preserved.
+ */
+
+#include <stdio.h>
+#include <openssl/err.h>
+#include "openscep_err.h"
+
+/* BEGIN ERROR CODES */
+#ifndef OPENSSL_NO_ERR
+static ERR_STRING_DATA OPENSCEP_str_functs[]=
+	{
+{ERR_PACK(0,OPENSCEP_F_D2I_ISSUER_AND_SUBJECT,0),	"D2I_ISSUER_AND_SUBJECT"},
+{ERR_PACK(0,OPENSCEP_F_D2I_PAYLOAD,0),	"D2I_PAYLOAD"},
+{ERR_PACK(0,OPENSCEP_F_ISSUER_AND_SUBJECT_NEW,0),	"ISSUER_AND_SUBJECT_NEW"},
+{ERR_PACK(0,OPENSCEP_F_PAYLOAD_NEW,0),	"PAYLOAD_NEW"},
+{0,NULL}
+	};
+
+static ERR_STRING_DATA OPENSCEP_str_reasons[]=
+	{
+{0,NULL}
+	};
+
+#endif
+
+#ifdef OPENSCEP_LIB_NAME
+static ERR_STRING_DATA OPENSCEP_lib_name[]=
+        {
+{0	,OPENSCEP_LIB_NAME},
+{0,NULL}
+	};
+#endif
+
+
+static int OPENSCEP_lib_error_code=0;
+static int OPENSCEP_error_init=1;
+
+void ERR_load_OPENSCEP_strings(void)
+	{
+	if (OPENSCEP_lib_error_code == 0)
+		OPENSCEP_lib_error_code=ERR_get_next_error_library();
+
+	if (OPENSCEP_error_init)
+		{
+		OPENSCEP_error_init=0;
+#ifndef OPENSSL_NO_ERR
+		ERR_load_strings(OPENSCEP_lib_error_code,OPENSCEP_str_functs);
+		ERR_load_strings(OPENSCEP_lib_error_code,OPENSCEP_str_reasons);
+#endif
+
+#ifdef OPENSCEP_LIB_NAME
+		OPENSCEP_lib_name->error = ERR_PACK(OPENSCEP_lib_error_code,0,0);
+		ERR_load_strings(0,OPENSCEP_lib_name);
+#endif
+		}
+	}
+
+void ERR_unload_OPENSCEP_strings(void)
+	{
+	if (OPENSCEP_error_init == 0)
+		{
+#ifndef OPENSSL_NO_ERR
+		ERR_unload_strings(OPENSCEP_lib_error_code,OPENSCEP_str_functs);
+		ERR_unload_strings(OPENSCEP_lib_error_code,OPENSCEP_str_reasons);
+#endif
+
+#ifdef OPENSCEP_LIB_NAME
+		ERR_unload_strings(0,OPENSCEP_lib_name);
+#endif
+		OPENSCEP_error_init=1;
+		}
+	}
+
+void ERR_OPENSCEP_error(int function, int reason, char *file, int line)
+	{
+	if (OPENSCEP_lib_error_code == 0)
+		OPENSCEP_lib_error_code=ERR_get_next_error_library();
+	ERR_PUT_error(OPENSCEP_lib_error_code,function,reason,file,line);
+	}
