#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

void insertAtEnd(node **start, int d)
{
    /* 1. allocate new node. */
    node * newNode = (node *) malloc(sizeof(node));
    /* 2. put the data into newNode. */
    newNode->data = d;
    /* 3. this new node is going to be the last node, so make the next null. */
    newNode->next = NULL;
    /* 4. if the linked list is empty, then make the newNode as start. */
    if(*start == NULL)
    {
        *start = newNode;
        return;
    }
    /*5. Else traverse till the last node */
    node *last = *start;
    while(last->next != NULL)
    {
        last = last->next;
    }
    /*6. change the next of the last node */
    last->next = newNode;
}

void split(node **start, node **frontRef, node **backRef)
{
    if((*start) == NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *temp = (*start);
    int c = 0;
    while(temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    if (c < 2)
    {
        *frontRef = (*start);
        *backRef = NULL;
        return;
    }
    node *current = (*start);
    int count = (c - 1) / 2;
    for (int i = 0; i < count; i++)
    {
        current = current->next;
    }
    *frontRef = (*start);
    *backRef = current->next;
    current->next = NULL;
}

void MoveNode(node **endRef, node **startRef)
{
    node *newNode = *startRef;
    if(newNode == NULL)
        return;
    *startRef = newNode->next;
    newNode->next = *endRef;
    *endRef = newNode;
}

void alternateSplit(node *start, node **aRef, node **bRef)
{
    node a;
    node *aEnd = &a;
    node b;
    node *bEnd = &b;
    node *current = start;
    a.next = NULL;
    b.next = NULL;
    while(current != NULL)
    {
        MoveNode(&(aEnd->next), &current);
        aEnd = aEnd->next;
        if (current != NULL)
        {
            MoveNode(&(bEnd->next), &current);
            bEnd = bEnd->next;
        }
    }
    *aRef = a.next;
    *bRef = b.next;
}

void insertPos(node **start, int d, int pos)
{
    if((*start) == NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *ptr = (*start);
    int size = 0;
    while(ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    if (pos < 1 || pos > size + 1)
    {
        printf("\nInvalid position.");
        return;
    }
    while (pos--)
    {
        if (pos == 0)
        {
            node * newNode = (node *) malloc(sizeof(node));
            newNode->data = d;
            newNode->next = NULL;
            node *temp = newNode;
            temp->next = *start;
            *start = temp;
        }
        else
            start = &(*start)->next;
    }
    size++;
}

void deletePos(node **start, int pos)
{
    if((*start) == NULL)
    {
        printf("List is Empty.");
        return;
    }
    node *temp = *start;
    if(pos == 1)
    {
        printf("\nNode deleted.");
        *start = temp->next;
        free(temp);
        return;
    }
    for(int i=1; temp != NULL && i<pos-1; i++)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid Position.");
        return;
    }
    node *ptr = temp->next->next;
    free(temp->next);
    temp->next = ptr;
}

void print_multiple(node *start, int k)
{
    if(start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    int i = 0;
    node *ptr = start;
    while (ptr != NULL)
    {
        if (i % k == 0)
            printf("%d ", ptr->data);
        i++;
        ptr = ptr->next;
    }
}

void circular_multiple(node *start, int k)
{
    if(start == NULL)
    {
        printf("List is Empty.");
        return;
    }
    int count = 0;
    node *ptr = start;
    do
    {
        count++;
        ptr = ptr->next;
    }
    while(ptr != start);
    int num = 0;
    while(count != 0)
    {
        if(num%k == 0 && ptr->data != -1)
        {
            printf("%d ",ptr->data);
            ptr->data = -1;
            count--;
        }
        num++;
        ptr = ptr->next;
    }
}

void reverseList(node **start)
{
    node* current = *start;
    node* prev = NULL;
    node* next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *start = prev;
}

void deleteLessNodes(node *start)
{
    node *current = start;
    node *maxnode = start;
    node *temp;
    while (current != NULL && current->next != NULL)
    {
        if (current->next->data < maxnode->data)
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
            maxnode = current;
        }
    }
}

void delLesserNodes(node **start)
{
    reverseList(start);
    deleteLessNodes(*start);
    reverseList(start);
    printf("\nRemoved successfully.\n");
}

void remove_greater(node **start)
{
    node *ptr = *start, *preptr, *ptrnext = ptr->next, *temp;
    if(ptr == NULL || ptrnext == NULL){
        return;
    }
    preptr = *start;
    while (ptr->next != NULL)
    {
        if (ptr->data < ptrnext->data)//checking adjacent nodes
        {
            if (ptr == *start)
            {
                temp = ptr;
                *start = ptr->next;
                ptr = *start;
                ptrnext = ptrnext->next;
                free(temp);
            }
            else
            {
                //removing the node
                temp = ptr;
                preptr->next = ptrnext;
                temp->next = NULL;
                printf("\n%d",ptr->data);
                free(temp);
                ptr = preptr->next;
                ptrnext = ptrnext->next;
            }
        }
        else{
            preptr = ptr;
            ptr = ptrnext;
            ptrnext = ptrnext->next;
        }
    }
    //display(start);
}

void pairWiseSwap(node **start)
{
    if (*start == NULL || (*start)->next == NULL)
    {
        printf("Pairwise Swapping not possible.");
        return;
    }
    node *prev = *start;
    node *curr = (*start)->next;
    *start = curr;
    while (1)
    {
        node *next = curr->next;
        curr->next = prev;
        if (next == NULL || next->next == NULL)
        {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    printf("\nPairwise Swapping done successfully.\n");
}

void display(node *start)
{
    if(start==NULL)
    {
        printf("List is Empty.");
        return;
    }
    printf("\nList : [");
    while(start)
    {
        printf("%d ", start->data);
        start=start->next;
    }
    printf("]\n");
}

int main()
{
    node *start = NULL, *a = NULL, *b = NULL;
    //printf("\nPress 1 to insert Node (at the End).");
    //printf("\nPress 2 to split list and display.");
    //printf("\nPress 3 to divide list into alternate elements.");
    //printf("\nPress 4 to insert node at inputted position.");
    //printf("\nPress 5 to delete node at inputted position.");
    //printf("\nPress 6 to print all elements at index of multiples of k.");
    //printf("\nPress 7 to print all elements at index of multiples of k in circular list.");
    //printf("\nPress 0 to exit.\n");
    int ar[] = {10, 12, 15, 20, 5, 16, 25, 8}, i;
    while(1)
    {
        int ch,d,pos,x;
        printf("\nPress 1 to insert Node (at the end).");
        printf("\nPress 8 to remove all nodes that have greater value to their right.");
        //printf("\nPress 9 to perform pair-wise swap of nodes of the list.");
        printf("\nPress 10 to display the list.\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 0:
            exit(ch); //return
        case 1:

            //printf("\nEnter data to be inserted : ");
            //scanf("%d",&d);
            for(i = 0; i < 8; i++){
                insertAtEnd(&start,ar[i]);
            }

            break;
        case 2:
            split(&start,&a,&b);
            printf("\nFront Half - \n");
            display(a);
            printf("\nBack Half - \n");
            display(b);
            break;
        case 3:
            alternateSplit(start,&a,&b);
            printf("\nFirst List - \n");
            display(a);
            printf("\nSecond List - \n");
            display(b);
            break;
        case 4:
            printf("\nEnter data to be inserted : ");
            scanf("%d",&d);
            printf("\nEnter position number where %d has to be inserted : ",d);
            scanf("%d",&pos);
            insertPos(&start,d,pos);
            display(start);
            break;
        case 5:
            printf("\nEnter position number from where node has to be deleted : ");
            scanf("%d",&pos);
            deletePos(&start,pos);
            display(start);
            break;
        case 6:
            printf("\nEnter the value of k : ");
            scanf("%d",&x);
            print_multiple(start,x);
            break;
        case 7:
            printf("\nEnter the value of k : ");
            scanf("%d",&x);
            circular_multiple(start,x);
            break;
        case 8:
            remove_greater(&start);
            break;
        case 9:
            pairWiseSwap(&start);
            break;
        case 10:
            display(start);
            break;
        default:
            printf("Invalid Choice.");
        }
    }
}

