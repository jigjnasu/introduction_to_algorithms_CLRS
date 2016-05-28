#ifndef DATA_STRUCTURE_INTODUCTION_TO_ALGORITHMS_EXERCISE_8DOT_2_4_H_
#define DATA_STRUCTURE_INTODUCTION_TO_ALGORITHMS_EXERCISE_8DOT_2_4_H_

#include <cstring>
#include <vector>
#include <cstdio>


template <typename T, std::size_t bucket_size>
class Exercise82_4 {
public:
	Exercise82_4();
	Exercise82_4(const std::vector<T>& V);
	~Exercise82_4();

	int NumberOfElements(const int& start, const int& end);

private:
	int m_data[bucket_size + 1];
};

template <typename T, std::size_t bucket_size>
Exercise82_4<T, bucket_size>::Exercise82_4() {}

template <typename T, std::size_t bucket_size>
Exercise82_4<T, bucket_size>::Exercise82_4(const std::vector<T>& V) {
	std::memset(m_data, 0, sizeof(T) * (bucket_size + 1));

	for (std::size_t i = 0; i < V.size(); ++i)
		++m_data[V[i]];

	for (std::size_t i = 1; i <= bucket_size; ++i)
		m_data[i] += m_data[i - 1];
}

template <typename T, std::size_t bucket_size>
Exercise82_4<T, bucket_size>::~Exercise82_4() {}

template <typename T, std::size_t bucket_size>
int Exercise82_4<T, bucket_size>::NumberOfElements(const int& start, const int& end) {
	if (start > 0)
		return m_data[end] - m_data[start - 1];
	else
		return (m_data[end] - m_data[start]) + m_data[start];
}

#endif // DATA_STRUCTURE_INTODUCTION_TO_ALGORITHMS_EXERCISE_8DOT_2_4_H_
