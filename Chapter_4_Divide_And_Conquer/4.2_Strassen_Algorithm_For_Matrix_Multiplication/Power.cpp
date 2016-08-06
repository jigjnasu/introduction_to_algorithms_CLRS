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
 */

int power_first(const int& x, const int& n) {
	int result = 1;
	for (int i = 0; i < n; ++i)
		result *= x;
	return result;
}

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

int main() {
	int x = 2;
	int n = 20;

	printf("---------------- Frist case result --------------------\n");
	printf("power of [%d] ^ [%d] == [%d]\n", x, n, power_first(x, n));
	printf("-------------------------------------------------------\n");	
	printf("---------------- Second case result --------------------\n");
	printf("power of [%d] ^ [%d] == [%d]\n", x, n, power_second(x, n));
	printf("-------------------------------------------------------\n");	
	
	return 0;
}
