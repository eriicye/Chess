//
// Created by Eric on 15/08/2026.
//

#ifndef CHESS_CONSTANTS_H
#define CHESS_CONSTANTS_H

#include "SFML/Graphics.hpp"

struct Constants {
public:
    // window
    static constexpr int WIDTH = 1400;
    static constexpr int HEIGHT = 1024;

    static constexpr int WINDOW_X = 265;
    static constexpr int WINDOW_Y = 25;

    static constexpr char *TITLE = "Chess";

    static constexpr int FPS = 60;

    // board
    static constexpr int SIZE_X = 128.f;
    static constexpr int SIZE_Y = SIZE_X;

    // colours
    inline static const sf::Color LIGHT_SQUARE{240, 217, 181};
    inline static const sf::Color DARK_SQUARE{181, 136, 99};

    // pieces
    static constexpr int PIECE_WIDTH = 333;
    static constexpr int PIECE_HEIGHT = 333;

    static constexpr float SCALE = 0.41f;
};

#endif //CHESS_CONSTANTS_H