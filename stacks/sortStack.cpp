//============================================================================
// Name        : sortStacks.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Sort a stack such that the smallest items are on the top.
//============================================================================

#include <iostream>
#include <stack>

using namespace std;

stack<int> sortStack(stack<int> s)
{
	int value;
	stack<int> r;

	while(!s.empty())
	{
		value = s.top();
		s.pop();
		while(!r.empty() and value<r.top())
		{
			s.push(r.top());
			r.pop();
		}
		r.push(value);

	}

	while(!r.empty())
	{
		s.push(r.top());
		r.pop();
	}
	return s;

}

void cleanALL(stack<int> s)
{
	while(!s.empty())
	{
		cout << s.top() <<endl;
		s.pop();
	}
}

int main()
{
	stack<int> stk;

	stk.push(3);
	stk.push(10);
	stk.push(5);
	// stk.push(7);
	// stk.push(1);
	// stk.push(9);
	// stk.push(12);

	stk=sortStack(stk);
	cleanALL(stk);

	return 0;
}