/*
  Introduction to algorithms, CLRS
  Chapter 10, Elementry Data Structures
  Test case for Exercise 10.1-2, implement two stacks in one single array.

  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 10th, 2016
 */

#include "Stack.h"

int main() {
	Stack<int, 5> stack;

	printf("-----------------------------------------------------------------\n");
	stack.PopOne();
	stack.PopTwo();

	stack.PushOne(1);
	stack.PushOne(2);
	stack.PushOne(3);
	stack.PushOne(4);
	stack.PushOne(5);

	stack.PushOne(6);
	stack.PushTwo(1);

	printf("%d\n", stack.PopOne());
	printf("%d\n", stack.PopTwo());
	printf("%d\n", stack.PopOne());
	printf("%d\n", stack.PopOne());
	printf("%d\n", stack.PopOne());
	printf("%d\n", stack.PopOne());
	printf("%d\n", stack.PopOne());
	printf("-----------------------------------------------------------------\n");
	return 0;
}
