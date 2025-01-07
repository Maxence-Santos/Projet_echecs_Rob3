#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "creer_plateau.h"
#include "affichage.h"
#include "appliquercoup.h"
#include "propositionjoueur.h"
#include "est_en_echec.h"
#include "mat.h"


int main() {
    int mat = 0;
    Partie partie;
    partie.plateau = creerplateau();
    partie.joueur_actif = noir;
    while (!mat) {
        if (partie.joueur_actif == blanc) {
            partie.joueur_actif = noir;
        } else {
            partie.joueur_actif = blanc;
        }
        affichage(partie);
        if (est_en_echec(partie, partie.joueur_actif)){
            if (est_en_mat(partie, partie.joueur_actif)){
                if (partie.joueur_actif == blanc) printf("Echec et mat, les noirs gagnent !\n");
                else printf("Echec et mat, les blancs a gagnent !\n");
                mat = 1;
                break;
            }
            if (partie.joueur_actif == blanc) printf("Echec au roi blanc\n");
            else printf("Echec au roi noir\n");
        }
        appliquer_coup(&partie, proposition_joueur(partie));
    }    
}