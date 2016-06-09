#ifndef DATA_STRUCTURE_CHAPTER_10_STACK_H_
#define DATA_STRUCTURE_CHAPTER_10_STACK_H_

#include <cstdio>
#include <vector>

template <typename T>
class Stack {
public:
	Stack();
	~Stack();

	void Push(const T& data);
	T Pop();
	int Size() const;
	
private:
	int m_top;
	std::vector<T> m_stack;

	bool m_isEmpty();
};

template <typename T>
Stack<T>::Stack() : m_top(-1) {}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
void Stack<T>::Push(const T& data) {
	if (m_top + 1 == m_stack.size())
		m_stack.push_back(data);
	else
		m_stack[m_top + 1] = data;
	++m_top;
}

template <typename T>
T Stack<T>::Pop() {
	if (m_isEmpty()) {
		printf("Error: Stack is underflow\n");
	} else {
		--m_top;
		return m_stack[m_top + 1];
	}
}

template <typename T>
int Stack<T>::Size() const {
	return m_top + 1;
}

template <typename T>
bool Stack<T>::m_isEmpty() {
	if (m_top ==  -1)
		return true;
	else
		return false;
}

#endif // DATA_STRUCTURE_CHAPTER_10_STACK_H_
