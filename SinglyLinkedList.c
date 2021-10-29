#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void addAtBegin(struct Node **start, int d){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = d;
    t->next =  *start;
    *start = t;
}
void traverse(struct Node *start){
    if(start == NULL){
        printf("\nEmpty list.");
    }
    while(start != NULL){
        printf("%d ", start->data);
        start = start->next;
    }

}
int main()
{
    struct Node *linkedList;
    linkedList = NULL;
    addAtBegin(&linkedList, 10);
    addAtBegin(&linkedList, 20);
    addAtBegin(&linkedList, 30);
    addAtBegin(&linkedList, 40);
    addAtBegin(&linkedList, 50);
    traverse(linkedList);
	return 0;
}
