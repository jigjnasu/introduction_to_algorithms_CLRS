/*
  Intrdocution to algortithms
  Chapter 2: Getting Started
  Exersice 2.1-3, Search a number (v) into a set {a1, a2, a3 .... an}
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

/*
  2.1-3
  Consider the searching problem:
  Input: A sequence of n numbers A = {a1, a2, ....., an } and a value
  Output: An index i such that D AOE or the special value NIL if does not
  appear in A.
  Write pseudocode for linear search, which scans through the sequence, looking
  for v .Using a loop invariant, prove that your algorithm is correct. Make sure that
  your loop invariant fulfills the three necessary properties.
 */

#include <vector>

#ifndef DATA_STRUCTURE_CHAPTER_2_2_1_3_LINEAR_SEARH_H_
#define DATA_STRUCTURE_CHAPTER_2_2_1_3_LINEAR_SEARH_H_

template <typename T>
class LinearSearch {
public:
	LinearSearch();
	~LinearSearch();

	int Search(const std::vector<T>& V, const T& N);
};

template <typename T>
LinearSearch<T>::LinearSearch() {}

template <typename T>
LinearSearch<T>::~LinearSearch() {}

template <typename T>
int LinearSearch<T>::Search(const std::vector<T>& V, const T& N) {
	int index = -1;
	for (std::size_t i = 0; i < V.size(); ++i) {
		if (N == V[i]) {
			index = i;
			break;
		}
	}
	
	return index;
}

#endif // DATA_STRUCTURE_CHAPTER_2_2_1_3_LINEAR_SEARH_H_
