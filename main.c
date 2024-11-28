#include <stdio.h>
#include <stdlib.h>
#include "creer_plateau.h"

int main() {
    
    Case **tab = creerplateau();

    printf("tableau :  %d\n", tab[0][0].p==tour);

}