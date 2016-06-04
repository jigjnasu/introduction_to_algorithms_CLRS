/*
  This is the implmentation of Bucket Sort, Based on Introduction to Alogrithms.
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date  : June 6th, 2016
 */

#ifndef DATA_STRUCTURE_BUCKET_SORT_H_
#define DATA_STRUCTURE_BUCKET_SORT_H_

#include "InsertionSort.h"
#include <vector>

/*
  According to the Bucket Sort algorithm we, need to assume something about the input.
  
  Let's assume that data is coming between range of 0 to 99.
  And the bucket size is of 10, example
  first bucket will contain 0 ..... 9 elements.
  seconds bucket will containt 10 .... 19 emlements.
  and so on.
 */

template <typename T>
class BucketSort {
public:
	BucketSort();
	~BucketSort();

	void Sort(std::vector<T>& V);

private:
	std::vector< std::vector<T> > m_buckets;
};

template <typename T>
BucketSort<T>::BucketSort() {
	// Initializing the m_buckets with empty bucket each.
	std::vector<T> bucket;
	for (int i = 0; i < 10; ++i)
		m_buckets.push_back(bucket);
}

template <typename T>
BucketSort<T>::~BucketSort() {}

template <typename T>
void BucketSort<T>::Sort(std::vector<T>& V) {
	// Collecting the elements from original vector to small small buckets.
	for (std::size_t i = 0; i < V.size(); ++i)
		m_buckets[V[i] / 10].push_back(V[i]);

	// Sort all the buckets with insertion sort.
	// Insertion sort has been mentioned in Introduction to Algorithms.
	InsertionSort<T> sort;
	for (std::size_t i = 0; i < m_buckets.size(); ++i)
		sort.SortAscending(m_buckets[i]);

	int iter = 0;
	for (std::size_t i = 0; i < m_buckets.size(); ++i)
		for (std::size_t j = 0; j < m_buckets[i].size(); ++j)
			V[iter++] = m_buckets[i][j];
}

#endif // DATA_STRUCTURE_BUCKET_SORT_H_
