/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Problem 2-4 d, Inverse counting with Divide and Conquer, which takes n lg n time.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 14th, 2016
*/

#include "inversion.h"
#include <cstdio>

int main() {
    std::vector<int> v = {2, 3, 8, 6, 1};

	Inversion<int> inversion;
	printf("Inversion count == [%d]\n", inversion.Count(v));

	return 0;
}
