// the result is not a perfect one for at some points it may crash down
// there can be unavoidable space,and the best measure should be the distance to it

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	bool attach[510][510];
	int distance[510], distance_t[510];
	memset(attach, false, sizeof(attach));
	queue <int> node;

	cin >> N >> L >> E; cin.ignore();
	for (int i = 0; i < N; i++)
	{
		distance[i] = 1001;//max of load
	}
	for (int i = 0; i < L; i++) {
		int N1; // N1 and N2 defines a link between these nodes
		int N2;
		cin >> N1 >> N2; cin.ignore();
		attach[N1][N2] = true;
		attach[N2][N1] = true;
	}
	for (int i = 0; i < E; i++) {
		int EI; // the index of a gateway node
		cin >> EI; cin.ignore();
		node.push(EI);
		distance[EI] = 0;
	}

	// game loop
	while (1) {
		memcpy(distance_t, distance, sizeof(distance));
		queue <int> node_t = node;
		int SI; // The index of the node on which the Skynet agent is positioned this turn
		cin >> SI; cin.ignore();
		int result = -1;


		while (!node_t.empty())
		{
			int tempNode = node_t.front();
			int tempD = distance_t[tempNode];
			node_t.pop();

			for (int i = 0; i < N; i++)
			{
				if (attach[tempNode][i] && distance_t[i] > tempD + 1)
				{
					if (SI == i)
					{
						result = tempNode;
					}
					distance_t[i] = tempD + 1;
					node_t.push(i);
				}
			}

		}


		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;

		// Example: 0 1 are the indices of the nodes you wish to sever the link between
		if (result != -1)
		{
			cout << SI << ' ' << result << endl;
			attach[SI][result] = false;
			attach[result][SI] = false;
		}
		else// if there is no way to the des or already reach the des  output a randon number in case the pro crash down
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = i + 1; j < N; j++)
				{
					if (attach[j][i])
					{
						cout << i << ' ' << j << endl;
						attach[i][j] = false;
						attach[j][i] = false;
					}
				}
			}
			// if no edge is printed out means there are no edges in the graph
		}
	}
}