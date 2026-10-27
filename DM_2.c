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

char *cycle(const char *s, int decalage)
{
    int n = strlen(s);
    char *res = malloc((n + 1) * sizeof(char));
    if (res == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = s[(i + decalage) % n];
    }
    res[n] = '\0';
    return res;
}

int main24(void)
{
    char *tests[] = {"abcdef", "abcdef", "abcdef", "x"};
    int decalages[] = {0, 3, 5, 0};
    for (int k = 0; k < 4; k++)
    {
        char *r = cycle(tests[k], decalages[k]);
        printf("cycle(\"%s\", %d) = \"%s\"\n", tests[k], decalages[k], r);
        free(r);
    }
    return 0;
}

// Exercice 25

// Écrire une fonction cycles prenant en argument une chaîne de caractères non vide (inutile
// de le vérifier) et renvoyant le tableau des chaînes obtenues par tous les décalages possibles (leur nombre est
// la taille de la chaîne).

char **cycles(const char *s)
{
    int n = strlen(s);
    char **res = malloc(n * sizeof(char *));
    if (res == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        res[i] = cycle(s, i);
        if (res[i] == NULL)
        {
            // Libérer la mémoire allouée jusqu'à présent
            for (int j = 0; j < i; j++)
            {
                free(res[j]);
            }
            free(res);
            return NULL;
        }
    }
    return res;
}

int main25(void)
{
    char *tests[] = {"abcdef", "x"};
    for (int k = 0; k < 2; k++)
    {
        char **r = cycles(tests[k]);
        int n = strlen(tests[k]);
        printf("cycles(\"%s\") = [", tests[k]);
        for (int i = 0; i < n; i++)
        {
            printf("\"%s\"", r[i]);
            if (i < n - 1)
            {
                printf(", ");
            }
            free(r[i]);
        }
        free(r);
        printf("]\n");
    }

    return 0;
}

// Exercice 26

// Écrire une fonction cyclemin prenant en argument une chaîne de caractères et renvoyant la
// plus petite (dans l’ordre lexicographique) des chaînes obtenues par décalage de la chaîne en argument

char *cyclemin(const char *s)
{
    int n = strlen(s);
    char *min = malloc((n + 1) * sizeof(char));
    if (min == NULL)
    {
        return NULL;
    }
    strcpy(min, s);
    for (int i = 0; i < n; i++)
    {
        char *c = cycle(s, i);
        if (strcmp(c, min) < 0)
        {
            strcpy(min, c);
        }
        free(c);
    }
    return min;
}

int main26(void)
{
    char *tests[] = {"abcdef", "x", "cba", "bca"};
    for (int k = 0; k < 4; k++)
    {
        char *r = cyclemin(tests[k]);
        printf("cyclemin(\"%s\") = \"%s\"\n", tests[k], r);
        free(r);
    }

    return 0;
}

// Exercice 27

// Écrire une fonction trichaine prenant en argument une chaîne de caractères et la mutant
// en permutant ses caractères afin qu’ils soient dans l’ordre croissant selon leur code ASCII (tous les caractères
// sont supposés être dans la table ASCII-8 bits)

int trichaine(char *s)
{
    int n = strlen(s);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] > s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    return 0;
}

int main27(void)
{
    char tests[4][10] = {"abcdef", "x", "cba", "bca"};
    for (int k = 0; k < 4; k++)
    {
        trichaine(tests[k]);
        printf("trichaine(\"%s\") = \"%s\"\n", tests[k], tests[k]);
    }
    return 0;
}

// Exercice 28

// Écrire une fonction tibere prenant en argument une chaîne de caractères en chiffres romains
// et renvoyant l’entier correspondant. On ne vérifiera pas que la chaîne correspond bien à un entier en chiffres
// romains.

int valeur_romaine(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int tibere(const char *s)
{
    int n = strlen(s);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int value = 0;
        switch (s[i])
        {
        case 'I':
            value = 1;
            break;
        case 'V':
            value = 5;
            break;
        case 'X':
            value = 10;
            break;
        case 'L':
            value = 50;
            break;
        case 'C':
            value = 100;
            break;
        case 'D':
            value = 500;
            break;
        case 'M':
            value = 1000;
            break;
        default:
            value = 0;
            break;
        }
        if (i + 1 < n && valeur_romaine(s[i + 1]) > value)
        {
            total -= value;
        }
        else
        {
            total += value;
        }
    }
    return total;
}

int main28(void)
{
    char *tests[] = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
    for (int k = 0; k < 5; k++)
    {
        int r = tibere(tests[k]);
        printf("tibere(\"%s\") = %d\n", tests[k], r);
    }

    return 0;
}

// Ecercice 29

// Écrire une fonction compresseromain prenant en argument une chaîne de caractères et ren-
// voyant la chaîne obtenue en convertissant toutes les suites de caractères correspondant à des chiffres romains
// dans la chaîne en le chiffre correspondant entouré de crochets. Quand un chiffre romain est rencontré, on
// capture le plus grand nombre de caractères consécutifs possible à partir de ce chiffre. Les autres caractères
// sont reportés tels quels. Pour simplifier, un caractère n’est interprété comme un chiffre romain que s’il est en
// capitales. Attention, la chaîne "IVI" pourra être rencontrée et il faudra renvoyer "[4][1]".

// Longueur du plus long préfixe de s qui est un chiffre romain valide
// (M*, puis centaines, dizaines, unités en notation canonique)
int longueur_romain(const char *s)
{
    int pos = 0;
    while (s[pos] == 'M')
        pos++;
    // centaines : CM | CD | D?C{0,3}
    if (s[pos] == 'C' && (s[pos + 1] == 'M' || s[pos + 1] == 'D'))
        pos += 2;
    else
    {
        if (s[pos] == 'D')
            pos++;
        for (int k = 0; k < 3 && s[pos] == 'C'; k++)
            pos++;
    }
    // dizaines : XC | XL | L?X{0,3}
    if (s[pos] == 'X' && (s[pos + 1] == 'C' || s[pos + 1] == 'L'))
        pos += 2;
    else
    {
        if (s[pos] == 'L')
            pos++;
        for (int k = 0; k < 3 && s[pos] == 'X'; k++)
            pos++;
    }
    // unités : IX | IV | V?I{0,3}
    if (s[pos] == 'I' && (s[pos + 1] == 'X' || s[pos + 1] == 'V'))
        pos += 2;
    else
    {
        if (s[pos] == 'V')
            pos++;
        for (int k = 0; k < 3 && s[pos] == 'I'; k++)
            pos++;
    }
    return pos;
}

char *compresseromain(const char *s)
{
    int n = strlen(s);
    char *res = malloc((n * 6 + 1) * sizeof(char));
    if (res == NULL)
    {
        return NULL;
    }
    res[0] = '\0';
    int i = 0;
    while (i < n)
    {
        int len = longueur_romain(s + i);
        if (len > 0)
        {
            int j = i + len;
            char *roman = strndup(s + i, len);
            int value = tibere(roman);
            free(roman);
            char buffer[20];
            sprintf(buffer, "[%d]", value);
            strcat(res, buffer);
            i = j;
        }
        else
        {
            strncat(res, s + i, 1);
            i++;
        }
    }
    return res;
}

int main29(void)
{
    char *tests[] = {"III", "IV", "IX", "LVIII", "MCMXCIV", "IVI", "M", "Salut XIV et HELLO", "XIX"};
    for (int k = 0; k < 9; k++)
    {
        char *r = compresseromain(tests[k]);
        printf("compresseromain(\"%s\") = \"%s\"\n", tests[k], r);
        free(r);
    }

    return 0;
}

// Fonction main

int main()
{
    int zero = main20();
    zero = main21();
    zero = main22();
    zero = main23();
    zero = main24();
    zero = main25();
    zero = main26();
    zero = main27();
    zero = main28();
    zero = main29();
    return zero;
}