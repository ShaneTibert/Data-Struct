#include <iostream> 
#include <string>

using namespace std;

#define SIZE 94

#define DEBUG TRUE;


int hashfn(string keyString)
{
	int i, sum, address;

	sum = 0;
	int len = keyString.length();
	for (i = 0; i < len; i++)
		sum += (int)keyString[i]; 

	address = sum % SIZE;

	return address;


}
#ifdef DEBUG
#endif