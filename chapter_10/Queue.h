/*
  Introduction to Algorithms
  Chapter 10: Elementry Data Structures
  Implementation Queue, based on array and finite size
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#ifndef DATA_STRUCTURE_CHAPTER_10_QUEUE_H_
#define DATA_STRUCTURE_CHAPTER_10_QUEUE_H_

#include <cstdio>

template <typename T, int SIZE>
class Queue {
public:
	Queue();
	~Queue();

	void EnQueue(const T& data);
	T DeQueue();

private:
	int m_tail;
	int m_head;
	bool m_isFull;

	T m_queue[SIZE];
};

template <typename T, int SIZE>
Queue<T, SIZE>::Queue() : m_tail(0), m_head(0), m_isFull(false)  {}

template <typename T, int SIZE>
Queue<T, SIZE>::~Queue() {}

template <typename T, int SIZE>
void Queue<T, SIZE>::EnQueue(const T& data) {
	if (m_isFull) {
		printf("Error: Queue is overflow\n");
	} else {
		m_queue[m_tail] = data;
		if (m_tail == SIZE - 1)
			m_tail = 0;
		else
			++m_tail;
		
		if (m_tail == m_head)
			m_isFull = true;
		else
			m_isFull = false;
	}		
}

template <typename T, int SIZE>
T Queue<T, SIZE>::DeQueue() {
	if (m_head == m_tail && m_isFull == false) {
		printf("Error: Queue is underflow\n");
	} else {
		const T value = m_queue[m_head];
		if (m_head == SIZE - 1)
			m_head = 0;
		else
			++m_head;

		m_isFull = false;
		return value;
	}
}

#endif // DATA_STRUCTURE_CHAPTER_10_QUEUE_H_
