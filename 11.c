//Double Ended Queue
#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size,f,r;
    int *arr;
    
};
int isEmpty(struct Queue *q)
{
    if(q->f == q->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Queue *q)
{
    int i,c=0;
    for(i=q->f;i<=q->r;i++)
    {
        c++;
    }
    if(c == q->size)
    {
        return 1;
    }
    
        return 0;
}
void enqueueAtRear(struct Queue *q,int val)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        if(q->f == -1)
        {
            q->f = q->f+1;
        }
        q->r=q->r+1;
        q->arr[q->r]=val;
        printf("Successfully Insertion at Rear\n");
    }
}
void enqueueAtFront(struct Queue *q,int val)
{
    if(isFull(q))
    {
        printf("Not possible Insertion at Front\n");
    }
    else
    {
        q->f = q->f - 1;
        q->arr[q->f] = val;
        printf("Successfully Insertion at front\n");
    }
}
int dequeueAtRear(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    else
    {
        int val=q->arr[q->r];
        q->r = q->r - 1;
        return val;
    }
}
int dequeueAtFront(struct Queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int val = q->arr[q->f];
        q->f = q->f + 1;
        return val;
    }
}
void display(struct Queue *q)
{
    int i;
    for(i=q->f;i<=q->r;i++)
    {
        printf("Element : %d\n",q->arr[i]);
    }
}
void main()
{
    struct Queue dq;
    dq.size = 5;
    dq.f=-1;
    dq.r=-1;
    dq.arr = (int *)malloc(sizeof(int)*dq.size);
    enqueueAtRear(&dq,10);
    enqueueAtRear(&dq,15);
    enqueueAtFront(&dq,5);
    enqueueAtFront(&dq,55);
    enqueueAtFront(&dq,50);
    enqueueAtFront(&dq,58);
    display(&dq);
    printf("Dequeuing element:%d\n",dequeueAtRear(&dq));
    printf("Dequeuing element:%d\n",dequeueAtFront(&dq));
    printf("Dequeuing element:%d\n",dequeueAtFront(&dq));
    printf("Dequeuing element:%d\n",dequeueAtFront(&dq));
    display(&dq);
}