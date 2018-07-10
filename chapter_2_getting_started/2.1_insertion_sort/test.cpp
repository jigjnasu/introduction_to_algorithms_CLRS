/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Test case for Insertion Sort implementation
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 10th, 2016
 */

#include "insertion_sort.h"
#include <cstdio>
#include <vector>

void print(const std::vector<int>& v) {
    printf("-----------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n-----------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {9, 738, 27, 23, 958, 37, 34, 274, 82, 16, 38, 163, 45, 82, 163, 858, 1, 7, 73, 17, 12, 74, 234, 721, 23};

    print(v);
	InsertionSort<int> sort;
	sort.Sort(v);
    print(v);

	return 0;
}
