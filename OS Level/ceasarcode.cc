#include <string>
#include <iostream>
#include <srdlib>
using namespace std;

string ceasarcijfer(string normaal, int rotatie)
{
	for(unsigned int i=0; index <=normaal.size(); index++)
	{
		if(normaal[i] >='a' && normaal[i] <= 'z')
		{
			normaal[i] = ' a' + ((normaal[i] -'a' + rotatie) % 26);
		}
		if(normaal[i] >= 'A' && normaal[i] <='Z')
		{
			normaal[i] = 'A' + ((normaal[i] -'a' + rotatie) %26);
		}
	}
	return normaal;
}

int main(inr argc, char* argv[])
{
	int rotation = atoi(argv[1]);
	string tekst;
	getline(cin, tekst);
	string cijfer = ceasarcijfer(tekst, rotation);
	cout << cijfer <<"\n";
}