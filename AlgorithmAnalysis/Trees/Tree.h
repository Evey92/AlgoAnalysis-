#include <iostream>
#include <stack>

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
   deleteNode(int key);

   void
   preOrder();
   
   void
   inOrder();
   
   void
   postOrder();
 
   void
   Destroy();

 private:

   Node* m_rootNode = nullptr;
};