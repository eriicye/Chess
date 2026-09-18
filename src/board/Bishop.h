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
    void updateTempValues(int xAmount, int yAmount);
    void addToValidMoves();
    void checkDifferentDirections(int x, int y);

private:
    std::vector<std::pair<int, int>> valid_moves;

    int temp_old_y = pieces.old_y;
    int temp_old_x = pieces.old_x;
};


#endif //CHESS_BISHOP_H