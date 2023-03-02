// Circular linked list:
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linklistTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is : %d\n",ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
}
struct Node * insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr ->next = head;
    struct Node *p = head -> next; // or struct Node *p = head;
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    head = ptr;
    return head;

}
struct Node *inserAtIndex(struct Node *head,int data ,int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head;
    int i=0;
    while(i != index - 1)
    {
        p = p -> next;
        i++;
    }
    ptr -> next = p -> next;
    p->next =ptr;
    return head;
}
struct Node *insertAtEnd(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head;
    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct Node *inserAfterNode(struct Node *head,struct Node *prevNode,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr ->data = data;
    ptr ->next = prevNode ->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth =  (struct Node*)malloc(sizeof(struct Node));
    head -> data = 4;
    head -> next = second;
    second -> data = 6;
    second -> next = third;
    third -> data = 3;
    third -> next = fourth;
    fourth -> data = 1;
    fourth -> next = head;
    linklistTraversal(head);
    head = insertAtFirst(head,59);
    printf("Affter the add of first element:");
    linklistTraversal(head);
    head = inserAtIndex(head,56,1);
    printf("After the Insert at index:");
    linklistTraversal(head);
    head = insertAtEnd(head,5);
    printf("After the add of last Element :");
    linklistTraversal(head);
    head = inserAfterNode(head,third,45);
    printf("After Node of Element:");
    linklistTraversal(head);
    return 0;
}