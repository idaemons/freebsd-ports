*** include/X3DTK/private/X3DAbstractNode.h.orig	Fri Aug 27 13:18:33 2004
--- include/X3DTK/private/X3DAbstractNode.h	Sat Dec 16 15:42:01 2006
***************
*** 102,108 ****
    inline void defineTypeName(const SFString &name, const SFString &component = SFString(""), const SFString &sceneGraph = SFString("")) {defineTempTypeName(this, name, component, sceneGraph);};
    /// Method to avoid defineTypeName having a template parameter.
    template<class T>
!   inline void defineTempTypeName(T *t, const SFString &name, const SFString &component, const SFString &sceneGraph) {define(Recorder<T>::getTypeName(name, component, sceneGraph));};
    /// Defines an attribute.
    template<class T, class V>
    inline void defineAttribute(const SFString &name, V T:: *member, const V &init);
--- 102,108 ----
    inline void defineTypeName(const SFString &name, const SFString &component = SFString(""), const SFString &sceneGraph = SFString("")) {defineTempTypeName(this, name, component, sceneGraph);};
    /// Method to avoid defineTypeName having a template parameter.
    template<class T>
!   inline void defineTempTypeName(T * /* t */, const SFString &name, const SFString &component, const SFString &sceneGraph) {define(Recorder<T>::getTypeName(name, component, sceneGraph));};
    /// Defines an attribute.
    template<class T, class V>
    inline void defineAttribute(const SFString &name, V T:: *member, const V &init);
***************
*** 132,137 ****
--- 132,147 ----
    /// Removes a parent.
    bool removeParent(const SFNode &N);
  };
+ 
+ inline void X3DAbstractNode_addParentToChild(SFNode parent, SFNode child) {
+   X3DAbstractNode::addParentToChild(parent,child);
+ }
+ inline void X3DAbstractNode_removeParentFromChild(SFNode parent, SFNode child) {
+   X3DAbstractNode::removeParentFromChild(parent,child);
+ }
+ inline SFType * X3DAbstractNode_getType(X3DAbstractNode * node) {
+   return node->getType();
+ }
  
  }
  
