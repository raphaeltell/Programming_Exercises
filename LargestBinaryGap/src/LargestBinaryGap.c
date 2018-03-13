#include <stdio.h>
#include <stdlib.h>

int solution(int N) {
    // write your code in C99 (gcc 6.2.0)
    int cur_chain = -1;
    int max_chain = 0;

    while (N > 0) {
        if (N % 2) {
            if (cur_chain > max_chain)
                max_chain = cur_chain;

            cur_chain = 0;
        } else if (cur_chain >= 0) {
            cur_chain++;
        }
        N /= 2;
    }

    return max_chain;
}

int main(void) {
    int M = 529;
    int N = 9;
    int O = 20;
    int P = 1041;

    printf("Solution for %d is: %d\n", M, solution(M));
    printf("Solution for %d is: %d\n", N, solution(N));
    printf("Solution for %d is: %d\n", O, solution(O));
    printf("Solution for %d is: %d\n", P, solution(P));

    return 0;
}
