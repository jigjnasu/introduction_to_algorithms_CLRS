/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Implementation of Sort, with Merge and Selction
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 7th, 2016
 */

/*
  Generally, the time complexity of Merge Sort is O(n lg n).
  But in this case, we have ommited the concept of out place merging to selction sort.
  No need of merging as well.
 */

#ifndef DATA_STRUCTURE_CHAPTER_2_SELECTION_MERGE_H_
#define DATA_STRUCTURE_CHAPTER_2_SELECTION_MERGE_H_

#include <vector>

template <typename T>
class SelectionMerge {
public:
	SelectionMerge();
	~SelectionMerge();

	void Sort(std::vector<T>& V);

private:
	void m_sort(std::vector<T>& V, const int& start, const int& end);
	void m_merge(std::vector<T>& V, const int& start, const int& end);
	int m_find_min(const std::vector<T>& V, const int& start_index, const int& end_index);
	void m_swap(T& A, T& B);
};

template <typename T>
SelectionMerge<T>::SelectionMerge() {}

template <typename T>
SelectionMerge<T>::~SelectionMerge() {}

template <typename T>
void SelectionMerge<T>::Sort(std::vector<T>& V) {
	m_sort(V, 0, V.size() - 1);
}

template <typename T>
void SelectionMerge<T>::m_sort(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = (start + end) / 2;
		m_sort(V, start, mid);
		m_sort(V, mid + 1, end);
		m_merge(V, start, end);
	}
}

template <typename T>
void SelectionMerge<T>::m_merge(std::vector<T>& V, const int& start, const int& end) {
	for (int i = start; i <= end; ++i) {
		int index = m_find_min(V, i, end);
		if (index != i)
			m_swap(V[i], V[index]);
	}
}

template <typename T>
int SelectionMerge<T>::m_find_min(const std::vector<T>& V, const int& start_index, const int& end_index) {
	int index = start_index;
	int min = V[index];
	for (int i = index + 1; i <= end_index; ++i) {
		if (V[i] < min) {
			min = V[i];
			index = i;
		}
	}

	return index;
}

template <typename T>
void SelectionMerge<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_CHAPTER_2_SELECTION_MERGE_H_
