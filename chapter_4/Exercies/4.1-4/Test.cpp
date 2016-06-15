/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Test case for Solution for Exersice 4.1-4, Modify Max Sub Array to identify does the max array == 0
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 15th, 2016
 */

#include "MaxEmptyArray.h"
#include "../../../Common/Common.h"

int main() {
	//int A[] = {0, -8, -9, -23, - 34};
	int A[] = {9, -9, 18, 12, 83, 32, -23, -283, -383, 23, 3, 23, 213, 213, 45, 321, 3, 2};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);

	MaxEmptyArray<int> max;
	printf("-----------------------------------------------------------\n");
	printf("Maximum sub array == [%d]\n", max.MaxSum(V));
	printf("-----------------------------------------------------------\n");
	return 0;
}

