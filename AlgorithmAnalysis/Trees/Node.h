
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

 private:

   int m_key;
   Node* m_left;
   Node* m_right;
};