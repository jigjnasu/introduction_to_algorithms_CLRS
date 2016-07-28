#include "Matrix.h"
#include "MatrixDivideAndConquer.h"
#include <cstdio>

template <std::size_t m, std::size_t n>
void print_matrix(const int (&A)[m][n]) {
	printf("------------------------------------------------------\n");
	for (std::size_t r = 0; r < m; ++r) {
		for (std::size_t c = 0; c < n; ++c) {
			printf("%8d ", A[r][c]);
		}
		printf("\n");
	}
	printf("------------------------------------------------------\n");
}

template <std::size_t size>
void multiply_matrices(const int (&A)[size][size], const int (&B)[size][size], int (&C)[size][size]) {
	Matrix<int, size, size, size, size> matrix;

	matrix.Multiply(A, B, C);

	printf("------------------------- N ^ 3 algorithm result -------------------\n");	
	print_matrix<size, size>(C);
	printf("------------------------- N ^ 3 algorithm result -------------------\n");	
}

template <std::size_t size>
void multiply_divide_and_conquer(const int (&A)[size][size], const int (&B)[size][size], int (&C)[size][size]) {
	MatrixDC<int, size> matrix;

	matrix.Multiply(A, B, C);

	printf("-------------- Divide and Conquer algorithm result -----------------\n");	
	print_matrix<size, size>(C);
	printf("-------------- Divide and Conquer algorithm result -----------------\n");		
}

int main() {
	const int N = 8;

	int A[N][N] = { {1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  },
					{9  , 10 , 11 , 12 , 13 , 14 , 15 , 16 },
					{17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 },
					{25 , 26 , 27 , 28 , 29 , 30 , 31 , 32 },
					{33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 },
					{41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 },
					{49 , 50 , 51 , 52 , 53 , 54 , 55 , 56 },
					{57 , 58 , 59 , 60 , 61 , 62 , 63 , 64 } };
	int B[N][N] = { {65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 },
					{73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 },
					{81 , 82 , 83 , 84 , 85 , 86 , 87 , 88 },
					{89 , 90 , 91 , 92 , 93 , 94 , 95 , 96 },
					{97 , 98 , 99 , 100, 101, 102, 103, 104},
					{105, 106, 107, 108, 109, 110, 111, 112},
					{113, 114, 115, 116, 117, 118, 119, 120},
					{121, 122, 123, 124, 125, 126, 127, 128} };
	int C[N][N] = {0};

	print_matrix<N, N>(A);
	print_matrix<N, N>(B);	
	
	multiply_matrices<N>(A, B, C);
	multiply_divide_and_conquer<N>(A, B, C);

	return 0;
}
