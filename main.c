#include <stdio.h>
#include <stdlib.h>
#include "creer_plateau.h"
#include "affichage.h"
#include "appliquercoup.h"
#include "propositionjoueur.h"
#include "struct.h"

int main() {
    Partie partie;
    partie.plateau = creerplateau();
    partie.joueur_actif = blanc;
    affichage(partie.plateau);
    appliquer_coup(&partie, proposition_joueur());
    printf("%d\n",partie.plateau[0][0].p);
    affichage(partie.plateau);

}