/*
  Introduction to Algorithms, CLRS
  Chapter 4, Divide and conquer
  Maximum sub array problem
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 14th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_4_MAX_SUB_ARRAY_H_
#define DATA_STRUCTURE_CHAPTER_4_MAX_SUB_ARRAY_H_

#include <vector>

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();

	void MaxSum(const std::vector<T>& V, T& max_sum);

private:
	void m_maxSum(const std::vector<T>& V, T& max_sum, const int& start, const int& end);

	void m_maxCrossSum(const std::vector<T>& V, T& max_sum, const int& start, const int& mid, const int& end);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
void MaxSubArray<T>::MaxSum(const std::vector<T>& V, T& max_sum) {
	return m_maxSum(V, max_sum, 0, V.size() - 1);
}

template <typename T>
void MaxSubArray<T>::m_maxSum(const std::vector<T>& V, T& max_sum, const int& start, const int& end) {
	T   left_sum = 0;
	T   right_sum = 0;
	T   cross_sum = 0;
	
	// If not the non recursive base case.
	if (start < end) {
		const int mid = (start + end) / 2;
		m_maxSum(V, left_sum, start, mid);
		m_maxSum(V, right_sum, mid + 1, end);
		m_maxCrossSum(V, cross_sum, start, mid, end);

		if (left_sum > right_sum && left_sum > cross_sum ) {
			max_sum = left_sum;
		} else if (right_sum > left_sum && right_sum > cross_sum) {
			max_sum = right_sum;
		} else {
			max_sum = cross_sum;			
		}
	}
}

template <typename T>
void MaxSubArray<T>::m_maxCrossSum(const std::vector<T>& V, T& max_sum, const int& start, const int& mid, const int& end) {
	T sum = V[mid];
	T left_sum = V[mid];
	int min = 0;
	for (int i = mid - 1; i >= start; --i) {
		sum += V[i];
		if (sum > left_sum) {
			left_sum = sum;
			min = i;
		}
	}

	sum = V[mid + 1];
	T right_sum = V[mid + 1];
	int max = 0;

	for (int i = mid + 2; i <= end; ++i) {
		sum += V[i];
		if (sum > right_sum) {
			right_sum = sum;
			max = i;
		}
	}

	max_sum = left_sum + right_sum;
}

#endif // DATA_STRUCTURE_CHAPTER_4_MAX_SUB_ARRAY_H_
