//
// Created by Eric on 10/09/2026.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Pieces.h"
#include <vector>

class Bishop {
public:
    Bishop();

    bool validMove();

private:
    void checkAllValidMoves();

    void resetTemp();
    void updateTempValues(int x_amount, int y_amount);
    void addToValidMoves(int x_amount, int y_amount);
    void checkDifferentDirections(int x, int y);

private:
    std::vector<std::pair<int, int>> valid_moves;

    int temp_old_y = pieces.old_y;
    int temp_old_x = pieces.old_x;

    int white = true;
};


#endif //CHESS_BISHOP_H