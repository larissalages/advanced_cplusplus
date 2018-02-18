#ifndef STACK_H
#define STACK_H_H

struct node
{
	int data;
	node* next;
};

class Stack
{
private:
	node* top;
	int len;

public:

	Stack()
	{
		top = NULL;
		len = 0;	
	}

	node* peek()
	{
		return top;
	}

	int length()
	{
		return len;
	}

	void push(int data)
	{
		node* n = new node;
		n->data = data;
		n->next = top;
		top = n;
		len++;
	}

	int pop()
	{
		if(top!=NULL)
		{
			int data = top->data;

			node* temp = top;
			top = top->next;
			delete temp;
			len--;

			return data;
		}
		return -1;	
	}

	bool isEmpty()
	{
		return top == NULL;
	}
	
};

#endif