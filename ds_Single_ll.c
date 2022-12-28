#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node* next;
}node;
node *head;
void printing()
{
node *p;
p=head;
while(p!=NULL)
{
printf("%d->",p->data);
p=p->next;
}
}
void counting()
{
node *p;
int c=0;
p=head;
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
free(p);
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
free(q);
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
printf("%d is found in linked list ",x);
c++;
}
p=p->next;
}
if(c==0)
{
printf("Element not found ");
}
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
printf("\nFirst Linked List\n");
while(p!=NULL)
{
printf("%d->",p->data);
p=p->next;
}
printf("\n");
printf("2nd Linked list\n");
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
textcolor(RED+BROWN);
cprintf("PROGRAM ");
textcolor(BROWN+GREEN);
cprintf("OF ");
textcolor(RED+BLUE);
cprintf("LINKED ");
textcolor(GREEN+RED);
cprintf("LIST ");
textcolor(RED+BLINK);
cprintf("\3 ");
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
 printf("Enter your choice...........\n1.Printing\n2.Counting\n3.Insertion at begining\n4.Insertion at lat\n5.Insertion at any position\n6.Deletion at beginning\n7.Deletion at last\n8.Deletion at position\n9.Searching\n10.Sorting\n11.Concatenation\n12.merging\n13.Split\n14.Exit\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
    printing();
    break;
 case 2:
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
