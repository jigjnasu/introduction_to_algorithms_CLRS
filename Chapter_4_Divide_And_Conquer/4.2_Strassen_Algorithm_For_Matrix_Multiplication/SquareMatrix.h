#ifndef ALGORITHM_CHAPTER4_4_2_SQUARE_MATRIX_H_
#define ALGORITHM_CHAPTER4_4_2_SQUARE_MATRIX_H_

/*
  Basic Square matrix class for all the basic operations on a Matrix.
  Like +, - and *.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: August 13th, 2016
*/

#include <vector>
#include <cstdio>

template <typename T>
class SquareMatrix {
public:
    // Default Constructor
    SquareMatrix();
    // Overloaded constructor
    SquareMatrix(const int& size);
    // Overloaded constructor to set the data
    SquareMatrix(const std::vector< std::vector<T> >& matrix);
    // Copy constructor
    SquareMatrix(const SquareMatrix& rhs);
    // Copy assignment operator
    SquareMatrix& operator = (const SquareMatrix& rhs);
    // Destructor	
    ~SquareMatrix();

    // Addition and subtraction of matricies
    SquareMatrix operator + (const SquareMatrix& rhs);
    SquareMatrix operator - (const SquareMatrix& rhs);

    SquareMatrix Concatinate(const SquareMatrix& rhs);

    void AddRow(const std::vector<T>& row);
    int Size() const;
    std::vector< std::vector<T> > Get() const;	
    void Print() const;
	
private:
    std::vector< std::vector<T> > m_matrix;
    int m_size;

    void m_clear();
};

template <typename T>
SquareMatrix<T>::SquareMatrix() : m_size(0) {}

template <typename T>
SquareMatrix<T>::SquareMatrix(const int& size) : m_size(size) {
    for (int r = 0; r < m_size; ++r) {
	std::vector<T> row;
	for (int c = 0; c < m_size; ++c)
	    row.push_back(0);
	m_matrix.push_back(row);
    }
}

template <typename T>
SquareMatrix<T>::SquareMatrix(const std::vector< std::vector<T> >& matrix) {
    for (std::size_t r = 0; r < matrix.size(); ++r) {
	std::vector<T> row;
	for (std::size_t c = 0; c < matrix[r].size(); ++c)
	    row.push_back(matrix[r][c]);
	m_matrix.push_back(row);
    }
}

template <typename T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix& rhs) {
    m_clear();
    for (std::size_t r = 0; r < rhs.m_matrix.size(); ++r) {
	std::vector<T> row;
	for (std::size_t c = 0; c < rhs.m_matrix[r].size(); ++c)
	    row.push_back(rhs.m_matrix[r][c]);
	m_matrix.push_back(row);
    }
}

template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator = (const SquareMatrix& rhs) {
    m_clear();
    for (std::size_t r = 0; r < rhs.m_matrix.size(); ++r) {
	std::vector<T> row;
	for (std::size_t c = 0; c < rhs.m_matrix[r].size(); ++c)
	    row.push_back(rhs.m_matrix[r][c]);
	m_matrix.push_back(row);
    }
    return *this;	
}

    template <typename T>
    SquareMatrix<T>::~SquareMatrix() {}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator + (const SquareMatrix& rhs) {
    SquareMatrix<T> matrix;
    for (std::size_t r = 0; r < m_matrix.size(); ++r) {
	std::vector<T> row;
	for (std::size_t c = 0; c < m_matrix[r].size(); ++c)
	    row.push_back(m_matrix[r][c] + rhs.m_matrix[r][c]);
	matrix.m_matrix.push_back(row);
    }
	
    return matrix;
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator - (const SquareMatrix& rhs) {
    SquareMatrix<T> matrix;
    for (std::size_t r = 0; r < m_matrix.size(); ++r) {
	std::vector<T> row;
	for (std::size_t c = 0; c < m_matrix[r].size(); ++c)
	    row.push_back(m_matrix[r][c] - rhs.m_matrix[r][c]);
	matrix.m_matrix.push_back(row);
    }
	
    return matrix;
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::Concatinate(const SquareMatrix& rhs) {
    std::vector< std::vector<T> > matrix;

    for (std::size_t i = 0; i < m_matrix.size(); ++i) {
	std::vector<T> row;
	for (std::size_t j = 0; j < m_matrix[i].size(); ++j)
	    row.push_back(m_matrix[i][j]);
	for (std::size_t j = 0; j < rhs.m_matrix[i].size(); ++j)
	    row.push_back(rhs.m_matrix[i][j]);
	matrix.push_back(row);
    }

    return SquareMatrix<T>(matrix);
}

template <typename T>
void SquareMatrix<T>::AddRow(const std::vector<T>& row) {
    m_matrix.push_back(row);
}

template <typename T>
int SquareMatrix<T>::Size() const {
    return static_cast<int>(m_matrix.size());
}

template <typename T>
std::vector< std::vector<T> > SquareMatrix<T>::Get() const {
    return m_matrix;
}

template <typename T>
void SquareMatrix<T>::Print() const {
    if (0 == m_matrix.size())
	return;
    printf("--------------------------------------------------------------------\n");
    for (std::size_t r = 0; r < m_matrix.size(); ++r) {
	for (std::size_t c = 0; c < m_matrix[r].size(); ++c)
	    printf("%8d ", m_matrix[r][c]);
	printf("\n");
    }
    printf("--------------------------------------------------------------------\n");	
}

template <typename T>
void SquareMatrix<T>::m_clear() {
    for (std::size_t i = 0; i < m_matrix.size(); ++i)
	m_matrix[i].clear();
}

#endif // ALGORITHM_CHAPTER4_4_2_SQUARE_MATRIX_H_
