//Stack Operation Using Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linklistTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct Node *top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Node *top)
{
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct Node *push(struct Node *top,int x)
{
    if(isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
struct Node *pop(struct Node *top)
{
    if(isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *p = top;
        top = top->next;
        printf("Popped element is :%d\n", p->data);
        free(p);
        
    }
    return top;
}
int peek(struct Node *top,int pos)
{
    struct Node *ptr = top;
    for(int i=0;(i<pos-1 && ptr != NULL);i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int stackTop(struct Node *top){
    return top->data;
}
int stackBottom(struct Node *top)
{
    struct Node *p = top;
    
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}
int main()
{
    struct Node *top = NULL;
    top = push(top,5);
    top = push(top,6);
    top = push(top,7);
    linklistTraversal(top);
    top = pop(top);
    linklistTraversal(top);
    for(int i=1;i<=2;i++)
    {
        printf("Value at position %d is :%d\n",i,peek(top,i));
    }
    int element = stackTop(top);
    printf("Top element is %d\n",element);
    int ele = stackBottom(top);
    printf("Bottom element is %d\n",ele);
    return 0;
}