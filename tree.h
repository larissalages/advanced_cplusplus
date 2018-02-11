#ifndef TREE_H
#define TREE_H

#include <iostream>

using namespace std;

struct Node { 
  int key; 
  Node* left;
  Node* right; 
};

class Tree
{
private:
	Node* root;

	Node* search(int key, Node* n)
	{	
		if(n == NULL) return n;

		if(n->key == key) return n;

		if(key < n->key) return search(key,n->left);
		else return search(key,n->right);
	}

	void insert(int key, Node* n)
	{
		if(this->root == NULL)
		{
			this->root = new Node;
			this->root->key = key;
			this->root->left = NULL;
			this->root->right = NULL;

			return;
		}

		if(key < n->key)
		{
			if(n->left != NULL) insert(key,n->left);
			else
			{
				n->left = new Node;
				n->left->key = key;
				n->left->left = NULL;
				n->left->right = NULL;
			}
		}
		else
		{
			if(n->right != NULL) insert(key,n->right);
			else
			{
				n->right = new Node;
				n->right->key = key;
				n->right->left = NULL;
				n->right->right = NULL;
			}
		}
	}

	void destroy(Node* n)
	{
		if(n != NULL)
		{
			destroy(n->left);
			destroy(n->right);
			delete n;
		}
	}

	void removeTwoChildren(Node* current)
	{
		Node* parent = current->right;
		if(parent->left == NULL)
		{
			current->key = parent->key;
			current->right = NULL;
			delete parent;
		}
		else
		{
			while(parent->left->left != NULL) //Search the minimal element of the right subtree
			{
				parent = parent->left;
			}
			current->key = parent->left->key;
			Node* temp = parent->left;
			parent->left = NULL;
			delete temp;
		}

	}
	void remove(int key, Node* n)
	{	
		
		if(n==NULL) return;

		if(key == n->key) //remove root
		{
			if(n->left == NULL and n->right == NULL) //Node does not have children
			{
				delete n;
				root = NULL;
			}
			else if(n->left != NULL and n->right == NULL) //Node has only one child
			{
				Node* temp = root;
				root = n->left;
				delete temp;
			}
			else if(n->right !=NULL and n->left == NULL) //Node has only one child
			{
				Node* temp = root;
				root = n->right;
				delete temp;
			}
			else //Node has two children
			{
				removeTwoChildren(root);
			}
		}

		else if(key < n->key)
		{


			if(n->left != NULL && n->left->key == key)
			{
				
				Node* current = n->left;

				if(current->left == NULL and current->right == NULL) //Node does not have children
				{
					n->left = NULL;
					delete current;
				}
				else if(current->left != NULL and current->right == NULL) //Node has only one child
				{

					n->left = current->left;
					delete current;
				}
				else if(current->right !=NULL and current->left == NULL) //Node has only one child
				{
					n->left = current->right;
					delete current;
				}
				else //Node has two children
				{
					removeTwoChildren(current);
				}
			}

			else remove(key,n->left);
		}
		else if(key > n->key)
		{
			cout << n->left->key << endl << endl;
			if(n->right != NULL && n->right->key == key)
			{
				Node* current = n->right;

				if(current->left == NULL and current->right == NULL) //Node does not have children
				{
					n->right = NULL;
					delete current;
				}
				else if(current->left != NULL and current->right == NULL) //Node has only one child
				{
					n->right = current->left;
					delete current;
				}
				else if(current->right !=NULL and current->left == NULL) //Node has only one child
				{
					n->right = current->right;
					delete current;
				}
				else //Node has two children
				{
					removeTwoChildren(current);
				}
			}
			else remove(key,n->right);
		}


	}

	void printPreOrder(Node* n)
	{
		if(n == NULL) return;

		cout << n->key << endl;

		printPreOrder(n->left);
		printPreOrder(n->right);
	}

public:

	Tree()
	{
		root = NULL;
	}

	Node* get_root()
	{
		return root;
	}

	void insert(int key)
	{
		insert(key, root);
	}

	void remove(int key)
	{
		remove(key, root);
	}

	Node* search(int key)
	{
		return search(key, root);
	}

	void destroy()
	{
		destroy(root);
	}

	void printPreOrder()
	{
		printPreOrder(root);
	}
};

#endif