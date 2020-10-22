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

void Append(struct Array* arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array* arr, int index, int x)
{
    int i;

    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
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

    Append(&arr, 8);
    Insert(&arr, 2, 10);
    Display(arr);

    free(arr.A);
}
