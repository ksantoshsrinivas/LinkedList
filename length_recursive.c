#include<stdio.h>
#include<stdlib.h>

int FindLengthRecursive(struct node *head_ref)
{
   if(head_ref==NULL)
      return 0;
   return FindLengthRecursive(head_ref->next)+1;
}
