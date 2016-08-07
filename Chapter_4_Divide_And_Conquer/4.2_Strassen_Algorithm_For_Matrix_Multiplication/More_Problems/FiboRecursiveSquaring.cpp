#include <cstdio>
#include <cstring>

/*
  This is the recursive squaring solution for computing Nth Fibonacci number.
  According to the theorem F(n) can be caluclated as follows
  F(n) = { 1 1 } ^ n
  	     { 1 0 }

  Solution is using divide and conquer approach to multiply 2 X 2 matrices.
  It is also using divide and conquer(dynamic programing) with cahce
  to compute the power of matrices as well.

  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: August 7th, 2016
 */

typedef unsigned long long int u_long;

const int SIZE = 2;
const u_long U[SIZE][SIZE] = {{1, 1}, {1, 0}};

// For testing the matrix data.
void print_matrix(u_long const* A) {
	printf("---------------------------\n");
	for (int i = 0; i < SIZE * SIZE; ++i) {
		if (i != 0 && i % SIZE == 0)
			printf("\n%8llu ", *(A + i));
		else
			printf("%8llu ", *(A + i));
	}
	printf("\n---------------------------\n");
}

// multiplay the matrices with divide and conquer with 7 additions and 8 multiplications.
u_long multiply(const int& N, const int& I, const int& J,
			    u_long const* A, u_long const* B, u_long* C) {
	if (N == 1) {
		return *(A + I) * *(B + J);
	} else {
		const int H = N / 2;
		const int O = H * SIZE;
		const int r = I / SIZE;
		const int c = J % SIZE;

		// C[r][c]
		*(C + (r * SIZE) + c) += multiply(H, I, J, A, B, C) +
			multiply(H, I + H, J + O, A, B, C);
		// C[r][c + H]
		*(C + (r * SIZE) + c + H) += multiply(H, I, J + H, A, B, C) +
			multiply(H, I + H, J + O + H, A, B, C);
		// C[r + H][c]
		*(C + ((r * SIZE) + (H * SIZE)) + c) += multiply(H, I + O, J, A, B, C) +
			multiply(H, I + O + H, J + O, A, B, C);
		// C[r + H][c + H]
		*(C + ((r * SIZE) + (H * SIZE)) + c + H) += multiply(H, I + O, J + H, A, B, C) +
			multiply(H, I + O + H, J + O + H, A, B, C);		
	}
	
	return 0;
}

void matrix_multiply(u_long const* A, u_long const* B, u_long* C) {
	multiply(SIZE, 0, 0, A, B, C);
}

// Using divide and conquer approach to do power of N
void fibonacci(const int& N, u_long const* X, u_long* R) {
	if (N == 0) {
		printf("Before --> address of R == [%d] || I == [%d]\n", R, &U[0][0]);		
		R = const_cast<u_long*>(&U[0][0]);
		printf("After  --> address of R == [%d] || I == [%d]\n", R, &U[0][0]);				
	} else {
		if (N % 2 == 0) {
			// return fibo(N / 2) * fibo(N / 2)
			u_long A[SIZE][SIZE] = {0};
			u_long B[SIZE][SIZE] = {0};
			fibonacci(N / 2, X, &A[0][0]);
			fibonacci(N / 2, X, &B[0][0]);			
			matrix_multiply(&A[0][0], &B[0][0], R);
		} else {
			// return X * fibo((N - 1) / 2) * fibo((N - 1) / 2)
			u_long A[SIZE][SIZE] = {0};
			u_long B[SIZE][SIZE] = {0};
			fibonacci((N - 1) / 2, X, &A[0][0]);
			fibonacci((N - 1) / 2, X, &B[0][0]);
			matrix_multiply(&A[0][0], &B[0][0], R);
			matrix_multiply(X, R, R);
		}
	}
}

// Testing case for fibonacci recursive squaring.
void test_fibonacci_recursive_squaring() {
	const u_long I[SIZE][SIZE] = { {1, 1}, {1, 0} };
	int N = 0;

	u_long R[SIZE][SIZE] = new ;
	printf("Before --> address of R == [%d]\n", &R[0][0]);			
	fibonacci(N, &I[0][0], &R[0][0]);
	printf("Before --> address of R == [%d]\n", &R[0][0]);			
	printf("---------------------------------------------\n");
	printf("Fibonacci number at [%3d] == [%8llu]\n", N, R[0][1]);
	printf("Fibonacci number at [%3d] == [%8llu]\n", N + 1, R[0][0]);
	printf("Fibonacci number at [%3d] == [%8llu]\n", N - 1, R[1][1]);	
	printf("---------------------------------------------\n");
}

int main() {
	test_fibonacci_recursive_squaring();

	return 0;
}
