//
// Created by Eric on 10/09/2026.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include <iostream>

class Bishop {
public:
    Bishop();

    bool validMove();

private:
    bool diagonallyMoving();

    bool pieceBlocked(int amount_x, int amount_y);
};


#endif //CHESS_BISHOP_H