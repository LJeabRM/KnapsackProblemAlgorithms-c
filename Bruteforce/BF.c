#include "BF.h"

// Recursive utility function for Bruteforce Knapsack
int knapsackBFUtil(int maxWeight, Item* items, int n) {
    if (n == 0 || maxWeight == 0)
        return 0;

    // If the weight of the nth item exceeds the current capacity, exclude it
    if (items[n - 1].weight > maxWeight)
        return knapsackBFUtil(maxWeight, items, n - 1);

    // Calculate the value of including and excluding the current item
    int includeItem = items[n - 1].value + knapsackBFUtil(maxWeight - items[n - 1].weight, items, n - 1);
    int excludeItem = knapsackBFUtil(maxWeight, items, n - 1);

    // Return the maximum of the two options
    return (includeItem > excludeItem) ? includeItem : excludeItem;
}

// Main function for Bruteforce Knapsack
int knapsackBF(int maxWeight, Item* items, int n) {
    return knapsackBFUtil(maxWeight, items, n);
}
