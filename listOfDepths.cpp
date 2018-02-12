//=====================================================================================================
// Name        : listOfDepths.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Algorithm which creates a linked list of all the nodes at each depth of a binary tree
//=====================================================================================================

#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

struct NodeList
{
	Node* t;
	NodeList* next;
};

vector<NodeList*> createListOfDepths(Node* root)
{
	vector<NodeList*> v;
	bool allNULL;
	bool isRoot;
	int i;

	NodeList* rootPrev = new NodeList;
	rootPrev->t = root;
	rootPrev->next = NULL;
	v.push_back(rootPrev);

	i =1;
	do
	{
		allNULL = true;
		isRoot = true;

		//Get the previous list
		NodeList* prev = v[i-1];

		//create current List
		NodeList* curr = new NodeList;
		curr->next = NULL; 

		while(prev!=NULL)
		{
			if(prev->t->left != NULL)
			{
				if(isRoot)
				{
					curr->t = prev->t->left;
					v.push_back(curr);
					isRoot = false;
				}
				else
				{
					NodeList* nCurr = new NodeList;
					nCurr->next = NULL;
					nCurr->t = prev->t->left;
					curr->next = nCurr;
					curr = curr->next;
				}

				allNULL = false;
			}
			if(prev->t->right != NULL)
			{
				if(isRoot)
				{
					curr->t = prev->t->right;
					v.push_back(curr);
					isRoot = false;
				}
				else
				{
					NodeList* nCurr = new NodeList;
					nCurr->next = NULL;
					nCurr->t = prev->t->right;
					curr->next = nCurr;
					curr = curr->next;
				}
				allNULL = false;
			}

			prev = prev->next;
		}

		i++;

	}while(allNULL == false);

	return v;
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
   
    vector<NodeList*> vt = createListOfDepths(T.get_root());

    for(int i=0;i<vt.size();i++)
    {
    	for(NodeList* n = vt[i]; n != NULL ;n=n->next)
    	{
    		cout << n->t->key << "->"; 
    	}
    	cout << endl;
    }

	return 0;
}