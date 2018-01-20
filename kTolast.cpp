//=================================================================================
// Name        : kTolast.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Algorithm to find the kth to last element of a singly linked list.
//=================================================================================

#include <iostream>
#include "linked_list.h"

using namespace std;

node* kToLast(node* head, int k)
{
	if(head==NULL || head->next==NULL)
	{
		return NULL;
	}
	node* p1 = head;
	node* p2 = head;
	
	for(int i=0;i<k;i++)
	{
		if(p1 != NULL)
		{
			p1 = p1->next;
		}
		else
		{
			return NULL;
		}	
	}

	while(p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

int main()
{
	node* h;
	node* n;
	linked_list list;

	list.insertEnd(5);
	list.insertEnd(8);
	list.insertEnd(15);
	list.insertEnd(2);
	list.insertEnd(4);
	list.insertEnd(3);
	list.insertEnd(11);
	list.insertEnd(0);
	list.insertEnd(7);
	list.print();

	h = list.get_head();

	n = kToLast(h,5);

	cout << n->data << endl;

	return 0;
}
