#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * n);

    for (int i = 0; i < n; i++) {
        result[i] = (char*)malloc(sizeof(char) * 8);
    }

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) { result[i - 1] = "FizzBuzz\0"; }
        else if (i % 3 == 0) { result[i - 1] = "Fizz\0"; }
        else if (i % 5 == 0) { result[i - 1] = "Buzz\0"; }
        else {
            sprintf(result[i - 1], "%d", i);
        }
    }

    *returnSize = n;
    return result;
}


int main() {
    int n = 15;
    int* ptr = (int*)malloc(sizeof(int*));

    char** result = fizzBuzz(n, ptr);

    for (int i = 0; i < n; i++) {
        printf("%s, ", result[i]);
    }

    free(ptr);
    free(result);
}
