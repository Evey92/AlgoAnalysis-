
class Node {

 public:
   
   Node(int key) : m_key(key) {}

   void
   setKey(int key);

   int
   getKey();
   
   void
   setLeft(Node* node);

   Node*
   getLeft();

   void
   setRight(Node* node);

   Node*
   getRight();

   void
   setParent(Node* node);

   Node*
   getParent();

 private:

   int m_key;
   Node* m_left = nullptr;
   Node* m_right = nullptr;
   Node* m_parent = nullptr;
};