#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../sauvegarde.h"

void sauvegarder_partie(Partie partie) {
    FILE* fichier = fopen(FICHIER_SAUVEGARDE, "a");
    if (!fichier) {
        printf("Erreur : Impossible d'ouvrir le fichier de sauvegarde.\n");
        return;
    }

    int id = prochain_identifiant();
    fprintf(fichier, "# Partie %d\n", id);
    fprintf(fichier, "# Joueur %d\n", partie.joueur_actif);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fprintf(fichier, "%d %d ", partie.plateau[i][j].p, partie.plateau[i][j].c);
        }
        fprintf(fichier, "\n");
    }
    fprintf(fichier, "\n");

    fclose(fichier);
    printf("Partie sauvegardee sous l'identifiant %d.\n", id);
}

bool charger_partie(Partie partie, int id, Couleur *jactif) {
    FILE *file = fopen(FICHIER_SAUVEGARDE, "r");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier de sauvegarde");
        return false;
    }
     // Nous chargeons simplement la première partie sauvegardée
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        int partie_id;
        if (sscanf(buffer, "# Partie %d", &partie_id) == 1 && partie_id == id) {
            printf("Chargement de la partie %d...\n", id);
            // Charger les données de la partie ici (plateau, joueur_actif)
            int a;
            fscanf(file, "# Joueur %d", &a);
            *jactif = a;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    int piece, couleur;
                    fscanf(file, "%d %d", &piece, &couleur);
                    partie.plateau[i][j].p = piece;
                    partie.plateau[i][j].c = couleur;
                }
            }
            fclose(file);
            printf("Joueur actif : %d\n", partie.joueur_actif);
            return true; // Chargement réussi
        }
    }

    fclose(file);
    printf("Aucune partie sauvegardee trouvee.\n");
    return false; // Aucune partie trouvée
}

int lister_parties() {
    int parties = 0;
    FILE* fichier = fopen(FICHIER_SAUVEGARDE, "r");
    if (fichier == NULL) {
        printf("Aucune sauvegarde disponible.\n");
        return parties;
    }

    char ligne[256];
    printf("Parties disponibles :\n");
    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strncmp(ligne, "# Partie", 8) == 0) {
            printf("%s", ligne);
            parties++;
        }
    }

    fclose(fichier);
    return parties;
}

int prochain_identifiant() {
    FILE* fichier = fopen(FICHIER_SAUVEGARDE, "r");
    if (fichier == NULL) {
        return 1; // Première partie
    }

    char ligne[256];
    int dernier_id = 0;

    while (fgets(ligne, sizeof(ligne), fichier)) {
        if (strncmp(ligne, "# Partie", 8) == 0) {
            sscanf(ligne, "# Partie %d", &dernier_id);
        }
    }

    fclose(fichier);
    return dernier_id + 1;
}

bool supprimer_fichier() {
    if (remove(FICHIER_SAUVEGARDE) == 0) {
        printf("Les sauvegardes ont ete supprime avec succes.\n");
        return true;
    } else {
        perror("Erreur lors de la suppression du fichier");
        return false;
    }
}
