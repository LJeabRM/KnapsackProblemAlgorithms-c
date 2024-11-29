#include "IP.h"
#include <stdlib.h>
#include <stdio.h>

// Function to calculate the total value of items in the knapsack
static int knapsackValue(Item items[], int n, int capacity, int *currentWeight) {
    int totalValue = 0;
    *currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (items[i].isPick) {
            *currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    // If the weight exceeds capacity, return -1 as an invalid solution
    if (*currentWeight > capacity) {
        return -1;
    }

    return totalValue;
}

// Function to calculate the value-to-weight ratio and sort items
static void sortItemsByRatio(Item items[], double ratio[], int n) {
    for (int i = 0; i < n; i++) {
        ratio[i] = (items[i].weight > 0) ? (double)items[i].value / items[i].weight : 0.0;
        items[i].isPick = 0; // Initialize all items as not picked
    }

    // Sort items by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                double tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;

                // Swap corresponding items
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

// Iterative Improvement Knapsack Function
int iterativeImprovementKnapsack(int capacity, Item items[], int n) {
    double *ratio = (double *)malloc(n * sizeof(double));
    if (!ratio) {
        printf("Error: Memory allocation failed for ratio array.\n");
        return -1;
    }

    int currentWeight = 0;

    // Step 1: Sort items by value-to-weight ratio
    sortItemsByRatio(items, ratio, n);

    // Step 2: Initialize solution with greedy approach
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            items[i].isPick = 1; // Pick the item
            currentWeight += items[i].weight;
        }
    }

    int currentValue = knapsackValue(items, n, capacity, &currentWeight);

    // Step 3: Iteratively improve the solution
    int improved = 1;
    while (improved) {
        improved = 0;

        // Try swapping items in the knapsack with items outside
        for (int i = 0; i < n; i++) {
            if (items[i].isPick) {
                // Remove the item and check if the value increases
                items[i].isPick = 0;
                int tempWeight = 0;
                int tempValue = knapsackValue(items, n, capacity, &tempWeight);

                if (tempValue > currentValue) {
                    currentValue = tempValue;
                    currentWeight = tempWeight;
                    improved = 1;
                    break; // Restart the improvement loop
                } else {
                    // Revert if no improvement
                    items[i].isPick = 1;
                }
            } else {
                // Try adding the item if it is not in the knapsack
                items[i].isPick = 1;
                int tempWeight = 0;
                int tempValue = knapsackValue(items, n, capacity, &tempWeight);

                if (tempValue > currentValue && tempWeight <= capacity) {
                    currentValue = tempValue;
                    currentWeight = tempWeight;
                    improved = 1;
                    break; // Restart the improvement loop
                } else {
                    // Revert if no improvement
                    items[i].isPick = 0;
                }
            }
        }
    }

    free(ratio); // Release memory for ratio array
    return currentValue;
}
