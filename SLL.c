#include <stdio.h>
#include "insert.c"
#include "delete.c"
#include "display.c"
#include "length.c"
#include "length_recursive.c"
#include "searchLL.c"
#include "swap.c"
#include "middle.c"
#include "delete_list.c"
#include "nth_node.c"

int main()
{
   struct node *head = NULL;
   int ch, n, pos, del;
   int val, key1, key2;
   while(1)
   {
      printf("********---MENU---********\n");
      printf("1:Insert an element\n");
      printf("2:Delete an element\n");
      printf("3:Find length of the list\n");
      printf("4:Search for a value in the list\n");
      printf("5:Swap two nodes\n");
      printf("6:Print the middle node\n");
      printf("7:Delete the list completely\n");
      printf("8:Print the nth node\n");
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
         case 1:  /*Insertion*/
                  printf("Enter the value to be inserted:");
                  scanf("%d", &n);
                  printf("Enter the position where to insert:");
                  scanf("%d", &pos);
                  atMiddle(&head, n, pos);
                  display(&head);
                  break;

         case 2:  /*Deletion*/
                  if(head==NULL)
                  {
                     printf("The list is empty, nothing to delete\n");
                     break;
                  }
                  printf("Enter the value to be deleted:");
                  scanf("%d", &del);
                  delete(&head, del);
                  display(&head);
                  break;
         
         case 3:  /*Find Length*/
                  printf("The number of elements in the list is %d\n", FindLengthRecursive(head));
                  break;

         case 4:  /*Searching*/
                  if(head)
                  {
                     printf("Enter the value to be searched:");
                     scanf("%d", &val);
                     searchLL(&head, val);
                  }
                  else
                     printf("The list is empty\n");
                  break;

         case 5:  /*Swapping*/
                  if(head && head->next)
                  {
                     printf("Enter the keys to be swapped:");
                     scanf("%d%d", &key1, &key2);
                     swap_nodes(&head, key1, key2);
                     display(&head);
                  }
                  else
                     printf("There are less than 2 elements in the list... cannot perform swap\n");
                  break;
         
         case 6:  /*Finding Middle*/
                  if(head)
                  {
                     display(&head);
                     print_middle(&head);
                  }
                  else
                     printf("The list is empty\n");
                  break;

         case 7:  /*Deleting the list*/
                  if(head)
                  {
                     printf("The list before deleting :");
                     display(&head);
                     delete_list(&head);
                     printf("Deleting...\n");
                     display(&head);
                  }
                  else
                     printf("The list is empty\n");
                  break;

         case 8:  /*
                   * Find the nth node
                   */
                  if(head)
                  {
                     printf("Enter the index to be found:");
                     scanf("%d", &pos);
                     find_nth_node(&head, pos);
                  }
                  else
                     printf("No elements found in the list\n");
                  break;

         default: printf("Please enter a valid choice\n");
                  break;
      }
   }
   return 0;
}
