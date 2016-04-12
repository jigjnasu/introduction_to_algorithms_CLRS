#ifndef DATA_STRUCTURE_MAX_PRIORITY_QUEUE_H_
#define DATA_STRUCTURE_MAX_PRIORITY_QUEUE_H_

#include <vector>

template <typename T>
class MaxPriorityQueue {
public:
	MaxPriorityQueue();
	~MaxPriorityQueue();

	void Insert(const T& value);
	T Top() const;
	void Pop();
	const std::size_t Size() const;

private:
	std::vector<T> m_queue;

	void m_adjust();
	void m_max_heap(int index);
	void m_swap(T& A, T& B);
	const int m_parent(const int& index);
};

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue() {}

template <typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue() {}

template <typename T>
void MaxPriorityQueue<T>::Insert(const T& value) {
	m_queue.push_back(value);
	m_adjust();
}

template <typename T>
T MaxPriorityQueue<T>::Top() const {
	return m_queue[0];
}

template <typename T>
void MaxPriorityQueue<T>::Pop() {
	m_queue[0] = m_queue[m_queue.size() - 1];
	m_queue.erase(m_queue.begin() + m_queue.size() - 1);
	m_max_heap(0);
}

template <typename T>
const std::size_t MaxPriorityQueue<T>::Size() const {
	return m_queue.size();
}

template <typename T>
void MaxPriorityQueue<T>::m_adjust() {
	int index = m_queue.size() - 1;
	int parent = m_parent(index);

	while (parent >= 0 && m_queue[parent] < m_queue[index]) {
		m_swap(m_queue[parent], m_queue[index]);
		index = parent;
		parent = m_parent(index);
	}
}

template <typename T>
void MaxPriorityQueue<T>::m_max_heap(int index) {
	while (1) {
		int largest = index;
		const int left = (index << 1) + 1;
		const int right = left + 1;

		if (left < static_cast<int>(m_queue.size()) && m_queue[left] > m_queue[index])
			largest = left;
		if (right < static_cast<int>(m_queue.size()) && m_queue[right] > m_queue[largest])
			largest = right;

		if (largest == index)
			break;

		m_swap(m_queue[largest], m_queue[index]);
		index = largest;
	}
}

template <typename T>
void MaxPriorityQueue<T>::m_swap(T& A, T& B) {
	T t = A;
	A = B;
	B = t;
}

template <typename T>
const int MaxPriorityQueue<T>::m_parent(const int& index) {
	return (index % 2 == 0) ? (index >> 1) - 1 : index >> 1;
}

#endif // DATA_STRUCTURE_MAX_PRIORITY_QUEUE_H_
