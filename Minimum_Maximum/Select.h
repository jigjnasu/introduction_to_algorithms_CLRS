#ifndef DATA_STRUCTURE_SELECT_H_
#define DATA_STRUCTURE_SELECT_H_

/*
  This solution is based on Introduction to Algorithm
  Chapter 9, Section 9.3 : Medians and Order Statistics.
  Select with worst complexity of O(n).
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 6th, 2016
 */

#include <vector>

template <typename T>
class Select {
public:
	Select();
	~Select();

	T Find(const std::vector<T>& V, const int& index);

private:
	T m_find(std::vector<T>& V, int start, int end, const int& index);
	int m_median(std::vector<T>& V, const int& start, const int& end);
	int m_partition(std::vector<T>& V, const int& start, const int& end, const int& median);
	void m_swap(T& A, T& B);
	void m_sort(std::vector<T>& V, const int& start, const int& end);
};

template <typename T>
Select<T>::Select() {}

template <typename T>
Select<T>::~Select() {}

template <typename T>
T Select<T>::Find(const std::vector<T>& V, const int& index) {
	std::vector<T> data = V;
	return m_find(data, 0, data.size() - 1, index);
}

template <typename T>
T Select<T>::m_find(std::vector<T>& V, int start, int end, const int& index) {
	while (1) {
		if (start == end)
			return V[start];

		if (start < end) {
			const int mid = m_partition(V, start, end, m_median(V, start, end));

			if (index - 1 == mid)
				return V[mid];
			else if (index - 1 < mid)
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
}

template <typename T>
int Select<T>::m_median(std::vector<T>& V, const int& start, const int& end) {
	std::vector<int> medians;
	for (int i = start; i <= end; i += 5) {
		if (i + 5 < end) {
			m_sort(V, i, i + 4);
			medians.push_back(i + 2);
		} else {
			m_sort(V, i, end);
			if (i + 2 <= end)
				medians.push_back(i + 2);
		}
	}

	return medians[medians.size() / 2];
}

template <typename T>
int Select<T>::m_partition(std::vector<T>& V, const int& start, const int& end, const int& median) {
	m_swap(V[median], V[end]);

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
void Select<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

template <typename T>
void Select<T>::m_sort(std::vector<T>& V, const int& start, const int& end) {
	for (int i = start + 1; i <= end; ++i) {
		int j = i;
		while (j > start && V[j - 1] > V[j]) {
			m_swap(V[j], V[j - 1]);
			--j;
		}
	}
}

#endif // DATA_STRUCTURE_SELECT_H_
