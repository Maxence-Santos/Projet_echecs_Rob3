#include <stdlib.h>
#include "../struct.h"

// Implémentation de la fonction pour créer le plateau
Case **creerplateau() {
    // Allocation de mémoire pour le tableau 8x8
    Case **tableau = (Case **)malloc(8 * sizeof(Case *));
    for (int i = 0; i < 8; i++) {
        tableau[i] = (Case *)malloc(8 * sizeof(Case));
    }

    // Initialisation des pièces noires
    tableau[0][0].p = tour; tableau[0][1].p = cavalier; tableau[0][2].p = fou;
    tableau[0][3].p = reine; tableau[0][4].p = roi; tableau[0][5].p = fou;
    tableau[0][6].p = cavalier; tableau[0][7].p = tour;

    for (int j = 0; j < 8; j++) {
        tableau[0][j].c = noir;
        tableau[1][j].p = pion;
        tableau[1][j].c = noir;
    }

    // Initialisation des cases vides
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            tableau[i][j].p = vide;
            tableau[i][j].c = couleurvide;
        }
    }

    // Initialisation des pièces blanches
    for (int j = 0; j < 8; j++) {
        tableau[6][j].p = pion;
        tableau[6][j].c = blanc;
    }

    tableau[7][0].p = tour; tableau[7][1].p = cavalier; tableau[7][2].p = fou;
    tableau[7][3].p = reine; tableau[7][4].p = roi; tableau[7][5].p = fou;
    tableau[7][6].p = cavalier; tableau[7][7].p = tour;

    for (int j = 0; j < 8; j++) {
        tableau[7][j].c = blanc;
    }

    return tableau;
}
