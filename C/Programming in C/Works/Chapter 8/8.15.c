#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i=1; i<n; i++) {
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j-=1;  //从key开始，向后复制元素
        }
        arr[j+1] = key;
    }
}

int main() {
    int x;
    scanf("%d",&x);
    int arr[] = {11,22,33,44,55,66,77,x};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionSort(arr, n);
    
    printf("array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
