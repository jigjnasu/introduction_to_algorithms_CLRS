/*
  Introduction to algorithms, CLRS
  Chapter 4: Divide and conquer
  Solution for Exersice 4.1-3, Max Sub Array recursive problem and Brute Force problem.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 14th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_4_4_1_3_MAX_SUB_ARRAY_H_
#define DATA_STRUCTURE_CHAPTER_4_4_1_3_MAX_SUB_ARRAY_H_

#include <vector>

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();
	
	T MaxBruteForce(const std::vector<T>& V);
	T MaxIterative(const std::vector<T>& V);

private:
	T m_maxIterative(const std::vector<T>& V, const int& start, const int& end);
	T m_maxCross(const std::vector<T>& V, const int& start, const int& mid, const int& end);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
T MaxSubArray<T>::MaxBruteForce(const std::vector<T>& V) {
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

template <typename T>
T MaxSubArray<T>::MaxIterative(const std::vector<T>& V) {
	return m_maxIterative(V, 0, V.size() - 1);
}

template <typename T>
T MaxSubArray<T>::m_maxIterative(const std::vector<T>& V, const int& start, const int& end) {
	T left_sum = 0;
	T right_sum = 0;
	T cross_sum = 0;
	
	if (start == end) {
		return V[start];
	} else {
		const int mid = (start + end) / 2;

		// Get the max sub array sum of left portion of the set.
		left_sum = m_maxIterative(V, start, mid);

		// Get the max sub array sum of right portion of the set.
		right_sum = m_maxIterative(V, mid + 1, end);

		// Get the max sub array sum of cross over from start ... mid && mid + 1 .... end
		cross_sum = m_maxCross(V, start, mid, end);

		if (left_sum > right_sum && left_sum > cross_sum)
			return left_sum;
		else if (right_sum > left_sum && right_sum > cross_sum)
			return right_sum;
		else
			return cross_sum;
	}
}

template <typename T>
T MaxSubArray<T>::m_maxCross(const std::vector<T>& V, const int& start, const int& mid, const int& end) {
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



#endif // DATA_STRUCTURE_CHAPTER_4_4_1_3_MAX_SUB_ARRAY_H_
