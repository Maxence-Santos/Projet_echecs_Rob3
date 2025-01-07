#include "../propositionjoueur.h"
#include <stdio.h>

Coup proposition_joueur(Partie partie) {
    Coup coup;
    char case_from[3], case_to[3];

    // Demander à l'utilisateur la case de départ
    printf("Entrez la case de la pièce que vous voulez déplacer : ");
    scanf("%2s", case_from);
    
    // Convertir la case d'entrée (lettre + chiffre) en indices
    coup.jFrom = case_from[0] - 'A';  // Convertir la lettre en indice de colonne
    coup.iFrom = '8' - (case_from[1]); // Convertir le chiffre en indice de ligne

    // Vérifier que le joueur a bien sélectionné une de ses pièces
    if (partie.joueur_actif != partie.plateau[coup.iFrom][coup.jFrom].c) {
        printf("Ce n'est pas votre pièce, veuillez recommencer\n");
        return proposition_joueur(partie);  // Demander à nouveau
    }

    // Demander à l'utilisateur la case de destination
    printf("Entrez la case où vous voulez déplacer la pièce : ");
    scanf("%2s", case_to);
    
    // Convertir la case d'arrivée (lettre + chiffre) en indices
    coup.jTo = case_to[0] - 'A';  // Convertir la lettre en indice de colonne
    coup.iTo = '8' - (case_to[1]); // Convertir le chiffre en indice de ligne

    // Vérifier si le mouvement est valide
    if (est_mouvement_valide(coup, partie.plateau[coup.iFrom][coup.jFrom].p, partie)) {
        return coup;  // Retourner le coup si valide
    } else {
        printf("Mouvement invalide, veuillez recommencer\n");
        return proposition_joueur(partie);  // Demander à nouveau si invalide
    }
}
