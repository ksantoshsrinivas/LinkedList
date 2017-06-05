#include<stdio.h>
#include<assert.h>

void delete_list(struct node **head_ref)
{
   struct node *temp;
   struct node *current = *head_ref;
   while(current!=NULL)
   {
      temp = current->next;
      free(current);
      current = temp;
   }
   *head_ref = NULL;
}
