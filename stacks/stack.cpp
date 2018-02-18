#include <iostream>

using namespace std;

struct node
{
	int data;
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

	void push(int data)
	{
		node* n = new node;
		n->data = data;
		n->next = top;
		top = n;
	}

	int pop()
	{
		if(top!=NULL)
		{
			int data = top->data;

			node* temp = top;
			top = top->next;
			delete temp;

			return data;
		}
		return -1;	
	}

	bool isEmpty()
	{
		return top == NULL;
	}

};

int main()
{
	Stack stk;

	stk.push(1);
	stk.push(3);
	stk.push(5);
	stk.push(10);

	while(!stk.isEmpty())
	{
		cout << stk.pop() << endl;
	}

	return 0;
}