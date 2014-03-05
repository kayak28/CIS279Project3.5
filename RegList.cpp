//RegList.cpp
#include "RegList.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

RegList(int capa)
{
	head = new node();
	capacity = capa;
	manyNodes = 0;
}
void addStudent(int stuId)
{
	head = new node(head, stuId);
	manyNodes++;
}
void removeStudent(int stuId)
{
	node* targetNode;
	targetNode = head->list_search(head, stuId);
	if(targetNode == NULL)
	{
		printf("Target Node Was Not Found\n");
	}
	else
	{
		targetNode->set_data(head->data());
		head = head->link();
		manyNodes--;
		printf("Target Node has been removed\n");
	}
}
int removeFromFront()
{
	head->list_head_remove(head);
	head->printList(head);
}
bool isEnrolled(int stuId)const
{
	if (isThere(head, stuId))
	{
		printf("%d is enrolled.\n",stuId);
	}else
	{
		printf("%d is not enrolled.\n",stuId);
	}

}

ostream& operator<<(ostream& out, const RegList& obj)
{
	out << "Elements in the list"; 
	head->printList(head);
	return out;
}

bool isFull() const
{
	if(capacity == manyNodes)
	{
		return true;
	}
	return false;
}
bool isEmpty() const
{
	if(manyNodes == 0)
	{
		return true;
	}
	return false;
}
int listSize() const
{
	return manyNodes;
}
