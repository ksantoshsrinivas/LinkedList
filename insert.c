#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};

void atBeginning(struct node **head_ref, int n)
{
   struct node *p = (struct node*)malloc(sizeof(struct node));
   p->data = n;
   p->next = NULL;
   if(*head_ref==NULL)
   {
      *head_ref = p;
      return;
   }
   p->next = *head_ref;
   *head_ref = p;
   return;
}

void atMiddle(struct node **head_ref, int n, int pos)
{
   struct node *p = (struct node*)malloc(sizeof(struct node));
   struct node *q = *head_ref;
   int count = 0;
   p->data = n;
   p->next = NULL;
   if(*head_ref==NULL)
   {
      printf("List is empty.. so inserting at the beginning\n");
      *head_ref = p;
      return;
   }
   while(q->next!=NULL && count<pos-1)
   {
      q=q->next;
      count++;
   }
   if(q->next==NULL && count<pos)
   {
      printf("Position is more than the length of the list.. so cannot insert\n");
      return;
   }
   p->next = q->next;
   q->next = p;
   return;
}

void atEnd(struct node **head_ref, int n)
{
   struct node *p = (struct node*)malloc(sizeof(struct node));
   struct node *last = *head_ref;
   p->data = n;
   p->next = NULL;
   if(*head_ref==NULL)
   {
      *head_ref = p;
      return;
   }
   while(last->next!=NULL)
      last=last->next;
   last->next = p;
   return;
}

void display(struct node **head_ref)
{
   struct node *p = NULL;
   if(*head_ref==NULL)
   {
      printf("List is empty\n");
      return;
   }
   printf("The elements in the list are:\n");
   for(p=*head_ref;p->next!=NULL;p=p->next)
      printf("%d->", p->data);
   printf("%d\n", p->data);
}

int main()
{
   struct node *head = NULL;
   int ch, n, pos;
   do
   {
      printf("Enter the value to be inserted:");
      scanf("%d", &n);
      printf("********Choose where to insert*********\n");
      printf("1:Insert at the beginning\n");
      printf("2:Intert at middle\n");
      printf("3:Insert at end\n");
      printf("-1:Exit\n");
      printf("Enter your choice :");
      scanf("%d", &ch);
      switch(ch)
      {
         case 1:  atBeginning(&head,n);
                  display(&head);
                  break;

         case 2:  printf("Enter the position where to insert (otherthan at beginning and at end)\n");
                  scanf("%d", &pos);
                  atMiddle(&head, n, pos);
                  display(&head);
                  break;

         case 3:  atEnd(&head,n);
                  display(&head);
                  break;

         case -1: printf("Program exiting...\n");
                  break;

         default: printf("Please enter a valid choice\n");
                  break;
      }
   }while(ch!=-1);
   return 0;
}
