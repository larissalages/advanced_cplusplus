//=================================================================================
// Name        : removeDups2.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Remove duplicates from an unsorted list
//=================================================================================

#include <iostream>
#include "linked_list.h"

using namespace std;

void removeDups(node* head)
{
	if(head==NULL || head->next == NULL)
	{
		return;
	}

	node* temp;
	node* n = head;
	node* runner = head;

	while(n != NULL)
	{
		while(runner->next != NULL)
		{
			if(n->data == runner->next->data)
			{
				temp = runner->next;
				runner->next = runner->next->next;
				delete temp;
			}
			else
			{
				runner = runner->next;
			}
		}
		n = n->next;
		runner = n;
	}
}

int main()
{
	node* h = new node;
	linked_list list;

	list.insertEnd(5);
	list.insertEnd(8);
	list.insertEnd(3);
	list.insertEnd(50);
	list.insertEnd(5);
	list.insertEnd(3);
	list.insertEnd(11111);
	list.insertEnd(58);
	list.insertEnd(5);
	list.print();

	h = list.get_head();
	
	removeDups(h);

	list.print();

	return 0;
}