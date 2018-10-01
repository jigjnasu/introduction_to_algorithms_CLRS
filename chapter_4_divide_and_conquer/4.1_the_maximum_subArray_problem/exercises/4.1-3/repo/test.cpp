#include "max_sub_array.h"
#include "max_sub_array_iterative.h"
#include <cstdio>
#include <cstdlib>
#include <chrono>

void print_vector(const std::vector<int>& V) {
    printf("-----------------------------------------------------------\n");
    for (std::size_t i = 0; i < V.size(); ++i)
        printf("%d ", V[i]);
    printf("\n-----------------------------------------------------------\n");
}

void generate(std::vector<int>& V, const int& n) {
    const int start = -100;
    const int end = 100;
    for (int i = 0; i < n; ++i) {
        int value = rand() % (end - start + 1) + start;
        V.push_back(value);
    }
}

void max_dnc(const std::vector<int>& V) {
    MaxSubArray<int> max;
    printf("Max sub array sum Divide and Conquer    == [%d]\n", max.Max(V));
}

void max_iterative(const std::vector<int>& V) {
    MaxSubArrayIterative<int> max;

    int sum = 0;
    int start = V[0];
    int end = 0;
    max.Max(V, sum, start, end);
    printf("Max sub array sum from [%4d] to [%4d] == [%d]\n", start, end, sum);
}

int main() {
    int n = 2;
    while (1) {
        std::vector<int> V;
        generate(V, n);

        //print_vector(V);

        using clock = std::chrono::steady_clock;
        clock::time_point start_d = clock::now();
        max_dnc(V);
        clock::time_point end_d = clock::now();

        clock::time_point start_i = clock::now();
        max_iterative(V);
        clock::time_point end_i = clock::now();

        printf("-----------------------------------------------------------------------------\n");
        printf("N == [%d] || Divide and Concquer == [%16lf] seconds || Iterative == [%16lf] seconds\n",
               n, (end_d - start_d, (end_i - start_i).count()));
        printf("-----------------------------------------------------------------------------\n");

        if ((end_i - start_i) > (end_d - start_d))
            break;

        ++n;
    }

    return 0;
}
