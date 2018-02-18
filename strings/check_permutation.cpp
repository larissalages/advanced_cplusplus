//=================================================================================
// Name        : check_permutation.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Given two strings, to decide if one is a permutation of the other.
//=================================================================================

#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

bool isPermutation(string str1, string str2)
{
    int chr_value;
    vector<int> cont (128,0);

    /*If the size is diferent, they aren't permutations*/
    if(str1.length() != str2.length())
    {
        return false;   
    }   
  

   for(int i=0;i < str1.length();i++)
   {
        chr_value = (int) str1[i];
        cont[chr_value]++;
  
   }

   for(int i=0;i < str2.length();i++)
   {
        chr_value = (int) str2[i];
        cont[chr_value]--;

        if( cont[chr_value] < 0)
        {
            return false;
        }
        
   }
    return true;
}


int main()
{
    cout<< isPermutation("casa","asac") << endl;
    cout<< isPermutation("Harry Potter","PttoerrryHa ") << endl;
    cout<< isPermutation("aabcd","aaacd") << endl;

    return 0;
}