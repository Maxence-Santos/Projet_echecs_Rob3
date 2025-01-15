#include "../score.h"

int score(Partie partie, Couleur joueur_actif){
    int score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (partie.plateau[i][j].c == joueur_actif) {
                switch (partie.plateau[i][j].p) {
                    case pion:
                        score += 1;
                        break;
                    case cavalier:
                        score += 3;
                        break;
                    case fou:
                        score += 3;
                        break;
                    case tour:
                        score += 5;
                        break;
                    case reine:
                        score += 9;
                        break;
                }
            }
        }
    }
    return score;
}