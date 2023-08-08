#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *llink;
  struct node *rlink;
};

typedef struct node DLIST;

DLIST* getnode()
{
  DLIST* nn;
  nn = (DLIST*)malloc(sizeof(DLIST));
  printf("Enter value : ");
  scanf("%d",&nn->data);
  nn->llink = NULL;
  nn->rlink = NULL;
  return nn;
}

DLIST* createdclist(DLIST *start,int *count)
{
   DLIST *nnode,*last;
   int ch=1;
   while(ch)
   {
      nnode = getnode();
      if(start==NULL)
	 start =  nnode;
      else
	{
	  last->rlink = nnode;
	  nnode->llink = last;
	}
      last = nnode;
      (*count)++;
      printf("Want to continue? (1-Yes/0-No) : ");
      scanf("%d",&ch);
   }
   return start;
}


DLIST* insertatpos(DLIST *start,int *count)
{
   DLIST *nnode,*curr;
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
	nnode->rlink = curr;
	curr->llink = nnode;
	start = nnode;
      }
      else
      {
	for(i=1;i<pos-1;i++)
	   curr = curr->rlink;
	/*next = curr->rlink;
	nnode->rlink = next;
	next->llink = nnode; */

	nnode->rlink = curr->rlink;
	(curr->rlink)->llink = nnode;

	curr->rlink = nnode;
	nnode->llink = curr;
      }
      (*count)++;
   }
   return start;
}


DLIST* deletebypos(DLIST *start,int *count)
 {
   DLIST *temp, *prev;
   int pos,i;
   printf("\nEnter the position from where the node to be deleted : ");
   scanf("%d",&pos);
   if((pos<=0) || (pos > *count))
      printf("ERROR ! Entered Invalid position.....\n");
   else
   {
      temp = start;
      if(pos == 1)
      {
	start = temp->rlink;
	start->llink = NULL;
      }
      else
      {
	for(i=1;i<pos;i++)
	  {
	    prev = temp;
	    temp = temp->rlink;
	  }
	prev->rlink = temp->rlink;
	(temp->rlink)->llink = prev;
      }
      temp->rlink = NULL;
      temp->llink = NULL;
      free(temp);
      (*count)--;
   }
  return start;
}

void updateval(DLIST *start)
{
   DLIST *temp;
   int val,x;
   printf("\nEnter the value which is to be updated : ");
   scanf("%d",&val);
   temp = start;
   if(temp->data== val)
     {
       printf("\nEnter the new value : ");
       scanf("%d",&x);
       temp->data = x;
     }
   else
     {
       temp = start->rlink;
       while((temp != start)&&(val != temp->data))
	  temp = temp->rlink;
       if(temp != start)
	{
	  printf("\nEnter the new value : ");
	  scanf("%d",&x);
	  temp->data = x;
	}
       else
	 printf("%d is not present in the list.....cannot update...\n",val);
     }
}

DLIST* deletebyval(DLIST *start, int *count)
  {
   DLIST *temp, *prev;
   int val;
   printf("\nEnter the value which is to be deleted : ");
   scanf("%d",&val);
   temp = start;
   if(val == temp->data)
     {
       prev = temp->llink;
       start = temp->rlink;
       prev->rlink = start;
       start->llink = prev;
     }
   else
    {
      while((temp->rlink != start)&&(val != temp->data))
      {
	prev = temp;
	temp = temp->rlink;
      }
      if(temp->data == val)
	{
	  prev->rlink = temp->rlink;
	  temp->rlink->llink = prev;
	}
    }
   if(temp->data == val)
   {
      temp->rlink = temp->llink = NULL;
      free(temp);
      (*count)--;
   }
   else
      printf("%d is not present in the list.....cannot delete...\n",val);
   return start;
}

void search(DLIST *start)
{
   DLIST *temp;
   int val,pos;
   printf("\nEnter the value which is to be searched : ");
   scanf("%d",&val);
   temp = start;
   pos = 0;
   /*if(start->data == val)
      printf("%d found at position %d in the list.....\n",val,pos+1);
   else
   {
      temp = start->rlink;    */
      while((temp != NULL)&&(temp->data != val))
      {
	temp = temp->rlink;
	pos++;
      }
      if(temp != NULL)
	 printf("%d found at position %d in the list.....\n",val,pos+1);
      else
	 printf("%d not found in the list.....\n",val);
}

void printlist(DLIST *start)
{
    DLIST *temp=start;

    if(start != NULL)
    {
       printf("Doubly Linked List is.....\n");
       while(temp != NULL)
       {
	  printf("%d <-> ",temp->data);
	  temp = temp->rlink;
       }
       printf("NULL \n");
    }
    else
       printf("Doubly linked list is empty.....\n");
}

void printrevlist(DLIST *start)
{
    DLIST *temp;
    temp = start;

    if(start != NULL)
    {
       printf("Linked list from right to left is.....\n");
       while(temp->rlink != NULL)
	   temp = temp->rlink;

       while(temp != NULL)
       {
	  printf("%d <-> ",temp->data);
	  temp = temp->llink;
       }
       printf("NULL\n");
    }
    else
       printf("Doubly linked list is empty.....\n");
}

int main()
{
   DLIST *head;
   int count=0,ch=1;
   head = NULL;
   printf("Creation of Linked List.....\n");
   head = createdclist(head,&count);
   printlist(head);
   printf("\n M E N U for Singly Linked List operations......\n");
   printf("1. Insert node at given position \n2. Delete node by position\n");
   printf("3. Delete node by value \n4. Print Linked List \n5. Search node\n");
   printf("6. Update value of node\n7. Quit\n");
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
		 printrevlist(head);
		 break;
	case 5 : search(head);
		 break;
	case 6 : updateval(head);
		 printlist(head);
		 break;
	case 7 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
     }
   return(0);
}

