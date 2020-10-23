#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int* A;
    int size;
    int length;
};

void Display(struct Array arr);
void Append(struct Array* arr, int x);
void Insert(struct Array* arr, int index, int x);
void Delete(struct Array* arr, int index);
void Reverse(struct Array* arr);
void ReverseOpti(struct Array* arr);
int LinearSearch(struct Array* arr, int key);
int BinarySearch(struct Array arr, int key);
int RBinarySearch(struct Array arr,int l, int h, int key);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
float Avg(struct Array arr);
void Swap(int* x, int* y);
int Get(struct Array arr,int index);
void Set(struct Array* arr, int index, int number);

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

    //Append(&arr, 8);
    //Insert(&arr, 2, 10);
    //Delete(&arr, 5);
    LinearSearch(&arr, 4);
    Display(arr);

    free(arr.A);
}


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

void Delete(struct Array* arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    }
}

void Reverse(Array* arr)
{
    int* B;

    B = (int*)malloc(arr->length * sizeof(int));
    for (int i = arr->length - 1, int j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (int i = 0; i > arr->length; i++)
        arr->A[i] = B[i];
    free(B);
}

void ReverseOpti(Array* arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
        Swap(&arr->A[i], &arr->A[j]);
}

int LinearSearch(struct Array* arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(struct Array arr, int l, int h, int key)
{
    int mid = 0;
    if (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return RBinarySearch(arr, l, mid - 1, key);
        else
            return RBinarySearch(arr, mid + 1, h, key);
    }
    return -1;
}

int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(Array arr)
{
    int total = 0;
    for (int i = 0; i < arr.length; i++)
        total += arr.A[i];
    return total;
}

float Avg(Array arr)
{
    return (float)Sum(arr) / arr.length;
}

void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(Array* arr, int index, int number)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = number;
}
