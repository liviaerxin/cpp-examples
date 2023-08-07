#include "linked_list.h"
#include "queue.h"
#include "sorting.h"
#include "tree.h"
#include <iostream>

void testQueue() {
  my::Queue q(10);
  q.dequeue();
}

void testTree() {
  int a[7] = {27, 14, 35, 10, 19, 31, 42};
  my::Tree tree;

  for (int i = 0; i < 7; i++)
    tree.insert(a[i]);

  int i;

  i = 31;
  auto *temp = tree.search(i);
  if (temp != nullptr) {
    printf("[%d] Item found.", temp->data);
    printf("\n");
  } else {
    printf("[ x ] Item not found (%d).\n", i);
  }

  i = 15;
  temp = tree.search(i);
  if (temp != nullptr) {
    printf("[%d] Item found.", temp->data);
    printf("\n");
  } else {
    printf("[ x ] Item not found (%d).\n", i);
  }

  delete temp;

  printf("\nPreorder traversal: ");
  tree.preOrderTraversal();

  printf("\nInOrder traversal: ");
  tree.inOrderTraversal();

  printf("\nPostorder traversal: ");
  tree.postOrderTraversal();
}

void testLinkedList() {
  my::LinkedList list;
  list.insertBegin(10);
  list.insertBegin(20);
  list.insertBegin(10);
  list.insertBegin(30);
  list.insertBegin(50);

  printf("\nList after insertBegin:");
  list.printList();
  // [50 30 10 20 10]
  printf("\nlength[%d]", list.length());

  list.deleteAll();
  // []
  printf("\nList after deleting all items:");
  list.printList();
  printf("\nlength[%d]", list.length());

  list.deleteAll();
  list.insertEnd(10);
  list.insertEnd(20);
  list.insertEnd(10);
  list.insertEnd(30);
  list.insertEnd(50);
  printf("\nList after insertEnd:");
  list.printList();
  // [10 20 10 30 50]
  printf("\nlength[%d]", list.length());

  list.insertAt(0, 11);
  printf("\nList after insertAt 0:");
  list.printList();

  list.insertAt(3, 71);
  printf("\nList after insertAt 3:");
  list.printList();
}

int main() {
  int array[100]; // 100 buffer size
  int n;

  // testQueue();
  // testTree();
  testLinkedList();
  return 0;

  // std::cout << "q" << q.Capacity() << std::endl;
  // 1. Input Array
  std::cout << "\nPlease enter the array length: " << std::endl;
  std::cin >> n;

  std::cout << "Please enter the array elements: " << std::endl;
  for (size_t i = 0; i < n; i++) {
    /* code */
    std::cout << "Array[" << i << "]=";
    std::cin >> array[i];
  }

  std::cout << "The original array is: ";
  printarray(array, n);

  // merge_sorted_array((int[]){1, 5, 3, 4}, 0, 1, 3);

  // 2. Sorting
  // bubble_sort(array, n);
  // insert_sort(array, n);
  // select_sort(array, n);
  // quick_sort(array, 0, n - 1);
  merge_sort(array, 0, n - 1);

  std::cout << "The sorted array is: ";
  printarray(array, n);

  return 0;
}