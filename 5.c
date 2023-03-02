#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr,char val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow! cannot push %d to the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
      printf("stack Underflow!Cannot pop from the stack\n");
      return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int match(char a,char b)
{
    if(a =='{' && b == '}')
    {
        return 1;
    }
    if(a == '(' && b == ')')
    {
        return 1;
    }
    if(a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}    
int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
    for(int i = 0;exp[i]!='\0';i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            
            popped_ch = pop(sp);
            if(!match(popped_ch,exp[i]))
            {
                return 0;
            }
        }
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = "{[8](*--$&9)}";
    if(parenthesisMatch(exp))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }
    return 0;
}