#ifndef DATA_STRUCTURE_INSERTION_SORT_H_
#define DATA_STRUCTURE_INSERTION_SORT_H_

#include <vector>

template <typename T>
class InsertionSort {
public:
	InsertionSort();
	~InsertionSort();

	void SortAscending(std::vector<T>& V);
	void SortDescending(std::vector<T>& V);

private:
	void m_swap(T& A, T& B);
};

template <typename T>
InsertionSort<T>::InsertionSort() {}

template <typename T>
InsertionSort<T>::~InsertionSort() {}

template <typename T>
void InsertionSort<T>::SortAscending(std::vector<T>& V) {
	for (std::size_t i = 1; i < V.size(); ++i) {
		int j = static_cast<int>(i);

		while (j > 0 && V[j] < V[j - 1]) {
			m_swap(V[j], V[j - 1]);
			--j;
		}
	}
}

template <typename T>
void InsertionSort<T>::SortDescending(std::vector<T>& V) {
	for (std::size_t i = 1; i < V.size(); ++i) {
		int j = static_cast<int>(i);

		while (j > 0 && V[j] > V[j - 1]) {
			m_swap(V[j], V[j - 1]);
			--j;
		}
	}
}

template <typename T>
void InsertionSort<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_INSERTION_SORT_H_
