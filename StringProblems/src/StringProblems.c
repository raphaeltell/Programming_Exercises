#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_str(char *init, char *end) {
    char temp;
    char *ret = init;

    while (init < end) {
        temp = *init;
        *init++ = *end;
        *end-- = temp;
    }

    return ret;
}

char *reverse_words(char *str) {
    char *temp = str;
    char *word_boundary = str;

    while (*temp) {
        temp++;

        if (*temp == '\0') {
            reverse_str(word_boundary, temp - 1);
        } else if (*temp == ' ') {
            reverse_str(word_boundary, temp - 1);
            word_boundary = temp + 1;
        }
    }

    return reverse_str(str, temp - 1);
}

int is_same_histogram(int A[], int B[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (A[i] != B[i])
            return 0;
    }
    return 1;
}

int b_contain_anagram_a(char A[], int size_A, char B[], int size_B) {
    int hist_A[128] = {0};
    int hist_B[128] = {0};
    int i;

    if (size_A > size_B)
        return 0;

    for (i = 0; i < size_A; i++) {
        hist_A[(int) A[i]]++;
        hist_B[(int) B[i]]++;
    }

    i = 0;
    while (1) {
        if (is_same_histogram(hist_A, hist_B, (sizeof(hist_A)) / sizeof(hist_A[0])))
            return 1;

        if (i == (size_B - size_A))
            return 0;

        // Slide window
        hist_B[(int)  B[i]]--;
        hist_B[(int) B[i + size_A]]++;
        i++;
    }
}

int main(void) {
    char A[] = "cbd";
    char B[] = "asidjiscbdckas";
    char C[] = "abcdefgh";
    char D[] = "Testando a inversao de palavras";

    printf("%d\n", b_contain_anagram_a(A, strlen(A), B, strlen(B)));
    printf("%s\n", reverse_str((char *) C, C + strlen(C) - 1));
    printf("%s\n", reverse_words(D));

    return 0;
}
