# Knapsack Problem Algorithms (Greedy Approach)

## 📚 Problem Overview

The **Knapsack Problem** is a classical optimization problem. The goal is to select a subset of items such that the total weight of the selected items does not exceed the knapsack's weight capacity, and the total value is maximized.

### Types of Knapsack Problems:
1. **0/1 Knapsack Problem**: Each item can either be included or excluded from the knapsack.
2. **Fractional Knapsack Problem**: Items can be divided into fractions, and a fraction of an item can be included in the knapsack.

This repository implements the **Fractional Knapsack Problem** using the **Greedy Algorithm**.

## 💻 Algorithms Implemented

- **Greedy Algorithm**: The greedy approach solves the Fractional Knapsack Problem by selecting items based on their **value-to-weight ratio**. The items with the highest ratio are selected first, and fractions of the items can be included in the knapsack.

## ⚙️ How It Works

The greedy solution works as follows:
1. Compute the **value-to-weight ratio** for each item.
2. Sort the items in descending order of their value-to-weight ratio.
3. Add items to the knapsack starting with the item having the highest ratio, and continue adding items or fractions of items until the knapsack reaches its capacity.

## 📥 Input Format

The input consists of:
- **n**: The number of items.
- **W**: The maximum weight capacity of the knapsack.
- **values[]**: An array of item values.
- **weights[]**: An array of item weights.

## 📤 Output Format

The output consists of:
- **Maximum Value**: The maximum total value that can be obtained by selecting the items based on the greedy approach, possibly with fractional selections.
