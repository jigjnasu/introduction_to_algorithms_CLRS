#ifndef ALGORITHMS_CHAPTER_4_4_2_MORE_PROBLEMS_SQUARE_MATRIX_H_
#define ALGORITHMS_CHAPTER_4_4_2_MORE_PROBLEMS_SQUARE_MATRIX_H_

#include <cstring>
#include <cstdio>

template <typename T, int size>
    class SquareMatrix {
public:
    SquareMatrix();
    SquareMatrix(const T matrix[size][size]);
    ~SquareMatrix();
    // copy constructor
    SquareMatrix(const SquareMatrix& mat);
    // copy assignment
    SquareMatrix& operator = (const SquareMatrix& rhs);
    SquareMatrix operator * (const SquareMatrix& rhs);
    bool operator == (const SquareMatrix& rhs);

    void Set(const T (&matrix)[size][size]);
    void Get(T (&result)[size][size]);
    void Print() const;

private:
    T m_data[size][size];

    T m_multiply(const int& N, const int& I, const int& j,
                 const T (&RHS)[size][size], T (&R)[size][size]);
};

template <typename T, int size>
    SquareMatrix<T, size>::SquareMatrix() {
    memset(&m_data[0][0], 0, sizeof(T) * size * size);
}

template <typename T, int size>
    SquareMatrix<T, size>::SquareMatrix(const T matrix[size][size]) {
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            m_data[r][c] = matrix[r][c];
}

template <typename T, int size>
    SquareMatrix<T,	size>::~SquareMatrix() {}

// copy constructor
template <typename T, int size>
    SquareMatrix<T, size>::SquareMatrix(const SquareMatrix& mat) {
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            m_data[r][c] = mat.m_data[r][c];
}

// copy assignment operator
template <typename T, int size>
    SquareMatrix<T, size>& SquareMatrix<T, size>::operator = (const SquareMatrix& rhs) {
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            m_data[r][c] = rhs.m_data[r][c];
    return *this;
}

// matrix multiplication
    template <typename T, int size>
    SquareMatrix<T, size> SquareMatrix<T, size>::operator * (const SquareMatrix& rhs) {
        T R[size][size] = {0};
        m_multiply(size, 0, 0, rhs.m_data, R);
        return SquareMatrix(R);
    }

// comparission matrix operator
template <typename T, int size>
        bool SquareMatrix<T, size>::operator == (const SquareMatrix& rhs) {
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            if (m_data[r][c] != rhs.m_data[r][c])
                return false;
    return true;
}

template <typename T, int size>
        void SquareMatrix<T, size>::Set(const T (&matrix)[size][size]) {
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            m_data[r][c] = matrix[r][c];
}

template <typename T, int size>
    void SquareMatrix<T, size>::Get(T (&result)[size][size]) {
    for (int r = 0; r < size; ++r)
        for (int c = 0; c < size; ++c)
            result[r][c] = m_data[r][c];
}

// Print the matrix
template <typename T, int size>
    void SquareMatrix<T, size>::Print() const {
    printf("----------------------------------------------------------------------------------\n");
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c)
            printf("%8d ", m_data[r][c]);
        printf("\n");
    }
    printf("----------------------------------------------------------------------------------\n");	
}

//Divide and conquer matrix multiplication implementation
template <typename T, int size>
    T SquareMatrix<T, size>::m_multiply(const int& N, const int& I, const int& J,
                                        const T (&RHS)[size][size], T (&R)[size][size]) {
    if (N == 1) {
        return *(&m_data[0][0] + I) * *(&RHS[0][0] + J);
    } else {
        const int H = N / 2;
        const int O = H * size;
	
        const int r = I / size;
        const int c = J % size;
        R[r][c] += m_multiply(H, I, J, RHS, R) + m_multiply(H, I + H, J + O, RHS, R);
        R[r][c + H] += m_multiply(H, I, J + H, RHS, R) + m_multiply(H, I + H, J + O + H, RHS, R);
        R[r + H][c] += m_multiply(H, I + O, J, RHS, R) + m_multiply(H, I + O + H, J + O, RHS, R);
        R[r + H][c + H] += m_multiply(H, I + O, J + H, RHS, R) + m_multiply(H, I + O + H, J + O + H, RHS, R);
    }
	
    return 0;
}

#endif // ALGORITHMS_CHAPTER_4_4_2_MORE_PROBLEMS_SQUARE_MATRIX_H_
