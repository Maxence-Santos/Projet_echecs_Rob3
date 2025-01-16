#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "creer_plateau.h"
#include "affichage.h"
#include "appliquercoup.h"
#include "propositionjoueur.h"
#include "est_en_echec.h"
#include "mat.h"
#include "sauvegarde.h"
#include <time.h>
#include "ia.h"

int main() {
    int mat = 0;
    Partie partie;
    char choix;
    partie.nb_coups = 0;
    char choixia;
    // Demander si l'utilisateur souhaite charger une partie
    printf("Bienvenue dans le jeu d'echecs.\n");
    printf("Voulez-vous jouer contre une IA ? (o/n) : ");
    scanf(" %c", &choixia);
    printf("Voulez-vous charger une partie ? (o/n) : ");
    scanf(" %c", &choix);
    partie.plateau = creerplateau();
    partie.joueur_actif = noir;
    if (choix == 'o' || choix == 'O') {
        // Lister les parties disponibles
        int nb_parties_save = lister_parties();
        if (nb_parties_save == 0) {
            printf("Aucune partie sauvegardée trouvée. Une nouvelle partie sera creee.\n");
            printf("Combien de temps voulez-vous que la partie dure ? (en secondes) : ");
            scanf("%d", &partie.temps_blanc);
            partie.temps_noir = partie.temps_blanc;
        } else {
            printf("Entrez l'identifiant de la partie à charger : ");
            int id;
            scanf("%d", &id);
            int tab[4];
            if (charger_partie(partie, id, tab)) {
                partie.joueur_actif = tab[0];
                partie.temps_blanc = tab[1];
                partie.temps_noir = tab[2];
                partie.nb_coups = tab[3];
                partie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                printf("Partie chargee avec succes.\n");
            } else {
                printf("Aucune partie sauvegardee trouvee. Une nouvelle partie sera creee.\n");
                printf("Combien de temps voulez-vous que la partie dure ? (en secondes) : ");
                scanf("%d", &partie.temps_blanc);
                partie.temps_noir = partie.temps_blanc;
            }
        }

    } else {
        // Initialisation d'une nouvelle partie
        printf("Combien de temps voulez-vous que la partie dure ? (en secondes) : ");
        scanf("%d", &partie.temps_blanc);
        partie.temps_noir = partie.temps_blanc;
    }
    if (choixia == 'n' || choixia == 'N'){
    while (!mat) {
        // Changer de joueur actif
        partie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
        // Afficher le plateau
        affichage(partie);
        // Vérifier si le joueur actif est en échec
        if (est_en_echec(partie, partie.joueur_actif)) {
            printf(" \n");
            if (est_en_mat(partie, partie.joueur_actif)) {
                if (partie.joueur_actif == blanc) {
                    printf("\n\nEchec et mat, les noirs gagnent !\n");
                } else {
                    printf("\n\nEchec et mat, les blancs gagnent !\n");
                }
                mat = 1;
                break;
            }
            if (partie.joueur_actif == blanc) {
                printf("\nEchec au roi blanc.\n");
            } else {
                printf("\nEchec au roi noir.\n");
            }
        }

        int avant = time(NULL);
        // Appliquer le coup proposé par le joueur
        appliquer_coup(&partie, proposition_joueur(partie), 0);
        partie.nb_coups++;
        int apres = time(NULL);
        if (partie.joueur_actif == blanc){
            partie.temps_blanc -= apres - avant;
        }
        else {
            partie.temps_noir -= apres - avant;
        }
        if (partie.temps_blanc <= 0) {
            printf("Temps ecoule pour les blancs, les noirs gagnent !\n");
            break;
        }
        if (partie.temps_noir <= 0) {
            printf("Temps ecoule pour les noirs, les blanc gagnent !\n");
            break;
        }
    }
    }
    else{
        while (!mat) {
        // Changer de joueur actif
        partie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
        // Afficher le plateau
        // Vérifier si le joueur actif est en échec
        if (est_en_echec(partie, partie.joueur_actif)) {
            printf(" \n");
            if (est_en_mat(partie, partie.joueur_actif)) {
                if (partie.joueur_actif == blanc) {
                    printf("\n\nEchec et mat, les noirs gagnent !\n");
                } else {
                    printf("\n\nEchec et mat, les blancs gagnent !\n");
                }
                mat = 1;
                break;
            }
            if (partie.joueur_actif == blanc) {
                printf("\nEchec au roi blanc.\n");
            } else {
                printf("\nEchec au roi noir.\n");
            }
        }
        if (partie.joueur_actif == blanc) {affichage(partie);}

        int avant = time(NULL);
        if (partie.joueur_actif == blanc){
            appliquer_coup(&partie, proposition_joueur(partie), 0);
        }
        else{
            appliquer_coup(&partie, proposition_ia(partie), 1);
        }
        // Appliquer le coup proposé par le joueur
        partie.nb_coups++;
        int apres = time(NULL);
        if (partie.joueur_actif == blanc){
            partie.temps_blanc -= apres - avant;
        }
        else {
            partie.temps_noir -= apres - avant;
        }
        if (partie.temps_blanc <= 0) {
            printf("Temps ecoule pour les blancs, les noirs gagnent !\n");
            break;
        }
        if (partie.temps_noir <= 0) {
            printf("Temps ecoule pour les noirs, les blanc gagnent !\n");
            break;
        }
    }
    }

    // Libérer la mémoire utilisée par le plateau
    libererTableau(partie);
    return 0;
}
