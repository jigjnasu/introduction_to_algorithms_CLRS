#ifndef DATA_STRUCTURE_SELECTION_QUICK_SORT_RANDOM_H_
#define DATA_STRUCTURE_SELECTION_QUICK_SORT_RANDOM_H_

#include <vector>

// In this algorithm, the piviot will not be always last one,
// It will generate a random number between start and end, and that will be random pivot point.
// So according the the research, will can make a balancing division, to get n(log2n) complexity.

template <typename T>
class QuickSortRandom {
public:
	QuickSortRandom();
	~QuickSortRandom();

	void SortAscending(std::vector<T>& V);
	void SortDescending(std::vector<T>& V);

private:
	void m_sortAscending(std::vector<T>& V, const int& start, const int& end);
	void m_sortDescending(std::vector<T>& V, const int& start, const int& end);
	int m_partitionAscending(std::vector<T>& V, const int& start, const int& end);
	int m_partitionDescending(std::vector<T>& V, const int& start, const int& end);

	int m_random(const int& start, const int& end);
	void m_swap(T& A, T& B);
};

template <typename T>
QuickSortRandom<T>::QuickSortRandom() {}

template <typename T>
QuickSortRandom<T>::~QuickSortRandom() {}

template <typename T>
void QuickSortRandom<T>::SortAscending(std::vector<T>& V) {
	m_sortAscending(V, 0, V.size() - 1);
}

template <typename T>
void QuickSortRandom<T>::SortDescending(std::vector<T>& V) {
	m_sortDescending(V, 0, V.size() - 1);
}

template <typename T>
void QuickSortRandom<T>::m_sortAscending(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = m_partitionAscending(V, start, end);
		m_sortAscending(V, start, mid - 1);
		m_sortAscending(V, mid + 1, end);
	}
}

template <typename T>
void QuickSortRandom<T>::m_sortDescending(std::vector<T>& V, const int& start, const int& end) {
	if (start < end) {
		const int mid = m_partitionDescending(V, start, end);
		m_sortDescending(V, start, mid - 1);
		m_sortDescending(V, mid + 1, end);
	}
}

template <typename T>
int QuickSortRandom<T>::m_partitionAscending(std::vector<T>& V, const int& start, const int& end) {
	// swap the last element with the random number.
	// It will try to balance the divide and conquer, to get the (n log2n) complexity.
	m_swap(V[m_random(start, end)], V[end]);

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
int QuickSortRandom<T>::m_partitionDescending(std::vector<T>& V, const int& start, const int& end) {
	// swap the last element with the random number.
	// It will try to balance the divide and conquer, to get the (n log2n) complexity.
	m_swap(V[m_random(start, end)], V[end]);

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
int QuickSortRandom<T>::m_random(const int& start, const int& end) {
	return rand() % (end - start + 1) + start;
}

template <typename T>
void QuickSortRandom<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_SELECTION_QUICK_SORT_RANDOM_H_
