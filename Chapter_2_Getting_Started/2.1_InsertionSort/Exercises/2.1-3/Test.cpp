/*
  Intrdocution to algortithms
  Chapter 2: Getting Started
  Test case for, Exersice 2.1-3, Search a number (v) into a set {a1, a2, a3 .... an}
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "LinearSearch.h"
#include "../../../Common/Common.h"
#include <cstdio>

int main() {
	int A[] = {897, 17, 13, 83, 2, 782, 72, 17, 284, 7, 381, 8482, 72, 384, 72, 1723, 72, 161, 73, 21, 1, 3, 72, 713, 72};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);

	LinearSearch<int> search;
	printf("[%4d] found at [%2d] index\n", 19, search.Search(V, 19));
	printf("[%4d] found at [%2d] index\n", 7, search.Search(V, 7));
	printf("[%4d] found at [%2d] index\n", 8482, search.Search(V, 8482));

	return 0;
}
