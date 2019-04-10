
  /****************************************/
  /*  Author      : PERUMAL.R             */
  /*  Date        : 10-april-2019         */
  /*  Filename    : single_linedlist.c    */
  /*  Description : single_linkedlist     */
  /****************************************/



#include "single_linkedlist.h"

void prinit_list();
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
	ptr->next=head;
	head=ptr;
}
void revers(struct node **one)
{
 	struct node *prev=NULL;
 	struct node *current= *one;
 	struct node *last;

 	while(current!=NULL)
 	{
	 	last=current->next;
	 	current->next =prev;
	 	prev=current;
	 	current=last;

	}
	*one =prev;
}
int main()
{
	printf("--------sorting linked list---------\n");

	insert_node  (1,"naveen\n");
	insert_node  (2,"perumal\n");
	insert_node  (3,"jeeva\n");
	insert_node  (4,"munui\n");
	insert_node  (5,"ten\n");

	sort_list();
	print_list();

	printf("-----after------shorting-----\n");
	revers(&head);
	print_list();

}
void print_list()
{
	print_ptr=head;
	int i=1;

	while(print_ptr!=NULL)
	{
		printf("node %d\t regno:%d\t name:%s\n",i++,print_ptr->regno,print_ptr->name);
		print_ptr=print_ptr->next;
	}
}

void sort_list()
{
	int i,j,k,size=0;
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
			if(strcmp(current->name,sort->name)>0)
			{
				temp=current->name;
				current->name=sort->name;
				sort->name=temp;
			}
			current =current->next;
			sort= sort->next;
		}
	}
}

