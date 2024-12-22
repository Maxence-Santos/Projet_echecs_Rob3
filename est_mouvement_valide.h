#include <stdbool.h>
#include <math.h>
#include "struct.h"

bool est_mouvement_valide(Coup coup, Piece type_piece, Partie partie) {
    int di = abs(coup.iTo - coup.iFrom);
    int dj = abs(coup.jTo - coup.jFrom);

    switch (type_piece) {
        case roi:
            return (di <= 1 && dj <= 1);
        case reine:
            if (di == 0 || dj == 0) { //Si la reine se déplace en ligne droite
                for (int i = coup.iFrom; i != coup.iTo; i += (coup.iTo - coup.iFrom) / di) {
                    for (int j = coup.jFrom; j != coup.jTo; j += (coup.jTo - coup.jFrom) / dj) {
                        if (partie.plateau[i][j].p != vide) {
                            return false;
                        }
                    }
                }
            } 
            else if (di == dj) { // Si la reine se déplace en diagonale
                for (int i = coup.iFrom, j = coup.jFrom; i != coup.iTo && j != coup.jTo; i += (coup.iTo - coup.iFrom) / di, j += (coup.jTo - coup.jFrom) / dj) {
                    if (partie.plateau[i][j].p != vide) {
                        return false;
                    }
                }
            }
            return (di == dj || di == 0 || dj == 0);
        case tour:
            return (di == 0 || dj == 0);
        case fou:
            return (di == dj);
        case cavalier:
            return (di == 2 && dj == 1) || (di == 1 && dj == 2);
        case pion:
            // Assuming white pawns move up the board (i.e., decreasing row index)
            return (di == 1 && dj == 0) || (partie.plateau[coup.iTo][coup.jTo].p != vide && partie.plateau[coup.iTo][coup.jTo].c == noir && (di == 1 && dj == 1)); // Simple move or capture
        default:
            return false;
    }
}