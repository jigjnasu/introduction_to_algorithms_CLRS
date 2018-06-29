#ifndef ALGORITHMS_CHAPTER_4_4_1_5_MAX_SUB_ARRAY_H_
#define ALGORITHMS_CHAPTER_4_4_1_5_MAX_SUB_ARRAY_H_

#include <vector>
#include <cstdio>

template <typename T>
class MaxSubArray {
public:
	MaxSubArray();
	~MaxSubArray();

	T Max(const std::vector<T>& V);
};

template <typename T>
MaxSubArray<T>::MaxSubArray() {}

template <typename T>
MaxSubArray<T>::~MaxSubArray() {}

template <typename T>
T MaxSubArray<T>::Max(const std::vector<T>& V) {
	T max_sum = V[0];
	T sum = V[0];
	int iter = 1;
	while (V[0] <= 0) {
		if (V[iter] <= 0) {
			if (V[iter] > max_sum)
				max_sum = V[iter];
			sum = V[iter++];			
		} else {
			max_sum = sum = V[iter++];
			break;
		}
		
		if (iter >= V.size())
			break;
	}

	while (iter < V.size()) {
		const int temp = V[iter] + sum;

		if (temp <= 0) {
			sum = V[iter];

			if (V[iter] > max_sum)
				max_sum = V[iter];
		} else {
			if (sum > 0)
				sum = temp;
			else
				sum = V[iter];

			if (sum > max_sum)
				max_sum = sum;
		}

		++iter;
	}

	return max_sum;	
}

#endif // ALGORITHMS_CHAPTER_4_4_1_5_MAX_SUB_ARRAY_H_
