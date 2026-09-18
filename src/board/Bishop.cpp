//
// Created by Eric on 10/09/2026.
//

#include "Bishop.h"
#include "Pieces.h"
#include "../constants/Constants.h"

#include "SFML/Graphics.hpp"

Bishop::Bishop() = default;

bool Bishop::validMove() {
    checkAllValidMoves();

    for (int i = 0; i < valid_moves.size(); i++) {
        if (pieces.square_x == valid_moves[i].first && pieces.square_y == valid_moves[i].second) {
            return true;
        }
    }

    return false;
}

void Bishop::checkAllValidMoves() {
    valid_moves.clear();

    // top right
    checkDifferentDirections(1, -1);

    // top left
    checkDifferentDirections(-1, -1);

    // bottom right
    checkDifferentDirections(1, 1);

    // bottom left
    checkDifferentDirections(-1, 1);
}

void Bishop::checkDifferentDirections(int x, int y) {
    resetTemp();

    while (pieces.board[temp_old_y + y][temp_old_x + x] == 8) {
        if (temp_old_x + x <= 8 && temp_old_y + y <= 8) {
            updateTempValues(x, y);
        }

        else break;

        addToValidMoves();

        if (pieces.board[temp_old_y][temp_old_x] < 0) {
            break;
        }
    }
}

void Bishop::resetTemp() {
    temp_old_y = pieces.old_y;
    temp_old_x = pieces.old_x;
}

void Bishop::updateTempValues(int xAmount, int yAmount) {
    temp_old_x += xAmount;
    temp_old_y += yAmount;
}

void Bishop::addToValidMoves() {
    valid_moves.emplace_back(temp_old_x, temp_old_y);
}
