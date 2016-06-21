/*
  Introduction to algorithms
  Chapter 2, Getting Started
  Exersice 2.1-4, adding two n-bit array numbers
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

/*
  2.1-4
  Consider the problem of adding two n-bit binary integers, stored in two n-element
  arrays A and B. The sum of the two integers should be stored in binary form in
  an .n C 1/-element array C. State the problem formally and write pseudocode for
  adding the two integers
 */

#include <vector>
#include <cstdio>

#ifndef DATA_STRUCTURE_CHAPTER_2_2_1_4_ADD_H_
#define DATA_STRUCTURE_CHAPTER_2_2_1_4_ADD_H_

template <typename T>
class Add {
public:
	Add();
	~Add();

	void AddBits(const std::vector<T>& A,
				 const std::vector<T>& B,
				 std::vector<T>& C);

private:
	int m_countOnes(const int& A, const int& B, const int& C);
};

template <typename T>
Add<T>::Add() {}

template <typename T>
Add<T>::~Add() {}

template <typename T>
void Add<T>::AddBits(const std::vector<T>& A,
					 const std::vector<T>& B,
					 std::vector<T>& C) {
	if (A.size() != B.size()) {
		printf("Need to add equal elements\n");
		return;
	}

	bool carry = false;
	for (std::size_t i = 0; i < A.size(); ++i) {
		const int count = m_countOnes(A[i], B[i], carry);
		C.push_back(count % 2);
		carry = count / 2;
	}

	if (carry)
		C.push_back(1);
}

template <typename T>
int Add<T>::m_countOnes(const int& A, const int& B, const int& C) {
	int count = 0;
	if (A) ++count;
	if (B) ++count;
	if (C) ++count;

	return count;
}

#endif // DATA_STRUCTURE_CHAPTER_2_2_1_4_ADD_H_
