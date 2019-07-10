#include "Node.h"

class Tree {

 public:
  
   Tree() = default;

   void 
   insert(int key, Node* node);

   Node*
   search(int key);

   void
   preOrder();
   
   void
   inOrder();
   
   void
   postOrder();
 
   void
   Destroy();

 private:

   Node* m_rootNode;
};