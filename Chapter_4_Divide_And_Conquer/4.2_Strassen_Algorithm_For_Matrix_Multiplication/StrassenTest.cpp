#include "SquareMatrix.h"
#include "Strassen.h"
#include <cstdio>
#include <vector>

std::vector<int> get_row(const int& start, const int& n) {
	std::vector <int> row;
	for (int i = 0; i <  n; ++i) {
		row.push_back(start + i);
	}
	
	return row;
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

void test_case() {
	for (int i = 2; i <= 16; i *= i) {
		printf("---------------------------------- Test Case for [%d] -------------------------------------------\n", i);
		test_strassen(i);
		printf("---------------------------------- Test Case for [%d] -------------------------------------------\n\n\n\n\n\n", i);		
	}
}

int main() {
	test_case();
	
	return 0;
}
