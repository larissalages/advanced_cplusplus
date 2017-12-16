//============================================================================
// Name        : exceptions.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : Your copyright notice
// Description : This file contains several examples of how to use exception in C ++
//============================================================================

#include <iostream>
#include <string>
#include <exception>

using namespace std;

void goesWrong()
{
	bool error1Detected = true;
	bool error2Dectected = false;

	if(error1Detected)
	{
		throw bad_alloc();
	}
	if(error2Dectected)
	{
		throw exception();
	}
}

void myException()
{
	//It only hadle one exception at time, change the error here to change the exception thrown
	bool error1 = false;
	bool error2 = false;
	bool error3 = true;

	if(error1)
	{
		throw -1;
	}
	if(error2)
	{
		throw "Some problem happened";
	}
	if(error3)
	{
		throw string("Some problem happened again");
	}
	
}

int main()
{
	try{
		myException();
	}catch(int e){
		cout << "Exception number: " << e << endl;
	}catch(char const* e){
		cout << "Exception msg: " << e << endl;
	}catch(string &e){
		cout << "Exception msg: " << e << endl;
	}


	/* Be careful about the order of throwing exceptions.
	 * bad_alloc is a subclass of exception, if you change the order of catch, the bad_alloc exception will be catch in the catch(exception &e).
	 * Probably, at least I hope, the compiler will give you a warning because of that.
	*/
	try{
		goesWrong();
	}
	catch(bad_alloc &e){
		cout << "Catching bad_alloc: " << e.what() <<endl;
	}catch(exception &e){
		cout << "Catching exception: " << e.what() << endl;
	}

	//After throw a exception the program continues
	cout << "Back to the main" << endl;

	return 0;

}