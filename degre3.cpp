#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

/* [DEBUT] RESOLUTION EQUATION DEGRE 3 */
double degre3(double a, double b, double c, double d, char variable = 'x', char variable2 = 'z', int ferrari = 0)
{
    // Division par a de tous les coefficients
    b /= a;
    c /= a;
    d /= a;
    a /= a;

    // Définition des variables locales
    double p, q, p2, q2, pose, delta;
    double equation[6] = {0.0};
    double polynome[6] = {d, c, b, a};
    int cpt;

    // Définition des variables servants aux racines u et v
    double u = 0, v = 0, u1 = 0, v1 = 0;
    double u2r = 0, u2i = 0, u3r = 0, u3i = 0, v2r = 0, v2i = 0, v3r = 0, v3i = 0;

    // Définition des variables servants aux variables temporaires (changement de variables)
    double t1 = 0, t2 = 0, t2r = 0, t2i = 0, t3r = 0, t3i = 0, z2r = 0, z3r = 0;

    // Définition des variables stockant le résultat, et le calcul des racines complexes
    double z[5], r, A;

    // Définition de j et j^2 avec les parties réelles et imaginaires
    double jr = -0.5;
    double ji = sqrt(3.0) / 2.0;
    double jr2 = jr;
    double ji2 = -ji;

    if(ferrari == 1)
    {
        printf("\r\nEn calculant le discriminant tel que delta = 0\r\nOn a donc l'equation suivante :\r\n\n");
        afficheEquation(variable, polynome, 3, 1);
    }

    if(b == 0.0)
    {
        pose = 0.0;
        p = c / a;
        q = d / a;
        variable2 = variable;
    }
    else
    {
        pose = - b / (3.0 * a);
        p = (-(b * b)/(3.0 * a * a))+(c / a);
        q = (b / (27.0 * a)) * (((2.0 * b * b) / (a * a)) - ((9.0 * c) / a)) + (d / a);
    }

    if(b != 0.0)
    {
        if(pose < 0.0)
        {
            printf("Posons %c = %c - (b / 3a) = %c%lf\r\n\n", variable, variable2, variable2, pose);
        }
        else if(pose > 0.0)
        {
            printf("Posons %c = %c - (b / 3a) = %c+%lf\r\n\n", variable, variable2, variable2, pose);
        }
    }

    if(p == 0 && q == 0)
    {
        z[0] = pose;
        printf("%c = %lf\r\n", variable, z[0]);
    }
    else if(q == 0)
    {
        z[0] = pose;
        printf("Nous avons une equation de la forme : ");
        printf("%c^3 + p%c = 0\r\n", variable2, variable2);
        printf("%c(%c^2 + p) = 0\r\n", variable2, variable2);

        if(-p < 0.0)
        {
            z[1] = -sqrt(p) + pose;
            z[2] = sqrt(p) + pose;
            printf("%c1 = 0\r\n ou\r\n%c2 = -racine(p)i\r\n ou \r\n%c3 = racine(p)i\r\n\n", variable2, variable2, variable2);
            printf("Soit :\r\n%c1 = %lf\r\n%c2 = %lfi\r\n%c3 = %lfi\r\n", variable, z[0], variable, z[1], variable, z[2]);
        }
        else
        {
            z[1] = -sqrt(-p) + pose;
            z[2] = sqrt(-p) + pose;
            printf("%c1 = 0\r\n ou\r\n%c2 = -racine(-p)\r\n ou \r\n%c3 = racine(-p)\r\n\n", variable2, variable2, variable2);
            printf("Soit :\r\n%c1 = %lf\r\n%c2 = %lf\r\n%c3 = %lf\r\n", variable, z[0], variable, z[1], variable, z[2]);
        }
    }
    else if(p == 0)
    {
        printf("Nous avons une equation de la forme : ");
        printf("%c^3 + q = 0\r\n", variable2);
        printf("%c^3 = -q = %lf\r\n", variable2, -q);

        if(-q < 0.0)
        {
            z[0] = pow(q, (1.0 / 3.0));
        }
        else
        {
            z[0] = pow(-q, (1.0 / 3.0));
        }

        printf("\nOn a alors :\r\n\n");
        printf("%c1 = %lf\r\n", variable2, z[0]);
        printf("%c2 = ", variable2);
        afficheComplexe(z[0] * jr, z[0] * ji);
        printf("%c3 = ", variable2);
        afficheComplexe(z[0] * jr2, z[0] * ji2);

        z[0] = z[0] + pose;
        printf("\nSoit :\r\n\n");
        printf("%c1 = %lf\r\n", variable, z[0]);
        printf("%c2 = ", variable);
        afficheComplexe(z[0] * jr, z[0] * ji);
        printf("%c3 = ", variable);
        afficheComplexe(z[0] * jr2, z[0] * ji2);
    }
    else
    {
        printf("Nous obtenons une equation de la forme : ");
        afficheEquationForme(variable2, 3, 'o', ferrari, 0, 1);

        if(ferrari == 1)
        {
            printf("Avec :\np' = -(b^2/3a^2) + (c/a)\nq' = (b/27a) * ((2b^2/a^2) - (9c/a)) + (d/a)\n\np' = %lf\nq' = %lf\n\n", p, q);
        }
        else
        {
            printf("Avec :\np = -(b^2/3a^2) + (c/a)\nq = (b/27a) * ((2b^2/a^2) - (9c/a)) + (d/a)\n\np = %lf\nq = %lf\n\n", p, q);
        }

        equation[0] = q;
        equation[1] = p;
        equation[3] = 1.0;

        printf("Soit : ");
        afficheEquation(variable2, equation, 3, 1);

        p2 = -q;
        q2 = -(p * p * p) / 27.0;

        printf("Posons %c = u + v\r\n\n", variable2);
        if(ferrari == 1)
        {
            printf("Soit (u + v)^3 + p'(u + v) + q' = 0\r\n");
            printf("u^3 + 3u^2v + 3uv^2 + v^3 + p'u + p'v + q' = 0\r\n");
            printf("u^3 + v^3 + (u + v)(3uv + p') + q' = 0\r\n\n");

            printf("Posons 3uv + p' = 0\r\n+-\r\n");
            printf("|u^3 + v^3 + q' = 0\r\n");
            printf("|3uv + p' = 0\r\n+-\r\n\n+-\r\n");

            printf("|u^3 + v^3 = -q' = %lf\r\n", p2);
            printf("|u^3v^3 = -p'^3/27 = %lf\r\n+-\r\n", q2);

            printf("\nOn a u^3 et v^3 racines de l'equation : X^2 + q'X - (p'^3/27) = 0\r\n\nSoit : X^2");
        }
        else
        {
            printf("Soit (u + v)^3 + p(u + v) + q = 0\r\n");
            printf("u^3 + 3u^2v + 3uv^2 + v^3 + pu + pv + q = 0\r\n");
            printf("u^3 + v^3 + (u + v)(3uv + p) + q = 0\r\n\n");

            printf("Posons 3uv + p = 0\r\n+-\r\n");
            printf("|u^3 + v^3 + q = 0\r\n");
            printf("|3uv + p = 0\r\n+-\r\n\n+-\r\n");

            printf("|u^3 + v^3 = -q = %lf\r\n", p2);
            printf("|u^3v^3 = -p^3/27 = %lf\r\n+-\r\n", q2);

            printf("\nOn a donc l'equation suivante : X^2 + qX - (p^3/27) = 0\r\n\nSoit : X^2");
        }

        p2 = -p2;
        if(p2 > 0.0)
        {
            printf("+%lfX", p2);
        }
        else if(p2 < 0.0)
        {
            printf("%lfX", p2);
        }

        if(q2 > 0.0)
        {
            printf("+%lf = 0\r\n\n", q2);
        }
        else if(q2 < 0.0)
        {
            printf("%lf = 0\r\n\n", q2);
        }
        else
        {
            printf(" = 0\r\n\n");
        }

        delta = calcul_delta(1.0, p2, q2);

        printf("Calculons le discriminant : \r\n");

        if(ferrari == 1)
        {
            printf("delta = (-q')^2 + 4p'^3/27 = %lf\r\n\n", delta);
        }
        else
        {
            printf("delta = (-q)^2 + 4p^3/27 = %lf\r\n\n", delta);
        }

        if(delta > 0.0)
        {
            printf("On obtient alors les racines :\r\n");
            u = racine_reelle(1.0, p2, delta, 1);
            v = racine_reelle(1.0, p2, delta, 2);

            if(ferrari == 1)
            {
                printf("u^3 = (-q' + racine(delta)) / 2 = %lf\r\n", u);
                printf("v^3 = (-q' - racine(delta)) / 2 = %lf\r\n", v);
            }
            else
            {
                printf("u^3 = (-q + racine(delta)) / 2 = %lf\r\n", u);
                printf("v^3 = (-q - racine(delta)) / 2 = %lf\r\n", v);
            }
        }

        if(delta > 0.0)
        {
            if(u < 0.0)
            {
                u1 = -pow(-u, (1.0 / 3.0));
            }
            else
            {
                u1 = pow(u, (1.0 / 3.0));
            }

            if(v < 0.0)
            {
                v1 = -pow(-v, (1.0 / 3.0));
            }
            else
            {
                v1 = pow(v, (1.0 / 3.0));
            }

            u2r = u1 * jr;
            u2i = u1 * ji;

            u3r = u1 * jr2;
            u3i = u1 * ji2;

            v2r = v1 * jr2;
            v2i = v1 * ji2;

            v3r = v1 * jr;
            v3i = v1 * ji;

            t1 = u1 + v1;
            t2r = u2r + v2r;
            t2i = u2i + v2i;
            t3r = u3r + v3r;
            t3i = u3i + v3i;
        }

        if(delta > 0.0)
        {
            printf("\nOn a alors :\r\n\n");
            if(ferrari == 1)
            {
                printf("u1 = ((-q' + racine(delta)) / 2)^(1/3) = %lf\r\n", u1);
                printf("v1 = ((-q' - racine(delta)) / 2)^(1/3) = %lf\r\n\n", v1);

                printf("u2 = j((-q' + racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(u2r, u2i);
                printf("v2 = j^2((-q' - racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(v2r, v2i);

                printf("\nu3 = j^2((-q' + racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(u3r, u3i);
                printf("v3 = j((-q' - racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(v3r, v3i);
            }
            else
            {
                printf("u1 = ((-q+ racine(delta)) / 2)^(1/3) = %lf\r\n", u1);
                printf("v1 = ((-q - racine(delta)) / 2)^(1/3) = %lf\r\n\n", v1);

                printf("u2 = j((-q + racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(u2r, u2i);
                printf("v2 = j^2((-q - racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(v2r, v2i);

                printf("\nu3 = j^2((-q + racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(u3r, u3i);
                printf("v3 = j((-q - racine(delta)) / 2)^(1/3) = ");
                afficheComplexe(v3r, v3i);
            }

            printf("\nOn a %c = u + v\r\n\n", variable2);
            printf("%c1 = u1 + v1 = %lf\r\n", variable2, t1);
            printf("%c2 = u2 + v2 = ", variable2);
            afficheComplexe(t2r, t2i);
            printf("%c3 = u3 + v3 = ", variable2);
            afficheComplexe(t3r, t3i);

            z[0] = t1 + pose;
            z2r = t2r + pose;
            z3r = t3r + pose;

            if(pose < 0.0)
            {
                printf("\nOn a alors %c = %c - b/3a = %c%lf, soit :\r\n\n", variable, variable2, variable2, pose);
                printf("%c1 = %c1%lf = %lf\r\n", variable, variable2, pose, z[0]);
                printf("%c2 = %c2%lf = ", variable, variable2, pose);
                afficheComplexe(z2r, t2i);
                printf("%c3 = %c3%lf = ", variable, variable2, pose);
                afficheComplexe(z3r, t3i);
            }
            else if(pose > 0.0)
            {
                printf("\nOn a alors %c = %c - b/3a = %c+%lf, soit :\r\n\n", variable, variable2, variable2, pose);
                printf("%c1 = %c1+%lf = %lf\r\n", variable, variable2, pose, z[0]);
                printf("%c2 = %c2+%lf = ", variable, variable2, pose);
                afficheComplexe(z2r, t2i);
                printf("%c3 = %c3+%lf = ", variable, variable2, pose);
                afficheComplexe(z3r, t3i);
            }
            else
            {
                printf("\nOn a alors :\r\n\n");
                printf("%c1 = %lf\r\n", variable, z[0]);
                printf("%c2 = ", variable);
                afficheComplexe(z2r, t2i);
                printf("%c3 = ", variable);
                afficheComplexe(z3r, t3i);
            }
        }
        else if(delta == 0.0)
        {
            t1 = 3.0 * q / p;
            t2 = - (3.0 * q) / (2.0 * p);

            if(pose != 0.0)
            {
                printf("On a alors :\r\n");
                if(ferrari == 1)
                {
                    printf("%c1 = 3q' / p' = %lf\r\n", variable2, t1);
                    printf("%c2 = %c3 = - 3q' / 2p' = %lf\r\n\n", variable2, variable2, t2);
                }
                else
                {
                    printf("%c1 = 3q / p = %lf\r\n", variable2, t1);
                    printf("%c2 = %c3 = - 3q / 2p = %lf\r\n\n", variable2, variable2, t2);
                }
            }

            z[0] = t1 + pose;
            z[1] = t2 + pose;

            if(pose < 0.0)
            {
                printf("\nOn a alors %c = %c - b/3a = %c%lf, soit :\r\n\n", variable, variable2, variable2, pose);
                printf("%c1 = %c1%lf = %lf\r\n", variable, variable2, pose, z[0]);
                printf("%c2 = %c3 = %c2%lf = %c3%lf = %lf", variable, variable, variable2, pose, variable2, pose, z[1]);
            }
            else if(pose > 0.0)
            {
                printf("\nOn a alors %c = %c - b/3a = %c+%lf, soit :\r\n\n", variable, variable2, variable2, pose);
                printf("%c1 = %c1+%lf = %lf\r\n", variable, variable2, pose, z[0]);
                printf("%c2 = %c3 = %c2+%lf = %c3+%lf = %lf", variable, variable, variable2, pose, variable2, pose, z[1]);
            }
            else
            {
                if(ferrari == 1)
                {
                    printf("\nOn a alors :\r\n\n");
                    printf("%c1 = 3q' / p' = %lf\r\n", variable, z[0]);
                    printf("%c2 = %c3 = - 3q' / 2p' = %lf", variable, variable, z[1]);
                }
                else
                {
                    printf("\nOn a alors :\r\n\n");
                    printf("%c1 = 3q / p = %lf\r\n", variable, z[0]);
                    printf("%c2 = %c3 = - 3q / 2p = %lf", variable, variable, z[1]);
                }
            }
        }
        else
        {
            r = sqrt(-p / 3.0);
            A = acos((-q / 2.0) * sqrt(27.0 / (-p * p * p)));

            printf("\nOn a alors :\r\n");
            for (cpt = 0 ; cpt < 3 ; cpt++)
            {
                z[cpt] = 2.0 * r * cos((1.0 / 3.0) * A + ((2 * cpt * M_PI) / 3.0)) + pose;
                if(z[cpt] == -0.0)
                {
                    z[cpt] = 0.0;
                    printf("%c%i = 0\r\n", variable, cpt);
                }
                else
                {
                    printf("%c%i = %lf\r\n", variable, cpt, z[cpt]);
                }
            }
        }
    }
    return z[0];
}
/* [FIN] RESOLUTION EQUATION DEGRE 3 */
