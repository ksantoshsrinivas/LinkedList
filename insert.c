#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};

void atBeginning(struct node **, int);
void atMiddle(struct node **, int, int);
void atEnd(struct node **, int);

void atBeginning(struct node **head_ref, int n)
{
   struct node *p = (struct node*)malloc(sizeof(struct node));
   p->data = n;
   p->next = NULL;
   if(*head_ref==NULL)
   {
      *head_ref = p;
      return;
   }
   p->next = *head_ref;
   *head_ref = p;
   return;
}

void atMiddle(struct node **head_ref, int n, int pos)
{
   /* We assume that the index starts with 0 */
   struct node *p = (struct node*)malloc(sizeof(struct node));
   struct node *q = *head_ref;
   int count = 0;
   p->data = n;
   p->next = NULL;
   if(*head_ref==NULL)
   {
      printf("List is empty.. so inserting at the beginning\n");
      *head_ref = p;
      return;
   }
   if(pos==0)
   {
      atBeginning(head_ref, n);
      return;
   }
   while(q->next!=NULL && count<pos-1)
   {
      q=q->next;
      count++;
   }
   if(q->next==NULL && count<pos)
   {
      printf("The list reached the end and length of list < position..so inserting at the end");
      atEnd(head_ref, n);
      return;
   }
   p->next = q->next;
   q->next = p;
   return;
}

void atEnd(struct node **head_ref, int n)
{
   struct node *p = (struct node*)malloc(sizeof(struct node));
   struct node *last = *head_ref;
   p->data = n;
   p->next = NULL;
   if(*head_ref==NULL)
   {
      *head_ref = p;
      return;
   }
   while(last->next!=NULL)
      last=last->next;
   last->next = p;
   return;
}

/*void display(struct node **head_ref)
{
   struct node *p = NULL;
   if(*head_ref==NULL)
   {
      printf("List is empty\n");
      return;
   }
   printf("The elements in the list are:\n");
   for(p=*head_ref;p->next!=NULL;p=p->next)
      printf("%d->", p->data);
   printf("%d\n", p->data);
}*/
