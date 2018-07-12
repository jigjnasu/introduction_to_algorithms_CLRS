#include "max_sub_array_iterative.h"
#include <cstdio>

void print_vector(const std::vector<int>& V) {
	printf("-----------------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n-----------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {-9, 19, 27, -92, 17, 28, 1, 72, 38, -3, -3, -45, 34, 93, 72, -8, -81, -83, 12};

	int sum = v[0];
	int start = 0;
	int end = 0;

	MaxSubArrayIterative<int> max_iterative;
	max_iterative.Max(v, sum, start, end);

	print_vector(v);

	printf("--------------------------- iterative ------------------------------\n");
	printf("Maximum sub array sum from [%d] to [%d] == [%d]\n", start, end, sum);
	printf("--------------------------- iterative ------------------------------\n");

	return 0;
}
