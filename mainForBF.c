#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Bruteforce/BF.h" // Include Bruteforce header
#include "Item.h"

int main() {
    int n;
    // Read the number of items from input
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items.\n");
        return 1;
    }

    // Allocate memory for the items
    Item* items = (Item*)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read the items' weights and values
    for (int i = 0; i < n; ++i) {
        if (scanf("%d %d", &items[i].weight, &items[i].value) != 2) {
            printf("Invalid input for item %d.\n", i + 1);
            free(items);
            return 1;
        }
    }

    int maxWeight;
    // Read the maximum weight capacity
    if (scanf("%d", &maxWeight) != 1 || maxWeight <= 0) {
        printf("Invalid maximum weight capacity.\n");
        free(items);
        return 1;
    }

    printf("===================================================\n");

    // Solve using Bruteforce
    printf("Bruteforce:\n");
    clock_t startBF = clock();
    int maxValueBF = knapsackBF(maxWeight, items, n);
    clock_t stopBF = clock();
    double durationBF = ((double)(stopBF - startBF)) / CLOCKS_PER_SEC * 1000;
    printf("Value = %d\n", maxValueBF);
    printf("Execution Time (BF): %.2lf ms\n", durationBF);

    printf("===================================================\n");

    // Free allocated memory
    free(items);
    return 0;
}
