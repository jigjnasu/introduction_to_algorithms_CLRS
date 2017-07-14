/*
  Let's mesaure the time of Insertion, Selection, Merge, Insertion + Merge, Selection + Merge with same set of data.
*/

/*
  ------------------ RESULT ------------------------
  Insertion Sort Time       == [0.56900000] seconds
  Selection Sort Time       == [0.47000000] seconds
  Merge Sort Time           == [0.02000000] seconds
  Bubble Sort Time          == [1.09100000] seconds
  Quick Sort Time           == [0.01000000] seconds
  Insertion Merge Sort Time == [0.57000000] seconds
  Selection Merge Sort Time == [0.67000000] seconds
  ------------------ RESULT ------------------------  
*/

#include "Insertion.h"
#include "Selection.h"
#include "Merge.h"
#include "Bubble.h"
#include "Quick.h"
#include "InsertionMerge.h"
#include "SelectionMerge.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>

void print(const std::vector<int>& V) {
    printf("----------------------------------------------------------------------------------------------------\n");
    for (std::size_t i = 0; i < V.size(); ++i)
        printf("%d ", V[i]);
    printf("\n----------------------------------------------------------------------------------------------------\n");	
}

int random(int min, int max) {
    return min + rand() % (max - min + 1);
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

    std::clock_t start = clock();
    insertion_sort.Sort(V1);
    printf("Insertion Sort Time O(n^2)       == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    start = clock();
    selection_sort.Sort(V2);
    printf("Selection Sort Time O(n^2)       == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    start = clock();
    merge_sort.Sort(V3);
    printf("Merge Sort Time     O(nlg(n))    == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    start = clock();
    bubble_sort.Sort(V4);
    printf("Bubble Sort Time    O(n^2)       == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    start = clock();
    quick_sort.Sort(V5);
    printf("Quick Sort Time     O(nlg(n))    == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    start = clock();
    insertion_merge_sort.Sort(V6);
    printf("Insertion Merge Sort Time        == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    start = clock();
    selection_merge_sort.Sort(V7);
    printf("Selection Merge Sort Time        == [%.8f] seconds\n", (clock() - start) / static_cast<double>(CLOCKS_PER_SEC));

    return 0;
}
