#include "tree.h"
#include <iostream>

namespace my {
  Tree::Tree(/* args */) {}

  Tree::~Tree() {}

  void Tree::print() {}

  void Tree::preOrderTraversal() { Tree::preOrderTraversal(m_root); }

  void Tree::preOrderTraversal(Node *root) {
    if (root != nullptr) {
      printf("%d ", root->data);
      Tree::preOrderTraversal(root->left_child);
      Tree::preOrderTraversal(root->right_child);
    }
  }

  void Tree::inOrderTraversal() { Tree::inOrderTraversal(m_root); }

  void Tree::inOrderTraversal(Node *root) {
    if (root != nullptr) {
      Tree::inOrderTraversal(root->left_child);
      printf("%d ", root->data);
      Tree::inOrderTraversal(root->right_child);
    }
  }

  void Tree::postOrderTraversal() { Tree::postOrderTraversal(m_root); }

  void Tree::postOrderTraversal(Node *root) {
    if (root != nullptr) {
      Tree::postOrderTraversal(root->left_child);
      Tree::postOrderTraversal(root->right_child);
      printf("%d ", root->data);
    }
  }

  void Tree::insert(int data) {
    Node *temp_node = new Node();
    temp_node->data = data;
    temp_node->left_child = nullptr;
    temp_node->right_child = nullptr;

    Node *current;

    if (m_root == nullptr) {
      m_root = temp_node;

    } else {
      current = m_root;
      while (true) {
        if (data > current->data) {
          if (current->right_child == nullptr) {
            current->right_child = temp_node;
            break;
          } else {
            current = current->right_child;
          }
        } else {
          if (current->left_child == nullptr) {
            current->left_child = temp_node;
            break;
          } else {
            current = current->left_child;
          }
        }
      }
    }

    return;
  }

  Tree::Node *Tree::search(int data) {
    Node *current = m_root;
    printf("Visiting items: ");

    while (current != nullptr) {
      printf("%d ", current->data);

      if (data > current->data) {
        current = current->right_child;
      } else if (data < current->data) {
        current = current->left_child;
      } else {
        return current;
      }
    }

    return nullptr;
  }
} // namespace my