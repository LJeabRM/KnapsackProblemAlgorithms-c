# Knapsack Problem Algorithms (Brute Force)

## 📚 Problem Overview

The **Knapsack Problem** is a classical optimization problem where the goal is to select a subset of items such that the total weight does not exceed the knapsack's capacity, and the total value is maximized.

### Types of Knapsack Problems:
1. **0/1 Knapsack Problem**: Each item can either be included or excluded from the knapsack.
2. **Fractional Knapsack Problem**: Items can be divided into fractions, and a fraction of an item can be included in the knapsack.

This repository implements the **0/1 Knapsack Problem** using the **Brute Force** approach.

## 💻 Algorithms Implemented

- **Brute Force Algorithm**: This is the simplest approach for solving the Knapsack Problem. It evaluates all possible subsets of items to find the one that provides the maximum value without exceeding the weight capacity. Although this method guarantees the optimal solution, it is computationally expensive because it must check every possible combination of items.

## ⚙️ How It Works

1. **Initialization**: Start by considering every item and its inclusion or exclusion from the knapsack.
2. **Generating All Possible Subsets**: For a given set of `n` items, there are `2^n` possible combinations of items (including the empty set). The brute force approach examines all of these subsets to determine which one maximizes the total value without exceeding the knapsack's weight limit.
3. **Subset Evaluation**: For each subset, calculate the total weight and total value.
   - If the total weight of the subset is less than or equal to the knapsack's weight capacity, calculate the total value.
   - If the total value is higher than the previously found value, update the best solution.
4. **Selection**: Once all subsets have been evaluated, the subset with the highest value (that fits within the weight capacity) is selected as the solution.
5. **Termination**: The algorithm terminates when all subsets have been evaluated, and the best subset is returned as the optimal solution.

The brute force method is straightforward and guarantees the optimal solution, but its time complexity is **O(2^n)**, which makes it inefficient for large numbers of items.
