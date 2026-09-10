//
// Created by Eric on 8/09/2026.
//

#include "Knight.h"
#include "Pieces.h"

Knight::Knight() = default;

bool Knight::validMove() {
    if (LshapeMovement() == true) {
        return true;
    }

    return false;
}

bool Knight::LshapeMovement() {
    if (std::abs(pieces.square_x - pieces.old_x) == 1 && std::abs(pieces.square_y - pieces.old_y) == 2 ||
        std::abs(pieces.square_x - pieces.old_x) == 2 && std::abs(pieces.square_y - pieces.old_y) == 1) {
        return true;
    }

    return false;
}



