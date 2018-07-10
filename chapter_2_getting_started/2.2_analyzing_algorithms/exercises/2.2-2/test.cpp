/*
  Introduction to algorithms
  Chapter 2: Getting started
  Test for Exersice 2.2-2, Implement a slection sort.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "selection_sort.h"

void print(const std::vector<int>& v) {
    printf("----------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n----------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {94, 18, 384, 828, 271, 1, 7, 938, 82234, 84, 72, 81, 84, 2, 27, 96, 284, 82, 1, 238, 27, 134, 43, 23, 12, 17};

    print(v);
	SelectionSort<int> sort;
	sort.Sort(v);
    print(v);

	return 0;
}
