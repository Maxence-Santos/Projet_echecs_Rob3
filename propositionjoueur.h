#include "struct.h"
#include <stdio.h>
#include "est_mouvement_valide.h"

Coup proposition_joueur(Partie partie){
    Coup coup;
    printf("Entrez la ligne de la pièce que vous voulez déplacer : ");
    scanf("%d", &coup.iFrom);
    printf("Entrez la colonne de la pièce que vous voulez déplacer : ");
    scanf("%d", &coup.jFrom);
    if (partie.joueur_actif != partie.plateau[coup.iFrom][coup.jFrom].c){
        printf("Ce n'est pas votre pièce, veuillez recommencer\n");
        return proposition_joueur(partie);
    }
    printf("Entrez la ligne de la case où vous voulez déplacer la pièce : ");
    scanf("%d", &coup.iTo);
    printf("Entrez la colonne de la case où vous voulez déplacer la pièce : ");
    scanf("%d", &coup.jTo);
    if (est_mouvement_valide(coup,partie.plateau[coup.iFrom][coup.jFrom].p,partie)){
        return coup;
    }
    else{
        printf("Mouvement invalide, veuillez recommencer\n");
        return proposition_joueur(partie);
    }
}