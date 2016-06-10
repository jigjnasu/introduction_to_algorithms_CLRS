/*
  Common functions for the rest of the code.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#ifndef DATA_STRUCTURE_COMMON_H_
#define DATA_STRUCTURE_COMMON_H_

#include <iostream>
#include <vector>

template <typename T>
class Common {
public:
	Common();
	~Common();

	void PrintVector(const std::vector<T>& V);
	void PrintVectorReverse(const std::vector<T>& V);
};

template <typename T>
Common<T>::Common() {}

template <typename T>
Common<T>::~Common() {}

template <typename T>
void Common<T>::PrintVector(const std::vector<T>& V) {
	for (std::size_t i = 0; i < V.size(); ++i)
		std::cout << V[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void Common<T>::PrintVectorReverse(const std::vector<T>& V) {
	for (int i = V.size() - 1; i >= 0; --i)
		std::cout << V[i] << " ";
	std::cout << std::endl;
}

#endif // DATA_STRUCTURE_COMMON_H_
