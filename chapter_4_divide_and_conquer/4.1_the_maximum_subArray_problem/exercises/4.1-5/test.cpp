#include "MaxSubArray.h"
#include <cstdio>

void print_vector(const std::vector<int>& V) {
	printf("-------------------------------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n-------------------------------------------------------------------------\n");	
}

int main() {
	int A[] = {-58, 77, -12, -94, -38, 75, 98, 53};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	print_vector(V);

	MaxSubArray<int> max;
	printf("-------------------------------------------------------------------------\n");
	printf("Maximum sub array == [%d]\n", max.Max(V));
	printf("-------------------------------------------------------------------------\n");	
	
	return 0;
}
