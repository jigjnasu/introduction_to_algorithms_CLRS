/*
  Intrdocution to algortithms
  Chapter 2: Getting Started
  Test case for, Exersice 2.1-3, Search a number (v) into a set {a1, a2, a3 .... an}
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "linear_search.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("-----------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n-----------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {897, 17, 13, 83, 2, 782, 72, 17, 284, 7, 381, 8482, 72, 384, 72, 1723, 72, 161, 73, 21, 1, 3, 72, 713, 72};

    print(v);
	LinearSearch<int> search;
	printf("[%4d] found at [%2d] index\n", 19, search.Search(v, 19));
	printf("[%4d] found at [%2d] index\n", 7, search.Search(v, 7));
	printf("[%4d] found at [%2d] index\n", 8482, search.Search(v, 8482));

	return 0;
}
