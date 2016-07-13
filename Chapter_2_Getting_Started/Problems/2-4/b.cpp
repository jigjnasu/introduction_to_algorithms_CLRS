/*
  Introduction to Algorithms, CLRS
  Chapter 2, Getting Started
  Problem 2-4 b, Inversion finding
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : July 13th, 2016
 */

/*
  Output:
  ------------------------------------------------------------------------------------------
  In this case, there will be no pairs, as it is a sorted Set {1, 2, 3, 4, ..... , n - 1, n}
  So there is no chance of A[i] > A[j], where i < j
  It will have ZERO pairs.
  ------------------------------------------------------------------------------------------  
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

void initialize_set(const int& n, std::vector<int>& V) {
	for (int i = 1; i <= n; ++i)
		V.push_back(i);
}

int main() {
	std::vector<int> V;
	initialize_set(10, V);

	std::vector<Pair> pairs;
	find_inversion_pairs(V, pairs);

	for (std::size_t i = 0; i < pairs.size(); ++i)
		printf("i == [%d] || j == [%d] || V[i] == [%d] || V[j] == [%d]\n",
			   pairs[i].i, pairs[i].j, V[pairs[i].i], V[pairs[i].j]);

	return 0;
}
