/*
  Let's mesaure the time of Insertion, Selection, Merge, Insertion + Merge, Selection + Merge with same set of data.
*/

/*
  ------------------ RESULT ------------------------
  Insertion Sort Time O(n^2)       == [9.25836600] seconds
  Selection Sort Time O(n^2)       == [8.94840200] seconds
  Merge Sort Time     O(nlg(n))    == [0.10700800] seconds
  Bubble Sort Time    O(n^2)       == [20.97214500] seconds
  Quick Sort Time     O(nlg(n))    == [0.02332800] seconds
  Insertion Merge Sort Time        == [10.41897500] seconds
  Selection Merge Sort Time        == [10.52556500] seconds
  ------------------ RESULT ------------------------
*/

#include "insertion.h"
#include "selection.h"
#include "merge.h"
#include "bubble.h"
#include "quick.h"
#include "insertion_merge.h"
#include "selection_merge.h"
#include <cstdio>
#include <chrono>
#include <cstdlib>
#include <random>

void print(const std::vector<int>& V) {
    printf("----------------------------------------------------------------------------------------------------\n");
    for (std::size_t i = 0; i < V.size(); ++i)
        printf("%d ", V[i]);
    printf("\n----------------------------------------------------------------------------------------------------\n");
}

int random(int min, int max) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(min, max);
    return dt(rd);
}

int main() {
    std::vector<int> V1;
    for (int i = 0; i < 50000; ++i)
        V1.push_back(random(1, 10000000));
    std::vector<int> V2 = V1;
    std::vector<int> V3 = V1;
    std::vector<int> V4 = V1;
    std::vector<int> V5 = V1;
    std::vector<int> V6 = V1;
    std::vector<int> V7 = V1;

    InsertionSort<int> insertion_sort;
    SelectionSort<int> selection_sort;
    MergeSort<int> merge_sort;
    BubbleSort<int> bubble_sort;
    QuickSort<int> quick_sort;
    InsertionMerge<int> insertion_merge_sort;
    SelectionMerge<int> selection_merge_sort;

    using clock = std::chrono::steady_clock;
    clock::time_point start = clock::now();
    insertion_sort.Sort(V1);
    printf("Insertion Sort Time O(n^2)       == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));

    start = clock::now();
    selection_sort.Sort(V2);
    printf("Selection Sort Time O(n^2)       == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));

    start = clock::now();
    merge_sort.Sort(V3);
    printf("Merge Sort Time     O(nlg(n))    == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));

    start = clock::now();
    bubble_sort.Sort(V4);
    printf("Bubble Sort Time    O(n^2)       == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));

    start = clock::now();
    quick_sort.Sort(V5);
    printf("Quick Sort Time     O(nlg(n))    == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));

    start = clock::now();
    insertion_merge_sort.Sort(V6);
    printf("Insertion Merge Sort Time        == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));

    start = clock::now();
    selection_merge_sort.Sort(V7);
    printf("Selection Merge Sort Time        == [%16lf] seconds\n",
           std::chrono::duration<double>(clock::now() - start));

    return 0;
}
