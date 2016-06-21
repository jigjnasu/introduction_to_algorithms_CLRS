/*
  Introduction to algorithms, CLRS
  Chapter 1: The Role of Algorithms in Computing
  Solution for Exersice 1.2-2
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 20th, 2016
*/

#include <cstdio>
#include <cmath>

int main() {
	int n = 2;
	while (1) {
		const double insertion_sort_timing = 8 * n * n;
		const double merge_sort_timing = 64 * n * log2(n);

		printf("n == [%2d] || Insertion Timing == [%3.6f] || Merge Timing == [%3.6f]\n", n, insertion_sort_timing, merge_sort_timing);

		if (insertion_sort_timing > merge_sort_timing)
			break;
		++n;
	}
	
	return 0;
}