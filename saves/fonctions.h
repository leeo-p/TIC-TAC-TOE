#ifndef _FONCTIONS_H_
#define _FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 3

/*Procédure d'initialisation du plateau*/
void init(int ttint_tab[TAILLE][TAILLE]);

/*Procédure d'affichage du plateau*/
void afficher(int ttint_tab[TAILLE][TAILLE]);

/*Fonction de jeu*/
int jouer(int ttint_tab[TAILLE][TAILLE], int int_joueur, int int_x, int int_y);

/*Procédure de vérification de la victoire*/
int aGagne(int ttint_tab[TAILLE][TAILLE]);

/*Procédure de tour de jeu*/
void tourDeJeu(int ttint_tab[TAILLE][TAILLE]);


#endif