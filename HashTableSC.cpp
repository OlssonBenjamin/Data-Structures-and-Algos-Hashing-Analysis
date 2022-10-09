#include "HashTableSC.h"


HashTableSC::HashTableSC(int size)
{
	collisions = 0; //Initialize all variables to 0 so that they are incremented correctly
	loadFactor = 0.0f;
	numEntries = 0;
	hashVector.resize(size);
	tableSize = size;

	double log = log2(tableSize); 
	int pow = ceil(log);
	double logSquare = log2((3 * tableSize) * (3 * tableSize));
	//Taking the log(base 2) of the tableSize and log(base 2) of the maximum possible number that key^2 can be will determine what to divide key^2 by when calculating the index for a mid square insertion
	int powSquare = ceil(logSquare);
	int difference = powSquare - pow;
	remove = difference / 2;
	//int difference is the difference in the number of binary digits between pow and powSquare
	//remove should be divided by 2 because half the digits should be removed from the front and half should be removed from the back
}

void HashTableSC::insertKeyMod(int key) 
{
	//Every time something is inserted, numEntries should be incremented so that the load factor is correct
	numEntries++;
	int index = key % tableSize; //Calculate the index key should be placed at by calculating key mod tableSize
	if (!hashVector[index].empty()) //If the list at this index is not empty, then a collision has occurred, so collisions should be incremented
		collisions++;
	hashVector[index].push_front(key); //The latest key should always be at the front of the list
	loadFactor = (float)numEntries / (float)tableSize; //Recalculate load factor based on the increased number of entries
}

void HashTableSC::insertMidSquare(int key) 
{
	numEntries++;
	int index = key * key; //First square the key
	int power = (int)pow(2, remove); 
	index /= power; //Remove half of the necessary "binary" digits as calculated in the constructor
	index %= tableSize; //Remove the other half of the digits by taking the index mod tableSize, completing the calculation of the mid square index
	if (!hashVector[index].empty())
		collisions++;
	hashVector[index].push_front(key);
	loadFactor = (float)numEntries / (float)tableSize;
}

float HashTableSC::getLoadFactor() const
{
	return loadFactor;
}

int HashTableSC::getCollsions() const 
{
	return collisions;
}
