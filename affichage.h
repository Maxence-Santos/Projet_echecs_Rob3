#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "struct.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Fonction pour obtenir le caractère représentant une pièce
char piece_to_char(Piece p, Couleur c);

// Fonction pour afficher l'état du plateau de jeu
void affichage(Partie partie);

#endif // AFFICHAGE_H
