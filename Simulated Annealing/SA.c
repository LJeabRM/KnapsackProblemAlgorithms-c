#include "SA.h"
#include <stdlib.h>
#include <stdio.h> 
#include <math.h>
#include <time.h>

// Helper function to calculate total weight and value of a solution
void evaluateSolution(int* solution, Item* items, int n, int* totalWeight, int* totalValue) {
    *totalWeight = 0;
    *totalValue = 0;

    for (int i = 0; i < n; ++i) {
        if (solution[i]) {
            *totalWeight += items[i].weight;
            *totalValue += items[i].value;
        }
    }
}

// Simulated Annealing function for Knapsack Problem
int knapsackSA(int maxWeight, Item* items, int n) {
    int* currentSolution = (int*)calloc(n, sizeof(int)); // Initial solution (all items excluded)
    int* bestSolution = (int*)calloc(n, sizeof(int));

    if (currentSolution == NULL || bestSolution == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Parameters for simulated annealing
    double temperature = 1000.0;
    double coolingRate = 0.99;
    int maxIterations = 1000;

    // Seed the random number generator
    srand(time(NULL));

    // Evaluate initial solution
    int currentWeight = 0, currentValue = 0;
    evaluateSolution(currentSolution, items, n, &currentWeight, &currentValue);

    int bestWeight = currentWeight, bestValue = currentValue;

    // Simulated Annealing Loop
    for (int iteration = 0; iteration < maxIterations && temperature > 1e-3; ++iteration) {
        // Generate a neighbor solution
        int* neighborSolution = (int*)malloc(n * sizeof(int));
        if (neighborSolution == NULL) {
            printf("Memory allocation failed.\n");
            free(currentSolution);
            free(bestSolution);
            return -1;
        }

        for (int i = 0; i < n; ++i) {
            neighborSolution[i] = currentSolution[i];
        }

        int index = rand() % n; // Pick a random item
        neighborSolution[index] = 1 - neighborSolution[index]; // Flip inclusion/exclusion

        // Evaluate neighbor solution
        int neighborWeight = 0, neighborValue = 0;
        evaluateSolution(neighborSolution, items, n, &neighborWeight, &neighborValue);

        // Check feasibility of the neighbor solution
        if (neighborWeight <= maxWeight) {
            // Calculate change in value
            int deltaValue = neighborValue - currentValue;

            // Accept or reject the neighbor solution
            if (deltaValue > 0 || ((double)rand() / RAND_MAX) < exp(deltaValue / temperature)) {
                for (int i = 0; i < n; ++i) {
                    currentSolution[i] = neighborSolution[i];
                }
                currentWeight = neighborWeight;
                currentValue = neighborValue;

                // Update the best solution if improved
                if (currentValue > bestValue) {
                    for (int i = 0; i < n; ++i) {
                        bestSolution[i] = currentSolution[i];
                    }
                    bestWeight = currentWeight;
                    bestValue = currentValue;
                }
            }
        }

        // Free neighbor solution
        free(neighborSolution);

        // Cool down the temperature
        temperature *= coolingRate;
    }

    // Free allocated memory
    free(currentSolution);
    free(bestSolution);

    return bestValue; // Return the value of the best solution
}
