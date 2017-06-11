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
   p->next = *head_ref;
   *head_ref = p;
}

void atMiddle(struct node **head_ref, int n, int pos)
{
   /* We assume that the index starts with 0 */
   struct node *q = *head_ref;
   int count = 0;
   if(*head_ref==NULL || pos==0)
   {
      atBeginning(head_ref, n);
      return;
   }
   while(q->next!=NULL && count<pos-1)
   {
      q=q->next;
      count++;
   }
   if(q->next==NULL)
   {
      printf("The list reached the end..so inserting at the end\n");
      atEnd(head_ref, n);
      return;
   }
   struct node *p = (struct node*)malloc(sizeof(struct node));
   p->data = n;
   p->next = q->next;
   q->next = p;
}

void atEnd(struct node **head_ref, int n)
{
   struct node *p = (struct node*)malloc(sizeof(struct node));
   struct node *last = *head_ref;
   p->data = n;
   p->next = NULL;
   for(; last->next!=NULL;last=last->next);
   last->next = p;
}
