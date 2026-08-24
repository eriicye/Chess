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

    void tick();
    void render(sf::RenderWindow &window);


private:
    void loadPieces();
    void drawPieces(sf::RenderWindow &window);


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

};


#endif //CHESS_PIECES_H