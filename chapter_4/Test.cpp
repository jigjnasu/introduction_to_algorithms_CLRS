/*
  Introduction to Algorithms, CLRS
  Chapter 4, Divide and conquer
  Maximum sub array problem
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 14th, 2016
 */

#include "MaxSubArray.h"
#include "../Common/Common.h"
#include <cstdio>

int main() {
	//int A[] = {-9, 1, 83, -9, -73, -2, -3, 4, 284, -8, 83, 1, -987, -3, -2, 3, 3, 283, 1, -3, 54, -8, -3, -2, 84, 38, 28, -98};
	//int A[] = {1, 2, 3, 4};
	//int A[] = {-1, -2, -3, -4};
	//int A[] = {-9, 12, 2, -10};
	//int A[] = {-9, 12, 2, -10, 9, 8, 12, -98};
	int A[] = {-9, 1, 83, -89, 83, 3, -2, 33, 132, 32, -73, 273, -74, -12, -32, 83};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	Common<int> common;
	common.PrintVector(V);

	int sum = 0;
	MaxSubArray<int> max;
	max.MaxSum(V, sum);

	printf("---------------------------------------------------------------------------------\n");
	printf("Maximum sum ==== [%d]\n", sum);
	printf("---------------------------------------------------------------------------------\n");
	
	return 0;
}
