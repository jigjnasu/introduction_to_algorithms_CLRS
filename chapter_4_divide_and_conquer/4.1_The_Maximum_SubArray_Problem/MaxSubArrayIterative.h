#ifndef ALGORITHMS_CHAPTER4_4_1_MAX_SUB_ARRAY_ITERATIVE_H_
#define ALGORITHMS_CHAPTER4_4_1_MAX_SUB_ARRAY_ITERATIVE_H_

#include <vector>

template <typename T>
class MaxSubArrayIterative {
public:
	MaxSubArrayIterative();
	~MaxSubArrayIterative();

	void Max(const std::vector<T>& V, T& sum, int& start, int& end);
};

template <typename T>
MaxSubArrayIterative<T>::MaxSubArrayIterative() {}

template <typename T>
MaxSubArrayIterative<T>::~MaxSubArrayIterative() {}

template <typename T>
void MaxSubArrayIterative<T>::Max(const std::vector<T>& V, T& sum, int& start, int& end) {
	for (std::size_t i = 0; i < V.size(); ++i) {
		T max = 0;
		for (std::size_t j = i; j < V.size(); ++j) {
			max += V[j];
			if (max > sum) {
				sum = max;
				start = i;
				end = j;
			}
		}
	}
}

#endif // ALGORITHMS_CHAPTER4_4_1_MAX_SUB_ARRAY_ITERATIVE_H_
