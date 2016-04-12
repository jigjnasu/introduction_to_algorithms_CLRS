#ifndef DATA_STRUCTURE_QUICK_HOARE_PARTITION_SORT_H_
#define DATA_STRUCTURE_QUICK_HOARE_PARTITION_SORT_H_

#include <vector>

template <typename T>
class QuickSortHoarePartition {
public:
	QuickSortHoarePartition();
	~QuickSortHoarePartition();

	void SortAscending(std::vector<T>& V);

private:
	void m_sortAscending(std::vector<T>& V, const int& start, const int& end);
	int m_hoareParitionAscending(std::vector<T>& V, const int& start, const int& end);

	void m_swap(T& A, T& B);
};

template <typename T>
QuickSortHoarePartition<T>::QuickSortHoarePartition() {}

template <typename T>
QuickSortHoarePartition<T>::~QuickSortHoarePartition() {}

template <typename T>
void QuickSortHoarePartition<T>::SortAscending(std::vector<T>& V) {
	m_sortAscending(V, 0, V.size() - 1);
}

template <typename T>
void QuickSortHoarePartition<T>::m_sortAscending(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = m_hoareParitionAscending(V, start, end);
		m_sortAscending(V, start, mid - 1);
		m_sortAscending(V, mid + 1, end);
	}
}

template <typename T>
int QuickSortHoarePartition<T>::m_hoareParitionAscending(std::vector<T>& V, const int& start, const int& end) {
	int i = start + 1;
	int j = end;
	while (1) {
		while (V[j] <= V[start])
			--j;

		while (V[i] >= V[start])
			++i;
		
		if (i < j)
			m_swap(V[i], V[j]);
		else
			break;
	}
	printf("start == [%d] || j == [%d]\n", start, j);
	m_swap(V[j], V[start]);
	return j;
}

template <typename T>
void QuickSortHoarePartition<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_QUICK_HOARE_PARTITION_SORT_H_
