//Stack Operation
#include <stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int * arr;
};
int isFull(struct stack * s)
{
    if(s -> top == s -> size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack * s)
{
    if(s -> top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack * s,int val)
{
    if(isFull(s))
    {
        printf("Satck Overflow\n");
        printf("%d is not push in stack\n",val);
    }
    else
    {
        s -> top++;
        s -> arr[s -> top] =val; 
        printf("Element is :%d\n",s -> arr[s->top]);
    }
}
void pop(struct stack * s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
        printf("Can not pop any element\n");
    
    }
    else
    {
        printf("Pop element is:%d\n",s -> arr[s -> top]);
        s -> top--;
    }
}
int peek(struct stack * s,int i)
{
    int arrayInd = s->top - i + 1;
    if(arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return s -> arr[arrayInd];
    }
}

int main() 
{
    struct stack * p= (struct stack *) malloc(sizeof(struct stack));
    p -> size = 5;
    p -> top=-1;
    p -> arr = malloc((p->size)*sizeof(int));
    push(p,14);
    push(p,50);
    push(p,4);
    push(p,24);
    push(p,54);
    push(p,34);
    pop(p);
    for(int j = 1;j <= p -> top + 1;j++)
    {
        printf("The Value at position %d is %d\n",j,peek(p,j));
    }
    return 0;
}