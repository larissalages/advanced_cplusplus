#include <iostream>
#include <vector>	
#include "stack.h"

using namespace std;

class SetOfStacks
{
private:
	vector<Stack> set;
	int capacity;
	int size;
public:
	SetOfStacks()
	{
		capacity = 5;
		size =0;
	}

	int numberOfStacks()
	{
		return size;
	}

	void changeCapacity(int value)
	{
		capacity = value;
	}

	void push(int data)
	{
		if(size ==0 || set[size-1].length() >= capacity)
		{
			Stack new_stk;
			new_stk.push(data);
			set.push_back(new_stk);
			cout << "new stack created" <<endl;
			size++;
		}
		else
		{
			set[size-1].push(data);
		}
		
	}

	int pop()
	{
		if(size != 0)
		{	
			Stack top = set[size-1];

			int value = top.pop();

			if(top.length()==0)
			{
				size--;
			}
			return value;

		}
		return -1;
	}

	void cleanALL()
	{
		for(int i=0;i<set.size();i++)
		{
			while(!set[i].isEmpty())
			{
				cout << set[i].pop() <<endl;
			}
			cout<< "next stack" <<endl;
		}
	}
};

int main()
{
	SetOfStacks stcks;
	stcks.push(10);
	stcks.push(2);
	stcks.push(4);
	stcks.push(5);
	stcks.push(8);
	stcks.push(12);

	stcks.push(6);
	stcks.push(0);
	stcks.push(24);
	//stcks.cleanALL();
	// cout << stcks.numberOfStacks()<< endl;
	int v1 = stcks.pop();
	cout << v1 << endl;
	

	return 0;
}