#include "Project_Knapsack-2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

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
int calculate_fitness(int* chromosome, Item* items, int n, int maxWeight);
void iterative_improvement(Individual* individual, Item* items, int n, int maxWeight, double mutation_rate);
int tournament_selection(Individual* population, int population_size, int tournament_size);

// Updated Genetic Algorithm function with Iterative Improvement and Tournament Selection
int project_genetic_algorithm_with_improvement(int maxWeight, Item* items, int n, int population_size, int generations, double mutation_rate, int elitism_count, int time_limit) {
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
    int best_solution_in_time = -1;

    // Run until time limit is reached
    while (1) {
        // Evaluate population
        evaluate_population(population, population_size, items, n, maxWeight);

        // Sort population by fitness
        sort_population_by_fitness(population, population_size);

        // Check for the best solution
        if (population[0].fitness > best_solution.fitness) {
            int total_weight = 0;
            for (int i = 0; i < n; ++i) {
                if (population[0].chromosome[i] == 1) {
                    total_weight += items[i].weight;
                }
            }

            // If overweight, discard this solution and try again
            if (total_weight <= maxWeight) {
                memcpy(best_solution.chromosome, population[0].chromosome, n * sizeof(int));
                best_solution.fitness = population[0].fitness;
            }
        }

        // Apply Iterative Improvement on the best solution
        iterative_improvement(&best_solution, items, n, maxWeight, mutation_rate);

        // Update best solution found so far during the run
        best_solution_in_time = best_solution.fitness;

        // Check time limit
        current_time = time(NULL);
        if (difftime(current_time, start_time) >= time_limit) {
            break;
        }

        // Create new population
        Individual* new_population = (Individual*)malloc(population_size * sizeof(Individual));
        for (int i = 0; i < population_size; ++i) {
            new_population[i].chromosome = (int*)malloc(n * sizeof(int));
        }

        // Elitism
        for (int i = 0; i < elitism_count; ++i) {
            memcpy(new_population[i].chromosome, population[i].chromosome, n * sizeof(int));
            new_population[i].fitness = population[i].fitness;
        }

        // Generate offspring using Tournament Selection
        for (int i = elitism_count; i < population_size; i += 2) {
            int parent1_idx = tournament_selection(population, population_size, 3);
            int parent2_idx = tournament_selection(population, population_size, 3);

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

    // Calculate and print the total weight of the best solution
    int total_weight = 0;
    for (int i = 0; i < n; ++i) {
        if (best_solution.chromosome[i] == 1) {
            total_weight += items[i].weight;
        }
    }

    // Print the results
    printf("Best Solution Fitness: %d\n", best_solution.fitness);
    printf("Total Weight of Selected Items: %d\n", total_weight);  // Display total weight of selected items

    // Free memory
    for (int i = 0; i < population_size; ++i) {
        free(population[i].chromosome);
    }
    free(population);
    free(best_solution.chromosome);

    // Return the best solution found within the time limit
    return best_solution_in_time;
}

void iterative_improvement(Individual* individual, Item* items, int n, int maxWeight, double mutation_rate) {
    int best_fitness = individual->fitness;

    // Try to improve the current best solution by applying mutation and checking fitness
    for (int i = 0; i < n; ++i) {
        individual->chromosome[i] = 1 - individual->chromosome[i]; // Flip bit (mutation)
        int new_fitness = calculate_fitness(individual->chromosome, items, n, maxWeight);
        if (new_fitness > best_fitness) {
            best_fitness = new_fitness;
            individual->fitness = new_fitness;
        } else {
            individual->chromosome[i] = 1 - individual->chromosome[i]; // Revert mutation if not improving
        }
    }
}

int tournament_selection(Individual* population, int population_size, int tournament_size) {
    int best_idx = -1;
    int best_fitness = -1;

    for (int i = 0; i < tournament_size; i++) {
        int idx = rand() % population_size;
        if (best_idx == -1 || population[idx].fitness > best_fitness) {
            best_fitness = population[idx].fitness;
            best_idx = idx;
        }
    }

    return best_idx;
}

void initialize_population(Individual* population, int population_size, int n, Item* items, int maxWeight) {
    for (int i = 0; i < population_size; ++i) {
        int weight = 0;
        for (int j = 0; j < n; ++j) {
            population[i].chromosome[j] = rand() % 2;
            if (population[i].chromosome[j] == 1) {
                weight += items[j].weight;
            }
        }

        // Ensure valid solution (repair if overweight)
        while (weight > maxWeight) {
            int idx = rand() % n;
            if (population[i].chromosome[idx] == 1) {
                population[i].chromosome[idx] = 0;
                weight -= items[idx].weight;
            }
        }
    }
}

void evaluate_population(Individual* population, int population_size, Item* items, int n, int maxWeight) {
    for (int i = 0; i < population_size; ++i) {
        int total_weight = 0;
        for (int j = 0; j < n; ++j) {
            if (population[i].chromosome[j] == 1) {
                total_weight += items[j].weight;
            }
        }

        // If overweight, discard this individual by setting its fitness to -1
        if (total_weight > maxWeight) {
            population[i].fitness = -1;
        } else {
            population[i].fitness = calculate_fitness(population[i].chromosome, items, n, maxWeight);
        }
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
    // Penalize solutions that exceed maxWeight
    if (weight > maxWeight) {
        return value - (weight - maxWeight) * 2; // Subtract penalty for overweight
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
        double r = (double)rand() / RAND_MAX;
        if (r < mutation_rate) {
            individual->chromosome[i] = 1 - individual->chromosome[i]; // Flip bit
            if (individual->chromosome[i] == 1) {
                weight += items[i].weight;
            } else {
                weight -= items[i].weight;
            }
        }
    }

    // Double check if overweight (shouldn't be if we handle carefully)
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
