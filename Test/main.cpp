#include "QuickSortRandom.h"
#include "Common.h"

int main() {
	int A[] = {10, 2, 345, 28, 382, 1, 384, 892, 2, 381, 34, 58, 2, 82, 82, 94, 82, 1, 84, 82, 284, 82};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

	QuickSortRandom<int> sort;
	Common<int> common;
	common.PrintVector(V);
	//sort.SortAscending(V);
	sort.SortDescending(V);
	common.PrintVector(V);
	
	return 0;
}
