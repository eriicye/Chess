//
// Created by Eric on 16/08/2026.
//

#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

class Pieces {
public:
    Pieces();

    void tick();
    void render();

public:
    int board[8][8] {
        {-5, -2, -3, -9, -10, -3, -2, -5},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {5, 2, 3, 9, 10, 3, 2, 5},
    };

private:

};


#endif //CHESS_PIECES_H