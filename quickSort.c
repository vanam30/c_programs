#include <stdio.h>

int read(int *A, int size)
{
    int l = 0;
    while (l < size)
    {
        scanf("%d", &A[l]);
        l++;
    }
}

// Function to swap position of elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the Array on the basis of pivot element
int partition(int A[], int lb, int ub)
{
    int pivot = A[lb]; // Select the pivot element
    int start = lb, end = ub;
    while (start < end)
    {
        while (A[start] <= pivot)
            start++;
        while (A[end] > pivot)
            end--;
        if (start < end)
            swap(&A[start], &A[end]);
    }
    swap(&A[lb], &A[end]);
    return end;
}

void quickSort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(A, lb, ub); // Select pivot position and put all the elements smaller than pivot on left and greater than pivot on right
        quickSort(A, lb, loc - 1); // Sort the elements on the left of pivot
        quickSort(A, loc + 1, ub); // Sort the elements on the right of pivot
    }
}
// Function to print elements of an A
void printArray(int A[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int A[n];
    read(A, n);
    printArray(A, n);
    quickSort(A, 0, n-1);
    printf("\nArray after quick sort : ");
    printArray(A, n);
    return 0;
}
