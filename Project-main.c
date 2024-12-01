#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Project_Knapsack/Project_Knapsack.h" // Include Project Knapsack header
#include "Item.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: Project-main.exe <time_limit> <input_file>\n");
        return 1;
    }

    // Display explanation about time limit (This part will be shown from the .bat file)
    int time_limit = atoi(argv[1]); // Convert time limit to integer
    if (time_limit <= 0) {
        printf("Invalid time limit.\n");
        return 1;
    }


    // Read the number of items from input file
    FILE *input_file = fopen(argv[2], "r");  // Open the file passed via arguments
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    int n;
    // Read the number of items
    if (fscanf(input_file, "%d", &n) != 1 || n <= 0) {
        printf("Invalid number of items.\n");
        fclose(input_file);
        return 1;
    }

    // Allocate memory for the items
    Item* items = (Item*)malloc(n * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed.\n");
        fclose(input_file);
        return 1;
    }

    // Read the items' weights and values from the input file
    for (int i = 0; i < n; ++i) {
        if (fscanf(input_file, "%d %d", &items[i].weight, &items[i].value) != 2) {
            printf("Invalid input for item %d.\n", i + 1);
            free(items);
            fclose(input_file);
            return 1;
        }
    }

    int maxWeight;
    // Read the maximum weight capacity from the file
    if (fscanf(input_file, "%d", &maxWeight) != 1 || maxWeight <= 0) {
        printf("Invalid maximum weight capacity.\n");
        free(items);
        fclose(input_file);
        return 1;
    }

    fclose(input_file);  // Close the file after reading

    printf("====================================================================================\n");

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
    printf("\nTime Limit: %d seconds\n", time_limit);
    printf("------------------------------------------------------------------------------------\n");

    clock_t startAdaptiveGA = clock();

    // Function call with time limit
    int maxValueWithImprovement = project_genetic_algorithm_with_improvement(
        maxWeight,
        items,
        n,
        adaptive_population_size,
        adaptive_generations,
        initial_mutation_rate,
        adaptive_elitism_count,
        time_limit  // Pass the time limit to the function
    );

    clock_t stopAdaptiveGA = clock();
    double durationAdaptiveGA = ((double)(stopAdaptiveGA - startAdaptiveGA)) / CLOCKS_PER_SEC;

    printf("Maximum Cost: %d\n", maxValueWithImprovement);
    printf("Run Time: %.6f seconds\n", durationAdaptiveGA);

    printf("====================================================================================\n");

    // Free allocated memory
    free(items);
    return 0;
}
