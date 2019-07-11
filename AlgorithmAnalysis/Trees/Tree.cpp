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
  Node* entry = m_rootNode;

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

  if (m_rootNode == nullptr || key == m_rootNode->getKey()) {
    return m_rootNode;
  }

  Node* currentNode = m_rootNode;

}

void
Tree::preOrder() {

}

void
Tree::inOrder() {

  if (m_rootNode == nullptr) {
    std::cout << "The tree is empty: YEET. \n";
  }

  std::stack<Node*> tempStack;
  Node* currentNode = m_rootNode;

  while (currentNode != nullptr || !tempStack.empty())
  {
    while (currentNode != nullptr)
    {
      tempStack.push(currentNode);
      currentNode = currentNode->getLeft();
    }

    currentNode = tempStack.top();
    tempStack.pop();

    std::cout << currentNode->getKey() << ", ";

    currentNode = currentNode->getRight();
  }

}

void
Tree::postOrder() {

}

void
Tree::Destroy(int key) {

}