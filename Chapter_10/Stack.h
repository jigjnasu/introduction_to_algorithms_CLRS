#ifndef DATA_STRUCTURE_CHAPTER_10_STACK_H_
#define DATA_STRUCTURE_CHAPTER_10_STACK_H_

#include <cstdio>

template <typename T, int SIZE>
class Stack {
public:
	Stack();
	~Stack();

	void Push(const T& data);
	T Pop();

private:
	T m_stack[SIZE];

	int m_top;
};

template <typename T, int SIZE>
Stack<T, SIZE>::Stack() : m_top(-1) {}

template <typename T, int SIZE>
Stack<T, SIZE>::~Stack() {}

template <typename T, int SIZE>
void Stack<T, SIZE>::Push(const T& data) {
	if (m_top + 1 == SIZE) {
		printf("Error: Stack overflow\n");
	} else {
		m_stack[++m_top] = data;
	}
}

template <typename T, int SIZE>
T Stack<T, SIZE>::Pop() {
	if (m_top == -1) {
		printf("Error: Stack underflow\n");
	} else {
		const T data = m_stack[m_top--];
		return data;
	}
}

#endif // DATA_STRUCTURE_CHAPTER_10_STACK_H_
