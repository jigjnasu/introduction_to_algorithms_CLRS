/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test case for Solution for Exersice 2.3-4, Binary Search for Insertion Sort.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016
 */

#include "insertion_sort.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("---------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n---------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {18, 38, 9, 378, 83, 1, 84, 82, 8, 2, 3, 334, 34, 3, 7, 23, 3272, 17, 372, 285, 823, 17, 63, 23, 457, 3271, 62};

    print(v);
	InsertionSort<int> sort;
	sort.Sort(v);
    print(v);

	return 0;
}
