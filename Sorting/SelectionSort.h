#ifndef DATA_STRUCTURE_SELECTION_SORT_H_
#define DATA_STRUCTURE_SELECTION_SORT_H_

#include <vector>

template <typename T>
class SelectionSort {
public:
	SelectionSort();
	~SelectionSort();

	void SortAscending(std::vector<T>& V);
	void SortDescending(std::vector<T>& V);

private:
	int m_find_smallest(const std::vector<T>& V, const int start_index);
	int m_find_largest(const std::vector<T>& V, const int start_index);

	void m_swap(T& A, T& B);
};

template <typename T>
SelectionSort<T>::SelectionSort() {}

template <typename T>
SelectionSort<T>::~SelectionSort() {}

template <typename T>
void SelectionSort<T>::SortAscending(std::vector<T>& V) {
	for (std::size_t i = 0; i < V.size() - 1; ++i) {
		const int index = m_find_smallest(V, i);
		if (index != i)
			m_swap(V[index], V[i]);
	}
}

template <typename T>
void SelectionSort<T>::SortDescending(std::vector<T>& V) {
	for (std::size_t i = 0; i < V.size() - 1; ++i) {
		const int index = m_find_largest(V, i);
		if (index != i)
			m_swap(V[index], V[i]);
	}
}

template <typename T>
int SelectionSort<T>::m_find_smallest(const std::vector<T>& V, const int start_index) {
	int index = start_index;
	int smallest = V[start_index];

	for (int i = start_index + 1; i < static_cast<int>(V.size()); ++i) {
		if (V[i] < smallest){
			index = i;
			smallest = V[i];
		}
	}

	return index;
}

template <typename T>
int SelectionSort<T>::m_find_largest(const std::vector<T>& V, const int start_index) {
	int index = start_index;
	int largest = V[start_index];

	for (int i = start_index + 1; i < static_cast<int>(V.size()); ++i) {
		if (V[i] > largest){
			index = i;
			largest = V[i];
		}
	}

	return index;
}

template <typename T>
void SelectionSort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_SELECTION_SORT_H_
