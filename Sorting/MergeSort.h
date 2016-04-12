#ifndef DATA_STRUCTURE_MERGE_SORT_H_
#define DATA_STRUCTURE_MERGE_SORT_H_

#include <vector>

template <typename T>
class MergeSort {
public:
	MergeSort();
	~MergeSort();

	void SortAscending(std::vector<T>& V);
	void SortDescending(std::vector<T>& V);

private:
	void m_merge_sort(std::vector<T>& V, const int& low, const int& high, bool is_ascending);
	void m_merge_ascending(std::vector<T>& V, const int& low, const int& mid, const int& high);
	void m_merge_descending(std::vector<T>& V, const int& low, const int& mid, const int& high);
};

template <typename T>
MergeSort<T>::MergeSort() {}

template <typename T>
MergeSort<T>::~MergeSort() {}

template <typename T>
void MergeSort<T>::SortAscending(std::vector<T>& V) {
	m_merge_sort(V, 0, V.size() - 1, true);
}

template <typename T>
void MergeSort<T>::SortDescending(std::vector<T>& V) {
	m_merge_sort(V, 0, V.size() - 1, false);
}

template <typename T>
void MergeSort<T>::m_merge_sort(std::vector<T>& V, const int& low, const int& high, bool is_ascending) {
	if (low != high) {
		const int mid = (low + high) >> 1;
		m_merge_sort(V, low, mid, is_ascending);
		m_merge_sort(V, mid + 1, high, is_ascending);
		if (is_ascending)
			m_merge_ascending(V, low, mid, high);
		else
			m_merge_descending(V, low, mid, high);
	}
}

template <typename T>
void MergeSort<T>::m_merge_ascending(std::vector<T>& V, const int& low, const int& mid, const int& high) {
	int index = low;
	int left_iterator = 0;
	int right_iterator = 0;
	std::vector<T> left;
	std::vector<T> right;

	for (int i = low; i <= mid; ++i)
		left.push_back(V[i]);

	for (int i = mid + 1; i <= high; ++i)
		right.push_back(V[i]);

	while (left_iterator < static_cast<int>(left.size()) &&
		   right_iterator < static_cast<int>(right.size())) {
		if (left[left_iterator] < right[right_iterator])
			V[index++] = left[left_iterator++];
		else
			V[index++] = right[right_iterator++];
	}

	while (left_iterator < static_cast<int>(left.size()))
		V[index++] = left[left_iterator++];

	while (right_iterator < static_cast<int>(right.size()))
		V[index++] = right[right_iterator++];
}

template <typename T>
void MergeSort<T>::m_merge_descending(std::vector<T>& V, const int& low, const int& mid, const int& high) {
	int index = low;
	int left_iterator = 0;
	int right_iterator = 0;
	std::vector<T> left;
	std::vector<T> right;

	for (int i = low; i <= mid; ++i)
		left.push_back(V[i]);

	for (int i = mid + 1; i <= high; ++i)
		right.push_back(V[i]);

	while (left_iterator < static_cast<int>(left.size()) &&
		   right_iterator < static_cast<int>(right.size())) {
		if (left[left_iterator] > right[right_iterator])
			V[index++] = left[left_iterator++];
		else
			V[index++] = right[right_iterator++];
	}

	while (left_iterator < static_cast<int>(left.size()))
		V[index++] = left[left_iterator++];

	while (right_iterator < static_cast<int>(right.size()))
		V[index++] = right[right_iterator++];
}

#endif // DATA_STRUCTURE_MERGE_SORT_H_
