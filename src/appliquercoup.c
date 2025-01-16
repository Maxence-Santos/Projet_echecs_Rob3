#include "../appliquercoup.h"

void appliquer_coup(Partie* partie, Coup coup, int ia) {
    partie->plateau[coup.iTo][coup.jTo] = partie->plateau[coup.iFrom][coup.jFrom];
    partie->plateau[coup.iFrom][coup.jFrom].p = vide;
    partie->plateau[coup.iFrom][coup.jFrom].c = couleurvide;
    if (ia != 0) {
        if ((coup.iTo == 0 || coup.iTo == 7) && partie->plateau[coup.iFrom][coup.jFrom].p == pion) {
            partie->plateau[coup.iTo][coup.jTo].p = reine;
        }
    }
}