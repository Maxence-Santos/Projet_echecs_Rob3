#include <stdio.h>
#include <stdlib.h>
#include "creer_plateau.h"
#include "affichage.h"

int main() {
    Partie partie;
    Case **tab = creerplateau();
    partie.plateau = tab;
    partie.joueur_actif = blanc;

    //printf("tableau :  %d\n", tab[0][0].p==tour);
    affichage(partie);
}