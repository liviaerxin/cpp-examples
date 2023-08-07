#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

namespace my {
  class LinkedList {
  public:
    struct Node {
      int data;
      Node *next;
    };

  private:
    /* data */
    Node *head{nullptr};
    Node *tail{nullptr};

  public:
    LinkedList(/* args */);
    ~LinkedList();

    void printList();
    void insertAfter(Node *node, int data);
    void insertBefore(Node *node, int data);
    void insertBegin(int data);
    void insertEnd(int data);
    void insertAt(int index, int data);
    void deleteAt(int index);
    void deleteAll();
    Node *getAt(int index);
    int search(Node *node);
    int length();
  };

} // namespace my
#endif // __LINKED_LIST_H__