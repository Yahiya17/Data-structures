#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node* next;
}node;
node *head;
void red()
{
printf("\033[1;31m");
}
void green()
{
printf("\033[1;32m");
}
void orange()
{
printf("\033[1;39m");
}
void yellow()
{
printf("\033[1;33m");
}
void purple()
{
printf("\033[1;34m");
}
void pink()
{
printf("\033[1;35m");
}
void blue()
{
printf("\033[1;36m");
}
void white()
{
printf("\033[1;37m");
}
void wait()
{
int i;
yellow();
printf("LOADING ");
for(i=200;i<=1000;i+=200)
{
red();
printf(">");
sound(i);
delay(200);
nosound();
}
printf("\n");
}
void printing()
{
node *p;
p=head;
wait();
while(p!=NULL)
{
purple();
printf("%d->",p->data);
p=p->next;
}
}
void counting()
{
node *p;
int c=0;
p=head;
wait();
white();
while(p!=NULL)
{
c++;
p=p->next;
}
printf("No of nodes in the linked list are %d\n ",c);
}
void insertion_at_beginning()
{
node *n;
n=(node*)malloc(sizeof(node));
printf("Enter data");
scanf("%d",&n->data);
n->next=NULL;
n->next=head;
head=n;
}
void insertion_at_last()
{
node *n,*p;
n=(node*)malloc(sizeof(node));
printf("Enter data");
scanf("%d",&n->data);
n->next=NULL;
p=head;
while(p->next!=NULL)
p=p->next;
p->next=n;
}
void insertion_at_pos()
{
node *p,*q,*n;
int pos,i;
n=(node *)malloc(sizeof(node));
printf("Enter data ");
scanf("%d",&n->data);
n->next=NULL;
printf("Enter a position to insert node ");
scanf("%d",&pos);
p=head;
for(i=1;i<(pos-1);i++)
{
p=p->next;
}
n->next=p->next;
p->next=n;
}
void deletion_beginning()
{
node *p;
p=head;
head=head->next;
red();
printf("Deleted element is %d ",p->data);
white();
free(p);
}
void deletion_last()
{
node *p,*q;
p=head;
while(p->next!=NULL)
{
p=p->next;
}
q=head;
while(q->next->next!=NULL)
q=q->next;
q->next=NULL;
red();
printf("Deleted Element is %d ",p->data);
free(p);
white();
}
void deletion_at_pos()
{
node *p,*q;
int pos,i;
printf("Enter the position to be deleted ");
scanf("%d",&pos);
p=head;
if(pos==1)
{
p=head;
head=head->next;
free(p);
}
for(i=1;i<(pos-1);i++)
p=p->next;
q=p->next;
p->next=q->next;
red();
printf("Deleted element is %d ",q->data);
free(q);
white();
}
void searching()
{
int x,c=0;
node *p;
printf("Enter the node data to be searched ");
scanf("%d",&x);
p=head;
while(p!=NULL)
{
if(x==p->data)
{
green();
printf("%d is found in linked list ",x);
c++;
}
p=p->next;
}
if(c==0)
{
red();
printf("Element not found ");
}
white();
}
void sort()
{
node *p,*q;
int t;
p=head;
while(p!=NULL)
{
q=p->next;
while(q!=NULL)
{
if(p->data>q->data)
{
t=p->data;
p->data=q->data;
q->data=t;
}
q=q->next;
}
p=p->next;
}
wait();
green();
printf("\nCOMPLETED\n");
white();
}
void concatenation()
{
node *head1,*p;
int n,i;
printf("Enter the no.of nodes ");
scanf("%d",&n);
head1=(node *)malloc(sizeof(node));
printf("Enter data ");
scanf("%d",&head1->data);
head1->next=NULL;
p=head1;
for(i=1;i<n;i++)
{
p->next=(node *)malloc(sizeof(node));
p=p->next;
printf("Enter data ");
scanf("%d",&p->data);
p->next=NULL;
}
p=head;
while(p->next!=NULL)
p=p->next;
p->next=head1;
}
void merging()
{
concatenation();
sort();
}
void split()
{
node *p,*head1;
int pos,i;
printf("Enter position to split ");
scanf("%d",&pos);
p=head;
for(i=1;i<pos;i++)
{
p=p->next;
}
head1=p->next;
p->next=NULL;
p=head;
printf("\nFIRST LINKED LIST\n");
while(p!=NULL)
{
printf("%d->",p->data);
p=p->next;
}
printf("\n");
printf("\nSECOND LINKED LIST\n");
p=head1;
while(p!=NULL)
{
printf("%d->",p->data);
p=p->next;
}
}
void main()
{
clrscr();
node *p;
int n,i,ch;
textcolor(RED+BLUE);
cprintf("PROGRAM OF SINGLE LINKED LIST ");
textcolor(RED+BLINK);
cprintf("\3 ");
white();
printf("\nEnter how many nodes ");
scanf("%d",&n);
head=(node*)malloc(sizeof(node));
printf("Enter data ");
scanf("%d",&head->data);
head->next=NULL;
p=head;
for(i=1;i<n;i++)
{
p->next=(node *)malloc(sizeof(node));
p=p->next;
printf("Enter data ");
scanf("%d",&p->data);
p->next=NULL;
}
while(1)
{
white();
 printf("\n********************************");
 red();
 printf("Enter your choice");
 white();
 printf("*******************************");
 blue();
 printf("\n1.Printing\n2.Counting\n3.Insertion at begining");
 printf("\n4.Insertion at lat\n5.Insertion at any position\n6.Deletion at beginning\n");
 printf("7.Deletion at last\n8.Deletion at position\n9.Searching");
 printf("\n10.Sorting\n11.Concatenation\n12.merging\n13.Split\n14.Exit\n\n");
 white();
 printf("********************************************************************************");
 scanf("%d",&ch);
system(“cls”);
 switch(ch)
 {
 case 1:
	blue();
	printing();
	break;
 case 2:
	white();
	counting();
	break;
 case 3:
	insertion_at_beginning();
	break;
 case 4:
	insertion_at_last();
	break;
 case 5:
	insertion_at_pos();
	break;
 case 6:
	deletion_beginning();
	break;
 case 7:
	deletion_last();
	break;
 case 8:
	deletion_at_pos();
	break;
 case 9:
	searching();
	break;
 case 10:
	sort();
	break;
 case 11:
	concatenation();
	break;
 case 12:
	merging();
	break;
 case 13:
	split();
	break;
 case 14:
	exit(1);
	break;
 default:
	printf("Invalid choice please enter correct choice ");

}
}
}
