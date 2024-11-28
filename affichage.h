#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "struct.h"

char piece_to_char(Piece p, Couleur c) {
    char ch;
    switch (p) {
        case tour:     ch = 'r'; break;
        case cavalier: ch = 'n'; break;
        case fou:      ch = 'b'; break;
        case reine:    ch = 'q'; break;
        case roi:      ch = 'k'; break;
        case pion:     ch = 'p'; break;
        case vide:     ch = ' '; break;
    }
    return (c == blanc && !(p = vide) ) ? (ch - 32) : ch; // Mettre en majuscule pour les pièces blanches
}

void affichage(Case **tableau) {
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
}