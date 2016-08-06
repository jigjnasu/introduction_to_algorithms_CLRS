#include <cstdio>

/*
  This is a problem of calculating x ^ n, where n >= 0.
  We will do this problem in three different ways.

  First:  naive algorithm, which will { x * x * .... x * x } n times.
  		  It will take O(n) time complexities.
  Second: divide and conquer one,
  		  O(lg n) time complexity.
		  T(n) = T(n / 2) + O(1).
		  F(n) = { if (n % 2 == 0), even, return (x ^ n / 2) * (x ^ n / 2)
		  	     { if (n % 2 != 0), odd, return (x) * (x ^ (n - 1) / 2) * (x ^ (n - 1) / 2)
  Third:  Second, problem is a non dynamic example, a divide and conquer problem with recursion.
  		  But if we can memoize the sub results we can make this problem a dyanmic problem.
		  we will try to solve the second problem with DP (dynamic programming).

  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: August 6th, 2016
 */

/*
  Naive algorithm, with O(n) time complexity.
 */
int power_first(const int& x, const int& n) {
	int result = 1;
	for (int i = 0; i < n; ++i)
		result *= x;
	return result;
}

/*
  Divide and Conquer solution
 */
int power_second(const int& x, const int& n) {
	if (n == 0) {
		return 1;
	} else {
		if (n % 2 == 0)
			return power_second(x, n / 2) * power_second(x, n / 2);
		else
			return x * power_second(x, (n - 1) / 2) * power_second(x, (n - 1) / 2);
	}
}

/*
  Divide and Conquer + Memoized solution
 */
template <int size>
int power_third(const int& x, const int& n, int (&dictionary)[size]) {
	if (n == 0) {
		return 1;
	} else {
		if (dictionary[n - 1])
			return dictionary[n - 1];
		
		if (n % 2 == 0) {
			const int sz = n / 2;
			dictionary[sz - 1] = power_third(x, sz, dictionary);
			return dictionary[sz - 1] * dictionary[sz - 1];
		} else {
			const int sz = (n - 1) / 2;
			dictionary[sz - 1] = power_third(x, sz, dictionary);
			return x * dictionary[sz - 1] * dictionary[sz - 1];
		}
	}
}

int main() {
	const int x = 2;
	const int n = 21;
	int dictionary[n] = {0};
	
	printf("---------------- Frist case result ---------------------\n");
	printf("power of [%d] ^ [%d] == [%d]\n", x, n, power_first(x, n));
	printf("--------------------------------------------------------\n");	
	printf("---------------- Second case result --------------------\n");
	printf("power of [%d] ^ [%d] == [%d]\n", x, n, power_second(x, n));
	printf("-------------------------------------------------------\n");

	printf("---------------- Third case result --------------------\n");
	printf("power of [%d] ^ [%d] == [%d]\n", x, n, power_third<n>(x, n, dictionary));
	printf("-------------------------------------------------------\n");
	
	return 0;
}
