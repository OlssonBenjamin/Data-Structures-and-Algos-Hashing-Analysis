#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include "HashTableSC.h"
#include "HashTableOA.h"

using namespace std;

//Random number generator from lab in Programming Fundamentals 2
random_device rd;
mt19937 gen(rd());
int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(gen);
}

void LoadData(ofstream& fileStream, int collisions, float loadFactor) //This function loads the number of collisions and the load factor on one line separated by a comma
{
	stringstream collisionStream;
	collisionStream << collisions;
	string collisionString(collisionStream.str());
	stringstream loadFactorStream;
	loadFactorStream << loadFactor;
	string loadFactorString(loadFactorStream.str());
	fileStream << loadFactorString;
	fileStream << ",";
	fileStream << collisionString;
	fileStream << "\n"; //The data will be loaded as a csv, which I can then open in excel so I can create graphs of the data
}

int main()
{
	int tableSize = 0;
	cout << "Enter table size: ";
	cin >> tableSize; //The table size is decided by the user upon starting the program
	
	//Four different files are opened, with each file holding data from a collision resolution scheme/hash function combination
	string fileName1 = "SepChainKeyMod";
	stringstream fileNumber1;
	fileNumber1 << tableSize;
	string num1(fileNumber1.str());
	fileName1 = fileName1 + num1 + "a.csv";
	ofstream file1(fileName1);

	string fileName2 = "SepChainMidSquare";
	stringstream fileNumber2;
	fileNumber2 << tableSize;
	string num2(fileNumber2.str());
	fileName2 = fileName2 + num2 + "a.csv";
	ofstream file2(fileName2);

	string fileName3 = "OpenAddKeyMod";
	stringstream fileNumber3;
	fileNumber3 << tableSize;
	string num3(fileNumber3.str());
	fileName3 = fileName3 + num3 + "a.csv";
	ofstream file3(fileName3);

	string fileName4 = "OpenAddMidSquare";
	stringstream fileNumber4;
	fileNumber4 << tableSize;
	string num4(fileNumber4.str());
	fileName4 = fileName4 + num4 + "a.csv";
	ofstream file4(fileName4);

	HashTableSC chainKM(tableSize); //Separate chaining collision resolution with key mod tableSize hash function
	HashTableSC chainMS(tableSize); //Separate chaining collision resolution with mid square hash function
	HashTableOA openKM(tableSize); //Open addressing collision resolution with key mod tableSize hash function
	HashTableOA openMS(tableSize); //Open addressing collision resolution with mid square hash function
	for (int i = 0; i < tableSize; i++)
	{
		int random = Random(0, tableSize);

		chainKM.insertKeyMod(random);
		LoadData(file1, chainKM.getCollsions(), chainKM.getLoadFactor());

		chainMS.insertMidSquare(random);
		LoadData(file2, chainMS.getCollsions(), chainMS.getLoadFactor());

		openKM.insertKeyMod(random);
		LoadData(file3, openKM.getCollsions(), openKM.getLoadFactor());

		openMS.insertMidSquare(random);
		LoadData(file4, openMS.getCollsions(), openMS.getLoadFactor());
		//Each implementation recieves the same number, which reduces the bias in the testing
	}
	file1.close();
	file2.close();
	file3.close();
	file4.close();
}


