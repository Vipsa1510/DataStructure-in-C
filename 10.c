//Queue using LinkedList
#include<stdio.h>
#include<stdlib.h>
struct Queue *f = NULL;
struct Queue *r = NULL;
struct Queue
{
    int data;
    struct Queue *next;
    
};
void enqueue(int val)
{
    struct Queue *n = (struct Queue *)malloc(sizeof(struct Queue));
    if(n == NULL)
    {
        printf("Full");
    }
    else
    {
        
        n->data = val;
        n->next = NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next = n;
            r=n;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct Queue *ptr = f;
    if(f == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        
        f = f->next;
        val = ptr->data;
       
        free(ptr);
        
    }
    return val;
}
void linkedListTraversal(struct Queue *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
void main()
{
    enqueue(15);
    enqueue(45);
    enqueue(5);
    linkedListTraversal(f);
    printf("Dequeuing element :%d\n",dequeue());
    linkedListTraversal(f);
    printf("Dequeuing element :%d\n",dequeue());
    linkedListTraversal(f);
    printf("Dequeuing element :%d\n",dequeue());
    linkedListTraversal(f);
    printf("Dequeuing element :%d\n",dequeue());
}