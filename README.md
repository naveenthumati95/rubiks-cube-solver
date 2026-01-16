# Rubik's Cube Solver (3x3)

A C++ based Rubik's Cube simulator and solver using an object-oriented approach and the Iterative Deepening Depth-First Search (IDDFS) algorithm.

## Features
- **Object-Oriented Design:** Clear representation of cube states, face rotations, and move notations.
- **IDDFS Solver:** Efficient brute-force solving with inverse-move pruning to avoid redundant states.
- **Performance Tracking:** Real-time analysis of execution time and branching factors using `std::chrono`.
- **Validation:** Ensures move legality and tracks cube state accuracy.

## Repository Structure
- `include/`: Header files for class definitions.
- `src/`: Implementation of the cube logic and solver.
- `main.cpp`: Main entry point for the application.

## How to Build and Run
1. Ensure you have a C++ compiler installed (e.g., g++).
2. Clone the repository.
3. Compile the code:
   ```bash
   g++ -Iinclude src/*.cpp main.cpp -o solver
