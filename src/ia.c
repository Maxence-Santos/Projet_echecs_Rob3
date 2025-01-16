#include "../ia.h"



Coup proposition_ia(Partie partie){
    Coup coup;
    Coup coup_courant;
    srand( time( NULL ) );
    Partie partie_copie;
    int joueuria = partie.joueur_actif;
    int meilleursscore = -1000;
    int meilleursscore2 = -1000;
    coup_courant.iFrom = 0;
    coup_courant.jFrom = 0;
    coup_courant.iTo = 0;
    coup_courant.jTo = 0;

    for (int i=0; i < 8; i++){
        for (int j=0; j < 8; j++){
            if (partie.plateau[i][j].c == partie.joueur_actif){
                if (partie.plateau[i][j].p == pion){
                    for (int k = 0; k<3;k++){
                        coup.iFrom = i;
                        coup.jFrom = j;
                        coup.jTo = j+-1+k;
                        coup.iTo = (partie.joueur_actif == noir) ? i+1 : i-1;
                        if (coup.iTo >= 0 && coup.iTo < 8 && coup.jTo >= 0 && coup.jTo < 8){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                        }
                    }
                }
            else if (partie.plateau[i][j].p == reine) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                }
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                    }
                }
            
            }
            else if (partie.plateau[i][j].p == tour) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                }
            }
            else if (partie.plateau[i][j].p == fou) {
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                    }
            }
        }
        else if (partie.plateau[i][j].p == cavalier) {
            int deplacements[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
            for (int k = 0; k < 8; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + deplacements[k][0];
                coup.jTo = j + deplacements[k][1];
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                }
            }
        }
        else if (partie.plateau[i][j].p == roi) {
            for (int k = 0; k < 3; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + k - 1;
                coup.jTo = j + k - 1;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup, 1);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            meilleursscore2 = meilleurscoup1(partie_copie, joueuria);
                            if (meilleursscore2 > meilleursscore){
                                meilleursscore = meilleursscore2;
                                coup_courant = coup;
                            }
                            if (meilleursscore2 == meilleursscore){
                                if (rand()%5 == 0){
                                    meilleursscore = meilleursscore2;
                                    coup_courant = coup;
                                }
                            }
                            libererTableau(partie_copie);
                        }
                }
            }
        }
    }
    }
    }

    return coup_courant;
}

int meilleurscoup1(Partie partie, int joueuria){
    Coup coup;
    Partie partie_copie;
    int score = 0;
    int moyenne = 0;
    int m = 0;
    for (int i=0; i < 8; i++){
        for (int j=0; j < 8; j++){
            if (partie.plateau[i][j].c == partie.joueur_actif){
                if (partie.plateau[i][j].p == pion){
                    for (int k = 0; k<3;k++){
                        coup.iFrom = i;
                        coup.jFrom = j;
                        coup.jTo = j+-1+k;
                        coup.iTo = (partie.joueur_actif == noir) ? i+1 : i-1;
                        if (coup.iTo >= 0 && coup.iTo < 8 && coup.jTo >= 0 && coup.jTo < 8){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup2(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                        }
                    }
                }
            else if (partie.plateau[i][j].p == reine) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup2(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup2(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup2(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup2(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                }
            
            }
            else if (partie.plateau[i][j].p == tour) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup2(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup2(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
            else if (partie.plateau[i][j].p == fou) {
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup2(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup2(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
            }
        }
        else if (partie.plateau[i][j].p == cavalier) {
            int deplacements[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
            for (int k = 0; k < 8; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + deplacements[k][0];
                coup.jTo = j + deplacements[k][1];
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup2(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
        else if (partie.plateau[i][j].p == roi) {
            for (int k = 0; k < 3; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + k - 1;
                coup.jTo = j + k - 1;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup2(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
    }
    }
    }
    if (m == 0){
        return -100;
    }
    return moyenne/m;
}

int meilleurscoup2(Partie partie, int joueuria){
    Coup coup;
    Partie partie_copie;
    int moyenne = 0;
    int score = 0;
    int m = 0;
    for (int i=0; i < 8; i++){
        for (int j=0; j < 8; j++){
            if (partie.plateau[i][j].c == partie.joueur_actif){
                if (partie.plateau[i][j].p == pion){
                    for (int k = 0; k<3;k++){
                        coup.iFrom = i;
                        coup.jFrom = j;
                        coup.jTo = j+-1+k;
                        coup.iTo = (partie.joueur_actif == noir) ? i+1 : i-1;
                        if (coup.iTo >= 0 && coup.iTo < 8 && coup.jTo >= 0 && coup.jTo < 8){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup4(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                        }
                    }
                }
            else if (partie.plateau[i][j].p == reine) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup4(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup4(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup4(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup4(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                }
            
            }
            else if (partie.plateau[i][j].p == tour) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup4(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup4(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
            else if (partie.plateau[i][j].p == fou) {
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup4(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            score = meilleurscoup4(partie_copie,joueuria);
                            moyenne += score;
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
            }
        }
        else if (partie.plateau[i][j].p == cavalier) {
            int deplacements[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
            for (int k = 0; k < 8; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + deplacements[k][0];
                coup.jTo = j + deplacements[k][1];
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup4(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
        else if (partie.plateau[i][j].p == roi) {
            for (int k = 0; k < 3; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + k - 1;
                coup.jTo = j + k - 1;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        score = meilleurscoup4(partie_copie,joueuria);
                        moyenne += score;
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
    }
    }
    }
    if (m == 0){
        return -100;
    }
    return moyenne/m;

}

/*int meilleurscoup3(Partie partie, int joueuria){ TROP DE CALCULS
    Coup coup;
    Partie partie_copie;
    int moyenne = 0;
    int m = 0;
    for (int i=0; i < 8; i++){
        for (int j=0; j < 8; j++){
            if (partie.plateau[i][j].c == partie.joueur_actif){
                if (partie.plateau[i][j].p == pion){
                    for (int k = 0; k<3;k++){
                        coup.iFrom = i;
                        coup.jFrom = j;
                        coup.jTo = j+-1+k;
                        coup.iTo = (partie.joueur_actif == noir) ? i+1 : i-1;
                        if (coup.iTo >= 0 && coup.iTo < 8 && coup.jTo >= 0 && coup.jTo < 8){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += meilleurscoup4(partie_copie,joueuria);
                            m++;
                            libererTableau(partie_copie);
                        }
                        }
                    }
                }
            else if (partie.plateau[i][j].p == reine) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += meilleurscoup4(partie_copie,joueuria);
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += meilleurscoup4(partie_copie,joueuria);
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += meilleurscoup4(partie_copie,joueuria);
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += meilleurscoup4(partie_copie,joueuria);
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                }
            
            }
            else if (partie.plateau[i][j].p == tour) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += meilleurscoup4(partie_copie,joueuria);
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += meilleurscoup4(partie_copie,joueuria);
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
            else if (partie.plateau[i][j].p == fou) {
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += meilleurscoup4(partie_copie,joueuria);
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += meilleurscoup4(partie_copie,joueuria);
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
            }
        }
        else if (partie.plateau[i][j].p == cavalier) {
            int deplacements[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
            for (int k = 0; k < 8; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + deplacements[k][0];
                coup.jTo = j + deplacements[k][1];
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += meilleurscoup4(partie_copie,joueuria);
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
        else if (partie.plateau[i][j].p == roi) {
            for (int k = 0; k < 3; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + k - 1;
                coup.jTo = j + k - 1;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        partie_copie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += meilleurscoup4(partie_copie,joueuria);
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
    }
    }
    }
    if (m == 0){
        return -100;
    }
    return moyenne/m;

}
*/

int meilleurscoup4(Partie partie, int joueuria){
    Coup coup;
    Partie partie_copie;
    int moyenne = 0;
    int m = 0;
    for (int i=0; i < 8; i++){
        for (int j=0; j < 8; j++){
            if (partie.plateau[i][j].c == partie.joueur_actif){
                if (partie.plateau[i][j].p == pion){
                    for (int k = 0; k<3;k++){
                        coup.iFrom = i;
                        coup.jFrom = j;
                        coup.iTo = j+-1+k;
                        coup.jTo = (partie.joueur_actif == noir) ? i+1 : i-1;
                        if (coup.iTo >= 0 && coup.iTo < 8 && coup.jTo >= 0 && coup.jTo < 8){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)){
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                            m++;
                            libererTableau(partie_copie);
                        }
                        }
                    }
                }
            else if (partie.plateau[i][j].p == reine) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc);
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                }
            
            }
            else if (partie.plateau[i][j].p == tour) {
                for (int k = 0; k < 8; k++) { // Déplacement en ligne
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = k;
                    coup.jTo = j;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                        m++;
                        libererTableau(partie_copie);
                    }
                }
                for (int k = 0; k < 8; k++) {
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i;
                    coup.jTo = k;
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
            else if (partie.plateau[i][j].p == fou) {
                for (int k = -7; k <= 7; k++) { // Déplacement en diagonale
                    coup.iFrom = i;
                    coup.jFrom = j;
                    coup.iTo = i+k;
                    coup.jTo = j+k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
                    coup.iTo = i+k;
                    coup.jTo = j-k;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                        if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                            partie_copie = copie_tableau(partie);
                            appliquer_coup(&partie_copie, coup,1);
                            moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                            m++;
                            libererTableau(partie_copie);
                        }
                    }
            }
        }
        else if (partie.plateau[i][j].p == cavalier) {
            int deplacements[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
            for (int k = 0; k < 8; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + deplacements[k][0];
                coup.jTo = j + deplacements[k][1];
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
        else if (partie.plateau[i][j].p == roi) {
            for (int k = 0; k < 3; k++) {
                coup.iFrom = i;
                coup.jFrom = j;
                coup.iTo = i + k - 1;
                coup.jTo = j + k - 1;
                    if (0 <=coup.iTo &&  coup.iTo <=7 && 0 <= coup.jTo && coup.jTo <= 7){
                    if (mouvement_echecia(coup, partie) && est_mouvement_valide(coup, partie.plateau[i][j].p, partie, partie.joueur_actif)) {
                        partie_copie = copie_tableau(partie);
                        appliquer_coup(&partie_copie, coup,1);
                        moyenne += (score(partie_copie,joueuria)-score(partie_copie, (joueuria == blanc) ? noir : blanc));
                        m++;
                        libererTableau(partie_copie);
                    }
                }
            }
        }
    }
    }
    }
    if (m == 0){
        return -100;
    }
    return moyenne/m;

}