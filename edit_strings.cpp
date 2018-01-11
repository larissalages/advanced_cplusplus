//============================================================================================================================================================================
// Name        : edit_strings.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Function to check if one string is a edition of the other. That is, it it is an insertion, remotion or replace of the other. Problem 1.5 of "Carcking the Code"
//==============================================================================================================================================================================

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isEdit(string str1,string str2)
{
	int i = 0,j = 0,dif = 0;
	int len1 = (int)str1.length();
	int len2 = (int) str2.length();

	if(abs(len1 - len2) > 1)
	{
		return false;
	}
	
	while(i < str1.length() and j < str2.length())
	{
		if(dif<=1)
		{
			if(str1[i] == str2[j])
			{
				i++;
				j++;
			}
			else
			{
				dif++;
				if(len1 > len2) i++;
				else if(len1 == len2)
				{
					i++;
					j++;
				}
				else j++;
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << isEdit("pale","ple") << endl;
	cout << isEdit("pales","pale") << endl;
	cout << isEdit("pale","bale") << endl;
	cout << isEdit("pale","bake") << endl;
	cout << isEdit("abc","abcde") << endl;
	cout << isEdit("CIn","In") << endl;

	return 0;
}