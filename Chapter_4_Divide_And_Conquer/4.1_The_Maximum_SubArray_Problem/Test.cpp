#include "MaxSubArrayIterative.h"
#include "MaxSubArray.h"
#include <cstdio>

void print_vector(const std::vector<int>& V) {
	printf("-----------------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n-----------------------------------------------------------\n");	
}

int main() {
	int A[] = {-9, 19, 27, -92, 17, 28, 1, 72, 38, -3, -3, -45, 34, 93, 72, -8, -81, -83, 12};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	int sum = 0;
	int start = 0;
	int end = 0;
	
	MaxSubArrayIterative<int> max_iterative;
	max_iterative.Max(V, sum, start, end);

	print_vector(V);
	
	printf("--------------------------- iterative ------------------------------\n");
	printf("Maximum sub array sum from [%d] to [%d] == [%d]\n", start, end, sum);
	printf("--------------------------- iterative ------------------------------\n");

	sum = 0;
	start = 0;
	end = 0;
	
	MaxSubArray<int> max;
	printf("------------------------- Divide and Conquer -----------------------\n");
	printf("Maximum sub array sum == [%d]\n", max.Max(V));
	printf("------------------------- Divide and Conquer -----------------------\n");	
	
	return 0;
}
