//
// Created by Eric on 15/08/2026.
//

#ifndef CHESS_WINDOW_H
#define CHESS_WINDOW_H

#include "SFML/Graphics.hpp"

class Window {
public:
    Window();

    void run();

private:
    void render();
    void tick();

private:
    sf::RenderWindow window;
    sf::Clock clock;
};


#endif //CHESS_WINDOW_H