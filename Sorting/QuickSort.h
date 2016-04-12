#ifndef DATA_STRUCTURE_SELECTION_QUICK_SORT_H_
#define DATA_STRUCTURE_SELECTION_QUICK_SORT_H_

#include <vector>

// In this piviot is always the last element of the divided portion.
template <typename T>
class QuickSort {
public:
	QuickSort();
	~QuickSort();

	void SortAscending(std::vector<T>& V);
	void SortDescending(std::vector<T>& V);

private:
	void m_sort_ascending(std::vector<T>& V, const int& start, const int& end);
	void m_sort_descending(std::vector<T>& V, const int& start, const int& end);
	int m_partition_ascending(std::vector<T>& V, const int& start, const int& end);
	int m_partition_descending(std::vector<T>& V, const int& start, const int& end);

	void m_swap(T& A, T& B);
};

template <typename T>
QuickSort<T>::QuickSort() {}

template <typename T>
QuickSort<T>::~QuickSort() {}

template <typename T>
void QuickSort<T>::SortAscending(std::vector<T>& V) {
	m_sort_ascending(V, 0, V.size() - 1);
}

template <typename T>
void QuickSort<T>::SortDescending(std::vector<T>& V) {
	m_sort_descending(V, 0, V.size() - 1);
}

template <typename T>
void QuickSort<T>::m_sort_ascending(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = m_partition_ascending(V, start, end);
		m_sort_ascending(V, start, mid - 1);
		m_sort_ascending(V, mid + 1, end);
	}
}

template <typename T>
void QuickSort<T>::m_sort_descending(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = m_partition_descending(V, start, end);
		m_sort_descending(V, start, mid - 1);
		m_sort_descending(V, mid + 1, end);
	}
}

template <typename T>
int QuickSort<T>::m_partition_ascending(std::vector<T>& V, const int& start, const int& end) {
	int i = start;
	for (int j = start; j < end; ++j) {
		if (V[j] <= V[end]) {
			if (i != j)
				m_swap(V[i], V[j]);
			++i;
		}
	}

	m_swap(V[i], V[end]);

	return i;
}

template <typename T>
int QuickSort<T>::m_partition_descending(std::vector<T>& V, const int& start, const int& end) {
	int i = start;
	for (int j = start; j < end; ++j) {
		if (V[j] >= V[end]) {
			if (i != j)
				m_swap(V[i], V[j]);
			++i;
		}
	}

	m_swap(V[i], V[end]);

	return i;
}

template <typename T>
void QuickSort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_SELECTION_QUICK_SORT_H_
