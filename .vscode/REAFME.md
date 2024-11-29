# 🚀 Knapsack Problem Algorithms (C Implementation)

This repository provides implementations of various algorithms to solve the 0/1 Knapsack Problem using the C programming language. The algorithms demonstrate different approaches and are designed to compare their performance and execution times.

---

## 📂 **Implemented Algorithms**
1. [**Bruteforce (BF)**](Bruteforce): Exhaustive search to find the optimal solution.
2. [**Dynamic Programming (DP)**](Dynamic%20Programming): Efficient method that uses a table to solve subproblems.
3. [**Genetic Algorithm (GA)**](Genetic%20Algorithm): Evolutionary algorithm inspired by natural selection.
4. [**Greedy Algorithm**](Greedy): Heuristic method that prioritizes items with the highest value-to-weight ratio.
5. [**Simulated Annealing (SA)**](Simulated%20Annealing): Optimization method inspired by annealing in metallurgy.
6. [**Iterative Improvement (IP)**](Iterativeimprovement): Improves an initial solution iteratively until no better solution is found.

---

## 📂 **File Structure**
- **`main.c`**: Main program that runs all algorithms to solve the knapsack problem.
- **Algorithm-specific Files**:
  - [Bruteforce](Bruteforce): `Bruteforce/BF.c`, `Bruteforce/BF.h`
  - [Dynamic Programming](Dynamic%20Programming): `Dynamic Programming/DP.c`, `Dynamic Programming/DP.h`
  - [Genetic Algorithm](Genetic%20Algorithm): `Genetic Algorithm/GA.c`, `Genetic Algorithm/GA.h`
  - [Greedy](Greedy): `Greedy/Greedy.c`, `Greedy/Greedy.h`
  - [Simulated Annealing](Simulated%20Annealing): `Simulated Annealing/SA.c`, `Simulated Annealing/SA.h`
  - [Iterative Improvement](Iterativeimprovement): `Iterativeimprovement/IP.c`, `Iterativeimprovement/IP.h`
- 📄 **Input Files**:
  - `knapsack25.txt`: Input file for a problem with 25 items.
  - `knapsack50.txt`: Input file for a problem with 50 items.
  - `knapsack100.txt`: Input file for a problem with 100 items.
- ⚙️ **Batch Files**:
  - `Run-25.bat`, `Run-50.bat`, `Run-100.bat`: Scripts to run the program with specific inputs.

---

## 💻 **How to Compile**
To compile the program, use the following command in a terminal or command prompt:

```bash
gcc -o "main.exe" "main.c" "Bruteforce/BF.c" "Dynamic Programming/DP.c" "Genetic Algorithm/GA.c" "Greedy/Greedy.c" "Simulated Annealing/SA.c" "Iterativeimprovement/IP.c" -I. -lm
