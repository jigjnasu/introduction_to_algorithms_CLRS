/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Solution for Exersice 4.1-4, Let's check for an empty sub array, where sum is zero.
  Using the bottom up approach or brute force, Time complexity O(n ^ 2).
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 14th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_BRUTE_H_
#define DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_BRUTE_H_

#include <vector>

template <typename T>
class MaxBrute {
public:
	MaxBrute();
	~MaxBrute();

	bool Validate(const std::vector<T>& V);
};

template <typename T>
MaxBrute<T>::MaxBrute() {}

template <typename T>
MaxBrute<T>::~MaxBrute() {}

template <typename T>
bool MaxBrute<T>::Validate(const std::vector<T>& V) {
	for (std::size_t i = 0; i < V.size(); ++i) {
		T sum = V[i];
		for (std::size_t j = i + 1; j < V.size(); ++j) {
			sum += V[j];
			if (0 == sum)
				return false;
		}
	}
	
	return true;
}


#endif // DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_BRUTE_H_
