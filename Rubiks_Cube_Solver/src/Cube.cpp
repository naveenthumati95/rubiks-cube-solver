#include "Cube.h"

// Face indices for readability
static constexpr int UP    = 0;
static constexpr int DOWN  = 1;
static constexpr int FRONT = 2;
static constexpr int BACK  = 3;
static constexpr int LEFT  = 4;
static constexpr int RIGHT = 5;

Cube::Cube()
    : faces{
        Face(Color::White),   // Up
        Face(Color::Yellow),  // Down
        Face(Color::Green),   // Front
        Face(Color::Blue),    // Back
        Face(Color::Orange),  // Left
        Face(Color::Red)      // Right
    }
{}

// Apply U move (Up face clockwise)
void Cube::moveU() {
    // 1. Rotate the Up face itself
    faces[UP].rotateClockwise();

    // 2. Rotate adjacent top rows
    Color temp[3];

    // Save Front top row
    for (int i = 0; i < 3; i++)
        temp[i] = faces[FRONT].getSticker(i);

    // Front <- Right
    for (int i = 0; i < 3; i++)
        faces[FRONT].setSticker(i, faces[RIGHT].getSticker(i));

    // Right <- Back
    for (int i = 0; i < 3; i++)
        faces[RIGHT].setSticker(i, faces[BACK].getSticker(i));

    // Back <- Left
    for (int i = 0; i < 3; i++)
        faces[BACK].setSticker(i, faces[LEFT].getSticker(i));

    // Left <- saved Front
    for (int i = 0; i < 3; i++)
        faces[LEFT].setSticker(i, temp[i]);
}

void Cube::moveD() {
    faces[DOWN].rotateClockwise();

    Color temp[3];

    // Save Front bottom row
    for (int i = 0; i < 3; i++)
        temp[i] = faces[FRONT].getSticker(6 + i);

    // Front <- Left
    for (int i = 0; i < 3; i++)
        faces[FRONT].setSticker(6 + i, faces[LEFT].getSticker(6 + i));

    // Left <- Back
    for (int i = 0; i < 3; i++)
        faces[LEFT].setSticker(6 + i, faces[BACK].getSticker(6 + i));

    // Back <- Right
    for (int i = 0; i < 3; i++)
        faces[BACK].setSticker(6 + i, faces[RIGHT].getSticker(6 + i));

    // Right <- saved Front
    for (int i = 0; i < 3; i++)
        faces[RIGHT].setSticker(6 + i, temp[i]);
}

void Cube::moveF() {
    faces[FRONT].rotateClockwise();

    Color temp[3];

    temp[0] = faces[UP].getSticker(6);
    temp[1] = faces[UP].getSticker(7);
    temp[2] = faces[UP].getSticker(8);

    faces[UP].setSticker(6, faces[LEFT].getSticker(8));
    faces[UP].setSticker(7, faces[LEFT].getSticker(5));
    faces[UP].setSticker(8, faces[LEFT].getSticker(2));

    faces[LEFT].setSticker(2, faces[DOWN].getSticker(0));
    faces[LEFT].setSticker(5, faces[DOWN].getSticker(1));
    faces[LEFT].setSticker(8, faces[DOWN].getSticker(2));

    faces[DOWN].setSticker(0, faces[RIGHT].getSticker(6));
    faces[DOWN].setSticker(1, faces[RIGHT].getSticker(3));
    faces[DOWN].setSticker(2, faces[RIGHT].getSticker(0));

    faces[RIGHT].setSticker(0, temp[0]);
    faces[RIGHT].setSticker(3, temp[1]);
    faces[RIGHT].setSticker(6, temp[2]);
}

void Cube::moveB() {
    faces[BACK].rotateClockwise();

    Color temp[3];

    temp[0] = faces[UP].getSticker(0);
    temp[1] = faces[UP].getSticker(1);
    temp[2] = faces[UP].getSticker(2);

    faces[UP].setSticker(0, faces[RIGHT].getSticker(2));
    faces[UP].setSticker(1, faces[RIGHT].getSticker(5));
    faces[UP].setSticker(2, faces[RIGHT].getSticker(8));

    faces[RIGHT].setSticker(2, faces[DOWN].getSticker(8));
    faces[RIGHT].setSticker(5, faces[DOWN].getSticker(7));
    faces[RIGHT].setSticker(8, faces[DOWN].getSticker(6));

    faces[DOWN].setSticker(6, faces[LEFT].getSticker(0));
    faces[DOWN].setSticker(7, faces[LEFT].getSticker(3));
    faces[DOWN].setSticker(8, faces[LEFT].getSticker(6));

    faces[LEFT].setSticker(0, temp[2]);
    faces[LEFT].setSticker(3, temp[1]);
    faces[LEFT].setSticker(6, temp[0]);
}

void Cube::moveL() {
    faces[LEFT].rotateClockwise();

    Color temp[3];

    temp[0] = faces[UP].getSticker(0);
    temp[1] = faces[UP].getSticker(3);
    temp[2] = faces[UP].getSticker(6);

    faces[UP].setSticker(0, faces[BACK].getSticker(8));
    faces[UP].setSticker(3, faces[BACK].getSticker(5));
    faces[UP].setSticker(6, faces[BACK].getSticker(2));

    faces[BACK].setSticker(2, faces[DOWN].getSticker(6));
    faces[BACK].setSticker(5, faces[DOWN].getSticker(3));
    faces[BACK].setSticker(8, faces[DOWN].getSticker(0));

    faces[DOWN].setSticker(0, faces[FRONT].getSticker(0));
    faces[DOWN].setSticker(3, faces[FRONT].getSticker(3));
    faces[DOWN].setSticker(6, faces[FRONT].getSticker(6));

    faces[FRONT].setSticker(0, temp[0]);
    faces[FRONT].setSticker(3, temp[1]);
    faces[FRONT].setSticker(6, temp[2]);
}

void Cube::moveR() {
    faces[RIGHT].rotateClockwise();

    Color temp[3];

    temp[0] = faces[UP].getSticker(2);
    temp[1] = faces[UP].getSticker(5);
    temp[2] = faces[UP].getSticker(8);

    faces[UP].setSticker(2, faces[FRONT].getSticker(2));
    faces[UP].setSticker(5, faces[FRONT].getSticker(5));
    faces[UP].setSticker(8, faces[FRONT].getSticker(8));

    faces[FRONT].setSticker(2, faces[DOWN].getSticker(2));
    faces[FRONT].setSticker(5, faces[DOWN].getSticker(5));
    faces[FRONT].setSticker(8, faces[DOWN].getSticker(8));

    faces[DOWN].setSticker(2, faces[BACK].getSticker(6));
    faces[DOWN].setSticker(5, faces[BACK].getSticker(3));
    faces[DOWN].setSticker(8, faces[BACK].getSticker(0));

    faces[BACK].setSticker(0, temp[2]);
    faces[BACK].setSticker(3, temp[1]);
    faces[BACK].setSticker(6, temp[0]);
}


// Check if cube is solved
bool Cube::isSolved() const {
    for (const Face& face : faces) {
        Color center = face.getSticker(4);
        for (int i = 0; i < 9; i++) {
            if (face.getSticker(i) != center)
                return false;
        }
    }
    return true;
}

const Face& Cube::getFace(int index) const {
    return faces[index];
}

void Cube::applyMove(const Move& move) {
    for (int i = 0; i < move.getTurns(); i++) {
        switch (move.getType()) {
            case MoveType::U: moveU(); break;
            case MoveType::D: moveD(); break;
            case MoveType::L: moveL(); break;
            case MoveType::R: moveR(); break;
            case MoveType::F: moveF(); break;
            case MoveType::B: moveB(); break;
            default:
                // Other moves coming later
                break;
        }
    }
}

