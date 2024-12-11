# Knapsack Problem Algorithms (Simulated Annealing)

## 📚 Problem Overview

The **Knapsack Problem** is a classical optimization problem where the goal is to select a subset of items such that the total weight does not exceed the knapsack's capacity, and the total value is maximized.

### Types of Knapsack Problems:
1. **0/1 Knapsack Problem**: Each item can either be included or excluded from the knapsack.
2. **Fractional Knapsack Problem**: Items can be divided into fractions, and a fraction of an item can be included in the knapsack.

This repository implements the **0/1 Knapsack Problem** using the **Simulated Annealing** algorithm.

## 💻 Algorithms Implemented

- **Simulated Annealing**: This probabilistic algorithm simulates the process of annealing in metallurgy, where materials are heated and then slowly cooled to reach a state of minimum energy. In the context of the Knapsack Problem, the algorithm iteratively explores possible solutions by accepting new solutions that are worse with a certain probability, which decreases over time. This allows the algorithm to escape local optima and hopefully reach a global optimum.

## ⚙️ How It Works

1. **Initialization**: Start with an initial solution (typically random) that is feasible and has a corresponding value and weight.
2. **Temperature Schedule**: Set an initial "temperature" that controls the probability of accepting worse solutions. The temperature is gradually reduced over time.
3. **Iteration**: In each iteration, generate a new solution by making a small change to the current solution, such as swapping an item in or out of the knapsack.
4. **Acceptance Criterion**: Evaluate the new solution:
   - If the new solution is better (higher value and within the capacity), accept it.
   - If the new solution is worse, accept it with a probability proportional to the temperature and the difference in solution quality. This allows the algorithm to escape local optima.
5. **Cooling Schedule**: Gradually lower the temperature after each iteration, reducing the probability of accepting worse solutions.
6. **Termination**: The algorithm continues for a set number of iterations or until the temperature reaches a predefined threshold, at which point the best solution found is returned.

Simulated Annealing provides a balance between exploration (searching for new solutions) and exploitation (refining the best solutions), making it a powerful heuristic for optimization problems like the Knapsack Problem.

