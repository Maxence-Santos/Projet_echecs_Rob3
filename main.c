#include <stdio.h>

typedef enum { tour, cavalier, fou, reine, roi, pion, vide } Piece;
typedef enum { blanc, noir } Couleur;

typedef struct {
    Piece p;
    Couleur c;
} Case;

typedef struct {
    int iFrom;
    int iFrom;
    int jTo;
    int jTo;
} Coup;

typedef struct {
    Case** plateau;
    Couleur joueur_actif;
} partie;


Case **creerplateau(){
    Case **tableau = malloc(8 * sizeof(Case *));
    for (int i = 0; i < 8; i++) {
        tableau[i] = malloc(8 * sizeof(Case));
    }

    tableau[0][0].p = tour; // initialisation des pièces 
    tableau[0][1].p = cavalier;
    tableau[0][2].p = fou;
    tableau[0][3].p = reine;
    tableau[0][4].p = roi;
    tableau[0][5].p = fou;
    tableau[0][6].p = cavalier;
    tableau[0][7].p = tour;
    
    for (int j = 1; j < 8; j++){
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

bool verifier_coup(Partie* partie, Coup coup){

}

int main() {
    

}