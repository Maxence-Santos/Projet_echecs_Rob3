#ifndef struct_h
#define struct_h

typedef enum { tour, cavalier, fou, reine, roi, pion, vide } Piece;
typedef enum { blanc, noir, couleurvide } Couleur;

typedef struct {
    Piece p;
    Couleur c;
} Case;

typedef struct {
    int iFrom;
    int jFrom;
    int iTo;
    int jTo;
} Coup;

typedef struct {
    Case** plateau;
    Couleur joueur_actif;
    int nb_coups;
    int temps_blanc;
    int temps_noir;
} Partie;
#endif