#ifndef DATA_STRUCTURE_QUICK_HOARE_SORT_H_
#define DATA_STRUCTURE_QUICK_HOARE_SORT_H_

#include <vector>

template <typename T>
class QuickSortHoare {
public:
	QuickSortHoare();
	~QuickSortHoare();

	void Sort(std::vector<T>& V);

private:
	void m_sort(std::vector<T>& V, const int& start, const int& end);

	void m_swap(T& A, T& B);
};

template <typename T>
QuickSortHoare<T>::QuickSortHoare() {}

template <typename T>
QuickSortHoare<T>::~QuickSortHoare() {}

template <typename T>
void QuickSortHoare<T>::Sort(std::vector<T>& V) {
	m_sort(V, 0, V.size() - 1);
}

template <typename T>
void QuickSortHoare<T>::m_sort(std::vector<T>& V, const int& start, const int& end) {
	int i = start;
	int j = end;
	const T piviot = V[(start + end) / 2];
	
	do {
		while (i < end && V[i] < piviot)
			++i;
		while (j > start && V[j] > piviot)
			--j;

		if (i <= j)
			m_swap(V[i++], V[j--]);
	} while (i <= j);

	if (start < j)
		m_sort(V, start, j);
	if (i < end)
		m_sort(V, i, end);
}

template <typename T>
void QuickSortHoare<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_QUICK_HOARE_SORT_H_
