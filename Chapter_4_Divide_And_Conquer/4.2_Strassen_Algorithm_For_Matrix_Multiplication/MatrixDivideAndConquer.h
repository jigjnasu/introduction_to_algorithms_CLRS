#ifndef ALGORITHM_CHAPTER_4_4_2_MATRIX_DIVIDE_AND_CONQUER_H_
#define ALGORITHM_CHAPTER_4_4_2_MATRIX_DIVIDE_AND_CONQUER_H_

template <typename T, std::size_t size>
class MatrixDC {
public:
	MatrixDC();
	~MatrixDC();

	void Multiply(const T (&A)[size][size], const T (&B)[size][size], T (&C)[size][size]);

private:
	T m_multiply(const int& N, const int& pos_a, const int& pos_b,
				 const T (&A)[size][size], const T (&B)[size][size], T (&)[size][size]);
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
T MatrixDC<T, size>::m_multiply(const int& N, const int& pos_a, const int& pos_b,
								   const T (&A)[size][size], const T (&B)[size][size], T (&C)[size][size]) {
	if (N == 1) {
		return (*(const_cast<int*>(&A[0][0])) + pos_a) * (*(const_cast<int*>(&B[0][0]) + pos_b)); 
	} else {
		// Next N / 2th size.
		const int H = N / 2;
		const int pos_a_bottom_left = (size * (H - 1)) + (pos_a % size);
		const int pos_b_bottom_left = (size * (H - 1)) + (pos_b % size);		

		C[pos_a / size][pos_b % size] += m_multiply(H, pos_a, pos_b, A, B, C) + m_multiply(H, pos_a + H, pos_b_bottom_left, A, B, C);
		C[pos_a / size][(pos_b + H) % size] += m_multiply(H, pos_a, pos_b + H, A, B, C) + m_multiply(H, pos_a + H, pos_b_bottom_left + H, A, B, C);
		C[pos_a_bottom_left / size][pos_b % size] += m_multiply(H, pos_a_bottom_left, pos_b, A, B, C) + m_multiply(H, pos_a_bottom_left + H, pos_b_bottom_left, A, B, C);
		C[pos_a_bottom_left / size][(pos_b + H) % size] += m_multiply(H, pos_a_bottom_left, pos_b + H, A, B, C) + m_multiply(H, pos_a_bottom_left + H, pos_b_bottom_left + H, A, B, C);
	}
}

#endif // ALGORITHM_CHAPTER_4_4_2_MATRIX_DIVIDE_AND_CONQUER_H_
