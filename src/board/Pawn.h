//
// Created by Eric on 29/08/2026.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


class Pawn {
public:
    Pawn();

    bool validMove();

private:
    bool overOneSquare();
    bool canMoveTwoSquares();
    bool differentColumn();

};


#endif //CHESS_PAWN_H