#ifndef DATA_STRUCTURE_RADIX_SORT_H_
#define DATA_STRUCTURE_RADIX_SORT_H_

#include <vector>

template <typename T>
class RadixSort {
public:
	RadixSort();
	~RadixSort();

	void Sort(std::vector<T>& V);

private:
	void m_countSort(std::vector<T>& V, const int& pow);
	T m_max(const std::vector<T>& V);
};

template <typename T>
RadixSort<T>::RadixSort() {}

template <typename T>
RadixSort<T>::~RadixSort() {}

template <typename T>
void RadixSort<T>::Sort(std::vector<T>& V) {
	const T max = m_max(V);
	for (T pow = 1; max / pow > 0; pow *= 10)
		m_countSort(V, pow);
}

template <typename T>
void RadixSort<T>::m_countSort(std::vector<T>& V, const int& pow) {
	int buffer[10] = { 0 };
	int A[V.size()] = { 0 };
	std::vector<T> output(A, A + sizeof(A) / sizeof(A[0]));

	for (std::size_t i = 0; i < V.size(); ++i)
		++buffer[(V[i] / pow) % 10];

	for (std::size_t i = 1; i <= 10; ++i)
		buffer[i] += buffer[i - 1];

	for (int i = V.size() - 1; i >= 0; --i) {
		output[buffer[(V[i] / pow) % 10] - 1] = V[i];
		--buffer[(V[i] / pow) % 10];
	}

	V = output;
}

template <typename T>
T RadixSort<T>::m_max(const std::vector<T>& V) {
	T max = V[0];
	for (std::size_t i = 1; i < V.size(); ++i)
		if (V[i] > max)
			max = V[i];
	return max;
}

#endif // DATA_STRUCTURE_RADIX_SORT_H_
