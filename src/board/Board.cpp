//
// Created by Eric on 15/08/2026.
//

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Board.h"
#include "../constants/Constants.h"

Board::Board() {
    square.setSize({Constants::SIZE_X, Constants::SIZE_Y});
}

void Board::drawSquare(sf::RenderWindow &window, float x, float y, sf::Color colour) {
    square.setPosition({x, y});
    square.setFillColor(colour);
    window.draw(square);
}

void Board::drawBoard(sf::RenderWindow &window) {
    for (float x = 0; x < 7; x += 2) {
        for (float y = 0; y < 4; y++) {
            drawSquare(window, x * 128, y * 128 * 2, Constants::LIGHT_SQUARE);
            drawSquare(window, x * 128 + 128, y * 128 * 2, Constants::DARK_SQUARE);
        }
    }

    for (float x = 0; x < 7; x += 2) {
        for (float y = 1; y < 8; y += 2) {
            drawSquare(window, x * 128, y * 128, Constants::DARK_SQUARE);
            drawSquare(window, x * 128 + 128, y * 128, Constants::LIGHT_SQUARE);
        }
    }
}

void Board::tick() {

}

void Board::render(sf::RenderWindow &window) {
    drawBoard(window);
}
