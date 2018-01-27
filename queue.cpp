#include <iostream>

struct node
{
	int data;
	node* next;
};

class Queue
{
private:
	node* first = NULL;
	node* last = NULL;
public:

	node* peek()
	{
		return first;
	}

	void add(int data)
	{
		node* n = new node;
		n->data = data;
		n->next = NULL;

		if(last!=NULL)
		{
			last->next = n;
		}
		else
		{
			first = n;
		}
		last = n;
	}

	void remove()
	{
		node* temp = first;

		if(first!=NULL) first = first->next;

		delete temp;
	}

	bool isEmpty()
	{
		return first == NULL;
	}

	void print()
	{
		for(node* n=first; n!=NULL; n=n->next)
		{
			std::cout << n->data << "->"; 
		}
		std::cout<<std::endl;
	}
};


int main()
{
	Queue queue;
	queue.add(7);
	queue.add(8);
	queue.add(10);
	queue.add(1);
	queue.add(2);
	queue.add(5);
	queue.add(3);

	//before removal
	queue.print();

	queue.remove();
	
	//after removal
	queue.print();

	return 0;	
}