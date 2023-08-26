/*
 ============================================================================
 Name        : Stock.c
 Author      : Mahmoud-Helmy
 Description : Find the maximum profit from buying and selling stocks
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the maximum profit using a single transaction
int maxProfit(int *prices, int size) {
    if (size <= 1) {
        return 0;
    }

    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < size; ++i) {
        if (prices[i] > min_price) {
            // Calculate the profit if selling at the current price
            int current_profit = prices[i] - min_price;

            // Update the maximum profit if the current profit is higher
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        } else {
            // Update the minimum price if a lower price is encountered
            min_price = prices[i];
        }
    }

    return max_profit;
}

// Function to calculate the maximum profit using multiple transactions
int maxProfit2(int *prices, int size) {
    int max_profit = 0;

    for (int i = 1; i < size; ++i) {
        if (prices[i] > prices[i - 1]) {
            // Accumulate profit from selling at each increasing price
            max_profit += prices[i] - prices[i - 1];
        }
    }

    return max_profit;
}

int main(void) {
    int array[4] = { 2, 6, 3, 10 };

    // Calculate the maximum profit using multiple transactions
    int max = maxProfit2(array, 4);

    // Print the calculated maximum profit
    printf("Maximum Profit: %d\n", max);

    return 0;
}
