/*
  Introduction to algorithms, CLRS
  Chapter 1: The Role of Algorithms in Computing
  Solution for Exersice 1.2-3
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 20th, 2016
*/

/*
  What is the smallest value of n such that an algorithm whose running time is 100n2
  runs faster than an algorithm whose running time is 2n on the same machine?
 */

#include <cstdio>
#include <cmath>

int main() {
	int n = 1;
	while (1) {
		const double lhs = 100 * n * n;
		const double rhs = pow(2, n);

		printf("n == [%4d] || 100 * n * n == [%3.6f] || pow(2, n) == [%3.6f]\n", n, lhs, rhs);
		
		if (lhs < rhs)
			break;
		++n;
	}

	return 0;
}
