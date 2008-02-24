--- nurbs/nurbsS_sp.h.orig	Mon May 13 14:07:46 2002
+++ nurbs/nurbsS_sp.h	Fri Dec  1 00:48:44 2006
@@ -78,7 +78,7 @@
 
 
   void modSurfCPby(int i, int j, const HPoint_nD<T,N>& a) //!< Moves a surface point by a value
-    { P(i,j) +=  a / (maxU[i]*maxV[j]) ;  }
+    { this->P(i,j) +=  a / (maxU[i]*maxV[j]) ;  }
   void modSurfCP(int i, int j, const HPoint_nD<T,N>& a) //!< Moves a surface point to a value
     { modSurfCPby(i,j,a-surfP(i,j)) ;  }
 
