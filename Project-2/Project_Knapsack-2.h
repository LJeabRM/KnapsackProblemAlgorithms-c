#ifndef PROJECT_KNAPSACK_2_H
#define PROJECT_KNAPSACK_2_H

#include "../Item.h" 

// Updated Genetic Algorithm function with Iterative Improvement
int project_genetic_algorithm_with_improvement(int maxWeight, Item* items, int n, int population_size, int generations, double mutation_rate, int elitism_count, int time_limit);

#endif // PROJECT_KNAPSACK_H
