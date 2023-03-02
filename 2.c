//Circular link list of Delete Operation:
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
//struct Node *deleteAtFirst(struct Node *head)
//{
//    struct Node *ptr = head;
//    struct Node *p = head ->next;
 //   head=head->next;
 //   while(p->next != head)
 //   {
 //       p = p->next;
  //  }
 //   p->next = head;
  //  free(ptr);
   // return head;
//}
struct Node *deleteAtIndex(struct Node *head,int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node *deleteAtValue(struct Node *head,int value)
{
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->data != value && q->next != head)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data == value)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}
struct Node *deleteAtlast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=head)
    {
        p=p->next;
        q=q->next;
    }
    p->next=head;
    free(q);
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
    //head = deleteAtFirst(head);
    //linklistTraversal(head);
    printf("Delete Element at index:\n");
    head = deleteAtIndex(head,2);
    linklistTraversal(head);
    printf("Delete Element at Value:\n");
    head=deleteAtValue(head,6);
    linklistTraversal(head);
    printf("Delete Element at last:\n");
    head = deleteAtlast(head);
    linklistTraversal(head);
    
    return 0;
}