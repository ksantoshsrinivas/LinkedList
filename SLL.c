#include <stdio.h>
#include "insert.c"
#include "delete.c"
#include "display.c"

int main()
{
   struct node *head = NULL;
   int ch, n, pos, del;
   while(1)
   {
      printf("********---MENU---********\n");
      printf("1:Insert an element\n");
      printf("2:Delete an element\n");
      printf("-1:Exit\n");
      printf("Enter your choice :");
      scanf("%d", &ch);
      if(ch==-1)
      {
         printf("Exiting...\n");
         break;
      }
      switch(ch)
      {        
         case 1:  printf("Enter the value to be inserted:");
                  scanf("%d", &n);
                  printf("Enter the position where to insert:");
                  scanf("%d", &pos);
                  atMiddle(&head, n, pos);
                  display(&head);
                  break;

         case 2:  if(head==NULL)
                  {
                     printf("The list is empty, nothing to delete\n");
                     break;
                  }
                  printf("Enter the value to be deleted:");
                  scanf("%d", &del);
                  delete(&head, del);
                  display(&head);
                  break;

         default: printf("Please enter a valid choice\n");
                  break;
      }
   }
   return 0;
}
