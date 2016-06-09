#ifndef DATA_STRUCTURE_CHAPTER_10_EXERCISE_10_1_1_STACK_H_
#define DATA_STRUCTURE_CHAPTER_10_EXERCISE_10_1_1_STACK_H_

#include <cstdio>

template <typename T, int SIZE>
class Stack {
public:
	Stack();
	~Stack();

	void PushOne(const T& data);
	void PushTwo(const T& data);

	T PopOne();
	T PopTwo();
	
private:
	int m_top_one;
	int m_top_two;

	T m_stack[SIZE];
};

template <typename T, int SIZE>
Stack<T, SIZE>::Stack() : m_top_one(-1), m_top_two(SIZE) {}

template <typename T, int SIZE>
Stack<T, SIZE>::~Stack() {}

template <typename T, int SIZE>
void Stack<T, SIZE>::PushOne(const T& data) {
	if (m_top_one + 1 == m_top_two) {
		printf("Error: Stack overflow\n");
	} else {
		m_stack[++m_top_one] = data;
	}
}

template <typename T, int SIZE>
void Stack<T, SIZE>::PushTwo(const T& data) {
	if (m_top_one + 1 == m_top_two) {
		printf("Error: Stack overflow\n");
	} else {
		m_stack[--m_top_two] = data;
	}	
}

template <typename T, int SIZE>
T Stack<T, SIZE>::PopOne() {
	if (m_top_one == -1) {
		printf("Error: Stack underflow\n");
	} else {
		const T data = m_stack[m_top_one];
		--m_top_one;
		return data;
	}
}

template <typename T, int SIZE>
T Stack<T, SIZE>::PopTwo() {
	if (m_top_two == SIZE) {
		printf("Error: Stack underflow\n");
	} else {
		const T data = m_stack[m_top_two];
		++m_top_two;
		return data;
	}	
}

#endif // DATA_STRUCTURE_CHAPTER_10_EXERCISE_10_1_1_STACK_H_
