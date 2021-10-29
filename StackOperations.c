#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int *a;
    int top;
    int size;
};
typedef struct Stack STACK;
STACK createStack(int n)
{
    STACK stk;
    stk.a = (int*) malloc(sizeof(int)*n);
    stk.top = -1;
    stk.size = n;
    return stk;
}
int isEmpty(STACK *stk)
{
    return stk->top == -1;
}
int isFull(STACK *stk)
{
    return stk->size -1 == stk->top;
}
void push(STACK *stk,int val)
{
    if(isFull(stk))
    {
        printf("\nStack Overflow!");
        return;
    }
    stk->a[++(stk->top)] = val;
}
void pop(STACK *stk)
{
    if(isEmpty(stk))
    {
        printf("\nStack Underflow!");
        return;
    }
    printf("\nPopped element : %d ",stk->a[(stk->top)--]);
}
void display(STACK *stk)
{
    if(isEmpty(stk))
    {
        printf("\nStack is empty.");
        return;
    }
    int i;
    printf("\nContents of stack :\n");
    for(i = stk->top; i >= 0; i--)
    {
        printf("\n%d",stk->a[i]);
    }
    printf("\n");
}
int main()
{

    int d, ch,n ;
    STACK stk;
    printf("\nEnter your required size : ");
    scanf("%d", &n);
    stk = createStack(n);
    while(1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n0. Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter your data to push into stack : ");
            scanf("%d", &d);
            push(&stk, d);
            break;
        case 2:
            pop(&stk);
            break;
        case 3:
            display(&stk);
            break;
        case 0:
            return 0;
        default:
            printf("\nWrong option selected!");
        }
    }
}
