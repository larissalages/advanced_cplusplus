#include <iostream>
#include <vector>

using namespace std;

int main()
{
	/* Create a 2D vector with 3 rows and 4 columns
	 * Each row is a vector with 4 elements
	 * Each element will be initialized with the value 1
	 */
	vector< vector<int> > grid(3, vector<int>(4,1));

	for(int row = 0; row < grid.size(); row++)
	{
		for(int col = 0; col < grid[row].size(); col++)
		{
			cout << grid[row][col] << endl;
		}
		cout << endl;
	}

	return 0;
}