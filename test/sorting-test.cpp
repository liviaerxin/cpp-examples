#include "sorting.h"
// #include "gmock/gmock.h"
#include "gtest/gtest.h"

template <typename T, size_t size>
::testing::AssertionResult ArraysMatch(const T (&expected)[size],
                                       const T (&actual)[size]) {
  for (size_t i(0); i < size; ++i) {
    if (expected[i] != actual[i]) {
      return ::testing::AssertionFailure()
             << "array[" << i << "] (" << actual[i] << ") != expected[" << i
             << "] (" << expected[i] << ")";
    }
  }

  return ::testing::AssertionSuccess();
}

TEST(blaTest, test1) {
  // arrange
  // act
  // assert
  EXPECT_EQ(0, 0);
  EXPECT_EQ(20, 20);
  EXPECT_EQ(100, 100);
}

TEST(sortTest, testbubble) {
  int array[] = {12, 22, 11, 12, 10, 9, 90, 34, 2, 1};
  int expect[] = {1, 2, 9, 10, 11, 12, 12, 22, 34, 90};

  bubble_sort(array, size_a(array));

  EXPECT_TRUE(ArraysMatch(array, expect));
}

TEST(sortTest, test_merge_sorted_array) {
  int array[] = {1, 5, 2, 4};
  int expect[] = {1, 2, 4, 5};

  merge_sorted_array(array, 0, 1, 3);

  EXPECT_TRUE(ArraysMatch(array, expect));
}

TEST(searchTest, test_linear_search) {
  int array[] = {10, 54, 21, 42};
  int key = 21;
  int expected = 2;

  int pos = linear_search(array, size_a(array), key);

  EXPECT_EQ(pos, expected);
}

TEST(searchTest, test_binary_search) {
  int array[] = {10, 21, 24, 42, 56, 90, 100};
  int key = 21;
  int expected = 1;

  int pos = binary_search(array, size_a(array), key);

  EXPECT_EQ(pos, expected);
}