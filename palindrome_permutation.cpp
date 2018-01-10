//==================================================================================================
// Name        : exceptions.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Given a string, to write a function to check if it is a permutation of a palindrome.
//===================================================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mapChar(char c)
{
	if('A' <= c and c <='Z')
	{
		c = tolower(c);
	}

	return (int) c - (int) 'a';
}

bool isPermPalindrome(string str)
{
	int index;
	int count_odd = 0;

	vector<int> count_occ(26,0);

	//count the amount of each character in the string
	for(int i=0;i<str.length();i++)
	{
		index= mapChar(str[i]);
		count_occ[index]++;
	}

	//if the string is a palindrome (or a permutation of a palindrome) it has at most one character that has the amount odd.
	for(int j=0;j<count_occ.size();j++)
	{
		if(count_occ[j] % 2 == 1)
		{
			count_odd++;
			if(count_odd>1)
			{
				return false;
			}
		}
	}
	return true;
}

void printUser(string str)
{
	cout << str << " is a Permutation of a Palindrome? "<<isPermPalindrome(str) << endl;
}

int main()
{
	printUser("Anna");
	printUser("asa");
	printUser("TactCoa");
	printUser("aabcaa");

	return 0;
}