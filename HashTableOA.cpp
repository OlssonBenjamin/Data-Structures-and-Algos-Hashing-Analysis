#include "HashTableOA.h"

HashTableOA::HashTableOA(int size)
{
	collisions = 0;
	loadFactor = 0.0f;
	numEntries = 0;
	hashVector.resize(size);
	tableSize = size;

	for (int i = 0; i < hashVector.size(); i++) //Set every entry in the vector to -1 to act as a "empty" index
	{
		hashVector[i] = -1;
	}

	double log = log2(tableSize);
	int pow = ceil(log);
	double logSquare = log2((3 * tableSize) * (3 * tableSize));
	int powSquare = ceil(logSquare);
	int difference = powSquare - pow;
	remove = difference / 2;
}

void HashTableOA::insertKeyMod(int key) //The index is calculated the same way, but how the key is added at that index is different
{
	numEntries++;
	int index = key % tableSize;
	bool added = false;
	if (hashVector[index] >= 0) //If this index has an element greater than or equal to zero, then it already has had a key added to it
	{
		collisions++; //A collision has occurred because this index was full
		for (int i = index + 1; i < hashVector.size(); i++) //Starting at the next index, move through the vector until an index that is empty is found
		{
			if (hashVector[i] < 0)
			{
				hashVector[i] = key;
				added = true;
				break;
			}
		}
		if (!added) //Every vector beyond the original index was full, thus start at the beginning of the vector and loop until the index before the original calculated index
		//Eventually, an index will be found, unless the load factor is already 1, but that won't happen in these tests
		{
			for (int i = 0; i < index; i++)
			{
				if (hashVector[i] < 0)
				{
					hashVector[i] = key;
					break;
				}
			}
		}
	}
	else 
		hashVector[index] = key; //If the original index is already empty, put the key in that index
	loadFactor = (float)numEntries / (float)tableSize; //Recalculate the load factor for the data set
}

void HashTableOA::insertMidSquare(int key)
{
	numEntries++;
	int index = key * key;
	int power = pow(2, remove);
	index /= power;
	index %= tableSize;
	bool added = false;
	if (hashVector[index] >= 0)
	{
		collisions++;
		for (int i = index + 1; i < hashVector.size(); i++)
		{
			if (hashVector[i] < 0)
			{
				hashVector[i] = key;
				added = true;
				break;
			}
		}
		if (!added)
		{
			for (int i = 0; i < index; i++)
			{
				if (hashVector[i] < 0)
				{
					hashVector[i] = key;
					break;
				}
			}
		}
	}
	else
		hashVector[index] = key;
	loadFactor = (float)numEntries / (float)tableSize;
}

float HashTableOA::getLoadFactor() const
{
	return loadFactor;
}

int HashTableOA::getCollsions() const
{
	return collisions;
}

