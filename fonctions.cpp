#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* [DEBUT] AFFICHAGE DE L'EQUATION */
void afficheEquation(char variable, double equation[6], int degree, int afficheZero = 1)
{
    int n;
    for(n = degree; n > 0; n--)
    {
        if(equation[n] != 0.0)
        {
            if(equation[n] == 1.0)
            {
                printf("%c", variable);
            }
            else if(equation[n] == -1.0)
            {
                printf("-%c", variable);
            }
            else
            {
                printf("%lf%c", equation[n], variable);
            }

            if(n > 1)
            {
                printf("^%i", n);
            }
        }

        if(equation[n - 1] > 0)
        {
            printf("+");
        }
    }

    if(equation[0] == 1.0)
    {
        printf("1");
    }
    else if(equation[0] == -1.0)
    {
        printf("-1");
    }
    else if(equation[0] != 0.0)
    {
        printf("%lf", equation[0]);
    }

    if(afficheZero == 1)
    {
        printf(" = 0\r\n\n");
    }

    return;
}
/* [FIN] AFFICHAGE DE L'EQUATION */

/* [DEBUT] AFFICHAGE DE LA FORME DE L'EQUATION */
void afficheEquationForme(char variable, int degree, char modele_coef, int depuis_ferrari = 0, int ferrari = 0, int cardan = 0)
{
    int n;

    if(depuis_ferrari == 1)
    {
        for(n = degree; n > 0; n--)
        {
            if(n == 1)
            {
                printf("%c'%c+%c' = 0\r\n\n", modele_coef, variable, modele_coef + 1);
            }
            else if((ferrari == 1 && n == 3) || (cardan == 1 && n == 2))
            {
                // On n'affiche pas z^3 pour la forme réduite de ferrari
                // Décrémentation à cause de l'incrémentation juste après
                modele_coef = modele_coef - 1;
            }
            else
            {
                if(modele_coef == 'o')
                {
                    printf("%c^%i+", variable, n);
                }
                else
                {
                    printf("%c'%c^%i+", modele_coef, variable, n);
                }
            }

            modele_coef = modele_coef + 1;
        }
    }
    else
    {
        for(n = degree; n > 0; n--)
        {
            if(n == 1)
            {
                printf("%c%c+%c = 0\r\n\n", modele_coef, variable, modele_coef + 1);
            }
            else
            {
                if(modele_coef == 'o')
                {
                    printf("%c^%i+", variable, n);
                }
                else if((ferrari == 1 && n == 3) || (cardan == 1 && n == 2))
                {
                    // On n'affiche pas z^3 pour la forme réduite de ferrari
                    // Décrémentation à cause de l'incrémentation juste après
                    modele_coef = modele_coef - 1;
                }
                else
                {
                    printf("%c%c^%i+", modele_coef, variable, n);
                }
            }

            modele_coef = modele_coef + 1;
        }
    }
}
/* [FIN] AFFICHAGE DE LA FORME DE L'EQUATION */

/* [DEBUT] AFFICHAGE DES NOMBRES COMPLEXES */
void afficheComplexe(double re, double im)
{
    if(re != 0.0)
    {
        printf("%lf", re);
        if(im > 0.0)
        {
            printf("+%lfi\r\n", im);
        }
        else if(im < 0.0)
        {
            printf("%lfi\r\n", im);
        }
    }
    else
    {
        if(im == 0.0)
        {
            printf("0\r\n");
        }
        else
        {
            printf("%lfi\r\n", im);
        }
    }
    return;
}
/* [FIN] AFFICHAGE DES NOMBRES COMPLEXES */

/* [DEBUT] RESOLUTION EQUATION DEGRE 1 */
double degre1(double a, double b)
{
    double x;
    x = -b / a;
    return x;
}
/* [FIN] RESOLUTION EQUATION DEGRE 1 */
