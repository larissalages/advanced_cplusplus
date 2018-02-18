//===============================================================================
// Name        : isunique.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : An algorithm to determine if a string has all unique characters.
//===============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isUnique(string str)
{
	/*
	 * Considering that all strings will come in ASCII code:
	 * If the string has more than 128 characters, te string is repeting some character
	*/
	int ascii_value;

	if(str.length() > 128) return false;

	vector<bool> charAppeared(128,false);

	for(int i=0; i < str.length(); i++)
	{
		ascii_value = (int) str[i];

		if(charAppeared[ascii_value] == true)
		{
			return false;
		}
		charAppeared[ascii_value] = true;
	}
	return true;
}

int main()
{
	string str1("Brazil");
	cout << str1 << " is unique?: " << isUnique(str1) <<endl; 

	string str2("United States of America");
	cout << str2 << " is unique?: " << isUnique(str2) <<endl; 

	return 0;
}