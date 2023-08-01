#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define mxsize 5

struct queue
{
   int front,rear;
   int arr[mxsize];
};

typedef struct queue QUE;

void initq(QUE *z)
{
   z->front = 0;
   z->rear = -1;
}

int isfullq(QUE q)
{
   if(q.rear == mxsize-1)
      return 1;
   else
      return 0;
}

int isemptyq(QUE q)
{
   if(q.rear == -1)  // if(q.rear<q.front)
      return 1;
   else
      return 0;
}

void insertq(QUE *q)
{
   int val;
   if(isfullq(*q))
     printf("No space to add element in queue.....Cannot add.\n");
   else
      {
	printf("Enter value to be added : ");
	scanf("%d",&val);
	q->rear = q->rear + 1;
	q->arr[q->rear] = val;
      }
}

void removeq(QUE *q)
{
   if(isemptyq(*q))
       printf("Queue is Empty.....Cannot remove.\n");
   else
      {
	 printf("%d is removed from queue.\n",q->arr[q->front++]);
	 if(q->front==q->rear+1)
	    {
	       q->front = 0;
	       q->rear = -1;
	     }
      }
}

void printdq(QUE q)
{
   int i;
   if(isemptyq(q))
      printf("Queue is Empty.....\n");
   else
      {
	 printf("Elements of queue are.....\n");
	 for(i=q.front;i<=q.rear;i++)
	    printf("%d\t",q.arr[i]);
	 printf("\n");
      }
}

int peekq(QUE q)
{
   return q.arr[q.front];
}

void main()
{
   QUE q;
   int x,ch=1;
   clrscr();
   initq(&q);
   printf("\n M E N U for operations on Queue......\n");
   printf("1. Add element in an queue \n");
   printf("2. Delete element from an queue \n");
   printf("3. Print queue \n");
   printf("4. Peek element\n");
   printf("5. Quit\n");
   while(ch)
   {
     printf("\nEnter your choice of operation : ");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1 : insertq(&q);
		 if(!isemptyq(q))
		    printdq(q);
		 break;
	case 2 : removeq(&q);
		 if(!isemptyq(q))
		    printdq(q);
		 break;
	case 3 : printdq(q);
		 break;
	case 4 : if(!isemptyq(q))
		 {
		    x = peekq(q);
		    printf("%d is at the front of an queue.\n",x);
		 }
		 else
		    printf("Cannot peek as Queue is Empty.....\n");
		 break;
	case 5 : exit(1);
	default: printf("ERROR ! Entered wrong choice.....Try again.....\n");
      }
   }
   getch();
}
