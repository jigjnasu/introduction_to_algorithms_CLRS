#include "MinMax.h"
#include "BucketSort.h"
#include "HeapSort.h"
#include "RadixSort.h"
#include "CountingSort.h"
#include "QuickSortRandom.h"
#include "QuickSortHoare.h"
#include "QuickSortHoareInitial.h"
#include "Exercise8.2_4.h"
#include "Common.h"
#include <cstdio>

void test_quick_sort_random() {
	int A[] = {10, 2, 345, 28, 382, 1, 384, 892, 2, 381, 34, 58, 2, 82, 82, 94, 82, 1, 84, 82, 284, 82};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	QuickSortRandom<int> sort;
	Common<int> common;
	common.PrintVector(V);
	//sort.SortAscending(V);
	sort.SortDescending(V);
	common.PrintVector(V);	
}

void test_quick_sort_hoare() {
	int A[] = {10, 2, 345, 28, 382, 1, 384, 892, 2, 381, 34, 58, 2, 82, 82, 94, 82, 1, 84, 82, 284, 82};
	//int A[] = {5, 3, 2, 6, 4, 1, 3, 7};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	QuickSortHoare<int> sort;
	Common<int> common;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);	
}

// This is the initial Hoare parition algorithm implementation
void test_quick_sort_hoare_initial() {
	int A[] = {10, 2, 345, 28, 382, 1, 384, 892, 2, 381, 34, 58, 2, 82, 82, 94, 82, 1, 84, 82, 284, 82};
	//int A[] = {5, 3, 2, 6, 4, 1, 3, 7};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	QuickSortHoareInitial<int> sort;
	Common<int> common;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);	
}

// This is the test for Counting sort
void test_counting_sort() {
	int A[] = {9, 8, 2, 3, 4, 5, 3, 4, 4, 2, 1, 3, 3, 5, 6, 7, 0, 0, 0, 1, 2, 3, 4, 5, 6, 9, 8, 8, 3, 2};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	CountingSort<int, 10> sort;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);
}

// This is the test for Radix Sort
void test_radix_sort() {
	int A[] = {981, 2831, 83, 18, 9, 183, 8482, 83, 123, 38, 8, 262, 3848, 12, 72, 73, 123, 848, 12, 84};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	Common<int> common;
	RadixSort<int> sort;
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);		
}

// This is the solution for Exercise 8.2-4 from Introduction to Algorithms
void test_exercise82_4() {
	int A[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	Exercise82_4<int, 5> numbers(V);
	int start = 1;
	int end = 5;
	printf("Numner of Elements between [%d] and [%d] range == [%d]\n", start, end, numbers.NumberOfElements(start, end));
}

// This is the solution for Bucket Sort.
void test_bucket_sort() {
	int A[] = {90, 83, 71, 38, 84, 2, 34, 1, 32, 31, 2, 24, 5, 3, 84, 73, 84, 17, 38, 85, 23, 83, 4, 56, 73, 71, 74, 27, 72, 13};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	
	Common<int> common;
	BucketSort<int> sort;
	
	common.PrintVector(V);
	sort.Sort(V);
	common.PrintVector(V);
}

// This is the test for Minimum and Maximum
void test_min_max() {
	int A[] = {9, 31, 68, 38, 1, 384, 84, 812, 88, 94, 18, 3, 56, 39, 8, 582, 24, 85, 2, 583, 83, 852, 4, 82, 842, 832, 381};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	
	Common<int> common;
	common.PrintVector(V);

	MinMax<int> min_max;
	printf("Minimum value == [%d]\n", min_max.Minimum(V));
	printf("Maximum value == [%d]\n", min_max.Maximum(V));
	printf("Second Minimum == [%d]\n", min_max.SecondMinimum(V));
	printf("Second Maximum == [%d]\n", min_max.SecondMaximum(V));
	
	int min = 0;
	int max = 0;
	min_max.MinimumMaximum(V, min, max);
	printf("Minimum value == [%d]\n", min);
	printf("Maximum value == [%d]\n", max);	
}

// Testing the O(n) complexity to find the ith smallest number
void test_find_smallest_number() {
	int A[] = {9, 1, 4, 5, 83, 82, 1, 838, 28, 284, 38, 12, 83, 234, 2, 81, 183, 73, 123, 84, 82, 27, 23, 84, 83, 27, 13};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	std::vector<int> V1 = V;
	Common<int> common;
	HeapSort<int> sort;
	common.PrintVector(V1);
	sort.SortAscending(V1);
	common.PrintVector(V1);

	MinMax<int> min_max;
	const int order = 21;
	printf("Smallest number at [%d] order == [%d]\n", order, min_max.SmallestNumber(V, order));
}

int main() {
	//test_quick_sort_random();
	//test_quick_sort_hoare();
	//test_quick_sort_hoare_initial();

	//test_counting_sort();
	//test_radix_sort();
	//test_bucket_sort();
	
	//test_exercise82_4();

	//test_min_max();

	test_find_smallest_number();
	return 0;
}
