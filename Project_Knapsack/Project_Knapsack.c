#include "Project_Knapsack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define TIME_LIMIT 10 // Time limit in seconds

typedef struct {
    int* chromosome;
    int fitness;
} Individual;

// Function prototypes
void initialize_population(Individual* population, int population_size, int n, Item* items, int maxWeight);
void evaluate_population(Individual* population, int population_size, Item* items, int n, int maxWeight);
void crossover(Individual* parent1, Individual* parent2, Individual* offspring, int n);
void mutate(Individual* individual, int n, double mutation_rate, Item* items, int maxWeight);
void sort_population_by_fitness(Individual* population, int population_size);
void copy_individual(Individual* dest, Individual* src, int n);
int calculate_fitness(int* chromosome, Item* items, int n, int maxWeight);
void iterative_improvement(Individual* individual, Item* items, int n, int maxWeight, double mutation_rate);

// Updated Genetic Algorithm function with Iterative Improvement
int project_genetic_algorithm_with_improvement(int maxWeight, Item* items, int n, int population_size, int generations, double mutation_rate, int elitism_count, int time_limit) {  // Add time_limit parameter
    srand((unsigned int)time(NULL));

    // Initialize population
    Individual* population = (Individual*)malloc(population_size * sizeof(Individual));
    for (int i = 0; i < population_size; ++i) {
        population[i].chromosome = (int*)malloc(n * sizeof(int));
    }
    initialize_population(population, population_size, n, items, maxWeight);

    Individual best_solution;
    best_solution.chromosome = (int*)malloc(n * sizeof(int));
    best_solution.fitness = -1;

    time_t start_time = time(NULL);
    time_t current_time;
    int best_fitness_so_far = -1;

    // Store best solution over time
    int best_solution_in_time = -1;
    int total_generations = 0; // Keep track of the number of generations

    // Run until time limit is reached
    while (1) {
        total_generations++;

        // Evaluate population
        evaluate_population(population, population_size, items, n, maxWeight);

        // Sort population by fitness
        sort_population_by_fitness(population, population_size);

        // Check for the best solution
        if (population[0].fitness > best_solution.fitness) {
            copy_individual(&best_solution, &population[0], n);
        }

        // Store the best fitness in this generation
        if (population[0].fitness > best_fitness_so_far) {
            best_fitness_so_far = population[0].fitness;
        }

        // Apply Iterative Improvement on the best solution
        iterative_improvement(&best_solution, items, n, maxWeight, mutation_rate);

        // Update best solution found so far during the run
        best_solution_in_time = best_solution.fitness;

        // Check time limit
        current_time = time(NULL);
        if (difftime(current_time, start_time) >= time_limit) {
            // If time limit is reached, break the loop
            break;
        }

        // Create new population
        Individual* new_population = (Individual*)malloc(population_size * sizeof(Individual));
        for (int i = 0; i < population_size; ++i) {
            new_population[i].chromosome = (int*)malloc(n * sizeof(int));
        }

        // Elitism
        for (int i = 0; i < elitism_count; ++i) {
            copy_individual(&new_population[i], &population[i], n);
        }

        // Generate offspring
        for (int i = elitism_count; i < population_size; i += 2) {
            int parent1_idx = rand() % population_size;
            int parent2_idx = rand() % population_size;

            crossover(&population[parent1_idx], &population[parent2_idx], &new_population[i], n);
            if (i + 1 < population_size) {
                crossover(&population[parent2_idx], &population[parent1_idx], &new_population[i + 1], n);
            }
        }

        // Apply mutation
        for (int i = elitism_count; i < population_size; ++i) {
            mutate(&new_population[i], n, mutation_rate, items, maxWeight);
        }

        // Replace old population
        for (int i = 0; i < population_size; ++i) {
            free(population[i].chromosome);
        }
        free(population);
        population = new_population;
    }

    // Free memory
    for (int i = 0; i < population_size; ++i) {
        free(population[i].chromosome);
    }
    free(population);
    free(best_solution.chromosome);

    // Return the best solution found within the time limit
    return best_solution_in_time;
}



// Iterative Improvement function to refine the best solution
void iterative_improvement(Individual* individual, Item* items, int n, int maxWeight, double mutation_rate) {
    int best_fitness = individual->fitness;

    // Try to improve the current best solution by applying mutation and checking fitness
    for (int i = 0; i < n; ++i) {
        individual->chromosome[i] = 1 - individual->chromosome[i]; // Flip bit (mutation)
        int new_fitness = calculate_fitness(individual->chromosome, items, n, maxWeight);
        if (new_fitness > best_fitness) {
            best_fitness = new_fitness; // Accept the new solution
        } else {
            individual->chromosome[i] = 1 - individual->chromosome[i]; // Revert mutation if not improving
        }
    }
}

// Helper functions
void initialize_population(Individual* population, int population_size, int n, Item* items, int maxWeight) {
    for (int i = 0; i < population_size; ++i) {
        int weight = 0;
        for (int j = 0; j < n; ++j) {
            population[i].chromosome[j] = rand() % 2; // Random 0 or 1
            if (population[i].chromosome[j] == 1) {
                weight += items[j].weight;
            }
        }
        // Ensure valid solution
        while (weight > maxWeight) {
            int idx = rand() % n; // Randomly turn off an item
            if (population[i].chromosome[idx] == 1) {
                population[i].chromosome[idx] = 0;
                weight -= items[idx].weight;
            }
        }
    }
}

void evaluate_population(Individual* population, int population_size, Item* items, int n, int maxWeight) {
    for (int i = 0; i < population_size; ++i) {
        population[i].fitness = calculate_fitness(population[i].chromosome, items, n, maxWeight);
    }
}

int calculate_fitness(int* chromosome, Item* items, int n, int maxWeight) {
    int value = 0, weight = 0;
    for (int i = 0; i < n; ++i) {
        if (chromosome[i] == 1) {
            weight += items[i].weight;
            value += items[i].value;
        }
    }
    if (weight > maxWeight) {
        return value - (weight - maxWeight) * 2; // Penalize overweight solutions
    }
    return value;
}

void crossover(Individual* parent1, Individual* parent2, Individual* offspring, int n) {
    int crossover_point = rand() % n;
    for (int i = 0; i < crossover_point; ++i) {
        offspring->chromosome[i] = parent1->chromosome[i];
    }
    for (int i = crossover_point; i < n; ++i) {
        offspring->chromosome[i] = parent2->chromosome[i];
    }
}

void mutate(Individual* individual, int n, double mutation_rate, Item* items, int maxWeight) {
    int weight = 0;
    for (int i = 0; i < n; ++i) {
        if (individual->chromosome[i] == 1) {
            weight += items[i].weight;
        }
    }

    for (int i = 0; i < n; ++i) {
        if ((double)rand() / RAND_MAX < mutation_rate) {
            individual->chromosome[i] = 1 - individual->chromosome[i]; // Flip bit
            if (individual->chromosome[i] == 1) {
                weight += items[i].weight;
            } else {
                weight -= items[i].weight;
            }
        }
    }

    // Ensure valid solution after mutation
    while (weight > maxWeight) {
        int idx = rand() % n;
        if (individual->chromosome[idx] == 1) {
            individual->chromosome[idx] = 0;
            weight -= items[idx].weight;
        }
    }
}

void sort_population_by_fitness(Individual* population, int population_size) {
    for (int i = 0; i < population_size - 1; ++i) {
        for (int j = 0; j < population_size - i - 1; ++j) {
            if (population[j].fitness < population[j + 1].fitness) {
                Individual temp = population[j];
                population[j] = population[j + 1];
                population[j + 1] = temp;
            }
        }
    }
}

void copy_individual(Individual* dest, Individual* src, int n) {
    memcpy(dest->chromosome, src->chromosome, n * sizeof(int));
    dest->fitness = src->fitness;
}
