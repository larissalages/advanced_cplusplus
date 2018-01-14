#include <iostream>

using namespace std;

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
		if (n==NULL) cout << "Node does not exist!" << endl;
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
		cout << "Node does not exist!" << endl;

	}


	void print()
	{
		node *n = new node;

		for(n = head; n != NULL; n = n->next)
		{
			cout << n->data;
			if(n->next != NULL) cout << "->";
		}
		cout << endl;
	}
};


int main()
{
	linked_list list;
	list.insertFront(1994);
	list.insertFront(2000);
	list.insertFront(2018);
	list.insertEnd(1993);
	list.insertAfterNode(2000,1995);
	list.print();
	list.deleteNode(2000);
	list.print();
	return 0;
}