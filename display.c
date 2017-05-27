#include<stdio.h>
void display(struct node **head_ref)
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
}

