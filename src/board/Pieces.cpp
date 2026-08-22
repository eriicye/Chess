//
// Created by Eric on 16/08/2026.
//

#include "Pieces.h"
#include "../constants/Constants.h"

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
            int piece = board[row][col];

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

void Pieces::render(sf::RenderWindow &window) {
    drawPieces(window);
}

void Pieces::tick() {

}
