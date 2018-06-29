/*
  Introduction to algorithms
  Chapter 2, Getting Started
  Solution for Exersice 2.1-4, adding two n-bit array numbers
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "Add.h"
#include "../../../Common/Common.h"

class Bits {
public:
	Bits();
	~Bits();

	void GetBits(std::vector<int>& number, const int& N);
	int GetNumber(const std::vector<int>& bits);
};


Bits::Bits() {}

Bits::~Bits() {}

void Bits::GetBits(std::vector<int>& number, const int& N) {
	for (int i = 0; i < 7; ++i)
		if (N & 1 << i)
			number.push_back(1);
		else
			number.push_back(0);
}

int Bits::GetNumber(const std::vector<int>& bits) {
	int number = 0;
	for (std::size_t i = 0; i < bits.size(); ++i)
		if (bits[i])
			number += 1 << i;

	return number;
}

int main() {
	Bits bits;
	std::vector<int> A;
	std::vector<int> B;
	
	bits.GetBits(A, 118);
	bits.GetBits(B, 79);

	Common<int> common;
	printf("------------ A && B ----------------\n");
	common.PrintVectorReverse(A);
	common.PrintVectorReverse(B);
	printf("------------ A && B ----------------\n");

	Add<int> add;
	std::vector<int> C;
	add.AddBits(A, B, C);
	printf("------------    C   ----------------\n");
	common.PrintVectorReverse(C);
	printf("C in decimal == [%d]\n", bits.GetNumber(C));
	printf("------------    C   ----------------\n");
		
	return 0;
}
