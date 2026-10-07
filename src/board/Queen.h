//
// Created by Eric on 4/10/2026.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "vector"
#include "Pieces.h"

class Queen {
public:
    Queen();

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


#endif //CHESS_QUEEN_H