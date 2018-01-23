//=================================================================================================
// Name        : partition.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : 
   // Cracking the coding interview edition 6
   // Problem 2.4 Partition:
   // Write code to partition linked list around a value x, such that
   // nodes less than x come before all the nodes greater than or equal to x.
   // If x is in the list, the values of x only need to be after the elements less
   // than x.
   // Example
   // 3-->5-->8-->5-->10-->2-->1 (x = 5)
   // 3-->1-->2-->10-->5-->5-->8
//=================================================================================================

#include <iostream>
#include "linked_list.h"

using namespace std;

//method 1
linked_list partition(node* head, int p)
{
	linked_list new_list;

	if(!(head == NULL || head->next == NULL))
	{
		for(node* n=head;n != NULL; n=n->next)
		{
			if(n->data < p)
			{
				new_list.insertFront(n->data);
			}
			else
			{
				new_list.insertEnd(n->data);
			}
		}
	}
	
	return new_list;
}

node* partition2(node* head, int p)
{
	node* bf_head = NULL;
	node* bf_tail = NULL;
	node* aft_head = NULL;

	if(!(head == NULL || head->next == NULL))
	{		
		for(node* n=head;n != NULL; n=n->next)
		{
			if(n->data < p)
			{
				node* new_nb = new node;
				new_nb->data = n->data;
				new_nb->next = bf_head;

				if(bf_tail == NULL)
				{
					bf_tail = new_nb;
				}

				bf_head = new_nb;
			}
			else
			{
				node* new_na = new node;
				new_na->data = n->data;
				new_na->next = aft_head;

				aft_head = new_na;
			}
		}
		bf_tail->next = aft_head;
	}
	return bf_head;
}

int main()
{
	linked_list list;

	list.insertEnd(1);
	list.insertEnd(2);
	list.insertEnd(10);
	list.insertEnd(5);
	list.insertEnd(8);
	list.insertEnd(5);
	list.insertEnd(3);
	list.print();

	node* h = list.get_head();

	cout<< "First method" << endl;
	linked_list lst = partition(h, 5);
	lst.print();

	cout<< "Second method" << endl;
	node* partitioned_list = partition2(h, 5);

	for(node* n = partitioned_list; n != NULL; n = n->next)
	{
		cout << n->data;
		if(n->next != NULL) cout << "->";
	}
	cout << endl;


	return 0;
}