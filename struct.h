typedef enum { tour, cavalier, fou, reine, roi, pion, vide } Piece;
typedef enum { blanc, noir } Couleur;

typedef struct {
    Piece p;
    Couleur c;
} Case;

typedef struct {
    int iFrom;
    int iFrom;
    int jTo;
    int jTo;
} Coup;

typedef struct {
    Case** plateau;
    Couleur joueur_actif;
} partie;
