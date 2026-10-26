#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Exerrcice 20

// Écrire une fonction nbindnb prenant en argument un tableau d’entiers et sa taille et renvoyant
// le nombre d’indices où se situent dans le tableau un nombre dont le nombre d’occurrences est égal à l’indice.

int nbindnb(int tableau[], int taille)
{
    int count = 0;
    for (int i = 0; i < taille; i++)
    {
        int occurrences = 0;
        for (int j = 0; j < taille; j++)
        {
            if (tableau[j] == i)
            {
                occurrences++;
            }
        }
        if (occurrences == i)
        {
            count++;
        }
    }
    return count;
}

int main20(void)
{

    int tableau[] = {1, 2, 3, 4, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int result = nbindnb(tableau, taille);
    printf("Le nombre d'indices où se situent dans le tableau un nombre dont le nombre d'occurrences est égal à l'indice est : %d\n", result);
    return 0;
}

// Exercice 21

// Écrire une fonction nbnbnb prenant en argument un tableau d’entiers et sa taille et renvoyant
// le nombre d’entiers strictement positifs égaux à leur nombre d’occurrences dans le tableau.

int nbnbnb(int tableau[], int taille)
{
    int count = 0;
    for (int i = 0; i < taille; i++)
    {
        int occurrences = 0;
        for (int j = 0; j < taille; j++)
        {
            if (tableau[j] == tableau[i])
            {
                occurrences++;
            }
        }
        if (tableau[i] > 0 && tableau[i] == occurrences)
        {
            count++;
        }
    }
    return count;
}

int main21(void)
{
    int tableau[] = {1, 2, 2, 3, 3, 3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int result = nbnbnb(tableau, taille);
    printf("Le nombre d'entiers strictement positifs égaux à leur nombre d'occurrences dans le tableau est : %d\n", result);
    return 0;
}

// Exercice 22

// Écrire une fonction nbsomindnb prenant en argument un tableau d’entiers et sa taille et
// renvoyant le nombre d’entiers naturels égaux à la somme des indices de leurs occurrences dans le tableau.

int nbsomindnb(int tableau[], int taille)
{
    int count = 0;
    for (int i = 0; i < taille; i++)
    {
        int somme_indices = 0;
        for (int j = 0; j < taille; j++)
        {
            if (tableau[j] == tableau[i])
            {
                somme_indices += j;
            }
        }
        if (tableau[i] >= 0 && tableau[i] == somme_indices)
        {
            count++;
        }
    }
    return count;
}

int main22(void)
{
    int tableau[] = {0, 1, 2, 3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int result = nbsomindnb(tableau, taille);
    printf("Le nombre d'entiers naturels égaux à la somme des indices de leurs occurrences dans le tableau est : %d\n", result);
    return 0;
}

// Exercice 23

// Écrire une fonction prodind prenant en argument un tableau d’entiers et sa taille ainsi qu’un
// entier et renvoyant le produit des indices où cet entier figure (inutile de gérer les dépassements).

int prodind(int tableau[], int taille, int entier)
{
    int produit = 1;
    int first = 1;
    for (int i = 0; i < taille; i++)
    {
        if (tableau[i] == entier)
        {
            if (first)
            {
                produit = i;
                first = 0;
            }
            else
            {
                produit *= i;
            }
        }
    }
    return produit;
}

int main23(void)
{
    int tableau[] = {1, 2, 2, 3, 3, 3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int result = prodind(tableau, taille, 2);
    printf("Le produit des indices où l'entier 2 figure dans le tableau est : %d\n", result);

    return 0;
}

// Exercice 24

// Écrire une fonction cycle prenant en argument une chaîne de caractères et un entier et
// renvoyant la chaîne obtenue en décalant la chaîne d’un nombre d’indices égal à l’entier en deuxième argument.
// Autrement dit, si l’entier vaut 3, les trois premiers caractères sont envoyés à la fin. On supposera (inutile de
// le vérifier) que le décalage est un nombre entre zéro inclus et la taille de la chaîne exclue.

int cycle(int tableau[], int taille, int decalage)
{
    for (int i = 0; i < decalage; i++)
    {
        int temp = tableau[0];
        for (int j = 0; j < taille - 1; j++)
        {
            tableau[j] = tableau[j + 1];
        }
        tableau[taille - 1] = temp;
    }

    return 0;
}

int main24(void)
{
    int tableau[] = {0, 1, 2, 3, 4};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int decalage = 2;
    cycle(tableau, taille, decalage);
    printf("Tableau après décalage de %d : ", decalage);
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", tableau[i]);
    }
    printf("\n");
    return 0;
}

// Exercice 25

// Écrire une fonction cycles prenant en argument une chaîne de caractères non vide (inutile
// de le vérifier) et renvoyant le tableau des chaînes obtenues par tous les décalages possibles (leur nombre est
// la taille de la chaîne).

int cycles()
{
}

int main25(void)
{

    return 0;
}

// Exercice 26

int cyclemin()
{
}

int main26(void)
{

    return 0;
}

// Exercice 27

int trichaine()
{
}

int main27(void)
{

    return 0;
}

// Exercice 28

int tibere()
{
}

int main28(void)
{

    return 0;
}

// Ecercice 29

int compresseromain()
{
}

int main29(void)
{

    return 0;
}

// Fonction main

// int main()
// {
//     int zero = main20();
//     zero = main21();
//     zero = main22();
//     zero = main23();
//     zero = main24();
//     zero = main25();
//     zero = main26();
//     zero = main27();
//     zero = main28();
//     zero = main29();
//     return zero;
// }
