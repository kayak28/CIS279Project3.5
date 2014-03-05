#include "node1.h"
#include <stdio.h>

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>
using namespace std;

size_t list_length(const node* head_ptr)
// Library facilities used: cstdlib
{

	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;
	
	return answer;

}
 
void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
	head_ptr = new node(entry, head_ptr);
}

void list_insert(node* previous_ptr, const node::value_type& entry) 
{
	node *insert_ptr;
    
	insert_ptr = new node(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
}

node* list_search(node* head_ptr, const node::value_type& target) 
    // Library facilities used: cstdlib
{
	node *cursor;
   
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
}

const node* list_search(const node* head_ptr, const node::value_type& target) 
    // Library facilities used: cstdlib
{
	const node *cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
}

node* list_locate(node* head_ptr, size_t position) 
    // Library facilities used: cassert, cstdlib
{
	node *cursor;
	size_t i;
    
	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
}

const node* list_locate(const node* head_ptr, size_t position) 
    // Library facilities used: cassert, cstdlib
{
	const node *cursor;
	size_t i;
    
	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
}

void list_head_remove(node*& head_ptr)
{
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
}

void list_remove(node* previous_ptr)
{
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
}

void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
{
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
}

void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr) 
    // Library facilities used: cstdlib
{
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;
    
	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;
    
	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( ); 
	while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
}


bool isThere(node* head_ptr, const node::value_type& entry)
{
	node* cursor;
	for (cursor = head_ptr; cursor!=NULL; cursor=cursor->link())
	{
		if (entry == cursor->data())
		{
			return true;
		}
	}
	return false;
}


void list_tail_insert(node *& head_ptr, const node::value_type& entry)
{

	node* cursor;
	node* previous;
	if (head_ptr == NULL)
	{
		return;
	}
	previous= head_ptr;

	for (cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
	{
		previous=cursor;
	}
	previous->set_link(new node(entry,NULL));

	printf("Added successfully\n");
}








void item_remove(node *& head_ptr, const node::value_type& entry)
{

	node* cursor;
	node* previous;

	for (cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
	{
		if (entry==cursor->data())
		{

			previous->set_link(cursor->link());
			printf("Removed successfully\n");
		}
		previous = cursor;
	}

}


/*
void outList(node* head_ptr, ostream& out)
{
	node* cursor;

	printf("List\n");
	for (cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
	{
		printf("  %f  \n",cursor->data());
	}
}
*/

void printList(node* head_ptr)
{
	node* cursor;

	printf("List\n");
	for (cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
	{
		printf("  %f  \n",cursor->data());
	}
}















int main()
{
	node * head=new node(0.11, (node *)NULL);
	node* node1= list_locate(head, 1) ;
	printf("node[1]->data  :  %f\n", node1->data());

	list_insert(head, 0.22);
	node* node2= list_locate(head, 2) ;
	printf("node[1]->data  :  %f\n", node1->data());
	printf("node[2]->data  :  %f\n", node2->data());

	list_insert(node2, 3.33);
	node* node3= list_locate(head, 3) ;
	printf("node[1]->data  :  %f\n", node1->data());
	printf("node[2]->data  :  %f\n", node2->data());
	printf("node[3]->data  :  %f\n", node3->data());

	if (isThere(head, 0.22))
	{
		printf("2 exists.\n");
	}else
	{
		printf("2 not exists.\n");
	}

	if (isThere(head, 0.4))
	{
		printf("4 exists.\n");
	}else
	{
		printf("4 not exists.\n");
	}

	list_tail_insert(head, 0.44);

	node* node4= list_locate(head, 4) ;
	printf("node[1]->data  :  %f\n", node1->data());
	printf("node[2]->data  :  %f\n", node2->data());
	printf("node[3]->data  :  %f\n", node3->data());
	printf("node[4]->data  :  %f\n", node4->data());

	item_remove(head, 0.44);
	node4= list_locate(head, 4) ;
	printf("node[1]->data  :  %f\n", node1->data());
	printf("node[2]->data  :  %f\n", node2->data());
	printf("node[3]->data  :  %f\n", node3->data());
	if (node4==NULL)
	{
		printf("node[4]is deleted\n");
	}else{
		printf("node[4]->data  :  %f\n", node4->data());
	}


	printList(head);


	list_clear(head) ;
	if (head==NULL)
	{
		printf("head is deleted\n");
	}else{
		printf("head->data  :  %f\n", head->data());
	}
}





















