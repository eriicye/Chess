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
    int temp_old_y = pieces.old_y;
    int temp_old_x = pieces.old_x;

    valid_moves.clear();
    // top right
    while (pieces.board[temp_old_y - 1][temp_old_x + 1] == 8) {

        if (temp_old_x + 1 < 8 && temp_old_y - 1 < 8) {
            temp_old_x++;
            temp_old_y--;
        }

        else break;


        valid_moves.emplace_back(temp_old_x, temp_old_y);

        if (pieces.board[temp_old_y][temp_old_x] < 0) {
            break;
        }
    }
}
