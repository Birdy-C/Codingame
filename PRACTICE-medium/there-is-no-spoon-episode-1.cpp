#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Don't let the machines win. You are humanity's last hope...
**/
int main()
{
	int width; // the number of cells on the X axis
	cin >> width; cin.ignore();
	int height; // the number of cells on the Y axis
	cin >> height; cin.ignore();
	vector <string> map;
	for (int i = 0; i < height; i++) {
		string line; // width characters, each either 0 or .
		getline(cin, line);
		map.push_back(line);
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			if (map.at(j).at(i) == '0')
			{
				cout << i << ' ' << j;
				int t;

				for (t = i + 1; t < width; t++)
				{
					if (map.at(j).at(t) == '0')
					{
						cout << ' ' << t << ' ' << j;
						break;
					}
				}
				if (t == width)	cout << " -1 -1";

				for (t = j + 1; t < height; t++)
				{
					if (map.at(t).at(i) == '0')
					{
						cout << ' ' << i << ' ' << t;
						break;
					}
				}
				if (t == height)	cout << " -1 -1";

				cout << endl;

			}
		}
	}
	// Three coordinates: a node, its right neighbor, its bottom neighbor
	//cout << "0 0 1 0 0 1" << endl;
}