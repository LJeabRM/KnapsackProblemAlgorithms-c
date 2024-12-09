#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Dynamic Programming/DP.h"   // Include Dynamic Programming header
#include "Simulated Annealing/SA.h"  // Include Simulated Annealing header
#include "Greedy/Greedy.h"           // Include Greedy header
#include "Genetic Algorithm/GA.h"   // Include Genetic Algorithm
#include "Iterativeimprovement/IP.h" // Include Iterativeimprovement
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

    // Solve using Dynamic Programming
    printf("Dynamic Programming:\n");
    clock_t startDP = clock();
    int maxValueDP = knapsackDP(maxWeight, items, n);
    clock_t stopDP = clock();
    double durationDP = ((double)(stopDP - startDP)) / CLOCKS_PER_SEC * 1000;
    printf("Maximum Cost = %d\n", maxValueDP);
    printf("Run Time (ms): %.2lf ms\n", durationDP);

    printf("===================================================\n");

    // Solve using Simulated Annealing
    printf("Simulated Annealing:\n");
    clock_t startSA = clock();
    int maxValueSA = knapsackSA(maxWeight, items, n);
    clock_t stopSA = clock();
    double durationSA = ((double)(stopSA - startSA)) / CLOCKS_PER_SEC * 1000;
    printf("Maximum Cost = %d\n", maxValueSA);
    printf("Run Time (ms): %.2lf ms\n", durationSA);

    printf("===================================================\n");

    // Solve using Greedy
    printf("Greedy:\n");
    clock_t startGreedy = clock();
    int maxValueGreedy = knapsackGreedy(maxWeight, items, n);
    clock_t stopGreedy = clock();
    double durationGreedy = ((double)(stopGreedy - startGreedy)) / CLOCKS_PER_SEC * 1000;
    printf("Maximum Cost = %d\n", maxValueGreedy);
    printf("Run Time (ms): %.2lf ms\n", durationGreedy);

    printf("===================================================\n");

    // Solve using Iterative Improvement
    printf("Iterative Improvement:\n");
    clock_t startIP = clock();
    int maxValueIP = iterativeImprovementKnapsack(maxWeight, items, n);
    clock_t stopIP = clock();
    double durationIP = ((double)(stopIP - startIP)) / CLOCKS_PER_SEC * 1000;
    printf("Maximum Cost = %d\n", maxValueIP);
    printf("Run Time (ms): %.2lf ms\n", durationIP);

    printf("===================================================\n");

    // Solve using Genetic Algorithm
    int population_size = 50;
    int generations = 100;
    double mutation_rate = 0.05;
    int elitism_count = 5;

    printf("Genetic Algorithm:\n");
    printf("Population Size: %d\n", population_size);
    printf("Generations Quantity: %d\n", generations);
    printf("Mutation Rate: %.6f\n", mutation_rate);
    printf("Elitism Count: %d\n", elitism_count);

    clock_t startGA = clock();
    int maxValueGA = genetic_algorithm(maxWeight, items, n, population_size, generations, mutation_rate, elitism_count);
    clock_t stopGA = clock();
    double durationGA = ((double)(stopGA - startGA)) / CLOCKS_PER_SEC * 1000;

    printf("\nMaximum Cost = %d\n", maxValueGA);
    printf("Run Time (ms): %.2lf ms\n", durationGA);

    printf("===================================================\n");

    // Free allocated memory
    free(items);
    return 0;
}
