#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *prev,*next;
}node;
node *head;
void main()
{
clrscr();
node *p,*q;
int i,n;
printf("Enter the size of node ");
scanf("%d",&n);
head=(node*)malloc(sizeof(node));
printf("Enter data ");
scanf("%d",&head->data);
head->prev=NULL;
head->next=NULL;
p=head;
for(i=1;i<n;i++)
{
p->next=(node*)malloc(sizeof(node));
q=p;
p=p->next;
printf("Enter data ");
scanf("%d",&p->data);
p->next=NULL;
p->prev=q;
}
p=head;
while(p!=NULL)
{
printf("<-%d->",p->data);
p=p->next;
}
getch();
}
