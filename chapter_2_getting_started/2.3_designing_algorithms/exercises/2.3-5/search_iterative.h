/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Solution for Exersice 2.3-5, Searching an element in a SET, if it is sorted.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016

  Time complexity will be O(log2(n)), because in every recurisive or iterative search,
  half of the SET items will be left alone and search will be done only in the rest half.

  For example SET has 8 elemets, in first iterative search 8 / 2, then 4 / 2 and then 2 / 2 ....
  And therefore time complexity will be O(log2(n)).
 */

#ifndef DATA_STRUCTURE_CHAPTER_2_2_3_5_SEARCH_H_
#define DATA_STRUCTURE_CHAPTER_2_2_3_5_SEARCH_H_

#include "../2.3-4/insertion_sort.h"
#include <vector>

template <typename T>
class Search {
public:
	Search();
	~Search();

	bool Find(const std::vector<T>& V, const T& key);

private:
	bool m_find(const std::vector<T>& V, const T& key, int start, int end);
};

template <typename T>
Search<T>::Search() {}

template <typename T>
Search<T>::~Search() {}

template <typename T>
bool Search<T>::Find(const std::vector<T>& V, const T& key) {
	std::vector<T> set = V;
	InsertionSort<T> sort;
	sort.Sort(set);

	return m_find(set, key, 0, set.size() - 1);
}

template <typename T>
bool Search<T>::m_find(const std::vector<T>& V, const T& key, int start, int end) {
	while (1) {
		if (start == end) {
			if (key == V[start])
				return true;
			else
				return false;
		} else {
			const int mid = (start + end) / 2;
			if (key == V[mid])
				return true;
			else if (key < V[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
}

#endif // DATA_STRUCTURE_CHAPTER_2_2_3_5_SEARCH_H_

