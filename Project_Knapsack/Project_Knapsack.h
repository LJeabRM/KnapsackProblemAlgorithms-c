#ifndef PROJECT_KNAPSACK_H
#define PROJECT_KNAPSACK_H

#include "../Item.h" 

// Updated Genetic Algorithm for Knapsack
int project_genetic_algorithm(int maxWeight, Item* items, int n, int population_size, int generations, double mutation_rate, int elitism_count);

// Updated Adaptive Mutation Genetic Algorithm for Knapsack
int project_genetic_algorithm_adaptive_mutation(int maxWeight, Item* items, int n, int population_size, int generations, double initial_mutation_rate, int elitism_count);

#endif // PROJECT_KNAPSACK_H
