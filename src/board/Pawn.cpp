//
// Created by Eric on 29/08/2026.
//

#include "Pawn.h"
#include "Pieces.h"

Pawn::Pawn() = default;

bool Pawn::validMove() {
    if (canCapture() == true) {
        return true;
    }

    if (overOneSquare() == true && canMoveTwoSquares() == false) {
        return false;
    }

    if (differentColumn() == true) {
        return false;
    }

    if (moveBackwards() == true) {
        return false;
    }

    if (pieceInFront() == true) {
        return false;
    }

    return true;
}

bool Pawn::overOneSquare() {
    if (std::abs(pieces.square_y - pieces.old_y) > 1) {
        return true;
    }

    return false;
}

bool Pawn::pieceInFront() {
    if (std::abs(pieces.square_y - pieces.old_y) >= 1 && pieces.board[pieces.square_y][pieces.square_x] != 8) {
        return true;
    }

    return false;
}

bool Pawn::canCapture() {
    if (pieces.board[pieces.square_y][pieces.square_x] != 8) {
        if (std::abs(pieces.square_x - pieces.old_x) == 1 && std::abs(pieces.square_y - pieces.old_y) == 1) {
            return true;
        }
    }

    return false;
}

bool Pawn::canMoveTwoSquares() {
    if (pieces.old_y == 6 || pieces.old_y == 1) {
        if (std::abs(pieces.square_y - pieces.old_y)  < 3) {
            return true;
        }
    }

    return false;
}

bool Pawn::moveBackwards() {
    if (pieces.board[pieces.old_y][pieces.old_x] == 5) {
        if (pieces.old_y < pieces.square_y) {
            return true;
        }
    }

    else if (pieces.board[pieces.old_y][pieces.old_x] == -5) {
        if (pieces.old_y > pieces.square_y) {
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



