/*
  Introduction to algorithms
  Chapter 2: Getting started
  Test for Exersice 2.2-2, Implement a slection sort.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "SelectionSort.h"
#include "../../../Common/Common.h"

int main() {
	int A[] = {94, 18, 384, 828, 271, 1, 7, 938, 82234, 84, 72, 81, 84, 2, 27, 96, 284, 82, 1, 238, 27, 134, 43, 23, 12, 17};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);
	SelectionSort<int> sort;
	sort.Sort(V);
	common.PrintVector(V);
	
	return 0;
}
