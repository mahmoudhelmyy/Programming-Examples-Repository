/*
 ============================================================================
 Name        : SubArraysSum.c
 Author      : Mahmoud-Helmy
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void longestSubarrayWithSum(int arr[], int size, int sum) {
int start = 0;
int end = 0;
int currSum =arr[0];
while(end<size){
	if(currSum==sum && start<size){
        for (int i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
	}
	else if(currSum<=sum){
		end++;
		currSum +=arr[end];
	}
	else{
		currSum -=arr[start];
		start++;
	}

}
}
