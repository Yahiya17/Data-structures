#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct queue
{
int data;
struct queue *next,*prev;
}queue;
queue *rear,*front;
//rear=NULL;
//front=NULL;
int queue_empty()
{
if(rear==NULL&&front==NULL)
{
return 1;
}
else
return 0;
}
void enqueue()
{
queue *q;
if(rear==NULL)
{
rear=(queue *)malloc(sizeof(queue));
printf("Enter data ");
scanf("%d",&rear->data);
rear->next=NULL;
rear->prev=NULL;
front=rear;
}
else
{
rear->next=(queue *)malloc(sizeof(queue));
q=rear;
rear=rear->next;
printf("Enter data ");
scanf("%d",&rear->data);
rear->next=NULL;
rear->prev=q;
}
}
void dequeue()
{
queue *p;
int i;
i=queue_empty();
if(i==0)
{
if(front!=rear)
{
p=front;
front=front->next;
front->prev=NULL;
printf("Deleted data is %d",p->data);
free(p);
}
else
{
	p=rear;
	printf("Deleted data is %d",p->data);
	front=rear=NULL;
	free(p);
}
}
else
printf("Queue Empty ");
}
void display()
{
queue *p;
p=front;
while(p!=NULL)
{
printf("<-%d->",p->data);
p=p->next;
}
}
void main()
{
int n,ch,i;
queue *p;
clrscr();
rear=NULL;
front=NULL;
printf("Enter the size of Linked List ");
scanf("%d",&n);
rear=(queue*)malloc(sizeof(queue));
printf("Enter data ");
scanf("%d",&rear->data);
rear->next=NULL;
rear->prev=NULL;
front=rear;
for(i=1;i<n;i++)
{
rear->next=(queue *)malloc(sizeof(queue));
p=rear;
rear=rear->next;
printf("Enter data ");
scanf("%d",&rear->data);
rear->next=NULL;
rear->prev=p;
}
while(1)
{
printf("\nEnter your choice \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
    enqueue();
    break;
case 2:
    dequeue();
    break;
case 3:
    display();
    break;
case 4:
    exit(1);
    break;
default:
    printf("Enter valid choice ");
}
}
getch();
}
