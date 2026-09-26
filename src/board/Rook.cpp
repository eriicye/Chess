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

    // white
    if (pieces.board[pieces.old_y][pieces.old_x] > 0) {
        while (pieces.board[temp_old_y + y][temp_old_x + x] == 8 || pieces.board[temp_old_y + y][temp_old_x + x] < 0) {
            if (pieces.board[temp_old_y + y][temp_old_x + x] < 0) {
                addToValidMoves(x, y);
                break;
            }

            if (temp_old_x + x <= 8 && temp_old_y + y <= 8) {
                updateTempValues(x, y);
            }

            else break;

            addToValidMoves(0, 0);
        }
    }

    // black
    else {
        while (pieces.board[temp_old_y + y][temp_old_x + x] == 8 || pieces.board[temp_old_y + y][temp_old_x + x] > 0) {
            if (pieces.board[temp_old_y + y][temp_old_x + x] != 8 && pieces.board[temp_old_y + y][temp_old_x + x]) {
                addToValidMoves(x, y);
                break;
            }

            if (temp_old_x + x <= 8 && temp_old_y + y <= 8) {
                updateTempValues(x, y);
            }

            else break;

            addToValidMoves(0, 0);
        }
    }
}

void Rook::resetTemp() {
    temp_old_y = pieces.old_y;
    temp_old_x = pieces.old_x;
}

void Rook::updateTempValues(int x_amount, int y_amount) {
    temp_old_x += x_amount;
    temp_old_y += y_amount;
}

void Rook::addToValidMoves(int x_amount, int y_amount) {
    valid_moves.emplace_back(temp_old_x + x_amount, temp_old_y + y_amount);
}


