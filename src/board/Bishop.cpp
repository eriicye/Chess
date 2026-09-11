//
// Created by Eric on 10/09/2026.
//

#include "Bishop.h"
#include "Pieces.h"

Bishop::Bishop() = default;

bool Bishop::validMove() {
    if (diagonallyMoving() == true) {
        return true;
    }

    return false;
}

bool Bishop::pieceBlocked(int amount_x, int amount_y) {
    int temp_square_x = pieces.square_x;
    int temp_square_y = pieces.square_y;

    while (temp_square_x != pieces.old_x && temp_square_y != pieces.old_y) {
        temp_square_x += amount_x;
        temp_square_y += amount_y;

        if (pieces.board[pieces.old_y][pieces.old_x] > 0 && pieces.board[temp_square_y][temp_square_x] > 0 ||
            pieces.board[pieces.old_y][pieces.old_x] < 0 && pieces.board[temp_square_y][temp_square_x] < 0) {
            return true;
        }
    }

    return false;
}

bool Bishop::diagonallyMoving() {
    // move left
    if (pieces.square_x < pieces.old_x) {
        // move left down
        if (pieces.square_y > pieces.old_y) {
            if (pieceBlocked(-1, 1) == true) {
                return false;
            }
        }

        // move left up
        else {
            if (pieceBlocked(-1, -1) == true) {
                return false;
            }
        }
    }

    // move right
    else {
        // move right down
        if (pieces.square_y > pieces.old_y) {
            if (pieceBlocked(1, -1) == true) {
                return false;
            }
        }

        // move right up
        else {
            if (pieceBlocked(-1, 1) == true) {
                return false;
            }
        }
    }

    return true;
}