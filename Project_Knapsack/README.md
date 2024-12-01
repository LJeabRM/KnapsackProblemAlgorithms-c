# 🚀 Project Knapsack (C Implementation)

This folder contains the **Project Knapsack** implementation, which utilizes a combination of the **Genetic Algorithm (GA)** and **Iterative Improvement (IP)** techniques to solve the **0/1 Knapsack Problem**. The implementation also features a **time limit** feature to control the runtime, balancing the trade-off between computation time and solution quality.

---

## 📂 **Overview of the Algorithm**

The **0/1 Knapsack Problem** is a classic optimization problem where the goal is to maximize the value of items placed in a knapsack, without exceeding its weight capacity. The challenge is to choose a subset of items that maximizes the total value while respecting the weight constraint.

This project combines two optimization techniques:

1. **Genetic Algorithm (GA)**: Inspired by natural selection, GA works with a population of potential solutions and evolves them through operations like **selection**, **crossover**, and **mutation**.
2. **Iterative Improvement (IP)**: After the GA has evolved a solution, IP is applied to improve the selected solution by exploring neighboring solutions and selecting the best one.

Additionally, the algorithm runs with a **time limit**, ensuring that the search process stops after a predefined time, which allows for quick evaluations of performance across different configurations.

---

## 📂 **File Structure**

- **`Project_Knapsack.c`**: The main program that implements the knapsack problem-solving approach using GA with iterative improvement.
- **`Project_Knapsack.h`**: Header file containing the function prototypes and definitions used in the `Project_Knapsack.c` file.
- **`Project-main.c`**: The entry point that runs the **Project Knapsack** algorithm with the GA and IP approach, with a time limit feature.
- **Input files**:
  - `knapsack500.txt`: Input file for a problem with 500 items.
  - `knapsack1000.txt`: Input file for a problem with 1000 items.
- ⚙️ **Batch Files**:
  - **For `Project-main.c`** (Project-specific implementation using GA with Iterative Improvement):
    - `Run-500.bat`: Script to run the project-specific implementation with an input of 500 items.
    - `Run-1000.bat`: Script to run the project-specific implementation with an input of 1000 items.

---

## 💻 **Key Functions and Their Explanation**

### 1. **`project_genetic_algorithm_with_improvement()`**
   - **Purpose**: This function is the main entry point for solving the knapsack problem using a combination of GA and IP.
   - **How it works**:
     - The function initializes the population, evaluates the fitness of each individual, and applies the genetic algorithm steps (selection, crossover, mutation).
     - It then applies iterative improvement on the best solution found so far.
     - The algorithm stops once the predefined time limit has been reached.
   
   - **Inputs**:
     - `maxWeight`: The weight capacity of the knapsack.
     - `items`: The list of items available for selection.
     - `n`: The number of items.
     - `population_size`: The size of the population for the GA.
     - `generations`: Number of generations to evolve the population.
     - `mutation_rate`: Probability of mutation during crossover.
     - `elitism_count`: Number of top individuals to carry over without modification.
     - `time_limit`: Time limit for the search process.

   - **Outputs**: Returns the best solution found within the time limit.

### 2. **`initialize_population()`**
   - **Purpose**: Initializes the population with random solutions.
   - **How it works**:
     - Each individual in the population is represented by a chromosome (a binary vector), which encodes the selection of items.
     - The function ensures that the initial solutions are feasible (i.e., they do not exceed the knapsack's weight capacity).

   - **Inputs**:
     - `population`: The array of individuals (solutions).
     - `population_size`: The number of individuals in the population.
     - `n`: The number of items.
     - `items`: The list of items.
     - `maxWeight`: The weight capacity of the knapsack.

   - **Outputs**: Populates the `population` array with random solutions.

### 3. **`evaluate_population()`**
   - **Purpose**: Evaluates the fitness of each individual in the population.
   - **How it works**:
     - The function calculates the total value and weight of each solution. The fitness is the value of the solution minus a penalty if the weight exceeds the knapsack’s capacity.

   - **Inputs**:
     - `population`: The array of individuals to evaluate.
     - `population_size`: The number of individuals in the population.
     - `items`: The list of items available for selection.
     - `n`: The number of items.
     - `maxWeight`: The weight capacity of the knapsack.

   - **Outputs**: Updates the fitness of each individual in the population.

### 4. **`crossover()`**
   - **Purpose**: Performs crossover (recombination) between two parent individuals to generate offspring.
   - **How it works**:
     - The function combines parts of two parent solutions to create a new solution (offspring).
     - A random crossover point is selected, and the genes (items) before the point come from one parent, while the genes after the point come from the other parent.

   - **Inputs**:
     - `parent1`: The first parent solution.
     - `parent2`: The second parent solution.
     - `offspring`: The resulting child solution.
     - `n`: The number of items.

   - **Outputs**: Fills the `offspring` with a combination of `parent1` and `parent2` genes.

### 5. **`mutate()`**
   - **Purpose**: Applies mutation to a solution.
   - **How it works**:
     - The mutation function randomly flips the bits of the chromosome to explore new solutions.
     - The mutation is applied with a probability determined by the mutation rate.

   - **Inputs**:
     - `individual`: The solution (individual) to mutate.
     - `n`: The number of items.
     - `mutation_rate`: Probability of mutation.
     - `items`: The list of items.
     - `maxWeight`: The weight capacity of the knapsack.

   - **Outputs**: Mutates the `individual` in-place.

### 6. **`iterative_improvement()`**
   - **Purpose**: Refines the best solution found so far.
   - **How it works**:
     - The function evaluates neighboring solutions by flipping each bit (item) in the solution.
     - If a neighboring solution improves the fitness, it is accepted as the new solution.

   - **Inputs**:
     - `individual`: The solution to improve.
     - `items`: The list of items.
     - `n`: The number of items.
     - `maxWeight`: The weight capacity of the knapsack.
     - `mutation_rate`: Rate of mutation used to explore neighboring solutions.

   - **Outputs**: Updates the `individual` to the best possible solution after improvement.

---

## 📝 **Summary**

The **Project Knapsack** implementation leverages **Genetic Algorithms (GA)** combined with **Iterative Improvement (IP)** to solve the **0/1 Knapsack Problem**. By using adaptive mutation, elitism, and selective crossover, the algorithm efficiently explores the solution space. The integration of **Iterative Improvement (IP)** helps refine solutions for better accuracy. The time-limited execution provides a way to balance runtime and solution quality.

This project provides an excellent framework for testing and comparing various optimization techniques for the knapsack problem.
