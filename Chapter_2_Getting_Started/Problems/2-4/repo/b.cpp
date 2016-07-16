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
  If we will sort the Set {1, 2, 3, .... , n - 1, n} in reverse order, descending
  like S {n, n - 1, ..... , 2, 1}, it will have maximum inversion pairs.
  It will be F(n) = [n * (n - 1)] / 2
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
	for (int i = n; i >= 1; --i)
		V.push_back(i);
}

int main() {
	std::vector<int> V;
	initialize_set(10, V);

	std::vector<Pair> pairs;
	find_inversion_pairs(V, pairs);

	for (std::size_t i = 0; i < pairs.size(); ++i)
		printf("[%2d] -->> i == [%2d] || j == [%2d] || V[i] == [%4d] || V[j] == [%4d]\n",
			   i + 1, pairs[i].i, pairs[i].j, V[pairs[i].i], V[pairs[i].j]);

	return 0;
}
