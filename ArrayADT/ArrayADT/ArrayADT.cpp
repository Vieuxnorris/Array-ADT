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
int Delete(struct Array* arr, int index);
void Reverse(struct Array* arr);
void ReverseOpti(struct Array* arr);
int LinearSearch(struct Array* arr, int key);
int BinarySearch(struct Array arr, int key);
int RBinarySearch(struct Array arr,int l, int h, int key);
void InsertSort(struct Array* arr, int x);
int IsSorted(struct Array arr);
void Rearrange(struct Array* arr);
struct Array* Merge(struct Array* arr1, struct Array* arr2);
struct Array* Union(struct Array* arr1, struct Array* arr2);
struct Array* Intersection(struct Array* arr1, struct Array* arr2);
struct Array* Difference(struct Array* arr1, struct Array* arr2);
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
    int ch;
    int x, index;

    printf("Enter Size of Array");
    scanf_s("%d", &arr.size);
    arr.A = (int*)malloc(arr.size * sizeof(int));
    do {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter you choice ");
        scanf_s("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index ");
            scanf_s("%d%d", &x, &index);
            Insert(&arr, index, x);
            break;
        case 2:
            printf("Enter index ");
            scanf_s("%d", &x);
            x = Delete(&arr, index);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search ");
            scanf_s("%d", &x);
            index = LinearSearch(&arr, x);
            printf("Element index %d", index);
            break;
        case 4:
            printf("Sum is %d\n", Sum(arr));
            break;
        case 5:
            Display(arr);
            break;
        }
    } while (ch < 6);

    free(arr.A);
    return 0;
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

int Delete(struct Array* arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];
        arr->length--;
    }
    return x;
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

void InsertSort(Array* arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i>=0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int IsSorted(Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void Rearrange(Array* arr)
{
    int i, j;
    i = 0;
    j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            Swap(&arr->A[i], &arr->A[j]);
    }
}

Array* Merge(Array* arr1, Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size; //possible modification futur
    return arr3;
}

Array* Union(Array* arr1, Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    return arr3;
}

Array* Intersection(Array* arr1, Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = arr1->size; // a changé dans le futur
    return arr3;
}

Array* Difference(Array* arr1, Array* arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    
    arr3->length = k;
    arr3->size = arr1->size; // a changé dans le futur
    return arr3;
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
