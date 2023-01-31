#include "fonctions.h"

/* Procédure d'initialisation du plateau */
void init(int ttint_tab[TAILLE][TAILLE]) {
    int int_i; //Variable de boucle
    int int_j; //Variable de boucle

    for (int_i = 0; int_i < TAILLE; int_i++) {
        for (int_j = 0; int_j < TAILLE; int_j++) {
            ttint_tab[int_i][int_j] = -1; //On initialise le plateau à -1
        }
    }
}

/* Procédure d'affichage du plateau */
void afficher(int ttint_tab[TAILLE][TAILLE]) {
    int int_i; //Variable de boucle
    int int_j; //Variable de boucle

    for (int_i = 0; int_i < TAILLE; int_i++) { 
        printf("-------------\n");
        for (int_j = 0; int_j < TAILLE; int_j++) {
            printf("|");
            if (ttint_tab[int_i][int_j] == -1) {
                printf("   "); //Si la case est vide, on affiche 3 espaces
            } else if (ttint_tab[int_i][int_j] == 0) {
                printf(" X "); //Si la case est occupée par le joueur 1, on affiche X
            } else if (ttint_tab[int_i][int_j] == 1) {
                printf(" O "); //Si la case est occupée par le joueur 2, on affiche O
            }
        }
        printf("|\n");
    }
    printf("-------------\n");
}

/* Fonction qui permet au joeur de placer son coup */
int jouer(int ttint_tab[TAILLE][TAILLE], int int_joueur, int int_x, int int_y) {
    if (ttint_tab[int_x][int_y] == -1) {      //Si la case est vide
        ttint_tab[int_x][int_y] = int_joueur; //On place le pion du joueur
        return 1;                             //On retourne 1 pour dire que le coup est valide
    } else {
        return 0; //On retourne 0 pour dire que le coup est invalide
    }
}

/* Méthode de vérification de la victoire */
int aGagne(int ttint_tab[TAILLE][TAILLE]) {
    int int_i;
    int int_j;

    /* Vérification des lignes */
    for (int_i = 0; int_i < TAILLE; int_i++) { 
        if (ttint_tab[int_i][0] == ttint_tab[int_i][1] && ttint_tab[int_i][1] == ttint_tab[int_i][2] && ttint_tab[int_i][0] != -1) { //Si les 3 cases de la ligne sont occupées par le même joueur
            return ttint_tab[int_i][0]; //On retourne le numéro du joueur
        }
    }

    /* Vérification des colonnes */ 
    for (int_j = 0; int_j < TAILLE; int_j++) {
        if (ttint_tab[0][int_j] == ttint_tab[1][int_j] && ttint_tab[1][int_j] == ttint_tab[2][int_j] && ttint_tab[0][int_j] != -1) { //Si les 3 cases de la colonne sont occupées par le même joueur
            return ttint_tab[0][int_j]; //On retourne le numéro du joueur
        }
    }

    /* Vérification des diagonales */
    if (ttint_tab[0][0] == ttint_tab[1][1] && ttint_tab[1][1] == ttint_tab[2][2] && ttint_tab[0][0] != -1) { //Si les 3 cases de la diagonale sont occupées par le même joueur
        return ttint_tab[0][0];
    }
    if (ttint_tab[0][2] == ttint_tab[1][1] && ttint_tab[1][1] == ttint_tab[2][0] && ttint_tab[0][2] != -1) { //Si les 3 cases de l'autre diagonale sont occupées par le même joueur
        return ttint_tab[0][2]; 
    }

    return -1; //Si aucun joueur n'a gagné, on retourne -1
}

/* Procédure de tour de jeu */
void tourDeJeu(int ttint_tab[TAILLE][TAILLE]) {
    int int_joueur; //Variable qui contient le numéro du joueur
    int int_x;      //Coordonnées de la case
    int int_y;      //Coordonnées de la case
    int int_gagne;  //Variable qui contient le numéro du joueur qui a gagné
    int int_retour; //Variable qui contient le retour de la fonction scanf

    int_joueur = 0; //On initialise le joueur à 0
    int_gagne = -1; //On initialise la variable de victoire à -1

    init(ttint_tab); //On initialise le plateau

    while (int_gagne == -1) { //Tant qu'aucun joueur n'a gagné
        afficher(ttint_tab);  //On affiche le plateau
        printf("Joueur %d, entrez les coordonnées de votre coup (x espace y) : ", int_joueur); //On demande au joueur de jouer
        int_retour = scanf("%d %d", &int_x, &int_y);               //On récupère les coordonnées du coup
        if (int_retour == 2) {                                     //Si les coordonnées sont valides (2 valeurs récupérées)
            if (jouer(ttint_tab, int_joueur, int_x, int_y) == 1) { //Si le coup est valide
                int_gagne = aGagne(ttint_tab);                     //On vérifie si le joueur a gagné
                int_joueur = (int_joueur + 1) % 2;                 //On passe au joueur suivant
            } 
            /* Cas ou le plateau est rempli */
            
            else {
                printf("Coup invalide !\n");                       //Sinon, on affiche un message d'erreur
            }
        } else {
            printf("Coup invalide !\n"); 
        }
    }
    afficher(ttint_tab); //On affiche le plateau
    printf("Le joueur %d a gagné !\n", int_gagne); //On affiche le joueur qui a gagné
}