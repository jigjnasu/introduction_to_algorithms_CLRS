#ifndef DATA_STRUCTURE_QUICK_HOARE_INITIAL_H_
#define DATA_STRUCTURE_QUICK_HOARE_INITIAL_H_

#include <vector>

template <typename T>
class QuickSortHoareInitial {
public:
	QuickSortHoareInitial();
	~QuickSortHoareInitial();

	void Sort(std::vector<T>& V);
	
private:
	void m_sort(std::vector<T>& V, const int& start, const int& end);
	int m_hoarePartition(std::vector<T>& V, const int& start, const int& end);

	void m_swap(T& A, T& B);
};

template <typename T>
QuickSortHoareInitial<T>::QuickSortHoareInitial() {}

template <typename T>
QuickSortHoareInitial<T>::~QuickSortHoareInitial() {}

template <typename T>
void QuickSortHoareInitial<T>::Sort(std::vector<T>& V) {
	m_sort(V, 0, V.size() - 1);
}

template <typename T>
void QuickSortHoareInitial<T>::m_sort(std::vector<T>& V, const int& start, const int& end) {
	if (start <= end) {
		const int mid = m_hoarePartition(V, start, end);
		m_sort(V, start, mid - 1);
		m_sort(V, mid + 1, end);
	}
}

template <typename T>
int QuickSortHoareInitial<T>::m_hoarePartition(std::vector<T>& V, const int& start, const int& end) {
	int i = start + 1;
	int j = end;

	while (1) {
		while (i < end && V[i] <= V[start])
			++i;
		while (j > start && V[j] > V[start])
			--j;

		if (i < j)
			m_swap(V[i], V[j]);
		else
			break;
	}

	m_swap(V[start], V[j]);
	return j;
}

template <typename T>
void QuickSortHoareInitial<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_QUICK_HOARE_INITIAL_H_
