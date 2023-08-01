#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *link;
};

typedef struct node LIST;

LIST* insertatpos(LIST*, int*);

LIST* getnode()
{
  LIST* nn;
  nn = (LIST*)malloc(sizeof(LIST));
  printf("Enter value : ");
  scanf("%d",&nn->data);
  nn->link = NULL;
  return nn;
}

LIST* createlist(LIST *start,int *count)
  {
   LIST *nnode,*last;
   int ch=1;
   while(ch)
   {
      nnode = getnode();
      if(start==NULL)
	 start =  nnode;
      else
	 last->link = nnode;
      last = nnode;
      (*count)++;
      printf("Want to continue? (1-Yes/0-No) : ");
      scanf("%d",&ch);
   }
   last->link = start;
   return start;
  }


void insertafter(LIST *start,int *count)
  {
   LIST *nnode,*curr;
   int val;
   printf("\nEnter the value after new node to be inserted : ");
   scanf("%d",&val);
   curr = start;
   while((curr != NULL)&&(val != curr->data))
      curr = curr->link;
   if(curr != NULL)
   {
      nnode = getnode();
      nnode->link = curr->link;
      curr->link = nnode;
      (*count)++;
    }
    else
       printf("%d is not present in the list.....cannot insert...\n",val);
  }

LIST* insertbefore(LIST *start,int *count)
  {
   LIST *nnode,*curr, *prev;
   int val;
   printf("\nEnter the value before new node to be inserted : ");
   scanf("%d",&val);
   curr = start;
   while((curr != NULL)&&(val != curr->data))
   {
      prev = curr;
      curr = curr->link;
   }
   if(curr != NULL)
   {
      nnode = getnode();
      if(curr == start)
	{
	   nnode->link = start;
	   start = nnode;
	}
       else
	 {
	    nnode->link = curr;
	    prev->link = nnode;
	 }
       (*count)++;
    }
    if(curr==NULL)
       printf("%d is not present in the list.....cannot insert...\n",val);
    return start;
  }


LIST* deletebypos(LIST *start,int *count)
 {
   LIST *temp, *prev;
   int pos,i;
   printf("\nEnter the position from where the node to be deleted : ");
   scanf("%d",&pos);
   if((pos<=0) || (pos > *count))
      printf("ERROR ! Entered Invalid position.....\n");
   else
   {
      temp = start;
      if(pos == 1)
	start = temp->link;
      else
      {
	for(i=1;i<pos;i++)
	  {
	    prev = temp;
	    temp = temp->link;
	  }
	prev->link = temp->link;
      }
      temp->link = NULL;
      free(temp);
      (*count)--;
   }
  return start;
 }

void updateval(LIST *start)
{
   LIST *temp;
   int val,x;
   printf("\nEnter the value which is to be updated : ");
   scanf("%d",&val);
   temp = start;
   while((temp != NULL)&&(val != temp->data))
	temp = temp->link;
   if(temp != NULL)
   {
     printf("\nEnter the new value : ");
     scanf("%d",&x);
     temp->data = x;
   }
   else
      printf("%d is not present in the list.....cannot update...\n",val);
}

LIST* deletebyval(LIST *start, int *count)
  {
   LIST *temp, *prev;
   int val;
   printf("\nEnter the value which is to be deleted : ");
   scanf("%d",&val);
   temp = start;
   if(val == start->data)
     start = temp->link;
   else
    {
      while((temp != NULL)&&(val != temp->data))
      {
	prev = temp;
	temp = temp->link;
      }
      if(temp != NULL)
	  prev->link = temp->link;
    }
   if(temp==NULL)
      printf("%d is not present in the list.....cannot delete...\n",val);
   else
     {
       temp->link = NULL;
       free(temp);
       (*count)--;
     }
   return start;
 }

void search(LIST *start)
  {
   LIST *temp;
   int val,pos;
   printf("\nEnter the value which is to be searched : ");
   scanf("%d",&val);
   temp = start;
   pos = 0;
   while((temp->link != start)&&(temp->data != val))
   {
      temp = temp->link;
      pos++;
   }

   if(temp->data == val)
      printf("%d found at position %d in the list.....\n",val,pos+1);
   else
       printf("%d not found in the list.....\n",val);
  }

void printlist(LIST *start)
  {
    LIST *temp=start;
    printf("Linked list is.....\n");
    if(start==NULL)
       printf("List is Empty.....\n");
    else
       do
       {
	 printf("%d -> ",temp->data);
	 temp = temp->link;
       }while(temp != start);
    printf("\b\b\b\n");
  }

void main()
{
   LIST *head;
   int count=0,ch=1;
   clrscr();
   head = NULL;
   printf("Creation of Linked List.....\n");
   head = createlist(head,&count);
   printlist(head);
   printf("\n M E N U for Singly Linked List operations......\n");
   printf("1. Insert node at given position \n2. Delete node by position\n");
   printf("3. Delete node by value \n4. Print Linked List \n5. Search node\n");
   printf("6. Insert new node before given value \n7. Insert new node after given value\n");
   printf("8. Update value of node\n9. Quit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : head = insertatpos(head,&count);
		 printlist(head);
		 break;
	case 2 : head = deletebypos(head,&count);
		 printlist(head);
		 break;
	case 3 : head = deletebyval(head,&count);
		 printlist(head);
		 break;
	case 4 : printlist(head);
		 break;
	case 5 : search(head);
		 break;
	case 6 : head = insertbefore(head,&count);
		 printlist(head);
		 break;
	case 7 : insertafter(head,&count);
		 printlist(head);
		 break;
	case 8 : updateval(head);
		 printlist(head);
		 break;
	case 9 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
     }
   getch();
}

LIST* insertatpos(LIST *start,int *count)
  {
   LIST *nnode,*curr;
   int pos,i;
   printf("\nEnter the position where the node to be inserted : ");
   scanf("%d",&pos);
   if((pos<=0) || (pos > *count+1))
      printf("ERROR ! Entered Invalid position.....\n");
   else
   {
      nnode = getnode();
      curr = start;
      if(pos == 1)
      {
	while(curr->link != start)
	   curr = curr->link;
	curr->link = nnode;
	nnode->link = start;
	start = nnode;
      }
      else
      {
	for(i=1;i<pos-1;i++)
	   curr = curr->link;
	nnode->link = curr->link;
	curr->link = nnode;
      }
      (*count)++;
   }
   return start;
  }
