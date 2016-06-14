/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Solution for Exersice 4.1-2
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 14th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_4_4_1_2_MAX_SUB_ARRAY_H_
#define DATA_STRUCTURE_CHAPTER_4_4_1_2_MAX_SUB_ARRAY_H_

#include <vector>

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();

	T MaxSum(const std::vector<T>& V);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
T MaxSubArray<T>::MaxSum(const std::vector<T>& V) {
	T max_sum = V[0];
	for (std::size_t i = 0; i < V.size(); ++i) {
		T sum = V[i];
		for (std::size_t j = i + 1; j < V.size(); ++j) {
			sum += V[j];
			if (sum > max_sum)
				max_sum = sum;
		}
	}

	return max_sum;
}

#endif // DATA_STRUCTURE_CHAPTER_4_4_1_2_MAX_SUB_ARRAY_H_
