/*
1;4601;0c  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test case for Exersice 2.3-2, Merge sort without sentinal
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 11th, 2016
 */

#include "merge_sort.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n------------------------------------------------------\n");
}

int main () {
    std::vector<int> v = {8, 88,23, 28838, 223, 28, 2334, 18, 1848, 8299, 234, 12, 72, 2, 381, 13, 4, 58, 323, 832, 283, 2, 384, 283, 23, 8283};

    print(v);
	MergeSort<int> sort;
	sort.Sort(v);
    print(v);

	return 0;
}
