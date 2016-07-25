#ifndef ALGORITHMS_CHAPTER4_4_1_MAX_SUB_ARRAY_H_
#define ALGORITHMS_CHAPTER4_4_1_MAX_SUB_ARRAY_H_

#include <vector>

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();

	T Max(const std::vector<T>& V);

private:
	T m_max(const std::vector<T>& V, const int& start, const int& end);
	T m_max_cross(const std::vector<T>& V, const int& start, const int& mid, const int& end);
	T m_find_max(const T& A, const T& B);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
T MaxSubArray<T>::Max(const std::vector<T>& V) {
	return m_max(V, 0, V.size() - 1);
}

template <typename T>
T MaxSubArray<T>::m_max(const std::vector<T>& V, const int& start, const int& end) {
	// Base case for recursion
	if (start == end) {
		return V[start];
	} else {
		const int mid = (start + end) / 2;
		T left_sum = m_max(V, start, mid);
		T right_sum = m_max(V, mid + 1, end);
		T cross_sum = m_max_cross(V, start, mid, end);

		return (m_find_max(left_sum, right_sum), cross_sum);
	}
}

template <typename T>
T MaxSubArray<T>::m_max_cross(const std::vector<T>& V, const int& start, const int& mid, const int& end) {
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

template <typename T>
T MaxSubArray<T>::m_find_max(const T& A, const T& B) {
	return A > B ? A : B;
}

#endif // ALGORITHMS_CHAPTER4_4_1_MAX_SUB_ARRAY_H_

