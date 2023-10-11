#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    // Dynamically allocate an integer array of size n
    int* sequence = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    // initialize
    int min = sequence[0];
    int max = sequence[0];

    // set min and max
    for (int i = 1; i < n; i++) {
        if (sequence[i] < min) {
            min = sequence[i];
        }
        if (sequence[i] > max) {
            max = sequence[i];
        }
    }

    int max_span = max - min;
    printf("%d\n", max_span);   //output

    // free memory of Array sequence
    free(sequence);

    return 0;
}
