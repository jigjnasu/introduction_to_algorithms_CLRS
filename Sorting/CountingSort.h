#ifndef DATA_STRUCTURE_COUNTING_SORT_H_
#define DATA_STRUCTURE_COUNTING_SORT_H_

#include <vector>

// In counting sort, elements should range between 0 t bucket_size
// And in this case only it will be able to sort the element in O(n) time.
template <typename T, std::size_t bucket_size>
class CountingSort {
public:
	CountingSort();
	~CountingSort();

	void Sort(std::vector<T>& V);
};

template <typename T, std::size_t bucket_size>
CountingSort<T, bucket_size>::CountingSort() {}

template <typename T, std::size_t bucket_size>
CountingSort<T, bucket_size>::~CountingSort() {}

template <typename T, std::size_t bucket_size>
void CountingSort<T, bucket_size>::Sort(std::vector<T>& V) {
	T buffer[bucket_size + 1] = {0};
	T A[V.size()] = {0};
	std::vector<T> output(A, A + sizeof(A) / sizeof(A[0]));

	for (std::size_t i = 0; i < V.size(); ++i)
		++buffer[V[i]];

	for (std::size_t i = 1; i <= bucket_size; ++i)
		buffer[i] += buffer[i -1];

	for (int i = V.size() - 1; i >= 0; --i) {
		output[buffer[V[i]] - 1] = V[i];
		--buffer[V[i]];
	}

	V = output;
}

#endif // DATA_STRUCTURE_COUNTING_SORT_H_
