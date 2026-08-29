//
// Created by Eric on 29/08/2026.
//

#include "Pawn.h"
#include "Pieces.h"

Pawn::Pawn() {

}

bool Pawn::checkIfOverOneSquare() {
    // TODO: debug through printing the square and old x and y

    if (pieces.square_y - pieces.old_y > 1) {
        std::cout << "illegal pawn move" << "\n";
    }


    return false;
}



