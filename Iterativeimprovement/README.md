# Knapsack Problem Algorithms (Iterative Improvement)

## 📚 Problem Overview

The **Knapsack Problem** is a classical optimization problem where the goal is to select a subset of items such that the total weight does not exceed the knapsack's capacity, and the total value is maximized.

### Types of Knapsack Problems:
1. **0/1 Knapsack Problem**: Each item can either be included or excluded from the knapsack.
2. **Fractional Knapsack Problem**: Items can be divided into fractions, and a fraction of an item can be included in the knapsack.

This repository implements the **0/1 Knapsack Problem** using the **Iterative Improvement** approach.

## 💻 Algorithms Implemented

- **Iterative Improvement**: This approach aims to iteratively enhance an initial solution by applying small changes. Starting with a feasible solution, it looks for ways to improve it through iterations by swapping items or adjusting the selection to increase the total value without violating the knapsack's capacity.

## ⚙️ How It Works

1. **Initialization**: Start with an initial feasible solution. This could be a random selection of items or a greedy solution.
2. **Neighborhood Exploration**: In each iteration, examine the "neighborhood" of the current solution. This typically involves making small changes to the solution, such as swapping an item in or out of the knapsack.
3. **Evaluation**: Evaluate the new solution by calculating its total value and checking whether it satisfies the weight constraint.
4. **Improvement**: If the new solution is better (i.e., higher value and within capacity), adopt it as the new current solution.
5. **Termination**: The process continues for a set number of iterations or until no further improvements are found.

The algorithm's goal is to improve the solution incrementally until an optimal or near-optimal solution is found.

