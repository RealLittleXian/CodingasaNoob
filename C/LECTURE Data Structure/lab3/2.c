long long mapNumber(int *mapping, int num) {
    if (num == 0) {
        return mapping[0]; // Special case for 0
    }

    long long mappedNum = 0;
    long long multiplier = 1;
    int temp = num;

    while (temp > 0) {
        int digit = temp % 10;
        mappedNum += (long long)mapping[digit] * multiplier;
        multiplier *= 10;
        temp /= 10;
    }

    return mappedNum;
}

// Comparison function for qsort
int compare(const void *a, const void *b, void *arg) {
    int *mapping = (int *)arg;
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    long long mappedNum1 = mapNumber(mapping, num1);
    long long mappedNum2 = mapNumber(mapping, num2);

    if (mappedNum1 < mappedNum2) {
        return -1;
    } else if (mappedNum1 > mappedNum2) {
        return 1;
    } else {
        return 0; // Maintain relative order
    }
}

void sortJumbled(int *mapping, int *nums, int numsSize) {
    // Use qsort to sort the nums array based on the mapped values
    qsort_r(nums, numsSize, sizeof(int), compare, mapping);

    // Print the sorted array
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
