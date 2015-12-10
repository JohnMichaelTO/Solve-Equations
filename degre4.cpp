#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

/* [DEBUT] RESOLUTION EQUATION DEGRE 4 */
void degre4(double a, double b, double c, double d, double e, char variable = 'x', char variable2 = 'z', char variable3 = 'y', double x0 = NULL)
{
    // Division par a de tous les coefficients
    if(a != 1.0)
    {
        b /= a;
        c /= a;
        d /= a;
        e /= a;
        a /= a;

        printf("a != 1.0 donc, on divise par a tous les coefficients :\r\n\n");
        printf("a = %lf\r\n", a);
        printf("b = %lf\r\n", b);
        printf("c = %lf\r\n", c);
        printf("d = %lf\r\n", d);
        printf("e = %lf\r\n\n", e);
    }

    double p, q, r, y, pose = 0.0;

    // Calcul des coefficients p, q et r
    if(b == 0.0)
    {
        // Si b = 0, on a p = c/a, q = d/a, r = e/a, or a = 1, donc on a :
        p = c;
        q = d;
        r = e;
    }
    else
    {
        p = (-3.0 * b * b) / (8.0 * a * a) + (c / a);
        q = pow((b / 2.0), 3.0) / pow(a, 3.0) - ((1.0 / 2.0) * b * c) / (a * a) + (d / a);
        r = -3.0 * pow(((b / 4.0) / a), 4.0) + c * (pow((b / 4.0), 2.0) / pow(a, 3.0)) - ((1.0 / 4.0) * b * d) / (a * a) + (e / a);

        // On pose x = z + (-b/4a)
        pose = - b / 4 * a;
    }

    if(pose != 0.0)
    {
        if(pose < 0.0)
        {
            printf("Posons %c = %c - b/4a = %c%lf\r\n", variable, variable2, variable2, pose);
        }
        else
        {
            printf("Posons %c = %c - b/4a = %c+%lf\r\n", variable, variable2, variable2, pose);
        }
    }

    double polynome[6] = {r, q, p, 0.0, 1.0};
    printf("Nous avons donc une equation de la forme : ");
    afficheEquationForme(variable2, 4, 'o', 0, 1, 0);
    printf("\r\nAvec les coefficients :\r\n\n");

    printf("p = -3b^2 / 8a^2 + c / a\r\n");
    printf("q = (b / 2)^3 / a^3 - ((1 / 2) * b * c) / a^2 + d / a\r\n");
    printf("r = -3((b / 4.0) / a)^4 + c * ((b / 4.0)^2 / a^3) - ((1 / 4) * b * d) / a^2 + e / a\r\n");

    printf("\nSoit :\r\n");
    printf("p = %lf\r\nq = %lf\r\nr = %lf\r\n", p, q, r);

    printf("On a alors l'equation suivante :\r\n");
    afficheEquation(variable2, polynome, 4, 1);

    printf("On a donc l'equation : (%c^2 + %c)^2 = (2%c - p)%c^2 -q%c + %c^2 - r\r\n", variable2, variable3, variable3, variable2, variable2, variable3);


    /*************************** Cas où q = 0 : équation bicarrée ***************************/
    /* Pour optimiser le programme, on pourrait faire un cas qui gère une équation bicarrée */
    /*************************** Cas où q = 0 : équation bicarrée ***************************/

    y = degre3(8.0, (-4.0 * p), (-8.0 * r), (4.0 * p * r - q * q), variable3, 't', 1);

    double A, B, C;
    A = 1.0;
    B = sqrt(2 * y - p);
    C = (q / (2 * sqrt(2 * y - p)));

    printf("\r\nOn a donc deux equations du second degre :\r\n\n");

    int numRacine = 1;

    if(x0 != NULL)
    {
        numRacine = 2;
    }

    printf("\r\n%c^2 + B%c + C = 0\r\n\n", variable2, variable2);
    printf("Avec B = %lf et C = %lf\r\n", B, y - C);
    degre2(A, B, y - C, 0.0, variable2, numRacine);

    printf("\r\net\r\n\n%c^2 + B'%c + C' = 0\r\n\n", variable2, variable2);
    printf("Avec B' = %lf et C' = %lf\r\n", -B, y + C);
    degre2(A, -B, y + C, 0.0, variable2, numRacine + 2);

    printf("\r\n\nOn a alors les racines :\r\n\n");

    if(x0 != NULL)
    {
        printf("%c1 = %lf\r\n", variable, x0);
    }
    degre2(A, B, y - C, pose, variable, numRacine);
    degre2(A, -B, y + C, pose, variable, numRacine + 2);
}
/* [FIN] RESOLUTION EQUATION DEGRE 4 */
