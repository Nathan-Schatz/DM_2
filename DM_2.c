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

int main(void)
{
    int tableau[] = {1, 2, 2, 3, 3, 3};
    int taille = sizeof(tableau) / sizeof(tableau[0]);
    int result = nbnbnb(tableau, taille);
    printf("Le nombre d'entiers strictement positifs égaux à leur nombre d'occurrences dans le tableau est : %d\n", result);
    return 0;
}

// Exercice 22

int nbsomindnb()
{
}

int main22(void)
{

    return 0;
}

// Exercice 23

int prodind()
{
}

int main23(void)
{

    return 0;
}

// Exercice 24

int cycle()
{
}

int main24(void)
{

    return 0;
}

// Exercice 25

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
