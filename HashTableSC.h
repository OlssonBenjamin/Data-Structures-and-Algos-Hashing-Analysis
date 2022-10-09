#pragma once
#include <vector>
#include <list>
#include <math.h>
#include <iostream>

using namespace std;

class HashTableSC
{
public:
	HashTableSC(int size);
	void insertKeyMod(int key);
	void insertMidSquare(int key);
	float getLoadFactor() const;
	int getCollsions() const;
private:
	vector<list<int>> hashVector;
	int tableSize;
	float loadFactor;
	int numEntries;
	int collisions;
	int remove;
};

