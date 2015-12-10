#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

using namespace std;

int main()
{
    // DEFINITION DES VARIABLES
    double equation[6];
    int degree;
    int saisie;
    int n;
    char modele_coef;
    int c;
    int erreur;
    int continuer;
    int equation_groupe;

    do
    {
        continuer = 0;
        modele_coef = 'a';
        erreur = 0;
        equation_groupe = 0;

        /* [DEBUT] SAISIE DE L'EQUATION */

        // Saisie du degré de l'équation à résoudre
        do
        {
            degree = 0;
            printf("Vous souhaitez resoudre une equation de quel degre ? (entre 1 et 5)\r\n");
            saisie = scanf("%i", &degree);
            if(saisie != 1)
            {
                while((c = getchar()) != '\n' && c != EOF);
            }
        } while(degree < 0 || degree > 5);

        if(degree == 0)
        {
            degree = 5;
            equation_groupe = 1;
            printf("Nous resolvons l'equation du groupe de degre 5 :\r\n\n");
        }
        else
        {
            // Affichage
            printf("Le degree saisi est %i\r\n", degree);
        }

        // Affichage
        printf("\nL'equation est de la forme : ");
        afficheEquationForme('x', degree, modele_coef, 0, 0, 0);

        if(equation_groupe == 1)
        {
            equation[5] = 1.0;
            equation[4] = 21.0;
            equation[3] = -2.0;
            equation[2] = 23.0;
            equation[1] = -21.0;
            equation[0] = 1.0 / 3.0;

            printf("Nous avons les coefficients suivants :\r\n\n");
            printf("a = %lf\r\n", equation[5]);
            printf("b = %lf\r\n", equation[4]);
            printf("c = %lf\r\n", equation[3]);
            printf("d = %lf\r\n", equation[2]);
            printf("e = %lf\r\n", equation[1]);
            printf("f = %lf\r\n\n", equation[0]);

            printf("L'equation est la suivante :\r\n");
        }
        else
        {
            printf("\r\nRappel : les coefficients doivent s'exprimer sous forme decimale.\r\n\n");
            // Saisie des coefficients
            for(n = degree; n >= 0; n--)
            {
                do
                {
                    erreur = 0;
                    if(modele_coef == 'a')
                    {
                        printf("\rSaisissez le coefficient %c != 0 : %c = ", modele_coef, modele_coef);
                    }
                    else if(equation[n] != NULL)
                    {
                        printf("\rSaisissez le coefficient %c : %c = ", modele_coef, modele_coef);
                    }

                    saisie = scanf("%lf", &equation[n]);
                    if(saisie != 1)
                    {
                        erreur = 1;
                        while((c = getchar()) != '\n' && c != EOF);
                    }

                    if(modele_coef == 'a' && equation[n] == 0)
                    {
                        erreur = 1;
                    }
                } while(erreur == 1);
                // printf("%c = %lf\r\n", modele_coef, equation[n]);

                modele_coef = modele_coef + 1;
            }

            // Affichage
            printf("\nL'equation saisie est :\r\n");
        }
        afficheEquation('x', equation, degree, 1);

        /* [FIN] SAISIE DE L'EQUATION */

        if(degree == 1)
        {
            printf("x = %lf", degre1(equation[1], equation[0]));
        }
        else if(degree == 2)
        {
            degre2(equation[2], equation[1], equation[0], 0.0, 'x', 1);
        }
        else if(degree == 3)
        {
            degre3(equation[3], equation[2], equation[1], equation[0], 'x', 'z', 0);
        }
        else if(degree == 4)
        {
            degre4(equation[4], equation[3], equation[2], equation[1], equation[0], 'x', 'z', 'y', NULL);
        }
        else if(degree == 5)
        {
            degree5(equation[5], equation[4], equation[3], equation[2], equation[1], equation[0], 'x');
        }

        printf("\r\n\nVoulez-vous saisir une nouvelle equation ? (o/n) : ");
        char reponse = 'n';
        cin >> reponse;
        if(reponse == 'o')
        {
            continuer = 1;
            printf("\r\n\n");
        }
    } while(continuer == 1);
    return 0;
}
