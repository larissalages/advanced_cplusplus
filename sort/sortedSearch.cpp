//====================================================================================================================================================================
// Name        : sortedSearch.cpp
// Author      : Larissa Lages de Oliveira
// Version     :
// Copyright   : 
// Description : Given an array-like data struct Listy, which lacks a size method and contains sorted, positive integers, find the index at which an element x occurs.
//====================================================================================================================================================================

#include <iostream>
#include <vector>

using namespace std;

class Listy
{
private:
	vector<int> array;
public:
	void add(int data)
	{
		array.push_back(data);
	}

	int elementAt(int i)
	{
		if(i < array.size()) return array[i];
		else return -1;
	}
};

int BinarySearch(Listy arr,int x, int low, int high)
{
	int mid = (low + high)/2;
	int middle = arr.elementAt(mid);

	if(low > high) return -1;

	if(x < middle || middle == -1)
	{
		return BinarySearch(arr,x,low,mid-1);
	}
	else if(x > middle)
	{
		return BinarySearch(arr,x,mid+1,high);
	}
	else
	{
		return mid;
	}
	
}

int Search(Listy arr,int x)
{
	int i =1;

	if(x == arr.elementAt(0)) return 0;
	
	while(arr.elementAt(i) != -1 && x > arr.elementAt(i)) i *= 2;
	
	return BinarySearch(arr,x,i/2,i);
}


int main()
{
	Listy arr;
	arr.add(1);
	arr.add(2);
	arr.add(5);
	arr.add(10);
	arr.add(13);
	arr.add(15);
	arr.add(20);
	arr.add(21);
	arr.add(25);
	arr.add(30);
	arr.add(50);

	cout << Search(arr,15) << endl;

}