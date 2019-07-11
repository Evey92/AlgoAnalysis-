#include "Tree.h"

void
Tree::insert(int key, Node* node) {

}

void
Tree::insert(int key) {
  
  Node* newNode = new Node(key);

  if (m_rootNode == nullptr) {
    m_rootNode = newNode;
    return;
  }

  Node* prev;
  Node* entry;
  entry = m_rootNode;

  while (entry != nullptr) {
    prev = entry;

    if (key <= entry->getKey()) {
      entry = entry->getLeft();
    }
    else {
      entry = entry->getRight();
    }
  }

  if (key <= prev->getKey()) {
    prev->setLeft(newNode);
  }
  else {
    prev->setRight(newNode);
  }
}

Node*
Tree::search(int key) {

  Node* entry = m_rootNode;

  if (key == entry->getKey()) {
    return entry;
  }
  else {

  }
}

void
Tree::preOrder() {

}

void
Tree::inOrder() {

  if (m_rootNode == nullptr) {
    std::cout << "The tree is empty: YEET. \n";

  }
}

void
Tree::postOrder() {

}

void
Tree::Destroy(int key) {

}