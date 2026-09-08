//
// Created by Eric on 16/08/2026.
//

#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include "SFML/Graphics.hpp"
#include "iostream"

class Pieces {
public:
    Pieces();

    void tick(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);

    void debugging() const;

public:
    int board[8][8] {
        {-4, -3, -2, -1, -10, -2, -3, -4}, // 0
        {-5, -5, -5, -5, -5, -5, -5, -5}, // 1
        {8, 8, 8, 8, 8, 8, 8, 8}, // 2
        {8, 8, 8, 8, 8, 8, 8, 8}, // 3
        {8, 8, 8, 8, 8, 8, 8, 8}, // 4
        {8, 8, 8, 8, 8, 8, 8, 8}, // 5
        {5, 5, 5, 5, 5, 5, 5, 5}, // 6
        {4, 3, 2, 1, 10, 2, 3, 4}, // 7
    };

    int square_x = -1000;
    int square_y = -1000;

    int old_x = square_x;
    int old_y = square_y;


private:
    void loadPieces();
    void drawPieces(sf::RenderWindow &window);

    void movePiece(sf::RenderWindow &window);

private:

    bool clicked = false;

    sf::Texture piecesTexture;

    std::vector<sf::Sprite> whitePieces;
    std::vector<sf::Sprite> blackPieces;

};

extern Pieces pieces;


#endif //CHESS_PIECES_H