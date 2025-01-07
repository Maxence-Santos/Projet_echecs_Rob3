#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#include <stdbool.h>
#include "struct.h"

// Déclaration de la fonction de validation de mouvement
bool est_mouvement_valide(Coup coup, Piece type_piece, Partie partie);

#endif // MOUVEMENT_H
