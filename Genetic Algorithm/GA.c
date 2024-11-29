#include "GA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Helper function to initialize the population
static int** create_population(int population_size, int num_items) {
    int** population = (int**)malloc(population_size * sizeof(int*));
    for (int i = 0; i < population_size; i++) {
        population[i] = (int*)malloc(num_items * sizeof(int));
        for (int j = 0; j < num_items; j++) {
            population[i][j] = rand() % 2; // Random binary chromosome
        }
    }
    return population;
}

// Helper function to calculate fitness
static int calculate_fitness(int* chromosome, Item* items, int num_items, int capacity, int* total_weight) {
    int total_value = 0;
    *total_weight = 0;

    for (int i = 0; i < num_items; i++) {
        if (chromosome[i]) {
            *total_weight += items[i].weight;
            total_value += items[i].value;
        }
    }
    return (*total_weight <= capacity) ? total_value : 0;
}

// Helper function to perform mutation
static void mutate_chromosome(int* chromosome, int num_items, double mutation_rate) {
    for (int i = 0; i < num_items; i++) {
        if ((double)rand() / RAND_MAX < mutation_rate) {
            chromosome[i] = 1 - chromosome[i]; // Flip the bit
        }
    }
}

// Helper function for crossover
static void perform_crossover(int* parent1, int* parent2, int num_items, int* child1, int* child2) {
    int crossover_point = rand() % num_items;
    for (int i = 0; i < crossover_point; i++) {
        child1[i] = parent1[i];
        child2[i] = parent2[i];
    }
    for (int i = crossover_point; i < num_items; i++) {
        child1[i] = parent2[i];
        child2[i] = parent1[i];
    }
}

// Genetic Algorithm function
int genetic_algorithm(int capacity, Item* items, int num_items) {
    // Default parameters
    int population_size = 50;
    int generations = 100;
    double mutation_rate = 0.05;
    int elitism_count = 5;

    srand(time(NULL)); // Seed the random number generator

    int** population = create_population(population_size, num_items);
    int best_fitness = 0;
    int* best_solution = (int*)malloc(num_items * sizeof(int));

    for (int generation = 0; generation < generations; generation++) {
        int* fitness_values = (int*)malloc(population_size * sizeof(int));
        int total_fitness = 0;

        // Evaluate fitness
        for (int i = 0; i < population_size; i++) {
            int total_weight;
            fitness_values[i] = calculate_fitness(population[i], items, num_items, capacity, &total_weight);
            total_fitness += fitness_values[i];

            if (fitness_values[i] > best_fitness) {
                best_fitness = fitness_values[i];
                memcpy(best_solution, population[i], num_items * sizeof(int));
            }
        }

        // Create new population
        int** new_population = (int**)malloc(population_size * sizeof(int*));
        for (int i = 0; i < elitism_count; i++) {
            new_population[i] = (int*)malloc(num_items * sizeof(int));
            memcpy(new_population[i], population[i], num_items * sizeof(int));
        }

        for (int i = elitism_count; i < population_size; i += 2) {
            int parent1_index = rand() % population_size;
            int parent2_index = rand() % population_size;

            int* child1 = (int*)malloc(num_items * sizeof(int));
            int* child2 = (int*)malloc(num_items * sizeof(int));

            perform_crossover(population[parent1_index], population[parent2_index], num_items, child1, child2);

            mutate_chromosome(child1, num_items, mutation_rate);
            mutate_chromosome(child2, num_items, mutation_rate);

            new_population[i] = child1;
            if (i + 1 < population_size) {
                new_population[i + 1] = child2;
            }
        }

        // Free old population
        for (int i = 0; i < population_size; i++) {
            free(population[i]);
        }
        free(population);

        population = new_population;
        free(fitness_values);
    }

    // Cleanup
    for (int i = 0; i < population_size; i++) {
        free(population[i]);
    }
    free(population);
    free(best_solution);

    return best_fitness;
}
