/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Solution for Exersice 4.1-4, Modify Max Sub Array to identify does the max array == 0
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 15th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_EMPTY_ARRAY_H_
#define DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_EMPTY_ARRAY_H_

#include <cstdio>
#include <vector>

template <typename T>
class MaxEmptyArray {
public:
	MaxEmptyArray();
	~MaxEmptyArray();

	T MaxSum(const std::vector<T>& V);

private:
	T m_maxSum(const std::vector<T>& V, const int& start, const int& end);
	T m_crossSum(const std::vector<T>& V, const int& start, const int& mid, const int& end);
};

template <typename T>
MaxEmptyArray<T>::MaxEmptyArray() {}

template <typename T>
MaxEmptyArray<T>::~MaxEmptyArray() {}

template <typename T>
T MaxEmptyArray<T>::MaxSum(const std::vector<T>& V) {
	const T sum = m_maxSum(V, 0, V.size() - 1);
	if (sum) {
		return sum;
	} else {
		printf("The max sub array is empty and therefore can't return a valid result\n");
		return -99;
	}
}

template <typename T>
T MaxEmptyArray<T>::m_maxSum(const std::vector<T>& V, const int& start, const int& end) {
	T left_sum = 0;
	T right_sum = 0;
	T cross_sum = 0;
	
	if (start == end) {
		return V[start];
	} else {
		const int mid = (start + end) / 2;

		// Max sub array from left part of the set.
		left_sum = m_maxSum(V, start, mid);

		// Max sub array from right part of the set.
		right_sum = m_maxSum(V, mid + 1, end);

		// Max sub array from across the set from start to end.
		cross_sum = m_crossSum(V, start, mid, end);

		if (left_sum > right_sum && left_sum > cross_sum)
			return left_sum;
		else if (right_sum > left_sum && right_sum > cross_sum)
			return right_sum;
		else
			return cross_sum;
	}
}

template <typename T>
T MaxEmptyArray<T>::m_crossSum(const std::vector<T>& V, const int& start, const int& mid, const int& end) {
	T left_sum = V[mid];
	T sum = V[mid];

	for (int i = mid - 1; i >= start; --i) {
		sum += V[i];
		if (sum > left_sum)
			left_sum = sum;
	}

	T right_sum = V[mid + 1];
	sum = V[mid + 1];
	for (int i = mid + 2; i <= end; ++i) {
		sum += V[i];
		if (sum > right_sum)
			right_sum = sum;
	}

	return left_sum + right_sum;
}

#endif // DATA_STRUCTURE_CHAPTER_4_4_1_4_MAX_EMPTY_ARRAY_H_
