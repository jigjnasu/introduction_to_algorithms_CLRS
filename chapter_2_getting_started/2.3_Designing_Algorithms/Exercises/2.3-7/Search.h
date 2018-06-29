/*
  Introduction to algorithms, CSLR
  Chapter:2, Getting Started.
  Solution for Exersice 2.3-7, Search a set for two elements have sum of an element
  with Time Complexity as O(log2(n)).

  As the algorithm searchs the sum in half and therefore it is N * LOG2(N) time complexity.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  June 14th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_2_2_3_7_SEARCH_H_
#define DATA_STRUCTURE_CHAPTER_2_2_3_7_SEARCH_H_

#include <vector>

template <typename T>
class Search {
public:
	Search();
	~Search();

	bool Find(const std::vector<T>& V, const T& sum);
};

template <typename T>
Search<T>::Search() {}

template <typename T>
Search<T>::~Search() {}

template <typename T>
bool Search<T>::Find(const std::vector<T>& V, const T& sum) {
	const std::size_t size = V.size();
	for (std::size_t i = 0; i < size; ++i) {
		int p = i + 1;
		int q = size - 1;

		while (p < q) {
			if (V[i] + V[p] == sum)
				return true;
			if (V[i] + V[q] == sum)
				return true;

			++p;
			--q;
		}
	}

	return false;
}

#endif // DATA_STRUCTURE_CHAPTER_2_2_3_7_SEARCH_H_
