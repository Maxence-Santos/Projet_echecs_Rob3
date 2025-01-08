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

int main() {
    int mat = 0;
    Partie partie;
    char choix;
    // Demander si l'utilisateur souhaite charger une partie
    printf("Voulez-vous charger une partie ? (o/n) : ");
    scanf(" %c", &choix);
    partie.plateau = creerplateau();
    partie.joueur_actif = noir;
    if (choix == 'o' || choix == 'O') {
        // Lister les parties disponibles
        int nb_parties_save = lister_parties();
        if (nb_parties_save == 0) {
            printf("Aucune partie sauvegardée trouvée. Une nouvelle partie sera creee.\n");
        } else {
            printf("Entrez l'identifiant de la partie à charger : ");
            int id;
            scanf("%d", &id);
            if (charger_partie(partie, id, &partie.joueur_actif)) {
                partie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;
                printf("Partie chargee avec succes.\n");
            } else {
                printf("Echec du chargement de la partie. Une nouvelle partie sera creee.\n");
            }
        }

    } else {
        // Initialisation d'une nouvelle partie
        partie.joueur_actif = noir;
    }

    while (!mat) {
        // Changer de joueur actif
        partie.joueur_actif = (partie.joueur_actif == blanc) ? noir : blanc;

        // Afficher le plateau
        affichage(partie);

        // Vérifier si le joueur actif est en échec
        if (est_en_echec(partie, partie.joueur_actif)) {
            if (est_en_mat(partie, partie.joueur_actif)) {
                if (partie.joueur_actif == blanc) {
                    printf("Echec et mat, les noirs gagnent !\n");
                } else {
                    printf("Echec et mat, les blancs gagnent !\n");
                }
                mat = 1;
                break;
            }
            if (partie.joueur_actif == blanc) {
                printf("Echec au roi blanc.\n");
            } else {
                printf("Echec au roi noir.\n");
            }
        }

        // Appliquer le coup proposé par le joueur
        appliquer_coup(&partie, proposition_joueur(partie));
    }

    // Libérer la mémoire utilisée par le plateau
    libererTableau(partie);
    return 0;
}
