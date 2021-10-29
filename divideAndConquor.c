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

void Merge(int A[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = 0, B[ub - lb + 1], m;
    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= ub)
    {
        B[k++] = A[j++];
    }
    m = 0;
    for (i = lb; i <= ub; i++)
        A[i] = B[m++];
}

void MergeSort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        MergeSort(A, lb, mid);
        MergeSort(A, mid + 1, ub);
        Merge(A, lb, mid, ub);
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

// Driver code
int main()
{
    printf("\nPress 1 to sort array using QuickSort Technique.");
    printf("\nPress 2 to sort array using MergeSort Technique.");
    printf("\nPress 0 to exit.\n");
    while (1)
    {
        int ch, n;
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
        {
            exit(ch);
        }
        case 1:
        {
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            int A[n];
            printf("-- Enter %d values: ", n);
            read(A, n);
            quickSort(A, 0, n - 1);
            printf("\nSorted Array after applying quick sort: ");
            printArray(A, n);
            break;
        }
        case 2:
        {
            printf("Enter the size of the array : ");
            scanf("%d", &n);
            int A[n];
            printf("-- Enter %d values: ", n);
            read(A, n);
            MergeSort(A, 0, n - 1);
            printf("\nSorted Array after applying Merge sort: ");
            printArray(A, n);
            break;
        }
        default:
        {
            printf("\nPress 1 or 2, or 0 to exit.");
            break;
        }
        }
    }
}
