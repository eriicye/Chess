//
// Created by Eric on 16/08/2026.
//

#include "Pieces.h"
#include "../constants/Constants.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"

Pieces pieces;
Pawn pawn;
Knight knight;
Bishop bishop;

Pieces::Pieces() {
    loadPieces();
}

void Pieces::loadPieces() {
    piecesTexture.loadFromFile("../res/pieces.png");

    // white pieces
    for (int i = 0; i < 6; i++) {
        whitePieces.emplace_back(piecesTexture);
        whitePieces[i].setTextureRect(sf::IntRect({i * Constants::PIECE_WIDTH, 0},
            {Constants::PIECE_WIDTH, Constants::PIECE_HEIGHT}));
        whitePieces[i].setScale({Constants::SCALE, Constants::SCALE});
    }

    // black pieces
    for (int i = 0; i < 6; i++) {
        blackPieces.emplace_back(piecesTexture);
        blackPieces[i].setTextureRect(sf::IntRect({i * Constants::PIECE_WIDTH, Constants::PIECE_HEIGHT},
            {Constants::PIECE_WIDTH, Constants::PIECE_HEIGHT}));
        blackPieces[i].setScale({Constants::SCALE, Constants::SCALE});
    }
}

void Pieces::drawPieces(sf::RenderWindow &window) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int piece = board[col][row];

            // white
            if (piece > 0 && piece != 8) {
                // king
                if (piece == 10) {
                    whitePieces[0].setPosition({static_cast<float>(row * Constants::SIZE_X), static_cast<float>(col * Constants::SIZE_Y)});
                    window.draw(whitePieces[0]);
                }
                else {
                    whitePieces[piece].setPosition({static_cast<float>(row * Constants::SIZE_X), static_cast<float>(col * Constants::SIZE_Y)});
                    window.draw(whitePieces[piece]);
                }
            }

            // black
            else if (piece != 8) {
                piece = std::abs(piece);

                // king
                if (piece == 10) {
                    blackPieces[0].setPosition({static_cast<float>(row * Constants::SIZE_X), static_cast<float>(col * Constants::SIZE_Y)});
                    window.draw(blackPieces[0]);
                }

                else {
                    blackPieces[piece].setPosition({static_cast<float>(row * Constants::SIZE_X), static_cast<float>(col * Constants::SIZE_Y)});
                    window.draw(blackPieces[piece]);
                }
            }
        }
    }
}

// remove after finished
void Pieces::debugging() const {
    std::cout << "Square X: " << square_x << " | " << "Square Y: " << square_y << "\n";
    std::cout << "Old X: " << old_x << " | " << "Old Y: " << old_y << "\n";
    std::cout << "\n";
}

void Pieces::movePiece(sf::RenderWindow &window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    square_x = std::ceil(mousePos.x / Constants::SIZE_X);
    square_y = std::ceil(mousePos.y / Constants::SIZE_Y);

    debugging();

    // pawn
    if (move(5, -5)) {
        if (pawn.validMove() == false) {

        }

        // valid moves
        else {
            validMove();
        }
    }

    // knight
    if (move(3, -3)) {
        if (knight.validMove() == false) {

        }

        else {
            validMove();
        }
    }

    if (move(2, -2)) {
        if (bishop.validMove() == false) {

        }

        else {
            validMove();
        }
    }


    old_x = square_x;
    old_y = square_y;
}

void Pieces::validMove() {
    board[square_y][square_x] = board[old_y][old_x];
    board[old_y][old_x] = 8;

    square_x = -1000;
    square_y = -1000;
}

bool Pieces::move(int white, int black) {
    if (board[old_y][old_x] == white || board[old_y][old_x] == black) {
        if (square_x != old_x || square_y != old_y) {
            if (old_x != -1000 && old_y != -1000) {
                return true;
            }
        }
    }

    return false;
}

void Pieces::render(sf::RenderWindow &window) {
    drawPieces(window);
}

void Pieces::tick(sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (clicked == false) {
            movePiece(window);
            clicked = true;
        }
    }

    else {
        clicked = false;
    }
}
