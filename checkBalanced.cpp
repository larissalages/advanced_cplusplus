//============================================================
// Name        : checkBalanced.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Check if a binary tree is balanced.
//============================================================

#include <iostream>
#include <cmath> 
#include <string>
#include "tree.h"

using namespace std;

int getHeight(Node* n)
{
	if(n == NULL) return 0;

	int left = getHeight(n->left);
	if(left==-1) return -1;

	int right = getHeight(n->right);
	if(right==-1) return -1;

	if(abs(right-left) > 1) return -1;
	else
	{
		int max = (right > left) ? right : left;
		return 1+ max;
	}

}

bool isBalanced(Node* root)
{
	return getHeight(root)==-1 ? false : true;
}

int main()
{
	Tree T;

	T.insert(50);
    T.insert(30);
    T.insert(20);
    T.insert(40);
    T.insert(70);
    T.insert(60);
    T.insert(80);

    Node* r = T.get_root();

    string result = isBalanced(r) == true ? "true" : "false";

    cout << "Is the tree balanced? "<<result << endl;

	return 0;
}