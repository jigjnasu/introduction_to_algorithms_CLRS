#ifndef DATA_STRUCTURE_MAX_SUBARRAY_H_
#define DATA_STRUCTURE_MAX_SUBARRAY_H_

#include <vector>

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();

	void FindMaxSubArray(const std::vector<T>& V, int& sum);

private:
	void m_findMaxSubArray(const std::vector<T>& V,
						   const int& low,
						   const int& high,
						   int& sum);

	void m_findMaxCrossSubArray(const std::vector<T>& V,
								const int& low,
								const int& mid,
								const int& high,
								int& sum);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
void MaxSubArray<T>::FindMaxSubArray(const std::vector<T>& V, int& sum) {
	m_findMaxSubArray(V, 0, V.size() - 1, sum);
}

template <typename T>
void MaxSubArray<T>::m_findMaxSubArray(const std::vector<T>& V,
									   const int& low, const int& high, int& sum) {
	int left_sum = 0;
	int right_sum = 0;
	int cross_sum = 0;

	if (low != high) {
		const int mid = (low + high) >> 1;
		m_findMaxSubArray(V, low, mid, left_sum);
		m_findMaxSubArray(V, mid + 1, high, right_sum);
		m_findMaxCrossSubArray(V, low, mid, high, cross_sum);

		if (left_sum > right_sum && left_sum > cross_sum)
			sum = left_sum;
		else if (right_sum > left_sum && right_sum > cross_sum)
			sum = right_sum;
		else
			sum = cross_sum;
	}
}

template <typename T>
void MaxSubArray<T>::m_findMaxCrossSubArray(const std::vector<T>& V, const int& low,
											const int& mid, const int& high, int& sum) {
	int left_sum = V[mid];
	int right_sum = V[mid + 1];

	int s = 0;
	for (int i = mid; i >= low; --i) {
		s += V[i];
		if (s > left_sum) {
			left_sum = s;
		}
	}

	s = 0;
	for (int i = mid + 1; i <= high; ++i) {
		s += V[i];
		if (s > right_sum) {
			right_sum = s;
		}
	}

	sum = left_sum + right_sum;
}

#endif // DATA_STRUCTURE_MAX_SUBARRAY_H_
