/*
  Introduction to algorithms
  Chapter 2: Getting started
  Exersice 2.2-2, Implement a slection sort.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

/*
  The main loop will run from 1 to n - 1, because the last item standing,
  will be the highest number.

  Let's say best case is, V is sorted.
  Time Complexity will be N ^ 2, because it will for for i to N - 1, to get the smallest positional number

  Worst Case will be same as N ^ 2 as well.
 */

/*
  2.2-2
  Consider sorting n numbers stored in array A by first finding the smallest element
  of A and exchanging it with the element in A[1]. Then find the second smallest
  element of A, and exchange it with A[2]. Continue in this manner for the first n - 1
  elements of A. Write pseudocode for this algorithm, which is known as selection
  sort. What loop invariant does this algorithm maintain? Why does it need to run
  for only the first n - 1 elements, rather than for all n elements? Give the best-case
  and worst-case running times of selection sort in ‚-notation.
 */

#ifndef DATA_STRUCTURE_CHAPTER_2_2_2_2_SELECTION_SORT_H_
#define DATA_STRUCTURE_CHAPTER_2_2_2_2_SELECTION_SORT_H_

#include <cstdio>
#include <vector>

template <typename T>
class SelectionSort {
public:
	SelectionSort();
	~SelectionSort();

	void Sort(std::vector<T>& V);

private:
	int m_findMin(const std::size_t& start, const std::vector<T>& V);
	void m_swap(T& A, T& B);
};

template <typename T>
SelectionSort<T>::SelectionSort() {}

template <typename T>
SelectionSort<T>::~SelectionSort() {}

template <typename T>
void SelectionSort<T>::Sort(std::vector<T>& V) {
	for (std::size_t i = 0; i < V.size() - 1; ++i) {
		const int index = m_findMin(i, V);
		if (i != index)
			m_swap(V[i], V[index]);
	}
}

template <typename T>
int SelectionSort<T>::m_findMin(const std::size_t& start, const std::vector<T>& V) {
	int index = start;
	T min = V[start];
	for (std::size_t i = start + 1; i < V.size(); ++i) {
		if (V[i] < min) {
			min = V[i];
			index = i;
		}
	}

	return index;
}

template <typename T>
void SelectionSort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_CHAPTER_2_2_2_2_SELECTION_SORT_H_
