/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Solution for Exersice 2.3-2, Merge sort without sentinal
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 11th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_2_2_3_2_MERGE_SORT_H_
#define DATA_STRUCTURE_CHAPTER_2_2_3_2_MERGE_SORT_H_

#include <vector>

template <typename T>
class MergeSort {
public:
	MergeSort();
	~MergeSort();

	void Sort(std::vector<T>& V);
	
private:
	void m_sort(std::vector<T>& V, const int& start, const int& end);
	void m_merge(std::vector<T>& V, const int& start, const int& mid, const int& end);
};

template <typename T>
MergeSort<T>::MergeSort() {}

template <typename T>
MergeSort<T>::~MergeSort() {}

template <typename T>
void MergeSort<T>::Sort(std::vector<T>& V) {
	m_sort(V, 0, V.size() - 1);
}

template <typename T>
void MergeSort<T>::m_sort(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = (start + end) / 2;
		m_sort(V, start, mid);
		m_sort(V, mid + 1, end);
		m_merge(V, start, mid, end);
	}
}

template <typename T>
void MergeSort<T>::m_merge(std::vector<T>& V, const int& start, const int& mid, const int& end) {
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
		if (left[left_iter] < right[right_iter])
			V[iter++] = left[left_iter++];
		else
			V[iter++] = right[right_iter++];
	}

	while (left_iter < left.size())
		V[iter++] = left[left_iter++];

	while (right_iter < right.size())
		V[iter++] = right[right_iter++];
}

#endif // DATA_STRUCTURE_CHAPTER_2_2_3_2_MERGE_SORT_H_
