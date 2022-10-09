#pragma once
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class HashTableOA
{
public:
	HashTableOA(int size);
	void insertKeyMod(int key);
	void insertMidSquare(int key);
	float getLoadFactor() const;
	int getCollsions() const;
private:
	vector<int> hashVector;
	int tableSize;
	float loadFactor;
	int numEntries;
	int collisions;
	int remove;
};

