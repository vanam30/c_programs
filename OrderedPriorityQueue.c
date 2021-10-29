#include<stdio.h>
#include<stdlib.h>

struct OrderedQueue{
    int *q;
    int front;
    int rear;
    int size;
};
typedef struct OrderedQueue OQ;
void initialize(OQ *oq, int ne){
    oq->q = (int*)malloc(sizeof(int) * ne);
    oq->size = ne;
    oq->front = oq->rear = -1;
}
void enqueue(OQ *oq, int data){
    int j;
    if(oq->rear == oq->size - 1){
        printf("\nQueue is full.");
        return;
    }
    if(oq->front == -1){
        oq->front = oq->rear = 0;
        oq->q[oq->front] = data;
    }
    else{
        for(j = oq->rear; j > -1 && oq->q[j] > data; j--){
            oq->q[j + 1] = oq->q[j];
        }
        oq->q[j+1] = data;
        oq->rear++;
    }
    printf("\nData inserted successfully.");
}
void display(OQ *oq){
    int j;
    if(oq->front == -1){
        printf("\nQueue empty!");
        return;
    }
    for(j = oq->rear; j >= oq->front; j--){
        printf("===>%d",oq->q[j]);
    }
}
void dequeue(OQ *oq){
    if(oq->front == -1 ){
        printf("\nEmpty queue!");
        return;
    }
    printf("\nProcessed data : %d", oq->q[oq->rear--]);
    if(oq->rear == -1){ //recycling condition.
        oq->front = oq->rear = -1;
    }
}
int main()
{
    int ch, n;
    OQ oq;
    printf("\nEnter the size of queue : ");
    scanf("%d", &n);
    initialize(&oq, n); //queue is ready.
    while(1){
        printf("\n1 to enqueue.");
        printf("\n2 to deque.");
        printf("\n3 display queue.");
        printf("\n0 to exit.");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                printf("\nEnter data to enqueue : ");
                scanf("%d", &n);
                enqueue(&oq,n);
                break;
            }
            case 2:{
                dequeue(&oq);
                break;
            }
            case 3:{
                display(&oq);
                break;
            }
            case 0:{
                exit(ch);
            }
            default:{
                printf("\nWrong option selected.");
            }
        }
    }
	return 0;
}
