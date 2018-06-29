/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test case for Solution for Exersice 2.3-7, Search a set for two elements have sum of an element
  with Time Complexity as O(log2(n)).
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016
 */

#include "Search.h"
#include "../../../Common/Common.h"
#include <cstdio>

int main() {
	int A[] = {1, 3, 7, 8, 12, 82, 7, 3, 85, 7, 7, 2, 13, 73, 2, 23, 12, 32, 12, 8, 8, 37, 17, 75, 23, 27, 12, 37, 32};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);

	Search<int> search;
	const int sum = 183;
	if (search.Find(V, sum))
		printf("Two elements of SET have sum == [%d]\n", sum);
	else
		printf("Two elements of SET have not sum == [%d]\n", sum);
	
	return 0;
}
