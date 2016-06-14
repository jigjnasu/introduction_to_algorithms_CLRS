/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Test case for Solution for Exersice 4.1-4, Let's check for an empty sub array, where sum is zero.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 14th, 2016
 */

#include "MaxSubArray.h"
#include "MaxBrute.h"
#include "../../../Common/Common.h"
#include <cstdio>

void test_max_sub_array() {
	//int A[] = {-9, 1, 2, 3, -6, 9, 7, 82, 9, 1, 98, -97};
	int A[] = {-9, 1, 2, 3, -6, 91, 7, 82, 9, 1, 98, -97};
	//int A[] = {-9, 9};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);

	MaxSubArray<int> max;

	printf("--------------------------------------------------\n");
	if (max.Validate(V))
		printf("Input SET is validated\n");
	else
		printf("Input SET FAILED the validion test\n");
	printf("--------------------------------------------------\n");	
}

void test_brute() {
	//int A[] = {-9, 1, 2, 3, -6, 9, 7, 82, 9, 1, 98, -97};
	int A[] = {-9, 1, 2, 3, -6, 91, 7, 82, 9, 1, 98, -97};
	//int A[] = {-9, 9};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);

	MaxBrute<int> brute;

	printf("--------------------------------------------------\n");
	if (brute.Validate(V))
		printf("Input SET is validated\n");
	else
		printf("Input SET FAILED the validion test\n");
	printf("--------------------------------------------------\n");	
}

int main() {
	test_max_sub_array();
	test_brute();
	
	return 0;
}
