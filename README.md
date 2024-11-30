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
7. [**Project Knapsack**](Project_Knapsack): A project-specific implementation to solve the Knapsack problem with additional features, such as integration of multiple algorithms for comparison.

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
  - [Project Knapsack](Project_Knapsack): `Project_Knapsack/Project_Knapsack.c`, `Project_Knapsack/Project_Knapsack.h`
- 📄 **Input Files**:
  - `knapsack25.txt`: Input file for a problem with 25 items.
  - `knapsack50.txt`: Input file for a problem with 50 items.
  - `knapsack100.txt`: Input file for a problem with 100 items.
  - `knapsack500.txt`: Input file for a problem with 500 items.
  - `knapsack1000.txt`: Input file for a problem with 1000 items.
- ⚙️ **Batch Files**:
  - `Run-25.bat`, `Run-50.bat`, `Run-100.bat`: Scripts to run the program with specific inputs.

---

## 💻 **How to Compile**
To compile the program, use the following command in a terminal or command prompt:

```bash
 gcc -o "main.exe" "main.c" "Bruteforce/BF.c" "Dynamic Programming/DP.c" "Genetic Algorithm/GA.c" "Greedy/Greedy.c" "Simulated Annealing/SA.c" "Iterativeimprovement/IP.c" "Project_Knapsack/Project_Knapsack.c" -I. -lm
```

---

## 📝 **Algorithm Details**

### **1. Bruteforce (BF)**  
- Exhaustive search that explores all possible combinations of items to find the optimal solution.  
- Guarantees the best result but is computationally expensive as the number of items increases.  
- **Time Complexity**: \(O(2^n)\), where \(n\) is the number of items.

---

### **2. Dynamic Programming (DP)**  
- Efficiently solves the problem by breaking it down into smaller subproblems and storing intermediate results in a table.  
- Solves the problem in a bottom-up manner, avoiding redundant calculations.  
- Guarantees an optimal solution.  
- **Time Complexity**: \(O(n 	imes W)\), where \(n\) is the number of items and \(W\) is the knapsack capacity.

---

### **3. Genetic Algorithm (GA)**  
- Evolutionary algorithm inspired by natural selection.  
- Utilizes populations of solutions and evolves them through selection, crossover, and mutation to approximate the optimal solution.  
- Best suited for large or complex problems where exact solutions are computationally infeasible.  
- Does not guarantee an optimal solution but often provides near-optimal results.  
- **Time Complexity**: Depends on population size, number of generations, and mutation/crossover rates.

---

### **4. Greedy Algorithm**  
- Heuristic method that selects items based on their value-to-weight ratio in descending order.  
- Quickly generates a feasible solution but does not guarantee the optimal one, especially for cases where high-value items with large weights are skipped.  
- Best used for approximate solutions in time-sensitive scenarios.  
- **Time Complexity**: \(O(n \log n)\), due to sorting of items.

---

### **5. Simulated Annealing (SA)**  
- Optimization method inspired by the annealing process in metallurgy.  
- Explores the solution space by accepting suboptimal solutions temporarily to escape local optima.  
- Gradually reduces the acceptance probability of worse solutions as the algorithm progresses (cooling schedule).  
- Effective for large-scale or constrained problems but requires careful parameter tuning.  
- **Time Complexity**: Depends on the cooling schedule and the number of iterations.

---

### **6. Iterative Improvement (IP)**  
- Starts with a feasible solution and iteratively refines it by modifying the selection of items in the knapsack.  
- Evaluates neighboring solutions by adding or removing items and accepts changes only if they improve the total value.  
- Simple and intuitive but may get stuck in local optima.  
- Often used to refine heuristic solutions.  
- **Time Complexity**: Depends on the number of iterations and neighboring solutions considered.

---

### **7. Project Knapsack**  
- A project-specific implementation that utilizes a Genetic Algorithm (GA) to solve the 0/1 Knapsack Problem.
- It integrates multiple genetic algorithm-based techniques, including elitism, crossover, mutation, and adaptive mutation, to optimize the selection of items for the knapsack.
- The implementation provides a framework for evaluating the performance of the algorithm with different mutation rates and elitism counts, making it suitable for comparative analysis and practical applications.
- **Time Complexity**: Varies depending on the algorithms used and their respective input parameters.
