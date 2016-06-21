/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test case for Exersice 2.3-2, Merge sort without sentinal
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 11th, 2016
 */

#include "MergeSort.h"
#include "../../../Common/Common.h"

int main () {
	int A[] = {8, 88,23, 28838, 223, 28, 2334, 18, 1848, 8299, 234, 12, 72, 2, 381, 13, 4, 58, 323, 832, 283, 2, 384, 283, 23, 8283};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	common.PrintVector(V);

	MergeSort<int> sort;
	sort.Sort(V);
	common.PrintVector(V);
	
	return 0;
}
