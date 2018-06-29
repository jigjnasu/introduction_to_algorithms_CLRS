/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Test case for Insertion Sort implementation
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 10th, 2016
 */

#include "InsertionSort.h"
#include "../../Common/Common.h"
#include <cstdio>
#include <vector>

int main() {
	int A[] = {9, 738, 27, 23, 958, 37, 34, 274, 82, 16, 38, 163, 45, 82, 163, 858, 1, 7, 73, 17, 12, 74, 234, 721, 23};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);

	InsertionSort<int> sort;
	sort.Sort(V);
	common.PrintVector(V);
	
	return 0;
}
