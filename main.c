#include <stdio.h>
#include <stdlib.h>
#include "creer_plateau.h"
#include "affichage.h"
#include "appliquercoup.h"
#include "propositionjoueur.h"
#include "struct.h"

int main() {
    int mat = 0;
    Partie partie;
    partie.plateau = creerplateau();

    while (!mat) {
        partie.joueur_actif = blanc;
        affichage(partie);
        appliquer_coup(&partie, proposition_joueur(partie));
        printf("%d\n",partie.plateau[0][0].p);
        partie.joueur_actif = noir;
        affichage(partie);
        appliquer_coup(&partie, proposition_joueur(partie));
    }    
}