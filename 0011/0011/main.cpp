#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int WIDTH = 20;
int ADJACENT[4][3][2] = {
	{{-1, 1},{-2, 2},{-3, 3}},
	{{ 0, 1},{ 0, 2},{ 0, 3}},
	{{ 1, 1},{ 2, 2},{ 3, 3}},
	{{ 1, 0},{ 2, 0},{ 3, 0}}};

// note data is 2d, where item at row x, column y is at data[x*width + y]
void readfile(vector<int>& data)
{
	string strNumber;
	int intNumber, i;
	ifstream myfile("data.txt");
	
	if (myfile.is_open())
	{
		while( myfile.good() )
		{
			getline (myfile, strNumber, ' ');

			intNumber = atoi(strNumber.c_str());

			data.push_back(intNumber);
		}
		myfile.close();
	}

}

int main(int argc, char* argv[])
{
	vector<int> data;
	int size, maxProduct, curProduct;
	int nextIndex, nextCol, curCol;

	readfile(data);
	size = data.size();
	maxProduct =  0;

	for (int i=0; i<size; i++)
	{
		for (int x=0; x<4; x++)
		{
			curProduct = data[i];
			curCol = i % 20;
#if DEBUG
			cout << "i = " << i / 20 << " " << i % 20 << "(" << data[i] << "), ";
#endif
			for (int y=0; y<3; y++)
			{
				nextIndex = i + ADJACENT[x][y][0] * WIDTH + ADJACENT[x][y][1];
				nextCol = nextIndex % 20;
				if (nextIndex >= 0 && nextIndex < size && nextCol >= curCol)
				{
					curProduct = curProduct * data[nextIndex];
#if DEBUG
					cout << nextIndex / 20 << " " << nextIndex % 20 << "(" << data[nextIndex] << "), ";
#endif
				}
				else
					break;
			}
#if DEBUG
			cout << endl;
#endif

			if (curProduct > maxProduct)
			{
				maxProduct = curProduct;

				if (nextIndex >= 0 && nextIndex < size)
				{
					cout << "new largest: " << i / 20 << " " << i % 20 << "(" << data[i] << "), " << " to ";
					cout << nextIndex / 20 << " " << nextIndex % 20 << "(" << data[nextIndex] << "), " << endl;
					cout << maxProduct << endl;
				}
			}
		}
	}

	cout << maxProduct << endl;
}