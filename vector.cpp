//============================================================================
// Name        : exceptions.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : Your copyright notice
// Description : This file contains several examples of how to use vectors in C ++
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//The parameter indicates the size of the vector
	vector<string> str(2);

	//Add strings inside vector
	str[0] = "games";
	str[1] = "Need for Speed";

	str.push_back("Super Mario");
	str.push_back("Final Fantasy");
	str.push_back("Injustice");

	cout << "str[0]: "<<str[0] << endl;

	cout << "size str: " << str.size() <<endl;

	//print all contents inside vector using iterator
	for(vector<string>::iterator it = str.begin(); it != str.end(); it++)
	{
		cout << *it << endl;
	}


	return 0;
}