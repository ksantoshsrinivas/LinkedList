#include<stdio.h>

void find_nth_node(struct node **head_ref, int index)
{
   int count = 0;
   struct node *temp = *head_ref;

   while(temp)
   {
      if(count==index)
      {
         printf("Found... the value at index %d is %d\n", index, temp->data);
         return;
      }
      temp=temp->next;
      count++;
   }
   printf("Index out of bounds\n");
}
