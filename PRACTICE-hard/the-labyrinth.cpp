#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

class point
{
public:
	int x;
	int y;
	int dir;
	point(int tx, int ty, int td) :x(tx), y(ty), dir(td) {}
};
/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int R; // number of rows.
	int C; // number of columns.
	int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
	cin >> R >> C >> A; cin.ignore();

	bool reachedC = false;
	bool searchedAll = false;
	vector<int>road;
	// game loop

	while (1)
	{
		int KR; // row where Kirk is located.
		int KC; // column where Kirk is located.
		cin >> KR >> KC; cin.ignore();

		vector<string> map;
		for (int i = 0; i < R; i++)
		{
			string ROW; // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
			cin >> ROW; cin.ignore();
			map.push_back(ROW);
		}

		if (map.at(KR).at(KC) == 'C')
		{
			reachedC = true;
			searchedAll = true;
		}
		bool des[101][201];

		if (!searchedAll)
		{
			memset(des, 0, sizeof(des));
			int aR[] = { -2,-1,0,1,2,-2,2,-2,2,-2,2,-2,-1,0,1,2 };
			int aC[] = { -2,-2,-2,-2,-2,-1,-1,0,0,1,1,2,2,2,2,2 };
			// set the destination to be two cells from the unknown area 
			// it's the destination recorded by 0
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (map.at(i).at(j) == '?')
					{
						for (int k = 0; k < 16; k++)
						{
							int tempR, tempC;
							tempR = max(min(i + aR[k], R - 1), 0);
							tempC = max(min(j + aC[k], C - 1), 0);
							des[tempR][tempC] = true;
						}
					}
				}
			}
		}

		bool searched[101][201];
		memset(searched, 0, sizeof(searched));

		queue<point> node_t;
		//  0
		// 1 2
		//  3
		int aR[] = { -1,0,0,1 };
		int aC[] = { 0,-1,1,0 };
		searched[KR][KC] = true;
		for (int k = 0; k < 4; k++)
		{
			int tempR = KR + aR[k];
			int tempC = KC + aC[k];
			if (tempR < R && tempR >= 0 && tempC < C && tempC >= 0)
			{
				if (map.at(tempR).at(tempC) != '#' && map.at(tempR).at(tempC) != 'C')
				{
					node_t.push(point(tempR, tempC, k));
					searched[tempR][tempC] = true;
				}
			}
		}
		int result = -1;



		while (!node_t.empty())
		{
			point tempNode = node_t.front();
			node_t.pop();
			if (!searchedAll)// still trying to find control room
			{
				if (true == des[tempNode.x][tempNode.y])
				{
					result = tempNode.dir;
					break;
				}
			}

			for (int k = 0; k < 4; k++)
			{
				int tempR = tempNode.x + aR[k];
				int tempC = tempNode.y + aC[k];
				if (tempR < R && tempR >= 0 && tempC < C && tempC >= 0)
				{
					if (map.at(tempR).at(tempC) != '#' && map.at(tempR).at(tempC) != 'C' && !searched[tempR][tempC])
					{
						searched[tempR][tempC] = true;
						node_t.push(point(tempR, tempC, tempNode.dir));
					}
				}
			}

		}

		if (result == -1)
		{
			searchedAll = true;
			memset(searched, 0, sizeof(searched));
			searched[KR][KC] = true;
			for (int k = 0; k < 4; k++)
			{
				int tempR = KR + aR[k];
				int tempC = KC + aC[k];
				if (tempR < R && tempR >= 0 && tempC < C && tempC >= 0)
				{
					if (map.at(tempR).at(tempC) != '#')
					{
						node_t.push(point(tempR, tempC, k));
						searched[tempR][tempC] = true;
					}
				}
			}

			while (!node_t.empty())
			{
				point tempNode = node_t.front();
				node_t.pop();
				if (!reachedC)//already found C but hasn't reached it
				{
					if (map.at(tempNode.x).at(tempNode.y) == 'C')
					{
						result = tempNode.dir;
						break;
					}
				}
				else// return to the starting place
				{
					if (map.at(tempNode.x).at(tempNode.y) == 'T')
					{
						result = tempNode.dir;
						break;
					}
				}


				for (int k = 0; k < 4; k++)
				{
					int tempR = tempNode.x + aR[k];
					int tempC = tempNode.y + aC[k];
					if (tempR < R && tempR >= 0 && tempC < C && tempC >= 0)
					{
						if (map.at(tempR).at(tempC) != '#' && !searched[tempR][tempC])
						{
							searched[tempR][tempC] = true;
							node_t.push(point(tempR, tempC, tempNode.dir));
						}
					}
				}

			}
		}
		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;
		//cout << "RIGHT" << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
		switch (result)
		{
		case 0:
			cout << "UP" << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
			break;
		case 1:
			cout << "LEFT" << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
			break;
		case 2:
			cout << "RIGHT" << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
			break;
		default:
			cout << "DOWN" << endl; // Kirk's next move (UP DOWN LEFT or RIGHT).
			break;
		}
	}
}