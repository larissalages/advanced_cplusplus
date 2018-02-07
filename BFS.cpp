//======================================================================================================
// Name        : BFS.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Breadth-First Search Algorithm, to find if exist a route between two vertices in a graph
//======================================================================================================

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Vertex
{
	char key;
	Vertex* next; //list that will contain the adjacents vertices
};

class Graph
{
private:
	vector<Vertex*> V;
	int size;
public:
	Graph(vector<char> names)
	{	
		for(int i=0;i<names.size();i++)
		{
			Vertex* nv = new Vertex;
			nv->next = NULL;
			nv->key = names[i];			
			V.push_back(nv);
		}

	}

	void addEdge(char v, char w)
	{
		int index1;
		bool find1 = false,find2 = false;

		for(int i=0;i<V.size();i++)
		{			
			if(V[i]->key == v)
			{
				index1 = i;
				find1 = true;
			} 
			if(V[i]->key == w)
			{
				find2 = true;
			} 
		}
		if(find1 and find2)
		{
			Vertex* ne = new Vertex;
			ne->key = w;
			ne->next = NULL;

			//add new node in the end of the list
			Vertex* n = V[index1];
			while(n->next!= NULL) n=n->next;
			n->next = ne;
		}
		else if(!find1) cout << v <<" not found" << endl;
		else if(!find2) cout << w <<" not found" << endl;

	}

	void printGraph()
	{
		for(int i=0;i<V.size();i++)
		{
			for(Vertex* n=V[i];n!=NULL;n=n->next)
			{
				cout << n->key << "->";
			}
			cout << endl;
		}
	}

	int searchIndexVertex(char key)
	{
		for(int i=0;i<V.size();i++)
		{
			if(V[i]->key==key) return i; 
		}
		return -1;
	}

	bool BFS(char start, char end)
	{
		if(start==end) return true;

		queue<char> q;
		vector<bool> visited (V.size(),false);
		int index;
		Vertex* n;

		q.push(start);

		while(!q.empty())
		{
			index = searchIndexVertex(q.front()); //get the vectors index of the element of the queue

			q.pop();

			if(V[index]->key == end) return true;

			if(visited[index]==false) visited[index] = true;

			for(n=V[index]->next;n!=NULL;n=n->next)
			{
				int i = searchIndexVertex(n->key);
				if(visited[i] == false) q.push(n->key);			 
			}

		}
		return false;
	}
};

int main()
{
	static const char arr[] = {'a','b','c','d','e'};
	vector<char> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );

	Graph graph(v);
	graph.addEdge('a','b');
	graph.addEdge('a','c');
	graph.addEdge('b','d');
	graph.addEdge('b','e');
	graph.addEdge('d','e');
	graph.addEdge('d','c');

	graph.printGraph();

	string result = graph.BFS('a','e') ? "True":"False";

	cout << "Is there a path? "<< result << endl;

	return 0;
}