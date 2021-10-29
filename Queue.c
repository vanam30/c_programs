#include<stdio.h>

struct Queue
{
    int *buffer;
    int front, rear, size;
};
typedef struct Queue Q;
Q createQ(int size)
{
    Q queue;
    queue.buffer = (int*)malloc(sizeof(int)*size);
    queue.front = -1;
    queue.rear = -1;
    queue.size = size;
    return queue;
}

int isEmpty(Q *queue)
{
    return queue->front == -1;
}
int isFull(Q *queue)
{
    return queue->rear == queue->size - 1;
}
int isCircularQueueFull(Q *q)
{
    return ((q->front == 0 && q->rear==q->size - 1) || ((q->rear%q->size) + 1 == q->front));
}
void enqueueCircularQueue(Q *queue, int data)
{
    if(isCircularQueueFull(queue))
    {
        printf("\nQueue is full, insert operation is not possible.");
        return;
    }
    if(isEmpty(queue))
    {
        queue->front = queue->rear = 0;
        queue->buffer[queue->front] = data;
        return;
    }
    queue->buffer[++(queue->rear) % queue->size ] = data;
}
void enqueue(Q *queue, int data)
{
    if(isFull(queue))
    {
        printf("\nQueue is full, insert operation is not possible.");
        return;
    }
    if(isEmpty(queue))
    {
        queue->front = queue->rear = 0;
        queue->buffer[queue->front] = data;
        return;
    }
    queue->buffer[++(queue->rear)] = data;
}
void dequeueCircularQueue(Q *queue)
{
    if(isEmpty(queue))
    {
        printf("\nEmpty Queue! Process not possible.\n");
        return;
    }
    int value = queue->buffer[queue->front];
    printf("\nProcessed data : %d", value);
    (queue->front)++;
    if(queue->front == queue->size )
    {
        queue->front = 0;
    }
}
void dequeue(Q *queue)
{
    if(isEmpty(queue))
    {
        printf("\nEmpty Queue! Process not possible.\n");
        return;
    }
    int value = queue->buffer[queue->front];
    printf("\nProcessed data : %d", value);
    (queue->front)++;

    if(queue->front > queue->rear)  //buffer recycling condition.
    {
        queue->front=queue->rear = -1;
    }
}
void displayCircularQueue(Q *queue)
{
    if(isEmpty(queue))
    {
        printf("\nQueue is empty!");
        return;
    }
    int i;
    printf("\nQueue : ");
    if(queue->front <= (queue->rear % queue->size))
    {
        for(i = queue->front; i <= (queue->rear % queue->size); i++)
        {
            printf("--->%d", queue->buffer[i]);
        }
    }
    else
    {
        for(i = queue->front; i < queue->size; i++)
        {
            printf("--->%d", queue->buffer[i]);
        }
        for(i = 0; i <= (queue->rear % queue->size); i++)
        {
            printf("--->%d", queue->buffer[i]);
        }
    }
    printf("\n");
}
void displayQueue(Q *queue)
{
    if(isEmpty(queue))
    {
        printf("\nQueue is empty!");
        return;
    }
    int i;
    printf("\nQueue : ");
    for(i = queue->front; i <= queue->rear; i++)
    {
        printf("--->%d", queue->buffer[i]);
    }
    printf("\n");
}
int main()
{
    int size, ch, data;
    Q q;
    printf("\nEnter the size of queue : ");
    scanf("%d",&size);
    while(1)
    {
        printf("\n1. For linear queue.");
        printf("\n2. For circular queue.");
        printf("\n0. For exit.");
        printf("\nEnter your choice : (0 - 2) : ");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
        {
            q = createQ(size);
            do
            {
                printf("\n1. Enqueue.");
                printf("\n2. Dequeue.");
                printf("\n3. Display Queue.");
                printf("\n0. Exit.");
                printf("\nEnter your choice (0-3) : ");
                scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                {
                    printf("\nEnter data to insert into queue : ");
                    scanf("%d", &data);
                    enqueue(&q, data);
                    break;
                }
                case 2:
                {
                    dequeue(&q);
                    break;
                }
                case 3:
                {
                    displayQueue(&q);
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                    printf("\nWrong option selected.");
                }
            }
            while(ch);
            break;
        }
        case 2:
        {
            q = createQ(size);
            do
            {
                printf("\n1. Enqueue Circular queue.");
                printf("\n2. Dequeue Circular queue.");
                printf("\n3. Display Circular Queue.");
                printf("\n0. Exit.");
                printf("\nEnter your choice (0-3) : ");
                scanf("%d", &ch);
                switch(ch)
                {
                case 1:
                {
                    printf("\nEnter data to insert into queue : ");
                    scanf("%d", &data);
                    enqueueCircularQueue(&q, data);
                    break;
                }
                case 2:
                {
                    dequeueCircularQueue(&q);
                    break;
                }
                case 3:
                {
                    displayCircularQueue(&q);
                    break;
                }
                case 0:
                {
                    break;
                }
                default:
                    printf("\nWrong option selected.");
                }
            }
            while(ch);
            break;
        }
        case 0:
            exit(ch);
        }
    }
    return 0;
}
