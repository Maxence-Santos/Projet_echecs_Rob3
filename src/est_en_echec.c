#include <stdbool.h>
#include <math.h>
#include "../est_en_echec.h"
#include "../est_mouvement_valide.h"

bool est_en_echec(Partie partie, Couleur joueur_actif) {
    int iroi, jroi, autrejoueur;
    if (joueur_actif == blanc) {
        int autrejoueur = noir;
    }
    else {
        int autrejoueur = blanc;
    }
    
    // Balayage du plateau pour trouver le roi du joueur actif

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (partie.plateau[i][j].p == roi && partie.plateau[i][j].c == joueur_actif) {
                iroi = i;
                jroi = j;
            }
        }
    }

    // Balayage du plateau pour trouver les pièces adverses

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (partie.plateau[i][j].p != vide && partie.plateau[i][j].c != joueur_actif) {
                Coup coup;
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = iroi;
                coup.jTo = jroi;
                if (est_mouvement_valide(coup, partie.plateau[i][j].p, partie, autrejoueur)) {
                    return true;
                }
            }
        }
    }
    return false;
}