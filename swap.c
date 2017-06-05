#include<stdio.h>
/*
 * Swapping nodes in a linked list without swapping data.
 * We assume that the values in the linked list are distinct
 *
 */
void swap_nodes(struct node **head_ref, int key1, int key2)
{
   /*
    * If both the keys are same, no need to do anything
    */
   if(key1 == key2)
   {
      printf("Both the keys are same.. So no need to swap\n");
      return;
   }
   /*
    * Search for the key1
    */
   struct node *prev1 = NULL;
   struct node *curr1 = *head_ref;
   while(curr1 && curr1->data != key1)
   {
      prev1 = curr1;
      curr1 = curr1->next;
   }

   /* 
    * Search for the key2
    */ 
   struct node *prev2 = NULL;
   struct node *curr2 = *head_ref;
   while(curr2 && curr2->data != key2)
   {
      prev2 = curr2;
      curr2 = curr2->next;
   }
   /*
    * If either of the keys is not found,
    * we no need to swap, we just return
    */
   if(curr1==NULL||curr2==NULL)
   {
      printf("Either of the elements is/are not found\n");
      return;
   }   
   /*
    * If the key1 is found at the head
    */ 
   /*struct node *temp;
   if(curr1==*head_ref)
   {
      temp = curr2->next;
      curr2->next = curr1->next;
      prev2->next = curr1;
      curr1->next = temp;
      *head_ref = curr2;
      return;
   }
   if(curr2==*head_ref)
   {
      temp = curr1->next;
      curr1->next = curr2->next;
      prev1->next = curr2;
      curr2->next = temp;
      *head_ref = curr1;
      return;
   }
   temp = curr2->next;
   curr2->next = curr1->next;
   prev1->next = curr2;
   prev2->next = curr1;
   curr1->next = temp;
   return;*/

   /* 
    * If key1 is not found at the head 
    */
   if(prev1!=NULL)
      prev1->next = curr2;
   else //if curr1 is at head, make curr2 as head
      *head_ref = curr2;

   if(prev2!=NULL) // If key2 is not at the head
      prev2->next = curr1;
   else //if curr2 is at head, make curr1 as head
      *head_ref = curr1;

   struct node *temp = curr2->next;
   curr2->next = curr1->next;
   curr1->next = temp;
}
