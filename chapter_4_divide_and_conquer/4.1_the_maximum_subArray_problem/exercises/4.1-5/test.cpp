#include "max_sub_array.h"
#include <cstdio>

void print_vector(const std::vector<int>& V) {
	printf("-------------------------------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n-------------------------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {-58, 77, -12, -94, -38, 75, 98, 53};
	print_vector(v);

	MaxSubArray<int> max;
	printf("-------------------------------------------------------------------------\n");
	printf("Maximum sub array == [%d]\n", max.Max(v));
	printf("-------------------------------------------------------------------------\n");

	return 0;
}
