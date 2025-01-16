#ifndef IA_H
#define IA_H

#include "struct.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "score.h"
#include "est_mouvement_valide.h"
#include "copie_tableau.h"
#include "appliquercoup.h"
#include "affichage.h"
#include <time.h>

Coup proposition_ia(Partie partie);

int meilleurscoup1(Partie partie, int joueuria);

int meilleurscoup2(Partie partie, int joueuria);

//int meilleurscoup3(Partie partie, int joueuria); POSSIBLE MAIS TROP DE CALCUL

int meilleurscoup4(Partie partie, int joueuria);

#endif
