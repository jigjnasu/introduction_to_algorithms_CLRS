#ifndef ALGORITHM_CHAPTER_4_4_2_MATRIX_DIVIDE_AND_CONQUER_H_
#define ALGORITHM_CHAPTER_4_4_2_MATRIX_DIVIDE_AND_CONQUER_H_

#include <cstdio>

template <typename T, std::size_t size>
    class MatrixDC {
public:
    MatrixDC();
    ~MatrixDC();

    void Multiply(const T (&A)[size][size], const T (&B)[size][size], T (&C)[size][size]);
	
private:
    T m_multiply(const int& N, const int& I, const int& J,
		 const T (&A)[size][size], const T (&B)[size][size], T (&C)[size][size]);
};

template <typename T, std::size_t size>
    MatrixDC<T, size>::MatrixDC() {}

template <typename T, std::size_t size>
    MatrixDC<T, size>::~MatrixDC() {}

template <typename T, std::size_t size>
    void MatrixDC<T, size>::Multiply(const T (&A)[size][size], const T (&B)[size][size], T (&C)[size][size]) {
    m_multiply(size, 0, 0, A, B, C);
}

template <typename T, std::size_t size>
    T MatrixDC<T, size>::m_multiply(const int& N, const int& I, const int& J,
				    const T (&A)[size][size], const T (&B)[size][size], T (&C)[size][size]) {
    if (N == 1) {
	return *(const_cast<int*>(&A[0][0]) + I) * *(const_cast<int*>(&B[0][0]) + J);
    } else {
	// Half of N
	const int H = N / 2;
	// Jump to the H + row.
	const int O = H * size;
	const int r = I / size;
	const int c = J % size;

	C[r][c] += m_multiply(H, I, J, A, B, C) + m_multiply(H, I + H, J + O, A, B, C);
	C[r][c + H] += m_multiply(H, I, J + H, A, B, C) + m_multiply(H, I + H, J + O + H, A, B, C);
	C[r + H][c] += m_multiply(H, I + O, J, A, B, C) + m_multiply(H, I + O + H, J + O, A, B, C);
	C[r + H][c + H] += m_multiply(H, I + O, J + H, A, B, C) + m_multiply(H, I + O + H, J + O + H, A, B, C);	
    }

    return 0;
}

#endif // ALGORITHM_CHAPTER_4_4_2_MATRIX_DIVIDE_AND_CONQUER_H_
