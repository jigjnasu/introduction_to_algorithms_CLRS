#ifndef DATA_STRUCTURE_MIN_PRIORITY_QUEUE_H_
#define DATA_STRUCTURE_MIN_PRIORITY_QUEUE_H_

#include <vector>

template <typename T>
class MinPriorityQueue {
public:
	MinPriorityQueue();
	~MinPriorityQueue();

	void Insert(const T& value);
	const T Top() const;
	void Pop();
	std::size_t Size() const;

private:
	std::vector<T> m_queue;

	void m_adjust();
	void m_min_heap(int index);
	int m_parent(const int& index);
	void m_swap(T& A, T& B);
};

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue() {}

template <typename T>
MinPriorityQueue<T>::~MinPriorityQueue() {}

template <typename T>
void MinPriorityQueue<T>::Insert(const T& value) {
	m_queue.push_back(value);
	m_adjust();
}

template <typename T>
const T MinPriorityQueue<T>::Top() const {
	return m_queue[0];
}

template <typename T>
void MinPriorityQueue<T>::Pop() {
	m_queue[0] = m_queue[m_queue.size() - 1];
	m_queue.erase(m_queue.begin() + m_queue.size() - 1);
	m_min_heap(0);
}

template <typename T>
std::size_t MinPriorityQueue<T>::Size() const {
	return m_queue.size();
}

template <typename T>
void MinPriorityQueue<T>::m_adjust() {
	int index = m_queue.size() - 1;
	int parent = m_parent(index);

	while (parent >= 0 && m_queue[parent] > m_queue[index]) {
		m_swap(m_queue[parent], m_queue[index]);
		index = parent;
		parent = m_parent(index);
	}
}

template <typename T>
void MinPriorityQueue<T>::m_min_heap(int index) {
	while (1) {
		int smallest = index;
		const int left = (index << 1) + 1;
		const int right = left + 1;

		if (left < static_cast<int>(m_queue.size()) && m_queue[left] < m_queue[index])
			smallest = left;
		if (right < static_cast<int>(m_queue.size()) && m_queue[right] < m_queue[smallest])
			smallest = right;

		if (smallest == index)
			break;

		m_swap(m_queue[index], m_queue[smallest]);
		index = smallest;
	}
}

template <typename T>
int MinPriorityQueue<T>::m_parent(const int& index) {
	return (index % 2 == 0) ? (index >> 1) - 1 : index >> 1 ;
}

template <typename T>
void MinPriorityQueue<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

#endif // DATA_STRUCTURE_MIN_PRIORITY_QUEUE_H_
