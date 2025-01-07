#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "../est_mouvement_valide.h"

bool est_mouvement_valide(Coup coup, Piece type_piece, Partie partie, Couleur joueur_actif) {
    int di = abs(coup.iTo - coup.iFrom);
    int dj = abs(coup.jTo - coup.jFrom);

    switch (type_piece) {
        case roi:
            // Vérifier la case d'arrivée
            if (partie.plateau[coup.iTo][coup.jTo].p != vide && partie.plateau[coup.iTo][coup.jTo].c == joueur_actif) {
                return false;
            }
            return (di <= 1 && dj <= 1);

        case reine:
            if (di == 0 || dj == 0) { // Si la reine se déplace en ligne droite
                int step_i = (di == 0) ? 0 : (coup.iTo - coup.iFrom) / di;
                int step_j = (dj == 0) ? 0 : (coup.jTo - coup.jFrom) / dj;
                for (int i = coup.iFrom + step_i, j = coup.jFrom + step_j; i != coup.iTo || j != coup.jTo; i += step_i, j += step_j) {
                    if (partie.plateau[i][j].p != vide) {
                        return false;
                    }
                }
            } 
            else if (di == dj) { // Si la reine se déplace en diagonale
                int step_i = (coup.iTo - coup.iFrom) / di;
                int step_j = (coup.jTo - coup.jFrom) / dj;
                for (int i = coup.iFrom + step_i, j = coup.jFrom + step_j; i != coup.iTo && j != coup.jTo; i += step_i, j += step_j) {
                    if (partie.plateau[i][j].p != vide) {
                        return false;
                    }
                }
            }
            // Vérifier la case d'arrivée
            if (partie.plateau[coup.iTo][coup.jTo].p != vide && partie.plateau[coup.iTo][coup.jTo].c == joueur_actif) {
                return false;
            }
            return (di == dj || di == 0 || dj == 0);

        case tour:
            if (di == 0 || dj == 0) { // Si la tour se déplace en ligne droite
                int step_i = (di == 0) ? 0 : (coup.iTo - coup.iFrom) / di;
                int step_j = (dj == 0) ? 0 : (coup.jTo - coup.jFrom) / dj;
                for (int i = coup.iFrom + step_i, j = coup.jFrom + step_j; i != coup.iTo || j != coup.jTo; i += step_i, j += step_j) {
                    if (partie.plateau[i][j].p != vide) {
                        return false;
                    }
                }
            }
            // Vérifier la case d'arrivée
            if (partie.plateau[coup.iTo][coup.jTo].p != vide && partie.plateau[coup.iTo][coup.jTo].c == joueur_actif) {
                return false;
            }
            return (di == 0 || dj == 0);

        case fou:
            if (di == dj) { // Si le fou se déplace en diagonale
                int step_i = (coup.iTo - coup.iFrom) / di;
                int step_j = (coup.jTo - coup.jFrom) / dj;
                for (int i = coup.iFrom + step_i, j = coup.jFrom + step_j; i != coup.iTo && j != coup.jTo; i += step_i, j += step_j) {
                    if (partie.plateau[i][j].p != vide) {
                        return false;
                    }
                }
            }
            // Vérifier la case d'arrivée
            if (partie.plateau[coup.iTo][coup.jTo].p != vide && partie.plateau[coup.iTo][coup.jTo].c == joueur_actif) {
                return false;
            }
            return (di == dj);

        case cavalier:
            // Vérifier la case d'arrivée
            if (partie.plateau[coup.iTo][coup.jTo].p != vide && partie.plateau[coup.iTo][coup.jTo].c == joueur_actif) {
                return false;
            }
            return (di == 2 && dj == 1) || (di == 1 && dj == 2);

        case pion:
            // Le pion se déplace d'une case en avant ou capture en diagonale
            if (dj == 0 && di == 1 && partie.plateau[coup.iTo][coup.jTo].p == vide) {
                return true;
            } else if (di == 1 && dj == 1 && partie.plateau[coup.iTo][coup.jTo].p != vide) {
                return true;
            }
            // Le pion peut se déplacer de deux cases en avant s'il n'a pas encore bougé
            if (di == 2 && dj == 0 && joueur_actif == 1 && coup.iFrom == 1 && coup.iTo == 3 && partie.plateau[2][coup.jTo].p == vide) {
                return true;
            }
            if (di == 2 && dj == 0 && joueur_actif == 0 && coup.iFrom == 6 && coup.iTo == 4 && partie.plateau[5][coup.jTo].p == vide) {
                return true;
            }

            return false;

        default:
            return false;
    }
}
