/*
  Introduction to Algorithms
  Chapter 10: Elementry Data Structures
  Test case for Queue and Stack
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: June 10th, 2016
 */

#include "Queue.h"
#include "Stack.h"

void test_queue() {
	Queue<int, 5> queue;
	printf("------------------------------------------------------\n");
	queue.DeQueue();
	queue.EnQueue(1);
	queue.EnQueue(2);
	queue.EnQueue(3);

	printf("First  element in queue == [%d]\n", queue.DeQueue());
	printf("Second element in queue == [%d]\n", queue.DeQueue());
	printf("Third  element in queue == [%d]\n", queue.DeQueue());
	queue.DeQueue();
	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");
	queue.EnQueue(1);
	queue.EnQueue(2);
	queue.EnQueue(3);
	queue.EnQueue(4);
	queue.EnQueue(5);
	queue.EnQueue(6);

	printf("First  element in queue == [%d]\n", queue.DeQueue());
	printf("Second element in queue == [%d]\n", queue.DeQueue());
	printf("Third  element in queue == [%d]\n", queue.DeQueue());
	printf("Fourth element in queue == [%d]\n", queue.DeQueue());
	printf("Fifth  element in queue == [%d]\n", queue.DeQueue());
	printf("Sixth  element in queue == [%d]\n", queue.DeQueue());
	printf("------------------------------------------------------\n");
}

void test_stack() {
	Stack<int, 5> stack;
	printf("------------------------------------------------------\n");
	stack.Pop();
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);

	printf("%d\n", stack.Pop());
	printf("%d\n", stack.Pop());
	printf("%d\n", stack.Pop());
	printf("------------------------------------------------------\n");
	printf("------------------------------------------------------\n");
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);
	printf("%d\n", stack.Pop());
	printf("%d\n", stack.Pop());
	printf("%d\n", stack.Pop());
	printf("%d\n", stack.Pop());
	printf("%d\n", stack.Pop());
	printf("%d\n", stack.Pop());
	printf("------------------------------------------------------\n");
}


int main() {
	test_queue();
	test_stack();

	return 0;
}
