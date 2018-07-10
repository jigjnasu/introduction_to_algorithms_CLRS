/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test Solution for Exersice 2.3-4, Recursive Insertion Sort.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016
 */

#include "insertion_sort.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("-----------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n-----------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {81, 83, 832, 78892, 276, 31, 37, 34, 73, 2, 374, 27, 2, 48, 5, 65, 348, 73, 2, 7438, 32, 84, 2, 4738, 32};

    print(v);
	InsertionSort<int> sort;
	sort.Sort(v);
    print(v);

	return 0;
}
