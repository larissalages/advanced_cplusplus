//=================================================================================
// Name        : queueStack.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Implementation of a queue with two stacks
//=================================================================================

#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
	stack<int> newStack;
	stack<int> oldStack;
public:
	int size()
	{
		return newStack.size() + oldStack.size();
	}
	
	void add(int data)
	{
		newStack.push(data);
	}

	void shiftStacks()
	{
		if(oldStack.empty())
		{
			while(!newStack.empty())
			{
				oldStack.push(newStack.top());
				newStack.pop();
			}
		}
	}
	
	int remove()
	{
		shiftStacks();
		oldStack.pop();
	}

	int peek()
	{
		shiftStacks();
		return oldStack.top();
	}

	void cleanAndPrintStack()
	{
		shiftStacks();
		while(!oldStack.empty())
		{
			cout << oldStack.top() << endl;
			oldStack.pop();
		}
		shiftStacks();
		while(!oldStack.empty())
		{
			cout << oldStack.top() << endl;
			oldStack.pop();
		}
	}
};


int main()
{
	MyQueue q;

	q.add(1);
	q.add(2);
	q.add(3);
	q.add(4);
	q.add(5);
	q.remove();
	q.remove();

	q.cleanAndPrintStack();

	return 0;
}