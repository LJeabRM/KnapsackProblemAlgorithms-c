# Knapsack Problem Algorithms (Dynamic Programming)

## 📚 Problem Overview

The **Knapsack Problem** is a well-known combinatorial optimization problem. The goal is to select a subset of items from a collection such that the total weight of the selected items does not exceed the capacity of the knapsack, and the total value is maximized.

### Types of Knapsack Problems
1. **0/1 Knapsack Problem**: Each item can either be included or excluded from the knapsack.
2. **Fractional Knapsack Problem**: Items can be divided into fractions, and a fraction of an item can be included in the knapsack.

This repository implements the **0/1 Knapsack Problem** using **Dynamic Programming**.

## 💻 Algorithms Implemented

- **Dynamic Programming Approach**: This solution builds a table `dp[][]`, where each entry `dp[i][w]` represents the maximum value that can be obtained with the first `i` items and a knapsack capacity of `w`.

## ⚙️ How It Works

The dynamic programming solution follows these steps:
1. Create a 2D array `dp[][]` where each entry represents the maximum value achievable with a given weight capacity.
2. Fill the array using a bottom-up approach, iterating through each item and weight combination.
3. After processing all items, the entry `dp[n][W]` (where `n` is the number of items and `W` is the maximum weight capacity) will contain the maximum value achievable.
