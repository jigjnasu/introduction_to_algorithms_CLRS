#include "Queue.h"

int main() {
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

	return 0;
}

