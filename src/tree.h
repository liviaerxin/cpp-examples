#ifndef MY_TREE_H
#define MY_TREE_H

namespace my {

  /**
   * @brief Binary Tree is a special data structure for data storage purposes.
   * It aims to search as quick as orderer array and insert or delete as fast as
   * linked list.
   *
   * @details
   * Operatioins on tree:
   * - Insert
   * - Search
   * - PreOrder Traversal
   * - InOrder Traversal
   * - PostOrder Traversal
   * - Delete
   */
  class Tree {
  public:
    struct Node {
      int data;
      Node *left_child;
      Node *right_child;
    };

  private:
    /* data */
    Node *m_root{nullptr};

    static void preOrderTraversal(Node *);
    static void inOrderTraversal(Node *);
    static void postOrderTraversal(Node *);

  public:
    Tree(/* args */);
    ~Tree();
    void print();
    void insert(int);
    Node *search(int);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
  };

} // namespace my

#endif