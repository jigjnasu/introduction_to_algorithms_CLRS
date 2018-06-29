/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test case for Solution for Exersice 2.3-4, Binary Search for Insertion Sort.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016
 */

#include "InsertionSort.h"
#include "../../../Common/Common.h"

int main() {
	int A[] = {18, 38, 9, 378, 83, 1, 84, 82, 8, 2, 3, 334, 34, 3, 7, 23, 3272, 17, 372, 285, 823, 17, 63, 23, 457, 3271, 62};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);
	InsertionSort<int> sort;
	sort.Sort(V);
	common.PrintVector(V);
	
	return 0;
}
