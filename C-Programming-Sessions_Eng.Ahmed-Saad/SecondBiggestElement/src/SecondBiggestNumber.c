/*
 ============================================================================
 Name        : SecondBiggestNumber.c
 Author      : Mahmoud Helmy
 Description : This program finds the second biggest number in an array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Swap two integers.
 *
 * @param a First integer.
 * @param b Second integer.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Sort an array in descending order.
 *
 * @param arr The array to be sorted.
 * @param size The size of the array.
 */
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] > arr[i]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

/**
 * Find and print the second biggest number in the array.
 *
 * @param arr The array of integers.
 * @param size The size of the array.
 */
void secondBiggest(int arr[], int size) {
    sort(arr, size);

    if (size >= 2) {
        printf("Sorted array: ");
        for (int i = 0; i < size; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\nSecond biggest number is %d\n", arr[1]);
    } else {
        printf("Array size is less than 2.\n");
    }
}

int main() {
    int array[4] = {13, 16, 14, 1};
    int size = sizeof(array) / sizeof(int);

    printf("Original array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    secondBiggest(array, size);

    return 0;
}
