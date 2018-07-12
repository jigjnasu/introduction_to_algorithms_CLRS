#ifndef ALGORITHM_CHAPTER_4_4_2_STRASSEN_H_
#define ALGORITHM_CHAPTER_4_4_2_STRASSEN_H_

/*
  Strassen's algorithm for Matrix Multiplication
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: August 13th, 2016
*/

#include "square_matrix.h"

template <typename T>
class Strassen {
public:
    Strassen();
    ~Strassen();

    SquareMatrix<T> Multiply(const SquareMatrix<T>& A, const SquareMatrix<T>& B);

private:
    SquareMatrix<T> m_multiply(const int& N, const SquareMatrix<T>& A, const SquareMatrix<T>& B);
    SquareMatrix<T> m_half_matrix(const int& N, const int& R, const int& C, const SquareMatrix<T>& M);
    SquareMatrix<T> m_add(SquareMatrix<T> C11,
			  SquareMatrix<T> C12,
			  SquareMatrix<T> C21,
			  SquareMatrix<T> C22);
};

template <typename T>
Strassen<T>::Strassen() {}

template <typename T>
Strassen<T>::~Strassen() {}

/*
  Strassen Algorithm

  P1 = a * (f - h)
  P2 = (a + b) * h
  P3 = (c + d) * e
  P4 = d * (g - e)
  P5 = (a + d) * (e + h)
  P6 = (b - d) * (g + h)
  P7 = (a - c) * (e + f)

  A*B = { P5 + P4 - P2 + P6          P1 + P2      }
  {      P3 + P4          P1 + P5 - P3 - P7 }
*/
template <typename T>
SquareMatrix<T> Strassen<T>::Multiply(const SquareMatrix<T>& A, const SquareMatrix<T>& B) {
    return m_multiply(A.Size(), A, B);
}

template <typename T>
SquareMatrix<T> Strassen<T>::m_multiply(const int& N, const SquareMatrix<T>& A, const SquareMatrix<T>& B) {
    if (N == 1) {
	std::vector< std::vector<T> > matrix;
	std::vector<T> row;
	row.push_back(A.Get()[0][0] * B.Get()[0][0]);
	matrix.push_back(row);
	return matrix;
    } else {
	const int H = N / 2;

	SquareMatrix<T> a = m_half_matrix(N, 0, 0, A);
	SquareMatrix<T> b = m_half_matrix(N, 0, N / 2, A);
	SquareMatrix<T> c = m_half_matrix(N, N / 2, 0, A);
	SquareMatrix<T> d = m_half_matrix(N, N / 2, N / 2, A);

	SquareMatrix<T> e = m_half_matrix(N, 0, 0, B);
	SquareMatrix<T> f = m_half_matrix(N, 0, N / 2, B);
	SquareMatrix<T> g = m_half_matrix(N, N / 2, 0, B);
	SquareMatrix<T> h = m_half_matrix(N, N / 2, N / 2, B);

	SquareMatrix<T> P1 = m_multiply(H, a, f - h);
	SquareMatrix<T> P2 = m_multiply(H, a + b, h);
	SquareMatrix<T> P3 = m_multiply(H, c + d, e);
	SquareMatrix<T> P4 = m_multiply(H, d, g - e);
	SquareMatrix<T> P5 = m_multiply(H, a + d, e + h);
	SquareMatrix<T> P6 = m_multiply(H, b - d, g + h);
	SquareMatrix<T> P7 = m_multiply(H, a - c, e + f);

	return  m_add(P5 + P4 - P2 + P6,
		      P1 + P2,
		      P3 + P4,
		      P1 + P5 - P3 - P7);
    }
}

template <typename T>
SquareMatrix<T> Strassen<T>::m_half_matrix(const int& N, const int& R, const int& C,
					   const SquareMatrix<T>& M) {
    std::vector< std::vector<T> > mat = M.Get();
    SquareMatrix<T> matrix;
    for (int r = 0; r < N / 2; ++r) {
	std::vector<T> row;
	for (int c = 0; c < N / 2; ++c)
	    row.push_back(mat[r + R][c + C]);
	matrix.AddRow(row);
    }
    return matrix;
}

template <typename T>
SquareMatrix<T> Strassen<T>::m_add(SquareMatrix<T> C11,
				   SquareMatrix<T> C12,
				   SquareMatrix<T> C21,
				   SquareMatrix<T> C22) {
    std::vector< std::vector<T> > matrix;

    std::vector< std::vector<T> > top = C11.Concatinate(C12).Get();
    for (std::size_t i = 0; i < top.size(); ++i)
	matrix.push_back(top[i]);
    std::vector< std::vector<T> > bottom = C21.Concatinate(C22).Get();
    for (std::size_t i = 0; i < bottom.size(); ++i)
	matrix.push_back(bottom[i]);

    return SquareMatrix<T>(matrix);
}

#endif // ALGORITHM_CHAPTER_4_4_2_STRASSEN_H_
