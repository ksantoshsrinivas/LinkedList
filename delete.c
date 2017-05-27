#include<stdio.h>

void delete(struct node **head_ref, int val)
{
   /*
    * If list is empty, just return
    * */
   if(*head_ref == NULL)
      return;
   struct node *curr = *head_ref;
   struct node *prev = NULL;
   /*
    * If the first node has the value, 
    * make the next node as head, 
    * delete the curr node
    * */
   if(curr->data == val)
   {
      *head_ref = curr->next;
      free(curr);
      printf("Deleted %d from the list\n", val);
      return;
   }
   /*
    * Traverse till we find the value within the list
    * */
   while(curr->next!=NULL && curr->data!=val)
   {
      prev = curr;
      curr = curr->next;
   }
   /* 
    * If we have reached the end of list without finding the value
    * */
   if(curr==NULL||curr->data!=val)
   {
      printf("Element not found in the list\n");
      return;
   }
   /*
    * If we find the value in the list,
    * make the next of prev to point to the next node of curr
    * free curr node
    * */
   prev->next = curr->next;
   free(curr);
   printf("Deleted %d from the list\n", val);
}
