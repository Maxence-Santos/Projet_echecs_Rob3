#include <stdio.h>
#include "struct.h"
#include "creer_plateau.h"

void affichage(Partie partie) {
    Case** tab = creerplateau();
    for (int i=0;i<=7;i++) {
        for (int j=0;j<=7;j++) {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}