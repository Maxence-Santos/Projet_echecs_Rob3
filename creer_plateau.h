#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

Case **creerplateau(){
    Case **tableau = (Case **)malloc(8 * sizeof(Case *));
    for (int i = 0; i < 8; i++) {
        tableau[i] = (Case *)malloc(8 * sizeof(Case));
    }

    tableau[0][0].p = tour; // initialisation des pièces 
    tableau[0][1].p = cavalier;
    tableau[0][2].p = fou;
    tableau[0][3].p = reine;
    tableau[0][4].p = roi;
    tableau[0][5].p = fou;
    tableau[0][6].p = cavalier;
    tableau[0][7].p = tour;
    
    for (int j = 0; j < 8; j++){
        tableau[0][j].c = noir;
    }

    for (int j = 0; j < 8; j++){
        tableau[1][j].p = pion;
        tableau[1][j].c = noir;
    }

    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++){
            tableau[i][j].p = vide;
            tableau[i][j].c = noir;
        }
    }

    for (int j = 0; j < 8; j++){
        tableau[6][j].p = pion;
        tableau[6][j].c = blanc;
    }

    tableau[7][0].p = tour; 
    tableau[7][1].p = cavalier;
    tableau[7][2].p = fou;
    tableau[7][3].p = reine;
    tableau[7][4].p = roi;
    tableau[7][5].p = fou;
    tableau[7][6].p = cavalier;
    tableau[7][7].p = tour;

    for (int j = 0; j < 8; j++){
        tableau[7][j].c = blanc;
    }
    return tableau;
}