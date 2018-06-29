#ifndef ALGORITHMS_CHAPTER_4_MATRIX_MULTIPLY_H_
#define ALGORITHMS_CHAPTER_4_MATRIX_MULTIPLY_H_

/*
  Matrix multiplication of m x n of two matrices.
  Time complexity is O(n ^ 3).
*/

#include <cstdio>

template <typename T, std::size_t m_a, std::size_t n_a, std::size_t m_b, std::size_t n_b>
class Matrix {
public:
    Matrix();
    ~Matrix();

    void Multiply(const T A[m_a][n_a], const T B[m_b][n_b], T(&C)[m_a][n_b]);
};

template <typename T, std::size_t m_a, std::size_t n_a, std::size_t m_b, std::size_t n_b>
Matrix<T, m_a, n_a, m_b, n_b>::Matrix() {}

template <typename T, std::size_t m_a, std::size_t n_a, std::size_t m_b, std::size_t n_b>
Matrix<T, m_a, n_a, m_b, n_b>::~Matrix() {}

template <typename T, std::size_t m_a, std::size_t n_a, std::size_t m_b, std::size_t n_b>
void Matrix<T, m_a, n_a, m_b, n_b>::Multiply(const T A[m_a][n_a], const T B[m_b][n_b], T(&C)[m_a][n_b]) {
    if (n_a != m_b) {
	printf("Can't multipy the matrices as first matrix column not equal to second matrix row [%lu] != [%lu]\n", n_a, m_b);
	return;
    }

    for (int i = 0; i < n_b; ++i) {
	for (int j = 0; j < m_a; ++j) {
	    int result = 0;
	    for (int k = 0; k < n_a; ++k) {
		result += (A[i][k] * B[k][j]);
	    }
	    C[i][j] = result;
	}
    }
}

#endif // ALGORITHMS_CHAPTER_4_MATRIX_MULTIPLY_H_
