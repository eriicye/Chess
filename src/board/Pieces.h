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

public:
    int square_x = -1000;
    int square_y = -1000;

private:
    void loadPieces();
    void drawPieces(sf::RenderWindow &window);

    void movePiece(sf::RenderWindow &window);


private:
    int board[8][8] {
        {-4, -3, -2, -1, -10, -2, -3, -4},
        {-5, -5, -5, -5, -5, -5, -5, -5},
        {8, 8, 8, 8, 8, 8, 8, 8},
        {8, 8, 8, 8, 8, 8, 8, 8},
        {8, 8, 8, 8, 8, 8, 8, 8},
        {8, 8, 8, 8, 8, 8, 8, 8},
        {5, 5, 5, 5, 5, 5, 5, 5},
        {4, 3, 2, 1, 10, 2, 3, 4},
    };

    sf::Texture piecesTexture;

    std::vector<sf::Sprite> whitePieces;
    std::vector<sf::Sprite> blackPieces;

    sf::Mouse::Button mouse;

};

extern Pieces pieces;


#endif //CHESS_PIECES_H