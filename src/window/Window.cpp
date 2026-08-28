//
// Created by Eric on 15/08/2026.
//

#include "Window.h"
#include "../constants/Constants.h"

#include "../board/Board.h"
#include "../board/Pieces.h"

Board board;

Window::Window() {
    windowSetup();
}

void Window::windowSetup() {
    window.create(sf::VideoMode({Constants::WIDTH, Constants::HEIGHT}), Constants::TITLE, sf::Style::Close);
    window.setFramerateLimit(Constants::FPS);
    window.setPosition({Constants::WINDOW_X, Constants::WINDOW_Y});
}

void Window::render(sf::RenderWindow &window) {
    board.render(window);
    pieces.render(window);
}

void Window::tick(sf::RenderWindow &window) {
    board.tick();
    pieces.tick(window);
}

void Window::run() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        tick(window);
        render(window);

        window.display();
    }
}
