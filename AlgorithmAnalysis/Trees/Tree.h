#include <iostream>

#include "Node.h"

class Tree {

 public:
  
   Tree() = default;

   void 
   insert(int key, Node* node);

   void
   insert(int key);

   Node*
   search(int key);

   void
   preOrder();
   
   void
   inOrder();
   
   void
   postOrder();
 
   void
   Destroy(int key);

 private:

   Node* m_rootNode;
};