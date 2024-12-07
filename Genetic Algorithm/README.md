# Knapsack Problem Algorithms (Genetic Algorithm)

## 📚 Problem Overview

The **Knapsack Problem** is a classical optimization problem where the goal is to select a subset of items such that the total weight does not exceed the knapsack's capacity, and the total value is maximized.

### Types of Knapsack Problems:
1. **0/1 Knapsack Problem**: Each item can either be included or excluded from the knapsack.
2. **Fractional Knapsack Problem**: Items can be divided into fractions, and a fraction of an item can be included in the knapsack.

This repository implements the **0/1 Knapsack Problem** using the **Genetic Algorithm** approach.

## 💻 Algorithms Implemented

- **Genetic Algorithm**: The genetic algorithm simulates the process of natural evolution. It applies the principles of selection, crossover (recombination), and mutation to evolve the solution to the knapsack problem over multiple generations.

## ⚙️ How It Works

The Genetic Algorithm approach works as follows:
1. **Initialization**: Randomly generate an initial population of potential solutions (chromosomes).
2. **Selection**: Select the fittest individuals (solutions) based on their fitness score (the total value of selected items, considering the weight constraint).
3. **Crossover**: Combine two selected solutions (parents) to produce new solutions (offspring) by exchanging segments of their chromosome representations.
4. **Mutation**: Introduce random changes to the offspring to maintain genetic diversity and prevent premature convergence.
5. **Repeat**: Continue the process for a set number of generations or until convergence, at which point the best solution is returned.
