#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "creer_plateau.h"
#include "affichage.h"
#include "appliquercoup.h"
#include "propositionjoueur.h"
#include "est_en_echec.h"


int main() {
    int mat = 0;
    Partie partie;
    partie.plateau = creerplateau();

    while (!mat) {
        partie.joueur_actif = blanc;
        affichage(partie);
        if (est_en_echec(partie, partie.joueur_actif)){
            printf("Echec au roi blanc\n");
        }
        appliquer_coup(&partie, proposition_joueur(partie));
        partie.joueur_actif = noir;
        affichage(partie);
        if (est_en_echec(partie, partie.joueur_actif)){
            printf("Echec au roi noir\n");
        }
        appliquer_coup(&partie, proposition_joueur(partie));
    }    
}