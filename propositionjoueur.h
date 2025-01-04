#include "struct.h"
#include <stdio.h>
#include "est_mouvement_valide.h"

Coup proposition_joueur(Partie partie){
    Coup coup;
    char case_from[3], case_to[3];
    printf("Entrez la case de la pièce que vous voulez déplacer (ex : A5) : ");
    scanf("%2s", case_from);
    coup.jFrom = case_from[0] - 'A'; //Convertir la lettre en indice de colonne
    coup.iFrom = 8 - (case_from[1] - '0'); //Convertir le chiffre en indice de ligne
    if (partie.joueur_actif != partie.plateau[coup.iFrom][coup.jFrom].c){
        printf("Ce n'est pas votre pièce, veuillez recommencer\n");
        return proposition_joueur(partie);
    }
    printf("Entrez la case où vous voulez déplacer la pièce : ");
    scanf("%2s", case_to);
    coup.jTo = case_to[0] - 'A'; //Convertir la lettre en indice de colonne
    coup.iTo = 8 - (case_to[1] - '0'); //Convertir le chiffre en indice de ligne
    if (est_mouvement_valide(coup,partie.plateau[coup.iFrom][coup.jFrom].p,partie)){
        return coup;
    }
    else{
        printf("Mouvement invalide, veuillez recommencer\n");
        return proposition_joueur(partie);
    }
}