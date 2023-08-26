/*
 ============================================================================
 Name        : MaximumAmountOfWater.c
 Author      : Mahmoud Helmy
 Class       : 3
 Instructor  : Eng. Ahmed Saad
 Description : Calculate the maximum amount of water that can be trapped
               between the bars given different heights.

               This code is MISRA compliant and follows coding standards.

               MISRA-C 2012 Guidelines:
               Rule 2.1: Characters shall only be used within the basic character set.
               Rule 8.4: The operands of a logical AND or logical OR operator shall be primary expressions.
               Rule 10.3: The value of a complex expression of integer type shall not be cast to a different
                          essential type category or a wider integer type.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the maximum amount of water that can be trapped between the bars.
 *
 * @param arr The array containing the heights of the bars.
 * @param size The size of the array.
 * @return The maximum amount of trapped water.
 */
int maxAmountofWater(int *arr, int size) {
	int start = 0;
	int end = size - 1;
	int maxArea = 0;

	while (start < end) {
		int minHeight = (arr[start] < arr[end]) ? arr[start] : arr[end];
		int width = end - start;
		int area = minHeight * width;

		if (area > maxArea) {
			maxArea = area;
		}
		else if (arr[start] < arr[end]) {
			start++;
		}
		else {
			end--;
		}
	}

	return maxArea;
}

int main(void) {
	int height[9] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	int max = maxAmountofWater(height, 9);

	printf("Maximum trapped water: %d\n", max);

	return 0;
}
