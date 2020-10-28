#include<stdio.h>
#include<stdlib.h>

typedef int item_type;

typedef struct node
{
   	item_type info;
   	struct node* next;
}node;

typedef struct
{
   node* start;
   node* end;	
}list;

void init(list*);
node* create(item_type item);
int size(node* start);
void display(node* start);
node* search(node* start,item_type item);
node* previous(node* ptr,item_type item);
void insertlast(list* lp,item_type item);
void insertfirst(list* lp,item_type item);
void insertsortedlist(list* lp,item_type item);
void insertgivenplace(list* lp,item_type item,int p);
item_type largest(node* ptr);
item_type smallest(node* ptr);
item_type deletefirst(list* lp);
item_type deletelast(list* lp); 


int isempty(node* ptr);

int isempty(node* ptr)
{
	return ptr==NULL;
}

void init(list* lp)
{
	lp->start = NULL;
	lp->end = NULL;
}

node* create(item_type item)
{
	node* ptr = (node*)malloc(sizeof(node));
	
	if(ptr==NULL)
	{
		puts("Memory is full!");
		return NULL;
	}
	
	ptr->info = item;
	ptr->next = NULL;
	
	return ptr;
}

void insertlast(list* lp,item_type item)
{
	node* ptr = create(item);
	
	if(ptr==NULL)
	   return;
	   
	if(isempty(lp->start))
	   lp->start = ptr;
	else
	   lp->end->next = ptr;
	lp->end = ptr;	
}

int size(node* ptr)
{
	int c;
	for(c=0;ptr;ptr = ptr->next,c++);
	return c;
}
void display(node* ptr)
{
	for(;ptr!=NULL;ptr = ptr->next)
	  printf("%d ",ptr->info);
}
node* search(node* ptr,item_type item)
{
	for(;ptr!=NULL;ptr = ptr->next)
	  if(ptr->info == item)
	     break;
    return ptr;
}

node* previous(node* ptr,item_type item)
{
	node* pre;
	for(pre=NULL;ptr!=NULL;pre=ptr,ptr = ptr->next)
	{
		if(ptr->info==item)
		    return pre;
	}
	return NULL;
}


void insertfirst(list* lp,item_type item)
{
	node* ptr = create(item);
	
	if(ptr==NULL)
	   return;
	   
	if(isempty(lp->start))
	   lp->end = ptr;
	else
	   ptr->next = lp->start;
	lp->start = ptr;		
}

void insertaftergiven(list* lp,item_type item,item_type given)
{
	node* ptr,*gptr = search(lp->start,given);
	if(gptr == NULL)
	   return;
	ptr = create(item);
	
	if(gptr==lp->end)
	   lp->end = ptr;
	else
	  ptr->next = gptr->next;
	gptr->next = ptr;
}
void insertbeforegiven(list* lp,item_type item,item_type given)
{
	node* pre = previous(lp->start,given),*ptr;
	if(pre!=NULL)
	{
		ptr = create(item);
		if(ptr==NULL)
		   return;
		ptr->next = pre->next;
		pre->next = ptr;
	}
	if(!isempty(lp->start) && lp->start->info==given)
	{
		ptr=create(item);
		if(ptr==NULL)
		  return;
		ptr->next = lp->start;
		lp->start=ptr;  
	}
}

void insertsortedlist(list* lp,item_type item)
{
	node *ptr,*pre,*temp;
	ptr = create(item);
	if(ptr==NULL)
	   return;
    for(pre=NULL,temp=lp->start;temp!=NULL;pre=temp,temp=temp->next)
	  if(item < temp->info)
	     break;
	if(isempty(lp->start))	
	{
	   lp->start = ptr;
	   lp->end = ptr;	
	}   
	else if(pre!=NULL && temp!=NULL)
	{
		ptr->next = temp;
		pre->next = ptr;
	}
	else if(pre==NULL)
	{
		ptr->next = lp->start;
		lp->start = ptr;
	}
	else
	{
		pre->next = ptr;
		lp->end = ptr;
	}
}

void insertgivenplace(list* lp,item_type item,int p)
{
	node *pre,*temp,*ptr;
	int i,count = size(lp->start);
	if(p<1 || p>count+1)
	{
		puts("Invalid Position");
		return;
	}
	ptr = create(item);
	for(pre=NULL,temp=lp->start,i=0;i<p-1;i++,pre=temp,temp=temp->next);
	if(isempty(lp->start))
	{
	   lp->start=ptr;
	   lp->end=ptr;
	}
	else if(pre!=NULL&&temp!=NULL)
	{
		ptr->next =temp;
		pre->next = ptr;
	}
	else if(pre==NULL)
	{
		ptr->next = lp->start;
		lp->start = ptr;
	}
	else
	{
		pre->next = ptr;
		lp->end = ptr;
	}
}
item_type largest(node* ptr)
{ 
   item_type large = ptr->info;
   for(ptr = ptr->next;ptr;ptr=ptr->next)
   {
   	  if(large < ptr->info)
   	     large = ptr->info;
   }
   return large;
}
item_type smallest(node* ptr)
{ 
   item_type small = ptr->info;
   for(ptr = ptr->next;ptr;ptr=ptr->next)
   {
   	  if(small > ptr->info)
   	     small = ptr->info;
   }
   return small;
}
item_type deletefirst(list* lp)
{
	item_type item;
	node* ptr;
	if(isempty(lp->start))
	{
		puts("List isempty!");
		return 0;
	}
	ptr = lp->start;
	item = ptr->info;
	if(lp->start==lp->end)
	   lp->end = NULL;
	lp->start = ptr->next;
	
	free(ptr);
	return item;
}

item_type deletelast(list* lp)
{
   item_type item;
   node* ptr,*pre,*temp;
   if(isempty(lp->start))	
   {
   	  puts("List is empty!");
   	  return 0;
   }
   ptr = lp->end;
   item = ptr->info;
   for(pre=NULL,temp=lp->start;temp->next;pre=temp,temp=temp->next);
   if(lp->start == lp->end)
   	  lp->start = lp->end = NULL;
   else
   {
   	  lp->end = pre;
	   pre->next = NULL;
   }
   free(ptr);
   return item;
}

