--- src/sequencer32_1676.so.c.orig	Tue Feb 11 09:17:55 2003
+++ src/sequencer32_1676.so.c	Tue Feb 11 09:18:15 2003
@@ -132,6 +132,8 @@
 void runSequencer(LADSPA_Handle instance,
                   unsigned long sample_count)
 {
+    int i,rst;
+    unsigned long s;
     Sequencer *plugin = (Sequencer *)instance;
 
     /* Gate */
@@ -165,14 +167,11 @@
     unsigned int loop_index = f_round_i(loop_steps);
     loop_index = loop_index == 0 ?  1 : loop_index;
     loop_index = loop_index > 32 ? 32 : loop_index;
-    int rst = f_round_i(reset);
-    int i;
+    rst = f_round_i(reset);
 
     for (i = 0; i < 32; i++) {
         values[i] = *(plugin->values[i]);
     }
-
-    unsigned long s;
 
     for (s = 0; s < sample_count; s++) {
         if (gate[s] > 0.0f) {
