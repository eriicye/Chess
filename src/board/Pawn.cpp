//
// Created by Eric on 29/08/2026.
//

#include "Pawn.h"
#include "Pieces.h"

Pawn::Pawn() = default;

bool Pawn::validMove() {
    if (overOneSquare() == true && canMoveTwoSquares() == false) {
        return false;
    }

    if (differentColumn() == true) {
        return false;
    }

    return true;
}

bool Pawn::overOneSquare() {
    if (abs(pieces.square_y - pieces.old_y) > 1) {
        return true;
    }

    return false;
}

// unused
bool Pawn::canMoveTwoSquares() {
    if (pieces.old_y == 6 || pieces.old_y == 1) {
        if (std::abs(pieces.square_y - pieces.old_y)  < 3) {
            return true;
        }
    }

    return false;
}

bool Pawn::differentColumn() {
    if (pieces.square_x != pieces.old_x) {
        return true;
    }

    return false;
}



