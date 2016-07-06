/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Implementation of Sort, with Merge and Insertion
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 5th, 2016
 */

/*
  Generally, the time complexity of Merge Sort is O(n lg n).
  But in this case, we have ommited the concept of out place merging to insertion sort.
  No need of merging as well.
 */
  
#ifndef DATA_STRUCTURE_CHAPTER_2_SORT_H_
#define DATA_STRUCTURE_CHAPTER_2_SORT_H_

#include <vector>

template <typename T>
class Sort {
public:
	Sort();
	~Sort();

	void sort(std::vector<T>& V);

private:
	void m_sort(std::vector<T>& V, const int& start, const int& end);
	void m_merge(std::vector<T>& V, const int& start, const int& end);
	void m_swap(T& A, T& B);
};

template <typename T>
Sort<T>::Sort() {}

template <typename T>
Sort<T>::~Sort() {}

template <typename T>
void Sort<T>::sort(std::vector<T>& V) {
	m_sort(V, 0, V.size() - 1);
}

template <typename T>
void Sort<T>::m_sort(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = (start + end) / 2;
		m_sort(V, start, mid);
		m_sort(V, mid + 1, end);
		m_merge(V, start, end);
	}
}

template <typename T>
void Sort<T>::m_merge(std::vector<T>& V, const int& start, const int& end) {
	for (int i = start; i <= end; ++i) {
		int j = i;
		while (j > start && V[j - 1] > V[j]) {
			m_swap(V[j - 1], V[j]);
			--j;
		}
	}
}

template <typename T>
void Sort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_CHAPTER_2_SORT_H_

