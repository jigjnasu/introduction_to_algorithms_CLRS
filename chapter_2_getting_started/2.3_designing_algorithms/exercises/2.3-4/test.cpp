/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test Solution for Exersice 2.3-4, Recursive Insertion Sort.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016
 */

#include "../../../Common/Common.h"
#include "InsertionSort.h"
#include <cstdio>

int main() {
	int A[] = {81, 83, 832, 78892, 276, 31, 37, 34, 73, 2, 374, 27, 2, 48, 5, 65, 348, 73, 2, 7438, 32, 84, 2, 4738, 32};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);
	InsertionSort<int> sort;
	sort.Sort(V);
	common.PrintVector(V);
		
	return 0;
}
