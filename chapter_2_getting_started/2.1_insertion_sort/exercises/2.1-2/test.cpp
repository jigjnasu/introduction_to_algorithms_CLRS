/*
  Introduction to Algorithms
  Chapter 2: Getting Started
  Test case for Exersice, 2.1-2 implementation for decreasing Insrtion Sort
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "insertion_sort.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("-------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n-------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {8, 938, 38, 13, 324, 85, 72, 6274, 74, 1, 763, 8, 23, 762, 761, 84, 784, 2, 731, 73, 85, 2, 727, 1, 4, 72, 7};

    print(v);
	InsertionSort<int> sort;
	sort.Sort(v);
    print(v);

	return 0;
}
