#include "../propositionjoueur.h"
#include <stdio.h>

Coup proposition_joueur(Partie partie) {
    Coup coup;
    char case_from[3], case_to[3];

    // Demander à l'utilisateur la case de départ
    printf("Entrez la case de la pièce que vous voulez deplacer : ");
    scanf("%2s", case_from);
    
    // Convertir la case d'entrée (lettre + chiffre) en indices
    coup.jFrom = case_from[0] - 'A';  // Convertir la lettre en indice de colonne
    coup.iFrom = '8' - (case_from[1]); // Convertir le chiffre en indice de ligne

    // Vérifier si les indices sont valides
    if ( (coup.iFrom < 0 || coup.iFrom > 7) || (coup.jFrom < 0 || coup.jFrom > 7) ) {
        printf("Case invalide, veuillez recommencer\n");
        return proposition_joueur(partie);  // Demander à nouveau
    }

    // Vérifier que le joueur a bien sélectionné une de ses pièces
    if (partie.joueur_actif != partie.plateau[coup.iFrom][coup.jFrom].c) {
        printf("Ce n'est pas votre piece, veuillez recommencer\n");
        return proposition_joueur(partie);  // Demander à nouveau
    }

    // Demander à l'utilisateur la case de destination
    printf("Entrez la case ou vous voulez deplacer la piece : ");
    scanf("%2s", case_to);
    
    // Convertir la case d'arrivée (lettre + chiffre) en indices
    coup.jTo = case_to[0] - 'A';  // Convertir la lettre en indice de colonne
    coup.iTo = '8' - (case_to[1]); // Convertir le chiffre en indice de ligne

    // Vérifier si le mouvement est valide

    if (est_mouvement_valide(coup, partie.plateau[coup.iFrom][coup.jFrom].p, partie, partie.joueur_actif)) {
        Partie partie2;
        partie2 = copie_tableau(partie);
        appliquer_coup(&partie2, coup);
        if (est_en_echec(partie2, partie.joueur_actif)) {
            printf("Mouvement invalide, veuillez recommencer\n");
            libererTableau(partie2);
            return proposition_joueur(partie);  // Demander à nouveau si invalide
        }   if ((coup.iTo == 0 || coup.iTo == 7) && partie.plateau[coup.iFrom][coup.jFrom].p == pion) {
                printf("\n\nPromotion du pion !\n");
                printf("Entrez la pièce de promotion (T, C, F, Q) : ");
                char promotion;
                scanf(" %c", &promotion);
                switch (promotion) {
                    case 'T':
                        partie.plateau[coup.iFrom][coup.jFrom].p = tour;
                        break;
                    case 'C':
                        partie.plateau[coup.iFrom][coup.jFrom].p = cavalier;
                        break;
                    case 'F':
                        partie.plateau[coup.iFrom][coup.jFrom].p = fou;
                        break;
                    case 'Q':
                        partie.plateau[coup.iFrom][coup.jFrom].p = reine;
                        break;
                    default:
                        printf("Pièce de promotion invalide, promotion automatique en reine\n");
                        partie.plateau[coup.iFrom][coup.jFrom].p = reine;
                        break;
                }
            }
        return coup;  // Retourner le coup si valide
    } else {
        printf("Mouvement invalide, veuillez recommencer\n");
        return proposition_joueur(partie);  // Demander à nouveau si invalide
    }
}
