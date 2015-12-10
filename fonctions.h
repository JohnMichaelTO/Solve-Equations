#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* [DEBUT] AFFICHAGE DE L'EQUATION */
void afficheEquation(char, double equation[6], int, int);
/* [FIN] AFFICHAGE DE L'EQUATION */

/* [DEBUT] AFFICHAGE DE LA FORME DE L'EQUATION */
void afficheEquationForme(char, int, char, int, int, int);
/* [FIN] AFFICHAGE DE LA FORME DE L'EQUATION */

/* [DEBUT] AFFICHAGE DES NOMBRES COMPLEXES */
void afficheComplexe(double, double);
/* [FIN] AFFICHAGE DES NOMBRES COMPLEXES */

/* [DEBUT] RESOLUTION EQUATION DEGRE 1 */
double degre1(double, double);
/* [FIN] RESOLUTION EQUATION DEGRE 1 */

/* [DEBUT] RESOLUTION EQUATION DEGRE 2 */
double calcul_delta(double, double, double);

double racine_reelle(double, double, double, int);

double racine_complexe(double, double, double, char);

void degre2(double, double, double, double, char, int);
/* [FIN] RESOLUTION EQUATION DEGRE 2 */

/* [DEBUT] RESOLUTION EQUATION DEGRE 3 */
double degre3(double, double, double, double, char, char, int);
/* [FIN] RESOLUTION EQUATION DEGRE 3 */

/* [DEBUT] RESOLUTION EQUATION DEGRE 4 */
void degre4(double, double, double, double, double, char, char, char, double);
/* [FIN] RESOLUTION EQUATION DEGRE 4 */

/* [DEBUT] METHODE DE NEWTON */
double calculPoly(double, int, double);

double newton(double, int, double);
/* [FIN] METHODE DE NEWTON */

/* [DEBUT] RESOLUTION EQUATION DEGRE 5 */
void degree5(double, double, double, double, double, double, char);
/* [FIN] RESOLUTION EQUATION DEGRE 5 */
