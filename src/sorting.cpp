#include "sorting.h"
#include <iostream>

// helpers
int temp;

void swap(int &a, int &b) {
  temp = a;
  a = b;
  b = temp;
}

template <class T>
void printarray(const T array[], const int length, const int offset) {
  // int count = sizeof(array) / sizeof(array[0]);
  int count = length + offset;
  for (size_t i = offset; i < count; i++) {
    /* code */
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

// Bubble Sort
void bubble_sort(int array[], int length) {
  printf("*************BUBBLE SORT*************\n");
  for (size_t i = length; i > 1; i--) {
    for (size_t j = 0; j < i - 1; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
      }
    }

#if defined(VERBOSE)
    std::cout << "iteration " << length - i + 1 << ": ";
    printarray(array, length);
#endif // VERBOSE
  }
}

// Insert Sort
void insert_sort(int array[], int length) {
  printf("*************INSERT SORT*************\n");
  for (int i = 0; i < length - 1; i++) {
    for (int j = i; j > -1; j--) {
      if (array[j + 1] < array[j]) {
        swap(array[j + 1], array[j]);
      } else {
        break;
      }
    }

#if defined(VERBOSE)
    std::cout << "iteration " << i + 1 << ": ";
    printarray(array, length);
#endif // VERBOSE
  }
}

// Select Sort
void select_sort(int array[], int length) {
  printf("*************SELECT SORT*************\n");
  for (int i = length - 1; i > 0; i--) {
    int pos = i;
    for (int j = i - 1; j > -1; j--) {
      if (array[pos] < array[j])
        pos = j;
    }
    swap(array[i], array[pos]);

#if defined(VERBOSE)
    std::cout << "iteration " << length - i + 1 << ": ";
    printarray(array, length);
#endif // VERBOSE
  }
}

// Quick Sort
void quick_sort(int array[], int start, int end) {
  printf("*************QUICK SORT*************\n");

#if defined(VERBOSE)
  std::cout << "before array is: " << std::endl;
  printarray(array, end - start + 1, start);
  std::cout << "start: " << start << ", end: " << end << std::endl;
#endif // VERBOSE

  if (end - start < 2) {
    printf("exit quick_sort()\n");
    return;
  }

  int pos = start;
  int i = start + 1;
  int j = end;
  while (true) {
    while (array[i] <= array[pos] && i <= end)
      i++;
    while (array[j] >= array[pos] && j >= start)
      j--;
    // upon bound
    i = i > end ? end : i;
    j = j < start ? start : j;

    if (j > i) {
      swap(array[i], array[j]);
    } else {
      break;
    }
    i++;
    j--;
  }
  swap(array[pos], array[j]);
  pos = j;

#if defined(VERBOSE)
  std::cout << "after array is: " << std::endl;
  printarray(array, end - start + 1, start);
  std::cout << "pos: " << pos << "; array[pos]: " << array[pos] << std::endl;
#endif // VERBOSE

  quick_sort(array, start, pos - 1);
  quick_sort(array, pos + 1, end);
}

// Merge Sort
void merge_sort(int array[], int low, int high) {
  printf("*************Merge Sort*************\n");

  int mid;
  if (high > low) {
    mid = ((high + low) / 2);
    merge_sort(array, low, mid);
    merge_sort(array, mid + 1, high);

    // merge sorted array
    merge_sorted_array(array, low, mid, high);
  }
}

void merge_sorted_array(int array[], int low, int mid, int high) {
  printf("*************merge_sorted_array()*************\n");

  // merge sorted array
#if defined(VERBOSE)
  std::cout << "left array:" << std::endl;
  printarray(array, mid - low + 1, low);
  std::cout << "right array:" << std::endl;
  printarray(array, high - mid, mid + 1);
#endif // VERBOSE

  for (int i = mid; i < high; i++) {
    for (int j = i; j > low - 1; j--) {
      if (array[j + 1] < array[j]) {
        swap(array[j + 1], array[j]);
      } else {
        break;
      }
    }
  }

#if defined(VERBOSE)
  std::cout << "after merge:" << std::endl;
  printarray(array, high - low + 1, low);
#endif // VERBOSE
}

int linear_search(int array[], int length, int key) {
  printf("*************Linear Search*************\n");

  for (int i = 0; i < length; i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return -1;
}

int binary_search(int a[], int n, int k) {
  printf("*************Binary Search*************\n");
  int low = 0;
  int high = n - 1;
  while (high >= low) {
    int mid = (low + high) / 2;

    if (k < a[mid]) {
      high = mid - 1;
    } else if (k > a[mid]) {
      low = mid + 1;
    } else {
      // k == a[mid]
      return mid;
    }
  }
  return -1;
}