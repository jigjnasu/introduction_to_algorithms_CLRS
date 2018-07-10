/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Test case for Solution for Exersice 2.3-5, Searching an element in a SET, if it is sorted.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016

  Time complexity will be O(log2(n)), because in every recurisive or iterative search,
  half of the SET items will be left alone and search will be done only in the rest half.

  For example SET has 8 elemets, in first iterative search 8 / 2, then 4 / 2 and then 2 / 2 ....
  And therefore time complexity will be O(log2(n)).
 */

//#include "Search.h"
#include "search_iterative.h"
#include <cstdio>

void print(const std::vector<int>& v) {
    printf("------------------------------------------------------------------\n");
    for (std::size_t i = 0; i < v.size(); ++i)
        printf("%d", v[i]);
    printf("\n------------------------------------------------------------------\n");
}

void test_search() {
    std::vector<int> v = {89, 18, 372, 828, 1, 327, 16, 84, 3, 848, 27, 8489, 37, 34, 16, 84, 74, 266, 17, 3778, 7};
    print(v);

	Search<int> search;
	int key = 372;
	if (search.Find(v, key))
		printf("[%d] is PRESNET in the SET\n", key);
	else
		printf("[%d] is NOT PRESNET in the SET\n", key);
}

void test_iterative_search() {
    std::vector<int> v = {89, 18, 372, 828, 1, 327, 16, 84, 3, 848, 27, 8489, 37, 34, 16, 84, 74, 266, 17, 3778, 7};

    print(v);
	Search<int> search;
	int key = 94;
	if (search.Find(v, key))
		printf("[%d] is PRESNET in the SET\n", key);
	else
		printf("[%d] is NOT PRESNET in the SET\n", key);
}

int main() {
	test_search();
	test_iterative_search();

	return 0;
}
