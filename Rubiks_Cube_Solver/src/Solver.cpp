#include "Solver.h"

Solver::Solver(Cube& cube) : cube(cube) {}

bool Solver::solve(int maxDepth) {
    solution.clear();

    // Iterative Deepening (IDDFS)
    for (int d = 1; d <= maxDepth; d++) {
        if (dfs(0, d, -1)) {
            return true;
        }
    }
    return false;
}

const std::vector<Move>& Solver::getSolution() const {
    return solution;
}

bool Solver::dfs(int depth, int maxDepth, int lastMoveIndex) {
    if (cube.isSolved()) return true;
    if (depth == maxDepth) return false;

    // Try all 18 moves
    for (int i = 0; i < 18; i++) {
        
        // === PRUNING ===
        if (lastMoveIndex != -1) {
            int currentFace = getFace(i);
            int lastFace = getFace(lastMoveIndex);

            // 1. Redundant turns (e.g., U after U)
            if (currentFace == lastFace) continue;

            // 2. Commutative order (e.g., Force U before D)
            if ((currentFace / 2) == (lastFace / 2)) {
                if (currentFace < lastFace) continue;
            }
        }

        // === APPLY ===
        cube.applyMove(i);
        solution.push_back(Move(moveNames[i]));

        // === RECURSE ===
        if (dfs(depth + 1, maxDepth, i)) return true;

        // === BACKTRACK ===
        solution.pop_back();
        cube.applyMove(inverseMoves[i]); // Fast undo
    }

    return false;
}