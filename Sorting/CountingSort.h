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

	for (std::size_t i = 0; i < V.size(); ++i)
		++buffer[V[i]];

	int iter = 0;
	for (std::size_t i = 0; i <= bucket_size; ++i)
		while (buffer[i]--)
			V[iter++] = i;
}

#endif // DATA_STRUCTURE_COUNTING_SORT_H_
