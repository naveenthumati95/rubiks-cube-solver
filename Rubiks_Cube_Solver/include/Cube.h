#ifndef CUBE_H
#define CUBE_H

#include <array>
#include "Face.h"
#include "Move.h"

class Cube {
public:
    Cube();

    // Apply basic moves
    void moveU();
    void moveD();
    void moveF();
    void moveB();
    void moveL();
    void moveR();

    // Utility
    bool isSolved() const;

    void applyMove(const Move& move);

    // Access (for testing & rendering)
    const Face& getFace(int index) const;

private:
    std::array<Face, 6> faces;
};

#endif
