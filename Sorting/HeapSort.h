#ifndef DATA_STRUCTURE_HEAP_SORT_H_
#define DATA_STRUCTURE_HEAP_SORT_H_

#include <vector>

template <typename T>
class HeapSort {
public:
	HeapSort();
	~HeapSort();

	void SortAscending(std::vector<T>& V);
	void SortDescending(std::vector<T>& V);

private:
	void m_build_max_heap(std::vector<T>& V);
	void m_build_min_heap(std::vector<T>& V);
	void m_max_heap(std::vector<T>& V, const int& size, int index);
	void m_min_heap(std::vector<T>& V, const int& size, int index);
	void m_swap(T& A, T& B);
};

template <typename T>
HeapSort<T>::HeapSort() {}

template <typename T>
HeapSort<T>::~HeapSort() {}

template <typename T>
void HeapSort<T>::SortAscending(std::vector<T>& V) {
	m_build_max_heap(V);
	for (int i = V.size() - 1; i > 0; --i) {
		m_swap(V[i], V[0]);
		m_max_heap(V, i, 0);
	}
}

template <typename T>
void HeapSort<T>::SortDescending(std::vector<T>& V) {
	m_build_min_heap(V);
	for (int i = V.size() - 1; i > 0; --i) {
		m_swap(V[i], V[0]);
		m_min_heap(V, i, 0);
	}
}

template <typename T>
void HeapSort<T>::m_build_max_heap(std::vector<T>& V) {
	for (int i = V.size() / 2; i >= 0; --i)
		m_max_heap(V, V.size(), i);
}

template <typename T>
void HeapSort<T>::m_build_min_heap(std::vector<T>& V) {
	for (int i = V.size() / 2; i >= 0; --i)
		m_min_heap(V, V.size(), i);
}

template <typename T>
void HeapSort<T>::m_max_heap(std::vector<T>& V, const int& size, int index) {
	while (1) {
		int largest = index;
		const int left = (index << 1) + 1;
		const int right = left + 1;

		if (left < size && V[left] > V[index])
			largest = left;
		if (right < size && V[right] > V[largest])
			largest = right;

		if (largest == index)
			break;

		m_swap(V[largest], V[index]);
		index = largest;
	}
}

template <typename T>
void HeapSort<T>::m_min_heap(std::vector<T>& V, const int& size, int index) {
	while (1) {
		int smallest = index;
		const int left = (index << 1) + 1;
		const int right = left + 1;

		if (left < size && V[left] < V[index])
			smallest = left;
		if (right < size && V[right] < V[smallest])
			smallest = right;

		if (smallest == index)
			break;

		m_swap(V[index], V[smallest]);
		index = smallest;
	}
}

template <typename T>
void HeapSort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_HEAP_SORT_H_
