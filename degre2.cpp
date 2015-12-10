#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

/* [DEBUT] RESOLUTION EQUATION DEGRE 2 */
double calcul_delta(double a, double b, double c)
{
    return (b * b) - (4.0 * a * c);
}

double racine_reelle(double a, double b, double delta, int numero_racine)
{
    double x;

    if(numero_racine == 1)
    {
        x = (-b - sqrt(delta)) / (2.0 * a);
    }
    else
    {
        x = (-b + sqrt(delta)) / (2.0 * a);
    }
    return x;
}

double racine_complexe(double a, double b, double delta, char partie)
{
    double z;

    if(partie == 'r')
    {
        z = (-b) / (2.0 * a);
    }
    else
    {
        z = (sqrt(-delta)) / (2.0 * a);
    }
    return z;
}

void degre2(double a, double b, double c, double changementVariable = 0.0, char variable = 'x', int numero_racine = 1)
{
    double x1, x2, delta;

    if(b == 0.0)
    {
        if((-c / a) >= 0.0)
        {
            x1 = sqrt(-c / a) + changementVariable;
            x2 = -sqrt(-c / a) + changementVariable;

            printf("%c%i = %lf\r\n", variable, numero_racine, x1);
            printf("%c%i = %lf\r\n", variable, numero_racine + 1, x2);
        }
        else
        {
            x1 = -sqrt(c / a) + changementVariable;
            x2 = sqrt(c / a) + changementVariable;

            printf("%c%i = %lfi\r\n", variable, numero_racine, x1);
            printf("%c%i = %lfi\r\n", variable, numero_racine + 1, x2);
        }
    }
    else if(c == 0.0)
    {
        x1 = degre1(a, b) + changementVariable;
        x2 = 0.0 + changementVariable;

        printf("%c%i = %lf\r\n", variable, numero_racine, x1);
        printf("%c%i = %lf\r\n", variable, numero_racine + 1, x2);
    }
    else
    {
        delta = calcul_delta(a, b, c);

        if(delta > 0.0)
        {
            x1 = racine_reelle(a, b, delta, 1) + changementVariable;
            x2 = racine_reelle(a, b, delta, 2) + changementVariable;

            printf("%c%i = %lf\r\n", variable, numero_racine, x1);
            printf("%c%i = %lf\r\n", variable, numero_racine + 1, x2);
        }
        else if(delta == 0.0)
        {
            x1 = (-b) / (2.0 * a) + changementVariable;
            x2 = x1;
            printf("%c%i = %c%i = %lf\r\n", variable, numero_racine, variable, numero_racine + 1, x1);
        }
        else
        {
            x1 = racine_complexe(a, b, delta, 'r') + changementVariable;
            x2 = racine_complexe(a, b, delta, 'i');

            printf("%c%i = ", variable, numero_racine);
            afficheComplexe(x1, -x2);
            printf("%c%i = ", variable, numero_racine + 1);
            afficheComplexe(x1, x2);
        }
    }
    return;
}
/* [FIN] RESOLUTION EQUATION DEGRE 2 */
