#include "bubble_sort.h"
#include <cstdio>

void print(const std::vector<int>& V) {
	printf("---------------------------------------------------------------------\n");
	for (std::size_t i = 0; i < V.size(); ++i)
		printf("%d ", V[i]);
	printf("\n---------------------------------------------------------------------\n");
}

int main() {
    std::vector<int> v = {98, 1, 83, 72, 26, 94, 27, 28, 94, 37, 38, 72, 84, 73, 12, 56, 89, 17, 28, 73, 27, 82, 74, 72, 71, 84, 23};

	print(v);
	BubbleSort<int> sort;
	sort.Sort(v);
	print(v);

	return 0;
}
