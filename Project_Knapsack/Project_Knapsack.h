#ifndef PROJECT_KNAPSACK_H
#define PROJECT_KNAPSACK_H

#include "../Item.h" 

// Updated Genetic Algorithm for Knapsack
int project_genetic_algorithm(int maxWeight, Item* items, int n, int population_size, int generations, double mutation_rate, int elitism_count);

// Updated Genetic Algorithm function with Iterative Improvement
int project_genetic_algorithm_with_improvement(int maxWeight, Item* items, int n, int population_size, int generations, double mutation_rate, int elitism_count, int time_limit);  // Add time_limit parameter



#endif // PROJECT_KNAPSACK_H
