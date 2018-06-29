#include <cstdio>
#include <ctime>

/*
  Solutions for Fibonacci number problem.

  First:	bottom up approach, where F0 F1 F2 ... FN.
  			Adding last two numbers till N.
			Time Complexity O(n) ... Linear Time.

  Second:	Naive Recursive algorithm.
  			It has exponential time complexity.
			F(n) = {0   , if n = 0}
			       {1   , if n = 1}
				   {F(n - 1) + F(n - 2), if n > 1}

  Third:    Recursive algorithm with a cache.
  			Simple example of Dynamic Programming.
  Author:   Rakesh Kumar @ cpp.rakesh@gmail.com
  Date:     August 6th, 2016
 */

typedef unsigned long long int u_long;

/*
  First implementation, Bottom Up
 */
u_long fibonacci_first(const int& N) {
	u_long result = 0;
	if (N == 1) {
		result = 1;
	} else {
		u_long a = 0;
		u_long b = 1;
		for (int i = 1; i < N; ++i) {
			result = a + b;
			a = b;
			b = result;
		}
	}
	
	return result;
}

/*
  Second implementation, Naive Recursive algorithm
 */
u_long fibonacci_second(const int& N) {
	if (N == 0)
		return 0;
	else if (N == 1)
		return 1;
	return fibonacci_second(N - 1) + fibonacci_second(N - 2);
}

/*
  Third implementation, DP, recursive with cache
 */
template <int size>
u_long fibonacci_third(const int& N, u_long (&dictionary)[size]) {
	if (N == 0) {
		dictionary[0] = 0;
		return 0;
	} else if (N == 1) {
		dictionary[1] = 1;
		return 1;
	} else {
		if (dictionary[N - 1])
			return dictionary[N - 1];

		dictionary[N - 1] = fibonacci_third(N - 1, dictionary) + fibonacci_third(N - 2, dictionary);
		return dictionary[N - 1];
	}
}

void test_first(const int& N) {
	printf("Number at [%d] == [%llu]\n", N, fibonacci_first(N));
}

void test_second(const int& N) {
	printf("Number at [%d] == [%llu]\n", N, fibonacci_second(N));	
}

template <int N>
void test_third() {
	u_long dictionary[N] = {0};
	printf("Number at [%d] == [%llu]\n", N, fibonacci_third<N>(N, dictionary));		
}

int main() {
	const int N = 100;
	printf("-------------- N ===== [%d] -------------------------\n", N);
	printf("-------------- First Method -------------------------\n");
	std::clock_t start = clock();
	test_first(N);
	printf("Execution time == [%.8f]\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	printf("-------------- Second Method ------------------------\n");	
	start = clock();
	test_second(N);
	printf("Execution time == [%.8f]\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

	printf("-------------- Third Method -------------------------\n");	
	start = clock();
	test_third<N>();
	printf("Execution time == [%.8f]\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));	
	return 0;
}
