#include <iostream>
#include "linked_list.h"


node* sum_list(node* l1, node* l2, int carry)
{	
	if(l1 == NULL and l2 == NULL and carry == 0)
	{
		return NULL;
	}

	int value = carry;

	if(l1 != NULL)
	{
		value += l1->data;
	}
	if(l2 != NULL)
	{
		value += l2->data;
	}

	node* l3 = new node;
	l3->data = value % 10; //get the second digit

	if(value > 9) carry = 1;
	else carry = 0;

	if(l1 != NULL || l2 != NULL)
	{
		l3->next = sum_list(l1==NULL? NULL:l1->next,l2==NULL? NULL:l2->next,carry);
	}
	return l3;

}


int main()
{
	linked_list list1;
	linked_list list2;

	list1.insertEnd(7);
	list1.insertEnd(1);
	list1.insertEnd(6);
	node* head1 = list1.get_head();

	list2.insertEnd(5);
	list2.insertEnd(9);
	list2.insertEnd(2);
	node* head2 = list2.get_head();

	node* head3 = sum_list(head1, head2, 0);

	for(node* n = true_head3; n != NULL; n = n->next)
	{
		std::cout << n->data;
		if(n->next != NULL) std::cout << "->";
	}
	std::cout << std::endl;

	return 0;
}