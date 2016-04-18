#include <iostream> 
#include <string>
#include "Hashing.h"

using namespace std;

void Hashing::Start(){
	for (int x = 0; x < TableLength; x++){
		hashTable[x] = NULL();
	}
}
void Hashing::Hash(string key){

	if (hashTable[HashString(key)] == nullptr){
		hashTable[HashString(key)] = new bucket();
		hashTable[HashString(key)]->name = key;
		hashTable[HashString(key)]->next = nullptr;
	}
	else{

		if (hashTable[HashString(key)]->next == nullptr){
			hashTable[HashString(key)]->next = new bucket();
			hashTable[HashString(key)]->next->name = key;
			hashTable[HashString(key)]->next->next = nullptr;
		}
		else{
			Hash(key, hashTable[HashString(key)]->next);
		}
	}
}

void Hashing::Hash(string key, bucket* currentBuck){

	if (currentBuck == nullptr){
		currentBuck = new bucket();
		currentBuck->name = key;
		currentBuck->next = nullptr;
	}
	else{
		Hash(key, currentBuck->next);
	}
}
int Hashing::HashString(string key)
{
	int value = 0;
	for (int i = 0; i < key.length(); i++)
		value += key[i];
	return value % TableLength;
}

void Hashing::PrintHashTable()
{
	for (int x = 0; x < TableLength; x++){
		{
			if (hashTable[x] != nullptr){
				cout << hashTable[x]->name << endl;
				if (hashTable[x]->next != nullptr){
					PrintHashTable(hashTable[x]->next, x);
				}
			}
		}
		cout << "\n-------" << endl;
	}
}
void Hashing::PrintHashTable(bucket* currentBuck, int currentNum){
	if (currentBuck != nullptr){
		cout << currentBuck->name << endl;
		if (currentBuck->next != nullptr){
			PrintHashTable(currentBuck, currentNum);
		}
	}
}