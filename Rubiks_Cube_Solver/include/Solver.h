#ifndef SOLVER_H
#define SOLVER_H

#include "Cube.h"
#include "Move.h"
#include <vector>
#include <string>

class Solver {
public:
    explicit Solver(Cube& cube);

    // Public API: Uses IDDFS (Iterative Deepening DFS) to find the shortest solution
    bool solve(int maxDepth);

    const std::vector<Move>& getSolution() const;

private:
    Cube& cube;
    std::vector<Move> solution;

    // Move lookup table
    // Order is strictly grouped by face to allow math-based pruning:
    // U(0-2), D(3-5), L(6-8), R(9-11), F(12-14), B(15-17)
    const std::vector<std::string> moveNames = {
        "U", "U'", "U2",
        "D", "D'", "D2",
        "L", "L'", "L2",
        "R", "R'", "R2",
        "F", "F'", "F2",
        "B", "B'", "B2"
    };

    // Helper: Maps move index (0-17) to face index (0-5)
    // 0=U, 1=D, 2=L, 3=R, 4=F, 5=B
    int getFace(int moveIndex) const {
        return moveIndex / 3;
    }

    // Recursive DFS worker
    // lastMoveIndex: Tracks previous move to prune redundant branches (like U after U)
    bool dfs(int depth, int maxDepth, int lastMoveIndex);
};

#endif