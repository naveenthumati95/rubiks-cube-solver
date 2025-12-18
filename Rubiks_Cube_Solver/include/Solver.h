#ifndef SOLVER_H
#define SOLVER_H

#include "Cube.h"
#include "Move.h"
#include <vector>

class Solver {
public:
    explicit Solver(Cube& cube);

    // Try to solve within maxDepth
    bool solve(int maxDepth);

    // Get solution after solve()
    const std::vector<Move>& getSolution() const;

private:
    Cube& cube;
    std::vector<Move> solution;

    // All possible basic moves
    const std::vector<std::string> moveSet = {
        "U", "U'", "U2",
        "D", "D'", "D2",
        "L", "L'", "L2",
        "R", "R'", "R2",
        "F", "F'", "F2",
        "B", "B'", "B2"
    };

    // Depth-limited DFS
    bool dfs(int depth, int maxDepth);

    // Apply + undo helpers
    void applyMove(const std::string& m);
    void undoMove(const std::string& m);
};

#endif
