#include "String.h"
#include<iostream>
const int ArSize = 10;
const int MaxLen = 81;
using namespace STRING;

int main()
{
	using namespace std;
	String name;
	std::cout << "Hi,what is your name\n";
	std::cin >> name;

	cout << name << " ,Please enter " << ArSize << " words\n";
	String sayings[ArSize];//array of objects
	char temp[MaxLen];

	int i;
	for (int i = 0; i < ArSize; i++)
	{
		cout <<( i + 1) << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}

	int total = i;

	cout << "Here are your inputs\n";

	for (i = 0; i < total; i++)
	{
		cout <<(i+1)<< " : " << sayings[i] << endl;
	}

	int shortest = 0;
	int first = 0;

	for (i = 1; i < total; i++)
	{
		if (sayings[i].length() < sayings[shortest].length())
			shortest = i;
		if (sayings[i] < sayings[first])
			first = i;
	}

	cout << "Shortest Word: " << sayings[shortest] << endl;
	cout << "First Alphabetically: " << sayings[first] << endl;
	cout << "The program used " << String::howmany() << " Strings objects\n";
}