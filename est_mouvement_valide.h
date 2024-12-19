#include <stdbool.h>
#include <math.h>
#include "struct.h"

bool est_mouvement_valide(Coup coup, Piece type_piece) {
    int di = abs(coup.iTo - coup.iFrom);
    int dj = abs(coup.jTo - coup.jFrom);

    switch (type_piece) {
        case roi:
            return (di <= 1 && dj <= 1);
        case reine:
            return (di == dj || di == 0 || dj == 0);
        case tour:
            return (di == 0 || dj == 0);
        case fou:
            return (di == dj);
        case cavalier:
            return (di == 2 && dj == 1) || (di == 1 && dj == 2);
        case pion:
            // Assuming white pawns move up the board (i.e., decreasing row index)
            return (di == 1 && dj == 0) || (di == 1 && dj == 1); // Simple move or capture
        default:
            return false;
    }
}