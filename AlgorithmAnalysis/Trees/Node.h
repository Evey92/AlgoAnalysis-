
class Node {

 public:
   
   Node() = default;

   int
   getKey();
   
   Node*
   getLeft();

   Node*
   getRight();

 private:

   int m_key;
   Node* m_left;
   Node* m_right;
};