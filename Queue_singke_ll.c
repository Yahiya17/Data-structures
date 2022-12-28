#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct queue
{
int data;
struct queue *next;
}queue;
queue *rear,*front;

int queue_empty()
{
if(rear==NULL && front==NULL)
return 1;
else
return 0;
}
void enqueue()
{
if(rear==NULL)
{
rear=(queue*)malloc(sizeof(queue));
printf("Enter Data ");
scanf("%d",&rear->data);
rear->next=NULL;
front=rear;
}
else
{
rear->next=(queue*)malloc(sizeof(queue));
rear=rear->next;
printf("Enter Data ");
scanf("%d",&rear->data);
rear->next=NULL;
}
}
void dequeue()
{
queue *p;
int i;
i=queue_empty();
if(i==0)
{
p=front;
front=front->next;
printf("Deleted Data is %d \n",p->data);
free(p);
if(front==NULL)
rear=NULL;
}
else
{
printf("Queue Empty ");
}
}
void display()
{
queue *p;
p=front;
while(p!=NULL)
{
printf("%d->",p->data);
p=p->next;
}
}
void main()
{
int ch;
rear=NULL;
front=NULL;
clrscr();
while(1)
{
printf("\nEnter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
    printf("Enter correct choice \n");
}
}
}
