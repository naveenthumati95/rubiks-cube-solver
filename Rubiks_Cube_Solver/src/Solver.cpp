#include "Solver.h"

// Constructor
Solver::Solver(Cube& cube) : cube(cube) {}

// Public solve entry (IDDFS)
bool Solver::solve(int maxDepth) {
    solution.clear();

    for (int depth = 0; depth <= maxDepth; depth++) {
        if (dfs(0, depth)) {
            return true;
        }
    }
    return false;
}

// DFS with depth limit
bool Solver::dfs(int depth, int maxDepth) {
    if (cube.isSolved()) {
        return true;
    }

    if (depth == maxDepth) {
        return false;
    }

    for (const auto& m : moveSet) {
        applyMove(m);
        solution.emplace_back(m);

        if (dfs(depth + 1, maxDepth)) {
            return true;
        }

        // backtrack
        undoMove(m);
        solution.pop_back();
    }

    return false;
}

// Apply move
void Solver::applyMove(const std::string& m) {
    cube.applyMove(Move(m));
}

// Undo move (inverse)
void Solver::undoMove(const std::string& m) {
    if (m.size() == 1)
        cube.applyMove(Move(m + "'"));
    else if (m[1] == '\'')
        cube.applyMove(Move(std::string(1, m[0])));
    else if (m[1] == '2')
        cube.applyMove(Move(m)); // 180° is self-inverse
}

// Getter
const std::vector<Move>& Solver::getSolution() const {
    return solution;
}
