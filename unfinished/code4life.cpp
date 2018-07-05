//https://www.codingame.com/multiplayer/bot-programming/code4life
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
enum gamestate
{
	update,


};

struct Player
{
	string target;
	int eta;
	int score;
	int storageA;
	int storageB;
	int storageC;
	int storageD;
	int storageE;
	int expertiseA;
	int expertiseB;
	int expertiseC;
	int expertiseD;
	int expertiseE;
};

struct Sample 
{
	int sampleId;
	int carriedBy;
	int rank;
	string expertiseGain;
	int health;
	int costA;
	int costB;
	int costC;
	int costD;
	int costE;

};

/**
* Bring data on patient samples from the diagnosis machine to the laboratory with enough molecules to produce medicine!
**/
int main()
{
	int projectCount;
	cin >> projectCount; cin.ignore();
	for (int i = 0; i < projectCount; i++) {
		int a;
		int b;
		int c;
		int d;
		int e;
		cin >> a >> b >> c >> d >> e; cin.ignore();
	}

	// game loop
	while (1) {
		Player mine, opponent;
		for (int i = 0; i < 2; i++) {
			Player *obj = i == 0 ? &mine : &opponent;
			cin >> obj->target >> obj->eta >> obj->score >> obj->storageA >> obj->storageB >> obj->storageC >> obj->storageD >> obj->storageE >> 
				obj->expertiseA >> obj->expertiseB >> obj->expertiseC >> obj->expertiseD >> obj->expertiseE; cin.ignore();
		}
		int availableA;
		int availableB;
		int availableC;
		int availableD;
		int availableE;
		cin >> availableA >> availableB >> availableC >> availableD >> availableE; cin.ignore();
		int sampleCount;
		cin >> sampleCount; cin.ignore();
		vector<Sample> sampleRecord;
		for (int i = 0; i < sampleCount; i++) {
			Sample newsample;

			cin >> newsample.sampleId >> newsample.carriedBy >> newsample.rank >> newsample.expertiseGain >> newsample.health >> 
				newsample.costA >> newsample.costB >> newsample.costC >> newsample.costD >> newsample.costE; cin.ignore();
			sampleRecord.push_back(newsample);
		}

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;

		cout << "GOTO DIAGNOSIS" << endl;
	}
}