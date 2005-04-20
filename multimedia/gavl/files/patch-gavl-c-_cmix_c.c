--- gavl/c/_mix_c.c.orig	Sun Aug 29 21:14:18 2004
+++ gavl/c/_mix_c.c	Sun Aug 29 21:19:30 2004
@@ -1,3 +1,24 @@
+#include <machine/limits.h>
+
+#ifndef INT8_MAX
+#define INT8_MAX	INT_MAX
+#endif
+#ifndef INT8_MIN
+#define INT8_MIN	INT_MIN
+#endif
+#ifndef INT16_MAX
+#define INT16_MAX	SHRT_MAX
+#endif
+#ifndef INT16_MIN
+#define INT16_MIN	SHRT_MIN
+#endif
+#ifndef INT32_MAX
+#define INT32_MAX	LONG_MAX
+#endif
+#ifndef INT32_MIN
+#define INT32_MIN	LONG_MIN
+#endif
+
 
 static void RENAME(mix_1_to_1)(gavl_mix_output_channel_t * channel,
                                gavl_audio_frame_t * input_frame,
