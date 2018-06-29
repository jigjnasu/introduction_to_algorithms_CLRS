#include "MaxSubArray.h"
#include <cstdio>

void print_vector(const std::vector<int>& V) {
	printf("---------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n---------------------------------------------------\n");	
}

int main() {
	int A[] = {-12, 12};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	
	MaxSubArray<int> max;

	int sum = 0;
	if (max.Max(V, sum)) {
		printf("Maximum sub array sum == [%d]\n", sum);
	} else {
		printf("Empty max sub array\n");
	}
	
	return 0;
}
