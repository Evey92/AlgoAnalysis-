#include "Node.h"

void
Node::setKey(int key) {
   m_key = key;
}

int
Node::getKey() {
  return m_key;
}

void
Node::setLeft(Node* node) {
  m_left = node;
}

Node*
Node::getLeft() {
  return m_left;
}

void
Node::setRight(Node* node) {
  m_right = node;
}

Node*
Node::getRight() {
  return m_right;
}

void
Node::setParent(Node* node) {
  m_parent = node;
}

Node*
Node::getParent() {
  return m_parent;
}