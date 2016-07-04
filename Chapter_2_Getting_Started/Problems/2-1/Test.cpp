#include "Sort.h"
#include <cstdio>

void print(const std::vector<int>& V) {
	printf("-------------------------------------------------------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n-------------------------------------------------------------------------------------------------\n");	
}

int main() {
	int A[] = {98, 1, 73, 7, 83, 12, 83, 34, 172, 83, 841, 737, 37, 84, 236, 848, 27, 234, 73, 2, 73, 2, 34, 83, 27, 27, 8342, 7};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	print(V);
	Sort<int> sort;
	sort.sort(V);
	print(V);
	
	return 0;
}
