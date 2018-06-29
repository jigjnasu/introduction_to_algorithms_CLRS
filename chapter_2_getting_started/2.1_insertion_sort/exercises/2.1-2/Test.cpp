/*
  Introduction to Algorithms
  Chapter 2: Getting Started
  Test case for Exersice, 2.1-2 implementation for decreasing Insrtion Sort
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "InsertionSort.h"
#include "../../../Common/Common.h"

int main() {
	int A[] = {8, 938, 38, 13, 324, 85, 72, 6274, 74, 1, 763, 8, 23, 762, 761, 84, 784, 2, 731, 73, 85, 2, 727, 1, 4, 72, 7};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	Common<int> common;
	common.PrintVector(V);
	InsertionSort<int> sort;
	sort.Sort(V);
	common.PrintVector(V);
	
	return 0;
}
