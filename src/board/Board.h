//
// Created by Eric on 15/08/2026.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "SFML/Graphics.hpp"

class Board {
public:
    Board();

    void tick();
    void render(sf::RenderWindow &window);

private:
    void drawBoard(sf::RenderWindow &window);
    void drawSquare(sf::RenderWindow &window, float x, float y, sf::Color colour);

    void initHighlightedSquare();
    void highlightSquare(sf::RenderWindow &window);

private:
    sf::RectangleShape square;
    sf::RectangleShape square_outline;
};


#endif //CHESS_BOARD_H