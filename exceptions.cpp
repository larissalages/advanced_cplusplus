//============================================================================
// Name        : exceptions.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : Your copyright notice
// Description : This file contains several examples of how to use exception in C ++
//============================================================================

#include <iostream>

void myException()
{
	bool error1 = true;

	if(error1)
	{
		throw -1;
	}
	
}

int main()
{
	using namespace std;

	try{
		myException();
	}catch(int e){
		cout << "Exception number: " << e << endl;
	} 

}