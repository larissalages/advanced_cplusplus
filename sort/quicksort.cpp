#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v)
{
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int swap(vector<int> &v,int a,int b)
{
	int aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

int partition(vector<int> &v, int start, int end)
{
	int x = v[end];
	int i = start-1;

	for(int j=start; j< end; j++)
	{
		if(v[j] <= x)
		{
			//swap v[i] and v[j]
			i++;
			swap(v,i,j);
		}
	}
	swap(v,i+1,end);
	return i+1;
}

void quicksort(vector<int> &v,int start,int end)
{
	if (start < end)
	{
		int p = partition(v,start,end);
		quicksort(v,start,p-1);
		quicksort(v,p+1,end);
	}

}

int main()
{
	vector<int> list_numbers = {9,5,7,2,100,55,12,0,7,6};

	cout << "vector UNsorted:" << endl;
	print_vector(list_numbers);

	quicksort(list_numbers,0,list_numbers.size()-1);

	cout << "vector sorted:" << endl;
	print_vector(list_numbers);

}

