// Array ADT Display.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int* A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int main()
{
    struct Array arr;
    int n;
    arr.length = 0;
    printf("entrer la taille de votre tableau : ");
    scanf_s("%d", &arr.size);

    arr.A = (int*)malloc(arr.size * sizeof(int));
    if (arr.A == NULL)
        return 0;

    printf("combien de nombre voulais vous mettre : ");
    scanf_s("%d", &n);

    printf("entrer vos nombre : ");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &arr.A[i]);
    arr.length = n;
    Display(arr);
    free(arr.A);
}
