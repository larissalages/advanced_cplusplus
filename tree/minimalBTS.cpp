//=======================================================================================================
// Name        : minimalBFS.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Binary Search Tree of a sorted array with minimal height
//=======================================================================================================

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node (int x): data(x), left(NULL), right(NULL) {};
};

void preOrder(Node* node)
{
	if(node != NULL)
	{
		cout << node->data << endl;
		preOrder(node->left);
		preOrder(node->right);
	}
}

Node* createMinimalBTS(vector<int> array,int low,int high)
{
	if(array.empty() || low>high)
	{
		return NULL;
	}
	int mid = (low+high)/2;

	Node* n = new Node(array[mid]);

	n->left =  createMinimalBTS(array,low,mid-1);
	n->right = createMinimalBTS(array,mid+1,high);
	return n;
}

int main()
{
	vector<int> array = {1,2,3,4,5,6,7};
	
	Node* root = createMinimalBTS(array,0,array.size()-1);
	preOrder(root);

	return 0;
}
