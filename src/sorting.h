#define VERBOSE

#define make_sub_array(type, arr, off, len) (type(&)[len])(*(arr + off));
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define size_a(array) (*(&array + 1) - array)

void swap(int &a, int &b);

template <class T>
void printarray(const T array[], const int length, const int offset = 0);

/**
 * @brief
 * Time Complexity  :   O(n * n)
 * @param array
 * @param length
 */
void bubble_sort(int array[], int length);

void insert_sort(int array[], int length);

void select_sort(int array[], int length);

/**
 * @brief
 * Time Complexity  :   O(n log n)
 * @param array
 * @param start
 * @param end
 */
void quick_sort(int array[], int start, int end);

/**
 * @brief
 * Time Complexity  :   O(n log n)
 * @param array
 * @param low
 * @param high
 */
void merge_sort(int array[], int low, int high);

void merge_sorted_array(int array[], int low, int mid, int high);

#pragma region Search
/**
 * @brief
 * Time Complexity  :   O(n)
 *
 * @param array
 * @param key
 * @param length
 * @return int
 */
int linear_search(int array[], int length, int key);

/**
 * @brief Applied only on sorted array, assuming ascending as default
 * Time Complexity  :   O(log n)
 *
 */
int binary_search(int a[], int n, int k);
#pragma region
