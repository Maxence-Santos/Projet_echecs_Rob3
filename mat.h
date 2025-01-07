#ifndef MAT_H
#define MAT_H

#include <stdbool.h>
#include "struct.h"
#include "est_en_echec.h"
#include "est_mouvement_valide.h"
#include "copie_tableau.h"
#include "appliquercoup.h"

// Déclaration de la fonction de validation de mouvement
bool est_en_mat(Partie partie, Couleur joueur_actif);

#endif 
