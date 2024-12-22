#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "struct.h"

char piece_to_char(Piece p, Couleur c) {
    char ch;
    switch (p) {
        case tour:     ch = 't'; break;
        case cavalier: ch = 'c'; break;
        case fou:      ch = 'f'; break;
        case reine:    ch = 'q'; break;
        case roi:      ch = 'k'; break;
        case pion:     ch = 'p'; break;
        case vide:     ch = ' '; break;
    }
    return (c == blanc && !(p = vide) ) ? (ch - 32) : ch; // Mettre en majuscule pour les pièces blanches
}

void affichage(Partie partie) {
    Case** tableau = partie.plateau;
    for (int i = 0; i < 8; i++){
        printf("+-");
    }
    printf("+\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char piece = piece_to_char(tableau[i][j].p, tableau[i][j].c);
            printf("|%c", piece);
        }
        printf("|\n");
        for (int i = 0; i < 8; i++){
            printf("+-");
        }
        printf("+\n");
    }

    if (partie.joueur_actif == blanc){
        printf("Au tour des blancs de jouer\n");
    }
    else{
        printf("Au tour des noirs de jouer\n");
    }
}