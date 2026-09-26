//
// Created by Eric on 21/09/2026.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include <vector>
#include "Pieces.h"

class Rook {
public:
    Rook();

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
};


#endif //CHESS_ROOK_H