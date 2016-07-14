/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Problem 2-4 d, Inverse counting with Divide and Conquer, which takes n lg n time.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 14th, 2016
*/

#include "Inversion.h"
#include <cstdio>

int main() {
	int A[] = {2, 3, 8, 6, 1};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	
	Inversion<int> inversion;
	printf("Inversion count == [%d]\n", inversion.Count(V));
	
	return 0;
}
