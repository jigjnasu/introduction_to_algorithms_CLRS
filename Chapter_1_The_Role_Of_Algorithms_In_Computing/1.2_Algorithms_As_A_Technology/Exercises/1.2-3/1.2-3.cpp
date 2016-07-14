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

/*
  Result

  n == [   1] || 100 * n * n == [     100] || pow(2, n) == [       2]
  n == [   2] || 100 * n * n == [     400] || pow(2, n) == [       4]
  n == [   3] || 100 * n * n == [     900] || pow(2, n) == [       8]
  n == [   4] || 100 * n * n == [    1600] || pow(2, n) == [      16]
  n == [   5] || 100 * n * n == [    2500] || pow(2, n) == [      32]
  n == [   6] || 100 * n * n == [    3600] || pow(2, n) == [      64]
  n == [   7] || 100 * n * n == [    4900] || pow(2, n) == [     128]
  n == [   8] || 100 * n * n == [    6400] || pow(2, n) == [     256]
  n == [   9] || 100 * n * n == [    8100] || pow(2, n) == [     512]
  n == [  10] || 100 * n * n == [   10000] || pow(2, n) == [    1024]
  n == [  11] || 100 * n * n == [   12100] || pow(2, n) == [    2048]
  n == [  12] || 100 * n * n == [   14400] || pow(2, n) == [    4096]
  n == [  13] || 100 * n * n == [   16900] || pow(2, n) == [    8192]
  n == [  14] || 100 * n * n == [   19600] || pow(2, n) == [   16384]
  n == [  15] || 100 * n * n == [   22500] || pow(2, n) == [   32768]
*/

#include <cstdio>
#include <cmath>

int main() {
	int n = 1;
	while (1) {
		const int lhs = 100 * n * n;
		const int rhs = pow(2, n);

		printf("n == [%4d] || 100 * n * n == [%8d] || pow(2, n) == [%8d]\n", n, lhs, rhs);
		
		if (lhs < rhs)
			break;
		++n;
	}

	return 0;
}
