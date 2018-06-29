/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Problem 2-4 a, Inversion finding
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 13th, 2016
 */

/*
  Output:
  --------------------------------------------------
  i == [0] || j == [4] || V[i] == [2] || V[j] == [1]
  i == [1] || j == [4] || V[i] == [3] || V[j] == [1]
  i == [2] || j == [3] || V[i] == [8] || V[j] == [6]
  i == [2] || j == [4] || V[i] == [8] || V[j] == [1]
  i == [3] || j == [4] || V[i] == [6] || V[j] == [1]
  --------------------------------------------------  
 */

#include <cstdio>
#include <vector>

struct Pair {
	int i;
	int j;

	Pair(const int& value_i, const int& value_j) : i(value_i), j(value_j) {}
};

void find_inversion_pairs(const std::vector<int>& V, std::vector<Pair>& pairs) {
	for (std::size_t i = 0; i < V.size() - 1; ++i) {
		for (std::size_t j = i + 1; j < V.size(); ++j) {
			if (i < j && V[i] > V[j]) {
				Pair p(i, j);
				pairs.push_back(p);
			}
		}
	}
}

int main() {
	int A[] = {2, 3, 8, 6, 1};
	std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));
	std::vector<Pair> pairs;
	
	find_inversion_pairs(V, pairs);

	for (std::size_t i = 0; i < pairs.size(); ++i)
		printf("i == [%d] || j == [%d] || V[i] == [%d] || V[j] == [%d]\n",
			   pairs[i].i, pairs[i].j, V[pairs[i].i], V[pairs[i].j]);

	return 0;
}
