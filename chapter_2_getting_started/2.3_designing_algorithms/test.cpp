/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Test case for Insertion sort and Merge Sort
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 10th, 2016
 */

#include "merge_sort.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("--------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n--------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {98, 12, 72, 123, 1, 8, 282, 3842, 8, 783, 23, 72, 17, 48, 52, 81, 73, 134, 84, 72, 841, 13, 85, 232, 4, 272};

    print(v);
	MergeSort<int> sort;
	sort.Sort(v);
    print(v);

	return 0;
}
