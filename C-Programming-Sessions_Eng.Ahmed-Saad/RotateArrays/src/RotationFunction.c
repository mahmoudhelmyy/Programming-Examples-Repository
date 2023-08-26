/*
 ============================================================================
 Name        : RotationFunction.c
 Author      : Mahmoud Helmy
 Description : This program demonstrates two methods for rotating an array
               left or right by a given number of positions.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Rotate an array to the left by k positions.
 *
 * @param arr The array to be rotated.
 * @param size The size of the array.
 * @param k The number of positions to rotate.
 */
void rotate_left(int *arr, int size, int k) {
    int temp;
    k = k % size;

    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            temp = arr[0];
            for (int j = 0; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            arr[size - 1] = temp;
        }
    }
}

/**
 * Rotate an array to the right by k positions.
 *
 * @param arr The array to be rotated.
 * @param size The size of the array.
 * @param k The number of positions to rotate.
 */
void rotate_right(int *arr, int size, int k) {
    int temp;
    k = k % size;

    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            temp = arr[size - 1];
            for (int j = size - 1; j > 0; --j) {
                arr[j] = arr[j - 1];
            }
            arr[0] = temp;
        }
    }
}

int main(void) {
    int array[5] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(int);
    int rotations = 2; // Number of positions to rotate

    printf("Original array = ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    rotate_left(array, size, rotations); // Rotate left by 'rotations' positions

    printf("Rotated array = ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
