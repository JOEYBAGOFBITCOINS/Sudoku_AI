CS627 Unit 5 Sudoku AI Solver

This project implements an artificial intelligence agent that solves a Sudoku puzzle using a systematic search approach. The solver is designed as part of the CS627 Design and Analysis of Algorithms course and demonstrates the application of state-space search, backtracking, and heuristic optimization.

Overview

The Sudoku solver models the puzzle as a state-space search problem. Each state represents a partially completed Sudoku board, and the goal is to reach a fully valid solution that satisfies all Sudoku constraints. The algorithm uses a recursive backtracking approach enhanced with a heuristic to improve efficiency.

Algorithm Approach

The solver uses backtracking combined with the Minimum Remaining Values heuristic. Instead of selecting an empty cell arbitrarily, the algorithm selects the cell with the fewest legal values available. This reduces the branching factor and helps eliminate invalid paths early in the search.

At each step, the algorithm:

Selects the most constrained empty cell
Generates all valid candidate values
Attempts each value recursively
Backtracks if a contradiction is reached

This approach significantly improves performance compared to naive brute-force methods.

Time Complexity

The worst-case time complexity of a naive brute-force approach is O(p^(n^2)), where n is the dimension of the board and p is the number of possible values for each cell. This exponential growth makes brute-force search impractical for larger problems.

By applying heuristic-guided search, the solver reduces the effective search space and improves performance in practice.

Program Structure

The main components of the program include:

Board representation using a 2D vector
Validation function to enforce Sudoku constraints
Candidate generation for possible values
Heuristic selection of the most constrained cell
Recursive backtracking solver

How to Run

Compile the program using:

g++ Unit5_Sudoku_AI/sudoku_solver.cpp -o sudoku_solver

Run the program using:

./sudoku_solver

The program will display the starting Sudoku board and the solved board in the terminal.

Output

The solver prints:

The initial puzzle configuration
The completed Sudoku solution

This output is used in the project report to demonstrate successful execution.

Course Context

This project builds on concepts from earlier units in the course, including algorithm efficiency, divide-and-conquer, greedy strategies, and dynamic programming. It extends these ideas into artificial intelligence by applying heuristic search to a constraint satisfaction problem.
