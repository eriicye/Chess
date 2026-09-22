//
// Created by Eric on 21/09/2026.
//

#include "Rook.h"

Rook::Rook() = default;

bool Rook::validMove() {
    checkAllValidMoves();

    for (int i = 0; i < valid_moves.size(); i++) {
        if (pieces.square_x == valid_moves[i].first && pieces.square_y == valid_moves[i].second) {
            return true;
        }
    }

    return false;
}

void Rook::checkAllValidMoves() {
    valid_moves.clear();

    // right
    checkDifferentDirections(1, 0);

    // up
    checkDifferentDirections(0, -1);

    // down
    checkDifferentDirections(0, 1);

    // left
    checkDifferentDirections(-1, 0);
}

void Rook::checkDifferentDirections(int x, int y) {
    resetTemp();

    if (pieces.board[pieces.old_y][pieces.old_x] > 0) {
        while (pieces.board[temp_old_y + y][temp_old_x + x] == 8 || pieces.board[temp_old_y + y][temp_old_x + x] < 0) {
            if (temp_old_x + x <= 8 && temp_old_y + y <= 8) {
                updateTempValues(x, y);
            }

            else break;

            addToValidMoves();
        }
    }

    else {
        while (pieces.board[temp_old_y + y][temp_old_x + x] == 8 || pieces.board[temp_old_y + y][temp_old_x + x] > 0) {
            if (temp_old_x + x <= 8 && temp_old_y + y <= 8) {
                updateTempValues(x, y);
            }

            else break;

            addToValidMoves();
        }
    }
}

void Rook::resetTemp() {
    temp_old_y = pieces.old_y;
    temp_old_x = pieces.old_x;
}

void Rook::updateTempValues(int xAmount, int yAmount) {
    temp_old_x += xAmount;
    temp_old_y += yAmount;
}

void Rook::addToValidMoves() {
    valid_moves.emplace_back(temp_old_x, temp_old_y);
}


