/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Test case for Solution for Exersice 4.1-3, Max Sub Array recursive problem and Brute Force problem.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 14th, 2016
 */

#include "MaxSubArray.h"
#include "../../../Common/Common.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>

int random(const int& start, const int& end) {
	return (rand() % (end - start) + 1) + start;
}

void get_random_data(std::vector<int>& V, const int& N) {
	const int start = -100;
	const int end = 100;
	
	for (int i = 0; i < N; ++i)
		V.push_back(random(start, end));
}

int main() {
	int N = 1;
	while (1) {
		std::vector<int> V;
		get_random_data(V, N);
	
		Common<int> common;
		printf("-------------------------------------------------\n");
		common.PrintVector(V);
		printf("-------------------------------------------------\n");

		MaxSubArray<int> max;
		printf("-------------------------------------------------\n");
		std::clock_t start = clock();
		printf("Algorithm -- Iterative   Maximum sub array == [%d]\n", max.MaxIterative(V));
		const double iterative_time = (clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
		printf("Execution time == [%.8f] seconds\n", iterative_time);
		printf("-------------------------------------------------\n");
		
		printf("-------------------------------------------------\n");
		start = clock();
		printf("Algorithm -- Brute Force Maximum sub array == [%d]\n", max.MaxBruteForce(V));
		const double brute_force_time = (clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
		printf("Execution time == [%.8f] seconds\n", brute_force_time);
		printf("-------------------------------------------------\n");

		if (iterative_time < brute_force_time) {
			printf("N == [%d] when Iterative Algorithm has better time than Brute Force Algorithm\n", N);
			break;
		}
		
		++N;
	}
		
	return 0;
}
