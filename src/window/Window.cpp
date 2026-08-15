//
// Created by Eric on 15/08/2026.
//

#include "Window.h"
#include "../constants/Constants.h"

Window::Window() {
    window.create(sf::VideoMode({Constants::WIDTH, Constants::HEIGHT}), Constants::TITLE, sf::Style::Close);

    window.setFramerateLimit(Constants::FPS);
}

void Window::render() {

}

void Window::tick() {

}

void Window::run() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        tick();
        render();

        window.display();
    }
}










