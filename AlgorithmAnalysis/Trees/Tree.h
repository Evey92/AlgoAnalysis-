#include <iostream>
#include <stack>
#include <queue>

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
   deleteDeepest(Node* node);

   void 
   deleteNode(int key);

   Node*
   minValueNode(Node* node);

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