#include <stdio.h>

void swap(int *arr1, int *arr2, int i) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    printf("array1:");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("array2:");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++){
    swap(arr1, arr2, i);
}
    printf("array1 after swap:");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("array2 after swap:");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
