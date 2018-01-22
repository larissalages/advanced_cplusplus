//=================================================================================================
// Name        : delete_middle_node.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Delete a node in the middle of a singy linked list, given only acess to that node.
//=================================================================================================

#include <iostream>
#include "linked_list.h"

using namespace std;


void removeNode(node* n)
{
	if(n == NULL || n->next == NULL)
	{
		return;
	}

	node* temp = n->next;
	n->data = n->next->data;
	n->next = n->next->next;
	delete temp;
	
}

int main()
{
	linked_list list;

	list.insertEnd(5);
	list.insertEnd(8);
	list.insertEnd(10);
	list.insertEnd(9);
	list.insertEnd(2);
	list.insertEnd(1);
	list.print();

	node* n = list.searchNode(9);

	removeNode(n);
	list.print();

	return 0;
}
