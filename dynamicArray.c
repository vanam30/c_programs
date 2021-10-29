#include<stdio.h>

int main()
{
    int *a, n, i;
    printf("\nEnter the size of the array : ");
    scanf("%d", &n);
    a = (int *) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        a[i] = i * 10;
    }
    for(i = 0; i < n; i++){
        printf("\n%d", a[i]);
    }
	return 0;
}
