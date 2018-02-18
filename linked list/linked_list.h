#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

struct node
{
	int data;
	node *next;
};

//linked_list 
class linked_list
{
private:
	node *head, *tail;
public:

	linked_list()
	{
		head = NULL;
		tail = NULL;
	}

	node* get_head()
	{
		return head;
	}

	node* get_tail()
	{
		return tail;
	}

	node* searchNode(int data)
	{
		node *n = new node;

		for(n = head; n != NULL; n = n->next)
		{
			if(n->data == data)
			{
				return n;
			}
		}
		return NULL;

	}

	void insertFront(int data)
	{
		node *new_node = new node;
		new_node->next = head;
		new_node->data = data;

		if (head==NULL)
		{
			tail = new_node;
		}

		head = new_node;
		
	}

	void insertEnd(int data)
	{
		node *new_node = new node;
		new_node->data = data;
		new_node->next = NULL;

		if(head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
	}

	void insertAfterNode(int data, int data2)
	{
		node *n = new node;

		n = searchNode(data);
		if (n==NULL) std::cout << "Node does not exist!" << std::endl;
		else
		{
			node *new_node = new node;
			new_node->data = data2;
			node *temp = new node;

			temp = n->next;
			new_node->next = temp;
			n->next = new_node;
		}

	}

	void deleteNode(int data)
	{
		node *n = new node;

		for(n = head; n != NULL; n = n->next)
		{
			if(n->next->data == data)
			{
				node *willBdeleted = new node;
				willBdeleted = n->next;

				n->next = willBdeleted->next;
				delete willBdeleted;

				return;
			}
		}
		std::cout << "Node does not exist!" << std::endl;

	}


	void print()
	{
		node *n = new node;

		for(n = head; n != NULL; n = n->next)
		{
			std::cout << n->data;
			if(n->next != NULL) std::cout << "->";
		}
		std::cout << std::endl;
	}
};



#endif