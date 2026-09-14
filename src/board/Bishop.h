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

private:
    std::vector<std::pair<int, int>> valid_moves;
};


#endif //CHESS_BISHOP_H