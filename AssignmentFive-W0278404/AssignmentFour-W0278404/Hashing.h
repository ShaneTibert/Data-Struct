#pragma once
#ifndef _HASHING_H
#define _HASHING_H

#include <iostream>

using namespace std;

class Hashing
{
private:

	struct bucket{
		string name;
		bucket* next;
	};

public:
	static const int TableLength = 10;
	void Hash(string key);
	void Hash(string key, bucket* currentBuck);
	int HashString(string value);
	bucket* hashTable[TableLength];
	void PrintHashTable();
	void PrintHashTable(bucket* currentBuck, int currentNum);
	void Start();
};

#endif
