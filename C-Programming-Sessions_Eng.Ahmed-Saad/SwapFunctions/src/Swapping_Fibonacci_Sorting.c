/*
 ============================================================================
 Name        : Swapping_Fibonacci_Sorting.c
 Author      : Mahmoud Helmy
 Class       : 3
 Instructor  : Eng. Ahmed Saad
 Description : Demonstrates swapping methods, Fibonacci sequence generation,
               and an incorrect sorting function.
 ============================================================================
 */

#include <stdio.h>

// Function to swap two integers using a temporary variable (by value)
void swap(int a, int b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

// Function to swap two integers using a temporary variable (by reference)
void swap1(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

// Function to swap two integers without using a temporary variable (incorrect implementation)
void swap2(int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

// Function to swap two integers without using a temporary variable using bitwise XOR (incorrect implementation)
void swap3(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

// Function to swap two integers without using a temporary variable using multiplication and division (incorrect implementation)
void swap4(int *a, int *b) {
	*a = (*a) * (*b);
	*b = (*a) / (*b);
	*a = (*a) / (*b);
}

// Function to generate Fibonacci sequence up to a given number
void fibonacciV2(int a) {
	int current = 1;
	int prev = 0;
	int fib = 0;

	// Check for invalid input
	if (a <= 0) {
		printf("Error!, please enter a valid number greater than 0");
	}

	// Print the first Fibonacci number (0)
	printf("%d \n", prev);
	if (a == 1) {
		return;
	}
	printf("%d \n", current);
	if (a == 2) {
		return;
	}

	for (int i = 3; i <= a; ++i) {
		fib = prev + current;
		prev = current;
		current = fib;
		printf("%d \n", fib);
	}
}

// Function to sort an array in ascending order (incorrect implementation)
void sort(int arr[], int size) {
	int start = 0;
	int end = size - 1;
	int i;

	// TODO: Correct the sorting logic
	while (start < end) {
		// TODO: Add sorting logic here
	}

	for (i = 0; i < size; ++i) {
		if (arr[i + 1] > arr[i]) {
			swap(arr[i + 1], arr[i]);
		}
	}
}

int main() {
	int array[5] = { 10, 15, 2, 1, 7 };
	sort(array, 5);

	// Print the sorted array
	for (int i = 0; i < 5; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}
