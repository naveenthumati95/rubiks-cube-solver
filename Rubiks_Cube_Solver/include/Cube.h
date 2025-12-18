#ifndef CUBE_H
#define CUBE_H

#include <array>
#include "Face.h"
#include "Move.h"

class Cube {
public:
    Cube();

    // Basic face rotations
    void moveU();
    void moveD();
    void moveF();
    void moveB();
    void moveL();
    void moveR();

    // Optimized apply for Solver (0-17: U, D, L, R, F, B groupings)
    void applyMove(int moveIndex);

    // Standard apply
    void applyMove(const Move& move);

    bool isSolved() const;
    const Face& getFace(int index) const;

private:
    std::array<Face, 6> faces;
};

#endif