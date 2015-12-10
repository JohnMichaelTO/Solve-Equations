#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

/* [DEBUT] METHODE DE NEWTON */
double calculPoly(double polynome[6], int degree, double x)
{
    double P = 0.0, S = 0.0;
    int cpt;
    for(cpt = degree; cpt >= 0; cpt--)
    {
        S = polynome[cpt] * pow(x, cpt);
        P = P + S;
    }
    return P;
}

double newton(double polynome[6], int degree, double x0)
{
    double polynomeDeriv[6] = {0.0};
    int cpt, p;
    double xi, P = 0.0, P2 = 0.0, Pverif, Pverif2, Xi;
    xi = x0;
    int n = 0;

    p = degree - 1;
    for(cpt = p; cpt > 0; cpt--)
    {
        polynomeDeriv[cpt - 1] = polynome[cpt] * cpt;
    }

    do
    {
        n += 1;
        P = calculPoly(polynome, degree, xi);
        P2 = calculPoly(polynomeDeriv, p, xi);
        if(P < 0.0 && P2 < 0.0)
        {
            xi = xi + P / P2;
        }
        else
        {
            xi = xi - P / P2;
        }
        Pverif = P * pow(10.0, 7.0);
        Pverif2 = P * pow(10.0, 6.0);
        if(Pverif < 0.0)
        {
            Pverif = -Pverif;
        }

        if(Pverif2 < 0.0)
        {
            Pverif2 = -Pverif2;
        }

        if(xi < 0.0)
        {
            Xi = -xi;
        }
        else
        {
            Xi = xi;
        }

        if(Xi > 1000)
        {
            xi = -x0;
        }
    } while((Pverif > 1.0 && Pverif2 >= 0) && n < 10000);

    // printf("P = %lf\r\nP2 = %lf\r\nx%i = %lf\r\n\n", P, P2, n, xi);
    return xi;
}
/* [FIN] METHODE DE NEWTON */

/* [DEBUT] RESOLUTION EQUATION DEGRE 5 */
void degree5(double a, double b, double c, double d, double e, double f, char variable = 'x')
{
    // Division des coefficients par a si a != 1
    if(a != 1.0)
    {
        b /= a;
        c /= a;
        d /= a;
        e /= a;
        f /= a;
        a /= a;
    }

    double x0, equation[6] = {f, e, d, c, b, a};
    x0 = newton(equation, 5, 0.5);
    printf("Une racine a ete trouvee : x1 = %lf\r\n\n", x0);

    double polynome[5];
    /* Factorisation par la méthode de Horner */
    polynome[4] = a ;
    polynome[3] = b + polynome[4] * x0;
    polynome[2] = c + polynome[3] * x0;
    polynome[1] = d + polynome[2] * x0;
    polynome[0] = e + polynome[1] * x0;


    printf("On factorise le polynome par la racine trouvee :\r\n\n");

    if(x0 < 0.0)
    {
        printf("(x+%lf)(", -x0);
    }
    else
    {
        printf("(x-%lf)(", x0);
    }

    afficheEquation(variable, polynome, 4, 0);
    printf(") = 0\r\n\n");

    degre4(polynome[4], polynome[3], polynome[2], polynome[1], polynome[0], variable, 'z', 'y', x0);
}
/* [FIN] RESOLUTION EQUATION DEGRE 5 */
