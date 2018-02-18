//==============================================================
// Name        : validateBTS.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Check if a binary tree is a binary search tree
//==============================================================

#include <iostream>
#include "tree.h"

bool checkBST(Node* n, int *last)
{
	if(n == NULL) return true;

	if(checkBST(n->left,last) == false) return false;

	if(*last != -1000000 && n->key < *last) return false;

	*last = n->key;

	if(checkBST(n->right,last) == false) return false;

	return true;
}

int main()
{
	int last = -1000000;
	Tree T;

	T.insert(50);
    T.insert(30);
    T.insert(20);
    T.insert(40);
    T.insert(70);
    T.insert(60);
    T.insert(80);

	Node* r = T.get_root();

	cout << checkBST(r,&last) << endl;

	return 0;
}