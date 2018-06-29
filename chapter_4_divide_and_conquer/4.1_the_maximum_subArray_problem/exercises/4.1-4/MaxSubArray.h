#ifndef ALGORITHMS_CHAPTER_4_4_1_4_MAX_SUBARRAY_H_
#define ALGORITHMS_CHAPTER_4_4_1_4_MAX_SUBARRAY_H_

#include <vector>

enum ERROR_CODES {
	ERROR   = 0x0000,
	SUCCESS = 0x0001,
};

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();

	ERROR_CODES Max(const std::vector<T>& V, T& max_sum);

private:
	ERROR_CODES m_max(const std::vector<T>& V, T& max_sum, const int& start, const int& end);
	ERROR_CODES m_cross_max(const std::vector<T>& V, T& max_sum, const int& start, const int& mid, const int& end);

	T m_find_max(const T& A, const T& B);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
ERROR_CODES MaxSubArray<T>::Max(const std::vector<T>& V, T& max_sum) {
	return m_max(V, max_sum, 0, V.size() - 1);
}

template <typename T>
ERROR_CODES MaxSubArray<T>::m_max(const std::vector<T>& V, T& max_sum, const int& start, const int& end) {
	if (start == end) {
		if (V[start]) {
			max_sum = V[start];
			return SUCCESS;
		} else {
			return ERROR;
		}		
	} else {
		const int mid = (start + end) / 2;

		T left_max_sum = 0;
		T right_max_sum = 0;
		T cross_max_sum = 0;
		
		m_max(V, left_max_sum, start, mid);
		m_max(V, right_max_sum, mid + 1, end);
		if (m_cross_max(V, cross_max_sum, start, mid, end)) {
			max_sum = m_find_max(m_find_max(left_max_sum, right_max_sum), cross_max_sum);
			return SUCCESS;
		} else {
			return ERROR;
		}
	}
}

template <typename T>
ERROR_CODES MaxSubArray<T>::m_cross_max(const std::vector<T>& V, T& max_sum, const int& start, const int& mid, const int& end) {
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

	max_sum = left_sum + right_sum;

	if (max_sum == 0)
		return ERROR;
	else
		return SUCCESS;
}

template <typename T>
T MaxSubArray<T>::m_find_max(const T& A, const T& B) {
	return A > B ? A : B;
}

#endif // ALGORITHMS_CHAPTER_4_4_1_4_MAX_SUBARRAY_H_
