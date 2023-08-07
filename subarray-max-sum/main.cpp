#include <cassert>
#include <iostream>

int max_sum(int *array, int len) {
    int best = 0, current = 0;
    for (int i = 0; i < len; i++) {
        /* code */
        current += *(array + i);
        if (current < 0) {
            current = 0;
        }
        best = current > best ? current : best;
    }
    return best;
}

int main() {
    int test1[] = {1, 2, -5, 4, -3, 2};
    int test1_size = sizeof(test1) / sizeof(test1[0]);
    int test1_max = max_sum(test1, test1_size);
    assert(test1_max == 4);

    std::cout << "Array: {";
    for (int element : test1) {
        std::cout << element << " ";
    }
    std::cout << "}, Max Array Sum: " << test1_max << std::endl;

    int test2[] = {1, 4, -5, 4, -3, 4};
    int test2_size = sizeof(test2) / sizeof(test2[0]);
    int test2_max = max_sum(test2, test2_size);
    assert(test1_max == 4);

    std::cout << "Array: {";
    for (int element : test2) {
        std::cout << element << " ";
    }
    std::cout << "}, Max Array Sum: " << test2_max << std::endl;

    return 0;
}