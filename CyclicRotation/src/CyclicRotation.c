#include <stdio.h>
#include <stdlib.h>

struct Results {
    int N;
    int *A;
};

struct Results solution(int A[], int N, int K) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.N = N;

    if (K == 0 || N <= 1) {
        result.A = A;
    } else {
        int i;
        int *retA = malloc(sizeof(int) * N);
        if (retA == NULL)
            exit(1);

        K = K % N;

        for (i = 0; i < N; i++) {
            int where_to = (i + K) % N;
            retA[where_to] = A[i];
        }
        result.A = retA;
    }

    return result;
}

int main(void) {
    int A[] = {3, 6, 1, 10};
    int i;
    struct Results result;

    result = solution(A, sizeof(A) / sizeof(A[0]), 5);

    for (i = 0; i < result.N; i++) {
        printf("%d ", result.A[i]);
    }

    return 0;
}
