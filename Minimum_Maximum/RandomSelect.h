#ifndef DATA_STRUCTURE_RANDOM_SELECT_H_
#define DATA_STRUCTURE_RANDOM_SELECT_H_

/*
  This solution is based on Introduction to Algorithm
  Chapter 9 : Medians and Order Statistics. Randomized Select.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 5th, 2016
 */

#include <cstdlib>
#include <vector>

template <typename T>
class RandomSelect {
public:
	RandomSelect();
	~RandomSelect();

	// This function will select the ith element in sorted order in increasing way.
	// It will take O(n) time.
	T Select(const std::vector<T>& V, const int& index);

private:
	T m_select(std::vector<T>& V, const int& start, const int& end, const int& index);
	T m_select_iterative(std::vector<T>& V, int start, int end, const int& index);
	int m_partition(std::vector<T>& V, const int& start, const int& end);
	void m_swap(T& A, T& B);
};

template <typename T>
RandomSelect<T>::RandomSelect() {}

template <typename T>
RandomSelect<T>::~RandomSelect() {}

template <typename T>
T RandomSelect<T>::Select(const std::vector<T>& V, const int& index) {
	std::vector<T> data = V;
	//return m_select(data, 0, data.size() - 1, index);
	return m_select_iterative(data, 0, data.size() - 1, index);
}

template <typename T>
T RandomSelect<T>::m_select(std::vector<T>& V, const int& start, const int& end, const int& index) {
	if (start == end)
		return V[start];

	if (start < end) {
		const int mid = m_partition(V, start, end);

		if (mid == index - 1)
			return V[mid];
		else if (index - 1 < mid)
			m_select(V, start, mid - 1, index);
		else
			m_select(V, mid + 1, end, index);
	}
}

template <typename T>
T RandomSelect<T>::m_select_iterative(std::vector<T>& V, int start, int end, const int& index) {
	while (1) {
		if (start == end)
			return V[start];

		if (start < end) {
			const int mid = m_partition(V, start, end);

			if (mid == index - 1)
				return V[mid];
			else if (index - 1 < mid)
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
}


template <typename T>
int RandomSelect<T>::m_partition(std::vector<T>& V, const int& start, const int& end) {
	m_swap(V[rand() % (end - start  + 1) + start], V[end]);

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
void RandomSelect<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_RANDOM_SELECT_H_
