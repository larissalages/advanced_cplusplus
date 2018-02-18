#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> numbers;

	//Adding elements in the final of the list
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	//Adding elements in front of the list
	numbers.push_front(0);

	for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{	
		if(*it == 1)
		{	
			//If you don't save the pointer to the next element of the list, you will lost the pointer
			it = numbers.erase(it);
		}
		cout << *it << endl;
	}

	return 0;
}