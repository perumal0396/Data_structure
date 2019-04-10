
/***************************************/
/* Author      : PERUMAL.R             */
/* Date        : 07-FEB-2019           */
/* Filename    : double_linked.h       */
/* Description : double_linked         */
/***************************************/



#include "double_linked.h"

void print_list();
void sort_list();
struct node
{
	struct node *prev;
	int regno;
	char *name;
	struct node *next;
};
struct node *head=NULL;
struct node *last=NULL;
struct node *print_ptr=NULL;

void insert_node(int data,char *name_ptr) 
{
	struct node *size;
	struct	node *ptr=(struct node *)malloc(sizeof (struct node));
	
	size =size+1;
	ptr->regno=data;
	ptr->name=name_ptr;
	if(head==NULL)
		last=ptr;
	else
	head->prev=ptr;
	ptr->next=head;
	head=ptr;
}
void revers(struct node **one)
{
	struct	node *current=(struct node *)malloc(5*sizeof (struct node));
	
	
	 	current=last;
		int i=1;

 	while(current!=NULL)
 	{
		printf("%d\t%d\t%s\n",i++,current->regno,current->name);
		current=current->prev;

	}
}
int main()
{
	printf("--------sorting linked list---------\n");

	insert_node(1,"naveen\n");
	insert_node(2,"perumal\n");
	insert_node(3,"jeeva\n");
	insert_node(4,"munui\n");
	insert_node(5,"ten\n");

	sort_list();
	print_list();

	printf("-----after------linked list-----\n");
	revers(&head);
	print_list();

}
void print_list()
{
	print_ptr=head;
	int i=1;

	while(print_ptr!=NULL)
	{
		printf("node %d regno:%d name:%s\n",i++,print_ptr->regno,print_ptr->name);
		print_ptr=print_ptr->next;
	}
}

void sort_list()
{
	int i,j,k,m,size=0;
	struct node *current;
	struct node *sort;
        char *temp =malloc(100);
        
	 k=size;
	for(i=0;i<size;i++,k--)
	{ 
		current=head;
		sort=head->next;
		for(j=0;j<k;j++)
		{
			if(current->regno,sort->regno)
			{
				m=current->regno;
				current->regno=sort->regno;
			        sort->regno=m;
			}

			if(strcmp(current->name,sort->name)>0)
			{
				temp=current->name;
				current->name=sort->name;
				sort->name=temp;
			}
			current =current->prev;
			sort= sort->prev;
		}
	}
}
