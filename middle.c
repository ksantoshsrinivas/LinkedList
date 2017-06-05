#include<stdio.h>
//#include "display.c"

void print_middle(struct node **head_ref)
{
   struct node *fast = *head_ref;
   struct node *slow = *head_ref;
   if(!*head_ref)
      return;
   while(fast && fast->next)
   {
      if(fast->next)
         fast = fast->next->next;
      else 
         fast = fast->next;
      slow = slow->next;
   }
   //display(head_ref);
   printf("The middle node contains value %d\n", slow->data);
}
