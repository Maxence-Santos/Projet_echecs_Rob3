#include <stdbool.h>
#include <math.h>
#include "../copie_tableau.h"

Partie copie_tableau(Partie partie){
    Partie copie;
    copie.plateau = malloc(8 * sizeof(Case*));
    for (int i = 0; i < 8; i++) {
        copie.plateau[i] = malloc(8 * sizeof(Case));
        for (int j = 0; j < 8; j++) {
            copie.plateau[i][j] = partie.plateau[i][j];
        }
    }
    copie.joueur_actif = partie.joueur_actif;
    return copie;
}

void libererTableau(Partie tab) {
    for (int i = 0; i < 8; i++) {
        free(tab.plateau[i]);
    }
    free(tab.plateau);
}