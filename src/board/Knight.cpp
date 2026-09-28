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

    // white capturing white
    if (pieces.board[pieces.old_y][pieces.old_x] > 0 && pieces.board[pieces.square_y][pieces.square_x] > 0
        && pieces.board[pieces.square_y][pieces.square_x] != 8) {
        return false;
    }

    // black capturing black
    if (pieces.board[pieces.old_y][pieces.old_x] < 0 && pieces.board[pieces.square_y][pieces.square_x] < 0) {
        return false;
    }

    if (std::abs(pieces.square_x - pieces.old_x) == 1 && std::abs(pieces.square_y - pieces.old_y) == 2 ||
    std::abs(pieces.square_x - pieces.old_x) == 2 && std::abs(pieces.square_y - pieces.old_y) == 1) {

        return true;
    }

    return false;
}