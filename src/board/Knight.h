//
// Created by Eric on 8/09/2026.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


class Knight {
public:
    Knight();

    bool validMove();

private:
    bool LshapeMovement();
};


#endif //CHESS_KNIGHT_H