#ifndef DATA_STRUCTURE_QUICK_HOARE_SORT_H_
#define DATA_STRUCTURE_QUICK_HOARE_SORT_H_

#include <vector>

template <typename T>
class QuickSortHoare {
public:
	QuickSortHoare();
	~QuickSortHoare();

	void SortAscending(std::vector<T>& V);

private:
	void m_sortAscending(std::vector<T>& V, const int& start, const int& end);
	int m_hoareParitionAscending(std::vector<T>& V, const int& start, const int& end);

	void m_swap(T& A, T& B);
};

template <typename T>
QuickSortHoare<T>::QuickSortHoare() {}

template <typename T>
QuickSortHoare<T>::~QuickSortHoare() {}

template <typename T>
void QuickSortHoare<T>::SortAscending(std::vector<T>& V) {
	m_sortAscending(V, 0, V.size() - 1);
}

template <typename T>
void QuickSortHoare<T>::m_sortAscending(std::vector<T>& V, const int& start, const int& end) {
	if (end - start < 2)
		return;
	const int mid = m_hoareParitionAscending(V, start, end);
	m_sortAscending(V, start, mid);
	m_sortAscending(V, mid, end);
}

template <typename T>
int QuickSortHoare<T>::m_hoareParitionAscending(std::vector<T>& V, const int& start, const int& end) {
	int i = start;
	int j = end;
	while (1) {
		do --j; while(V[j] > V[start]);
		do ++i; while(V[i] < V[start]);

		if (i < j)
			m_swap(V[i], V[j]);
		else
			return j + 1;
	}
}

template <typename T>
void QuickSortHoare<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_QUICK_HOARE_SORT_H_
