#ifndef DATA_STRUCTURE_SEARCH_H_
#define DATA_STRUCTURE_SEARCH_H_

#include <vector>

template <typename T>
class Search {
public:
	Search();
	~Search();

	int SearchInUnSorted(const std::vector<T>& V, const T& key);
	int SearchInSorted(const std::vector<T>& V, const T& key);
};

template <typename T>
Search<T>::Search() {}

template <typename T>
Search<T>::~Search() {}

// Time complexity of this is n / 2.
template <typename T>
int Search<T>::SearchInUnSorted(const std::vector<T>& V, const T& key) {
	int i = 0;
	int j = V.size() - 1;
	int index = -1;

	while (i < j) {
		if (V[i] == key) {
			index = i;
			break;
		}

		if (V[j] == key) {
			index = j;
			break;
		}

		++i;
		--j;
	}

	return index;
}

// Time complexity of this is log2(n)
template <typename T>
int Search<T>::SearchInSorted(const std::vector<T>& V, const T& key) {
	int index = -1;
	int low = 0;
	int high = V.size() - 1;
	while (low != high) {
		const int mid = (low + high) >> 1;

		if (V[mid] == key) {
			index = mid;
			break;
		} else if (key < V[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	return index;
}

#endif // DATA_STRUCTURE_SEARCH_H_
