#include <stdio.h>
#include <stdlib.h>

int FindLength(struct node **head_ref)
{
   struct node *p = *head_ref;
   int count = 0;
   if(*head_ref==NULL)
      return count;
   while(p!=NULL)
   {
      p=p->next;
      count++;
   }
   return count;
}
