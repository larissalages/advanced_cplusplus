//=================================================================================================
// Name        : stackMin.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Implement a function Min in a stack, that has O(1) time.

//=================================================================================================

#include <iostream>

using namespace std;

struct node
{
	int data;
	node* min;
	node* next;
};

class Stack
{
private:
	node* top = NULL;
public:

	node* peek()
	{
		return top;
	}

	node* min()
	{
		if(top!=NULL) return top->min;
		else return NULL;
	}
	
	void push(int data)
	{
		node* n = new node;
		n->data = data;
		n->next = top;

		if(top==NULL || data < top->min->data)
		{
			n->min = n;
		}
		else
		{
			n->min = top->min;
		}
		top = n; 
	}

	node* pop()
	{
	
		if(top!=NULL)
		{
			node* temp = top;
			top = top->next;
			temp->next = NULL;
			return temp;
		}
		return NULL;
	}

	bool isEmpty()
	{
		return top==NULL;
	}


};


int main()
{
	Stack stk;

	stk.push(4);
	stk.push(1);
	stk.push(7);
	stk.push(23);

	cout << "Min value inside the stack:" << endl;
	cout << stk.min()->data << endl;

	cout << "Stack:" << endl; 
	while(!stk.isEmpty())
	{
		cout << stk.pop()->data << endl;
	}

	return 0;
}