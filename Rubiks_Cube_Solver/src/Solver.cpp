#include "Solver.h"
#include <iostream>

Solver::Solver(Cube& cube) : cube(cube) {}

bool Solver::solve(int maxDepth) {
    solution.clear();

    // Iterative Deepening (IDDFS)
    // Try depth 1, then depth 2, etc., to ensure shortest solution.
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

            // 1. Don't turn the same face twice in a row (e.g. U then U)
            if (currentFace == lastFace) continue;

            // 2. Commutative Order: Enforce U before D, L before R, F before B
            // If faces are opposites (same pair index), only allow LowIndex -> HighIndex
            if ((currentFace / 2) == (lastFace / 2)) {
                if (currentFace < lastFace) continue;
            }
        }

        // Apply
        Move m(moveNames[i]);
        cube.applyMove(m);
        solution.push_back(m);

        // Recurse
        if (dfs(depth + 1, maxDepth, i)) return true;

        // Backtrack
        solution.pop_back();

        // Efficient undo logic
        std::string undoStr = moveNames[i];
        if (undoStr.back() == '2') { /* U2 -> U2 */ }
        else if (undoStr.back() == '\'') undoStr.pop_back(); // U' -> U
        else undoStr += "'"; // U -> U'
        
        cube.applyMove(Move(undoStr));
    }

    return false;
}