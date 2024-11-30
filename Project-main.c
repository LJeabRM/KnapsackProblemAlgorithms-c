#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Project_Knapsack/Project_Knapsack.h" // Include Project Knapsack header
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

    // Solve using Project Knapsack with Adaptive Genetic Algorithm
    int adaptive_population_size = 50;
    int adaptive_generations = 100;
    double initial_mutation_rate = 0.05;
    int adaptive_elitism_count = 5;

    printf("Project Knapsack (Adaptive Genetic Algorithm):\n");
    printf("\nPopulation Size: %d\n", adaptive_population_size);
    printf("Generations Quantity: %d\n", adaptive_generations);
    printf("Initial Mutation Rate: %.6f\n", initial_mutation_rate);
    printf("Elitism Count: %d\n", adaptive_elitism_count);

    clock_t startAdaptiveGA = clock();

    // function call
    int maxValueAdaptiveGA = project_genetic_algorithm_adaptive_mutation(
        maxWeight,
        items,
        n,
        adaptive_population_size,
        adaptive_generations,
        initial_mutation_rate,
        adaptive_elitism_count
    );

    clock_t stopAdaptiveGA = clock();
    double durationAdaptiveGA = ((double)(stopAdaptiveGA - startAdaptiveGA)) / CLOCKS_PER_SEC;

    printf("\nMaximum Cost: %d\n", maxValueAdaptiveGA);
    printf("Run Time: %.6f seconds\n", durationAdaptiveGA);

    printf("===================================================\n");

    // Free allocated memory
    free(items);
    return 0;
}
