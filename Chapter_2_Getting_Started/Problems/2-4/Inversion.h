#ifndef DATA_STRUCTURE_CHAPTER_2_PROBLEMS_2_4_INVERSION_H_
#define DATA_STRUCTURE_CHAPTER_2_PROBLEMS_2_4_INVERSION_H_

/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Problem 2-4 d, Inverse counting with Divide and Conquer, which takes n lg n time.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 14th, 2016
*/


/*
  Problem 2-4, d
  Give an algorithm that determines the number of inversions in any permutation
  on n elements in O(n lg n)/ worst-case time. (Hint: Modify merge sort.)
 */

#include <vector>

template <typename T>
class Inversion {
public:
	Inversion();
	~Inversion();

	int Count(std::vector<T>& V);

private:
	int m_count(std::vector<T>& V, const int& start, const int& end);
	int m_inversion_count(std::vector<T>& V, const int& start, const int& mid, const int& end);
};

template <typename T>
Inversion<T>::Inversion() {}

template <typename T>
Inversion<T>::~Inversion() {}

template <typename T>
int Inversion<T>::Count(std::vector<T>& V) {
	return m_count(V, 0, V.size() - 1);
}

template <typename T>
int Inversion<T>::m_count(std::vector<T>& V, const int& start, const int& end) {
	int count = 0;
	if (start < end) {
		const int mid = (start + end) / 2;
		count += m_count(V, start, mid);
		count += m_count(V, mid + 1, end);
		count += m_inversion_count(V, start, mid, end);
	} else {
		return 0;
	}
	
	return count;
}

template <typename T>
int Inversion<T>::m_inversion_count(std::vector<T>& V, const int& start, const int& mid, const int& end) {
	int count = 0;
	std::vector<T> left;
	std::vector<T> right;

	for (int i = start; i <= mid; ++i)
		left.push_back(V[i]);
	for (int i = mid + 1; i <= end; ++i)
		right.push_back(V[i]);

	int iter = start;
	int left_iter = 0;
	int right_iter = 0;
	
	while (left_iter < left.size() && right_iter < right.size()) {
		if (left[left_iter] < right[right_iter]) {
			V[iter++] = left[left_iter++];
		} else {
			count += left.size() - left_iter;
			V[iter++] = right[right_iter++];
		}
	}

	while (left_iter < left.size())
		V[iter++] = left[left_iter++];
	while (right_iter < right.size())
		V[iter++] = right[right_iter++];

	return count;
}

#endif // DATA_STRUCTURE_CHAPTER_2_PROBLEMS_2_4_INVERSION_H_
