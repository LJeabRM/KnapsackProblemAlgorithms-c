#include "Greedy.h"
#include <stdlib.h>

// Function to compare value/weight ratio of two items
int compareByValuePerWeight(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;

    double ratioA = (double)itemA->value / itemA->weight;
    double ratioB = (double)itemB->value / itemB->weight;

    if (ratioA > ratioB) return -1; // Sort in descending order
    else if (ratioA < ratioB) return 1;
    return 0;
}

int knapsackGreedy(int maxWeight, Item* items, int n) {
    // Sort items by value/weight ratio
    qsort(items, n, sizeof(Item), compareByValuePerWeight);

    int totalValue = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= maxWeight) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // No room for the whole item
            break;
        }
    }

    return totalValue;
}
