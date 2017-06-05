#include<stdio.h>

void searchLL(struct node **head_ref, int val)
{
   struct node *p = *head_ref;
   if(!(*head_ref))
   {
      printf("List is empty\n");
      return;
   }
   while(p!=NULL)
   {
      if(p->data==val)
      {
         printf("Element found\n");
         return;
      }
      p=p->next;
   }
   printf("Element not found\n");
   return;
}
