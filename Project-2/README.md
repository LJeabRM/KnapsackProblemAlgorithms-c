# Knapsack Problem Algorithms (Project-2)

## 📚 Problem Overview

The **Knapsack Problem** is a classical optimization problem where the goal is to select a subset of items such that the total weight of the selected items does not exceed the knapsack's weight capacity, and the total value is maximized. This problem is commonly used in fields such as resource allocation, logistics, and finance.

### Types of Knapsack Problems:
1. **0/1 Knapsack Problem**: Each item can either be included or excluded from the knapsack.
2. **Fractional Knapsack Problem**: Items can be divided into fractions, and a fraction of an item can be included in the knapsack.

This repository implements the **0/1 Knapsack Problem** using **Genetic Algorithms (GA)** with **Parallel Processing** and **Dynamic Mutation** to improve solution quality and computation speed, especially for large-scale datasets.

## 💻 Algorithms Implemented

- **Genetic Algorithm (GA) with Parallel Processing**: The GA is used to explore the solution space by evolving a population of solutions. This algorithm selects, crosses over, and mutates solutions over multiple generations. Parallel processing is applied to speed up the computation, especially when dealing with large input sizes.
  
- **Dynamic Mutation and Selection**: This enhancement improves the GA by dynamically adjusting mutation rates and selection strategies during execution. These adjustments help the algorithm avoid local optima and converge faster toward high-quality solutions.

## ⚙️ How It Works

The Genetic Algorithm (GA) with Iterative Improvement and Tournament Selection works as follows:

1. **Initialize Population**: A population of random solutions is created. Each solution is represented by a chromosome, which indicates whether an item is included in the knapsack (1) or not (0).
2. **Evaluate Fitness**: Each solution's fitness is evaluated based on the total value of the selected items, ensuring the total weight does not exceed the knapsack's capacity. If the weight exceeds the capacity, the solution is penalized.
3. **Selection**: The best solutions are selected for reproduction. **Tournament Selection** is used, where multiple individuals are randomly chosen, and the best among them (based on fitness) is selected as a parent.
4. **Crossover**: Pairs of selected solutions (parents) are combined (crossed over) to create offspring solutions. Each offspring inherits traits from both parent solutions, which helps introduce diversity in the population.
5. **Mutation**: Some offspring undergo random mutations (flipping bits). The mutation is applied based on a dynamic mutation rate, allowing the algorithm to adapt and explore more solutions, and the mutated solution is checked to ensure the weight is within the limit.
6. **Iterative Improvement**: The best solution found so far is further refined using an **Iterative Improvement** method, where bits in the chromosome are flipped and the fitness is evaluated. If this improves the solution, the change is kept; otherwise, the flip is reverted.
7. **Repeat**: This process of evaluating, selecting, crossing over, and mutating continues over multiple generations. The algorithm runs until the time limit is reached or the solution converges to a satisfactory result.

