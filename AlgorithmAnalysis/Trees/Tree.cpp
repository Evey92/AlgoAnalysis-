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

  Node* prev = nullptr;
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
    newNode->setParent(prev);
    prev->setLeft(newNode);

  }
  else {
    newNode->setParent(prev);
    prev->setRight(newNode);
  }
}

Node*
Tree::search(int key) {

  if (m_rootNode == nullptr) {
    return nullptr;
  }
  else if (key == m_rootNode->getKey()) {
    return m_rootNode;
  }

  Node* currentNode = m_rootNode;

  while (currentNode != nullptr)
  {
    if (key > currentNode->getKey()) {
      currentNode = currentNode->getRight();
    }
    else if (key < currentNode->getKey())
    {
      currentNode = currentNode->getLeft();
    }
    else {
      return currentNode;
    }
  }
}

void
Tree::deleteDeepest(Node* node) {

  std::queue<Node*> nodeQueue;
  nodeQueue.push(m_rootNode);

  Node* tempNode = nullptr;
  
  while (!nodeQueue.empty()) {
    
    tempNode = nodeQueue.front();
    nodeQueue.pop();

    if (tempNode == node) {
      tempNode == nullptr;
      delete(node);
      return;
    }
    if (tempNode->getRight() != nullptr) {
      if (tempNode->getRight() == node) {
        tempNode->setRight(nullptr);
        delete(node);
        return;
      }
      else {
        nodeQueue.push(tempNode->getRight());
      }
    }
    if (tempNode->getLeft() != nullptr) {
      if (tempNode->getLeft() == node) {
        tempNode->setLeft(nullptr);
        delete(node);
        return;
      }
      else {
        nodeQueue.push(tempNode->getLeft());
      }
    }
  }


}

void
Tree::deleteNode(int key) {
  
  Node* currentNode = search(key);
  if (currentNode == nullptr) {
    std::cout << "Couldn't find node with key: " << key << "\n";
    return;
  }

  if (currentNode->getLeft() == nullptr && currentNode->getRight() == nullptr) {
    
    currentNode = nullptr;
  }
  else if (currentNode->getLeft() != nullptr && currentNode->getRight() == nullptr 
    || currentNode->getLeft() == nullptr && currentNode->getRight() != nullptr) {
    
    currentNode = nullptr;
  }
  else if (currentNode->getLeft() != nullptr && currentNode->getRight() != nullptr) {

  }

  std::queue<Node*> nodeQueue;
  nodeQueue.push(m_rootNode);

  Node* tempNode = nullptr;
  Node* succNode = nullptr;

  while (!nodeQueue.empty()) {
    tempNode = nodeQueue.front();
    nodeQueue.pop();

    if (tempNode->getKey() == key) {
      succNode = tempNode;
    }
    if (tempNode->getLeft() != nullptr) {
      nodeQueue.push(tempNode->getLeft());
    }
    if (tempNode->getRight() != nullptr)
    {
      nodeQueue.push(tempNode->getRight());
    }
  }

  if (succNode != nullptr) {
    int newKey = tempNode->getKey();
    deleteDeepest(tempNode);
    succNode->setKey(newKey);
  }
   
}

Node*
minValueNode(Node* node) {
  
  Node* currentNode = node;

  while (currentNode && currentNode->getLeft() != nullptr)
  {
    currentNode = currentNode->getLeft();
  }

  return currentNode;
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
Tree::Destroy() {

}