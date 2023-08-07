#include "linked_list.h"
#include <exception>
#include <iostream>

struct NotImplementedException : public std::exception {
  const char *what() const throw() { return "Function not yet implemented."; }
};

namespace my {

  LinkedList::LinkedList(/* args */) {}

  LinkedList::~LinkedList() {}

  void LinkedList::printList() {
    Node *current = head;
    printf("\n[");

    while (current != nullptr) {
      printf("%d ", current->data);
      current = current->next;
    }

    printf("]");
  }

  void LinkedList::insertAfter(Node *node, int data) {
    Node *current = new Node();
    current->data = data;

    current->next = node->next;
    node->next = current;

    // update tail
    if (current->next == nullptr) {
      tail = current;
    }
  }

  void LinkedList::insertBefore(Node *node, int data) {
    throw NotImplementedException();
  }
  void LinkedList::insertBegin(int data) {
    Node *current = new Node();
    current->data = data;

    current->next = head;
    head = current;

    // update tail
    if (tail == nullptr) {
      tail = current;
    }
  }

  void LinkedList::insertEnd(int data) {
    if (tail == nullptr) {
      insertBegin(data);
    } else {
      insertAfter(tail, data);
    }
  }

  int LinkedList::length() {
    int length = 0;
    Node *current = head;

    while (current != nullptr) {
      length++;
      current = current->next;
    }

    return length;
  }

  void LinkedList::insertAt(int index, int data) {
    if (index == 0) {
      insertBegin(data);
    } else {
      Node *prev = getAt(index - 1);
      insertAfter(prev, data);
    }
  }

  LinkedList::Node *LinkedList::getAt(int index) {
    Node *current = head;
    int i = 0;

    while (current != nullptr) {
      if (index == i) {
        break;
      }
      i++;
      current = current->next;
    }

    return current;
  }

  void LinkedList::deleteAt(int index) { throw NotImplementedException(); }

  void LinkedList::deleteAll() {
    Node *current = head;

    while (current != nullptr) {
      Node *tmp = current;
      current = current->next;
      delete tmp;
    }

    head = nullptr;
    tail = nullptr;
  }

  int LinkedList::search(Node *node) { throw NotImplementedException(); }
} // namespace my