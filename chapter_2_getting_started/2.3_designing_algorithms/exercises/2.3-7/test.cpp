/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test case for Solution for Exersice 2.3-7, Search a set for two elements have sum of an element
  with Time Complexity as O(log2(n)).
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016
 */

#include "search.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("--------------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n--------------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {1, 3, 7, 8, 12, 82, 7, 3, 85, 7, 7, 2, 13, 73, 2, 23, 12, 32, 12, 8, 8, 37, 17, 75, 23, 27, 12, 37, 32};

    print(v);
	Search<int> search;
	const int sum = 183;
	if (search.Find(v, sum))
		printf("Two elements of SET have sum == [%d]\n", sum);
	else
		printf("Two elements of SET have not sum == [%d]\n", sum);

	return 0;
}
