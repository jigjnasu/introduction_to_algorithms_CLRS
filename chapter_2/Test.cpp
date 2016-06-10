/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Test case for Insertion sort
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 10th, 2016
 */

#include "InsertionSort.h"
#include "../Common/Common.h"

int main() {
	int A[] = {98, 12, 72, 123, 1, 8, 282, 3842, 8, 783, 23, 72, 17, 48, 52, 81, 73, 134, 84, 72, 841, 13, 85, 232, 4, 272};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);
	InsertionSort<int> sort;
	sort.Sort(V);
	common.PrintVector(V);
	sort.SortReverse(V);
	common.PrintVector(V);
	
	return 0;
}
