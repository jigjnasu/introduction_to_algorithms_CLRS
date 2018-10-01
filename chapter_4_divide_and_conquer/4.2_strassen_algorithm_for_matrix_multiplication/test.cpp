#include "matrix.h"
#include "matrix_divide_and_conquer.h"
#include "square_matrix.h"
#include "strassen.h"
#include <cstdio>
#include <vector>
#include <chrono>

template <std::size_t size>
void print_matrix(const int (&matrix)[size][size]) {
    printf("--------------------------------------------------------------------------------\n");
    for (std::size_t r = 0; r < size; ++r) {
	for (std::size_t c = 0; c < size; ++c) {
	    printf("%8d  ", matrix[r][c]);
	}
	printf("\n");
    }
    printf("--------------------------------------------------------------------------------\n");
}

std::vector<int> get_row(const int& start, const int& n) {
    std::vector <int> row;
    for (int i = 0; i <  n; ++i) {
	row.push_back(start + i);
    }

    return row;
}

template <std::size_t size>
void get_data(const int& start, int (&R)[size][size]) {
    for (int i = 0; i < size * size; ++i)
	*(&R[0][0] + i) = i + start;
}

void test_normal_2() {
    const int n = 2;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    Matrix<int, n, n, n, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}

void test_normal_4() {
    const int n = 4;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    Matrix<int, n, n, n, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}

void test_normal_8() {
    const int n = 8;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    Matrix<int, n, n, n, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}

void test_normal_16() {
    const int n = 16;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    Matrix<int, n, n, n, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}

void test_dnc_2() {
    const int n = 2;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    MatrixDC<int, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}

void test_dnc_4() {
    const int n = 4;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    MatrixDC<int, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}

void test_dnc_8() {
    const int n = 8;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    MatrixDC<int, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}

void test_dnc_16() {
    const int n = 16;
    int A[n][n] = {0};
    int B[n][n] = {0};
    int C[n][n] = {0};
    get_data(1, A);
    get_data((n * n) + 1, B);

    print_matrix(A);
    print_matrix(B);
    MatrixDC<int, n> matrix;
    matrix.Multiply(A, B, C);
    print_matrix(C);
}


void test_strassen(const int& N) {
    std::vector< std::vector<int> > VA;
    for (int i = 0; i < N; ++i)
	VA.push_back(get_row((i * N) + 1, N));

    SquareMatrix<int> A(VA);
    std::vector< std::vector<int> > VB;

    for (int i = N; i < N + N; ++i)
	VB.push_back(get_row((i * N) + 1, N));

    SquareMatrix<int> B(VB);

    A.Print();
    B.Print();

    Strassen<int> strassen;
    SquareMatrix<int> C = strassen.Multiply(A, B);
    C.Print();
}

void test_case_normal() {
    test_normal_2();
    test_normal_4();
    test_normal_8();
    test_normal_16();
}

void test_case_divide_and_conquer() {
    test_dnc_2();
    test_dnc_4();
    test_dnc_8();
    test_dnc_16();
}

void test_case_strassen() {
    for (int i = 2; i <= 16; i *= i)
	test_strassen(i);
}

void test_case() {
    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    test_case_normal();
    const double normal_time = std::chrono::duration<double>(clock::now() - start).count();
    start = clock::now();
    test_case_divide_and_conquer();
    const double dnc_time = std::chrono::duration<double>(clock::now() - start).count();
    start = clock::now();
    test_case_strassen();
    const double strassen_time = std::chrono::duration<double>(clock::now() - start).count();

    printf("Normal              execution time == [%16lf]\n", normal_time);
    printf("Divide and Concquer execution time == [%16lf]\n", dnc_time);
    printf("Strassen            execution time == [%16lf]\n", strassen_time);
}

int main() {
    test_case();
    return 0;
}
