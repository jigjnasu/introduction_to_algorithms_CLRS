#ifndef ALGORITHMS_CHAPTER_4_4_2_MORE_PROBLEMS_FIBONACCI_H_
#define ALGORITHMS_CHAPTER_4_4_2_MORE_PROBLEMS_FIBONACCI_H_

#include "SquareMatrix.h"
#include <cstdio>
#include <vector>

const int SIZE = 2;

template <typename T>
class Fibonacci {
public:
    Fibonacci();
    ~Fibonacci();

    void Calculate(const int& N, T (&result)[SIZE][SIZE]);

private:
    SquareMatrix<T, SIZE> m_unity;
    SquareMatrix<T, SIZE> m_null;
	
    SquareMatrix<T, SIZE> m_power(const int& N,
                                  SquareMatrix<T, SIZE> X,
                                  std::vector< SquareMatrix<T, SIZE> >& dictionary);
};

template <typename T>
Fibonacci<T>::Fibonacci() {
    T unity[SIZE][SIZE] = {0};
    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
            if (r == c)
                unity[r][c] = 1;
    m_unity.Set(unity);
	
    T null_matrix[SIZE][SIZE] = {0};
    m_null.Set(null_matrix);
}

template <typename T>
Fibonacci<T>::~Fibonacci() {}

template <typename T>
void Fibonacci<T>::Calculate(const int& N, T (&result)[SIZE][SIZE]) {
    T base_matrix[SIZE][SIZE] = {{1, 1}, {1, 0}};
    SquareMatrix<T, SIZE> X(base_matrix);
	
    std::vector< SquareMatrix<T, SIZE> > dictionary;
    for (int i = 0; i <= N; ++i)
        dictionary.push_back(m_null);
	
    m_power(N, X, dictionary).Get(result);
}

// Divide and conquer technique with cache also called Dynamic programing.
template <typename T>
SquareMatrix<T, SIZE> Fibonacci<T>::m_power(const int& N,
                                            SquareMatrix<T, SIZE> X,
                                            std::vector< SquareMatrix<T, SIZE> >& dictionary) {
    if (dictionary[N] == m_null) {
        if (N == 0) {
            dictionary[0] = m_unity;
            return m_unity;
        } else {
            if (N % 2 == 0) {
                dictionary[N / 2] = m_power(N / 2, X, dictionary);
                return dictionary[N / 2] * dictionary[N / 2];
            } else {
                dictionary[(N - 1) / 2] = m_power((N - 1) / 2, X, dictionary);
                return X * dictionary[(N - 1) / 2] * dictionary[(N - 1) / 2];
            }
        }
    } else {
        return dictionary[N];
    }
}

#endif // ALGORITHMS_CHAPTER_4_4_2_MORE_PROBLEMS_FIBONACCI_H_
