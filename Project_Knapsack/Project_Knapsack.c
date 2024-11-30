#include "Project_Knapsack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    int* chromosome;
    int fitness;
} Individual;

// Function prototypes
void initialize_population(Individual* population, int population_size, int n);
void evaluate_population(Individual* population, int population_size, Item* items, int n, int maxWeight);
void crossover(Individual* parent1, Individual* parent2, Individual* offspring, int n);
void mutate(Individual* individual, int n, double mutation_rate);
void sort_population_by_fitness(Individual* population, int population_size);
void copy_individual(Individual* dest, Individual* src, int n);
int calculate_fitness(int* chromosome, Item* items, int n, int maxWeight);

// Updated Genetic Algorithm function
int project_genetic_algorithm(int maxWeight, Item* items, int n, int population_size, int generations, double mutation_rate, int elitism_count) {
    srand((unsigned int)time(NULL));

    // Initialize population
    Individual* population = (Individual*)malloc(population_size * sizeof(Individual));
    for (int i = 0; i < population_size; ++i) {
        population[i].chromosome = (int*)malloc(n * sizeof(int));
    }
    initialize_population(population, population_size, n);

    for (int gen = 0; gen < generations; ++gen) {
        // Evaluate population
        evaluate_population(population, population_size, items, n, maxWeight);

        // Sort population by fitness
        sort_population_by_fitness(population, population_size);

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
            mutate(&new_population[i], n, mutation_rate);
        }

        // Replace old population
        for (int i = 0; i < population_size; ++i) {
            free(population[i].chromosome);
        }
        free(population);
        population = new_population;
    }

    // Evaluate final population and find the best solution
    evaluate_population(population, population_size, items, n, maxWeight);
    int best_fitness = population[0].fitness;

    // Free memory
    for (int i = 0; i < population_size; ++i) {
        free(population[i].chromosome);
    }
    free(population);

    return best_fitness;
}

// Adaptive Genetic Algorithm with mutation rate adjustment
int project_genetic_algorithm_adaptive_mutation(int maxWeight, Item* items, int n, int population_size, int generations, double initial_mutation_rate, int elitism_count) {
    double mutation_rate = initial_mutation_rate;
    int stagnant_generations = 0; // Counter for generations without improvement

    srand((unsigned int)time(NULL));

    // Initialize population
    Individual* population = (Individual*)malloc(population_size * sizeof(Individual));
    for (int i = 0; i < population_size; ++i) {
        population[i].chromosome = (int*)malloc(n * sizeof(int));
    }
    initialize_population(population, population_size, n);

    int best_fitness = 0;

    for (int gen = 0; gen < generations; ++gen) {
        // Evaluate population
        evaluate_population(population, population_size, items, n, maxWeight);

        // Sort population by fitness
        sort_population_by_fitness(population, population_size);

        // Check for improvement
        if (population[0].fitness > best_fitness) {
            best_fitness = population[0].fitness;
            stagnant_generations = 0; // Reset stagnant generation counter
        } else {
            stagnant_generations++;
        }

        // Adjust mutation rate if no improvement for a while
        if (stagnant_generations > 10) {
            mutation_rate += 0.01; // Increase mutation rate slightly
        } else {
            mutation_rate = initial_mutation_rate; // Reset mutation rate
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
            mutate(&new_population[i], n, mutation_rate);
        }

        // Replace old population
        for (int i = 0; i < population_size; ++i) {
            free(population[i].chromosome);
        }
        free(population);
        population = new_population;
    }

    // Evaluate final population and find the best solution
    evaluate_population(population, population_size, items, n, maxWeight);
    best_fitness = population[0].fitness;

    // Free memory
    for (int i = 0; i < population_size; ++i) {
        free(population[i].chromosome);
    }
    free(population);

    return best_fitness;
}


// Helper functions
void initialize_population(Individual* population, int population_size, int n) {
    for (int i = 0; i < population_size; ++i) {
        for (int j = 0; j < n; ++j) {
            population[i].chromosome[j] = rand() % 2;
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
        if (weight > maxWeight) {
            return 0; // Invalid solution
        }
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

void mutate(Individual* individual, int n, double mutation_rate) {
    for (int i = 0; i < n; ++i) {
        if ((double)rand() / RAND_MAX < mutation_rate) {
            individual->chromosome[i] = 1 - individual->chromosome[i];
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
