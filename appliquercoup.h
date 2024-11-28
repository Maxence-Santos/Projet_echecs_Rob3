#include "struct.h"

void appliquer_coup(Partie* partie, Coup coup) {
    partie->plateau[coup.iTo][coup.jTo] = partie->plateau[coup.iFrom][coup.jFrom];
    partie->plateau[coup.iFrom][coup.jFrom].p = vide;
    partie->plateau[coup.iFrom][coup.jFrom].c = blanc;
}