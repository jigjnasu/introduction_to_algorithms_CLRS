#include "Matrix.h"
#include <cstdio>

template <std::size_t m, std::size_t n>
void print_matrix(const int A[m][n]) {
	printf("------------------------------------------------------\n");
	for (std::size_t r = 0; r < m; ++r) {
		for (std::size_t c = 0; c < n; ++c) {
			printf("%2d ", A[r][c]);
		}
		printf("\n");
	}
	printf("------------------------------------------------------\n");
}

void multiply_matrices() {
	const std::size_t m_a = 2;
	const std::size_t n_a = 4;
	const std::size_t m_b = 4;
	const std::size_t n_b = 2;

	int A[m_a][n_a] = { { 1, 2, 3, 4 },
						{ 5, 6, 7, 8 } };
	int B[m_b][n_b] = { { 9, 10 },
						{ 11, 12 },
						{ 13, 14 },
						{ 15, 16 } };
	int C[m_a][n_b] = { 0 };

	Matrix<int, m_a, n_a, m_b, n_b> matrix;
	matrix.Multiply(A, B, C);

	print_matrix<m_a, n_a>(A);
	print_matrix<m_b, n_b>(B);
	print_matrix<m_a, n_b>(C);
}

int main() {
	multiply_matrices();

	return 0;
}
