#include <stdio.h>
#include "struct.h"

Coup proposition_joueur(){
    Coup coup;
    printf("Entrez la ligne de la pièce que vous voulez déplacer : ");
    scanf("%d", &coup.iFrom);
    printf("Entrez la colonne de la pièce que vous voulez déplacer : ");
    scanf("%d", &coup.jFrom);
    printf("Entrez la ligne de la case où vous voulez déplacer la pièce : ");
    scanf("%d", &coup.iTo);
    printf("Entrez la colonne de la case où vous voulez déplacer la pièce : ");
    scanf("%d", &coup.jTo);
    return coup;
}