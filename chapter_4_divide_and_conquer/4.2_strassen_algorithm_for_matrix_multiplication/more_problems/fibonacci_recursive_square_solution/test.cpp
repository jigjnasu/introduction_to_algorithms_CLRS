#include "fibonacci.h"

void print(const int (&A)[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main() {
    for (int i = 1; i <= 30; i += 3) {
        Fibonacci<int> fibo;
        int result[2][2] = {0};
        fibo.Calculate(i, result);
        printf("%d %d %d ", result[1][1], result[1][0], result[0][0]);
    }
    printf("\n");

    return 0;
}
