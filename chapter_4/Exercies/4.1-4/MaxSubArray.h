/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Solution for Exersice 4.1-4, Let's check for an empty sub array, where sum is zero.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 14th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_SUB_ARRAY_H_
#define DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_SUB_ARRAY_H_

#include <vector>

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();

	bool Validate(const std::vector<T>& V);

private:
	bool m_validate(const std::vector<T>& V, const int& start, const int& end);
	bool m_crossValidate(const std::vector<T>& V, const int& start, const int& end);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
bool MaxSubArray<T>::Validate(const std::vector<T>& V) {
	return m_validate(V, 0, V.size() - 1);
}

template <typename T>
bool MaxSubArray<T>::m_validate(const std::vector<T>& V, const int& start, const int& end) {
	if (start == end) {
		if (V[start] == 0)
			return false;
	} else {
		const int mid = (start + end) / 2;

		// Check for the left part for sub array as sum as zero.
		if (!m_validate(V, start, mid))
			return false;

		// Check for the right part for sub array as sum as zero.
		if (!m_validate(V, mid + 1, end))
			return false;

		// Check for the cross portion of the set for sub array as sum as zero.
		if (!m_crossValidate(V, start, end))
			return false;
	}
	
	return true;
}

template <typename T>
bool MaxSubArray<T>::m_crossValidate(const std::vector<T>& V, const int& start, const int& end) {
	T sum = V[start];
	for (int i = start + 1; i <= end; ++i ) {
		sum += V[i];
		if (0 == sum)
			return false;
	}

	return true;
}

#endif // DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_SUB_ARRAY_H_
