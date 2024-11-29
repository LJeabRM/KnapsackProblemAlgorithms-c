#include "IP.h"
#include <stdlib.h>
#include <stdio.h>

// Function to calculate the value-to-weight ratio and sort items
static void sortItemsByRatio(Item items[], double ratio[], int n) {
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)items[i].value / items[i].weight;
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
    double* ratio = (double*)malloc(n * sizeof(double));
    if (!ratio) {
        printf("Error: Memory allocation failed for ratio array.\n");
        return -1;
    }

    int currentWeight = 0;
    int currentValue = 0;

    // Step 1: Sort items by value-to-weight ratio
    sortItemsByRatio(items, ratio, n);

    // Step 2: Initialize solution with greedy approach
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            currentValue += items[i].value;
        }
    }

    // Step 3: Iteratively improve the solution
    int improved = 1;
    int maxIterations = 1000; // Limit iterations to avoid infinite loop
    int iteration = 0;

    while (improved && iteration < maxIterations) {
        improved = 0;
        iteration++;

        for (int i = 0; i < n; i++) {
            if (currentWeight >= items[i].weight) {
                // Try removing the item
                currentWeight -= items[i].weight;
                currentValue -= items[i].value;

                for (int j = 0; j < n; j++) {
                    if (currentWeight + items[j].weight <= capacity && j != i) {
                        // Try adding another item
                        int newWeight = currentWeight + items[j].weight;
                        int newValue = currentValue + items[j].value;

                        if (newValue > currentValue) {
                            currentValue = newValue;
                            currentWeight = newWeight;
                            improved = 1;
                            break; // Restart the improvement loop
                        }
                    }
                }

                // Revert removal if no improvement
                if (!improved) {
                    currentWeight += items[i].weight;
                    currentValue += items[i].value;
                } else {
                    break; // Restart the loop if improved
                }
            }
        }
    }

    free(ratio); // Release memory for ratio array
    return currentValue;
}
