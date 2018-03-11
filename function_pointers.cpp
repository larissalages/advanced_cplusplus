#include <iostream>

using namespace std;

void test(int value)
{
	cout << "Number: " << value << endl;
}

int main()
{
	test(7);

	//Declare a point to a function that returns void and receives an int as a parameter
	void (*pTest)(int);

	//The name of the function is the adress of the function
	pTest = test;

	pTest(10);

	return 0;
}