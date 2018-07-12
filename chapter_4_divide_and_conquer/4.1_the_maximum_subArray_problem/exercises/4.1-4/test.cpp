#include "max_sub_array.h"
#include <cstdio>

void print_vector(const std::vector<int>& V) {
	printf("---------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n---------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {-12, 12};

	MaxSubArray<int> max;

	int sum = 0;
	if (max.Max(v, sum))
		printf("Maximum sub array sum == [%d]\n", sum);
	else
		printf("Empty max sub array\n");

	return 0;
}
