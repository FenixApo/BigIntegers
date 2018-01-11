// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class DuzaLiczba
{
private:
	char *wartosc;
	char *tempArray;

	int amountOfNumbers = 0;

public:
	DuzaLiczba();
	DuzaLiczba(int);
	DuzaLiczba(const string &);
	DuzaLiczba(const DuzaLiczba &d);
	void printNumber();
	~DuzaLiczba();
};

DuzaLiczba::DuzaLiczba()
{
	tempArray = new char[2];

	tempArray[0] = '+';
	tempArray[1] = '0';

	wartosc = tempArray;

	tempArray = NULL;

	amountOfNumbers = 1;
}

DuzaLiczba::DuzaLiczba(int a)
{
	int temp = a;

	if (a == 0)
	{
		DuzaLiczba();
	}
	else
	{
		while (temp != 0)
		{
			temp /= 10;
			++amountOfNumbers;
		}

		++amountOfNumbers;

		wartosc = new char[amountOfNumbers];

		if (a < 0)
			wartosc[0] = '-';
		else
			wartosc[0] = '+';

		temp = a * 10;

		for (int i = 0, multiplicationValue = 1; i < (amountOfNumbers - 1); ++i, multiplicationValue = 1)
		{
			for (int j = 0; j < (amountOfNumbers - 1 - i); ++j)
			{
				multiplicationValue *= 10;
			}
			
			temp /= multiplicationValue;

			wartosc[i + 1] = temp + 48;
		}

	}
}

DuzaLiczba::DuzaLiczba(const DuzaLiczba & d)
{
	amountOfNumbers = d.amountOfNumbers;
	
	wartosc = new char[amountOfNumbers];

	for (int i = 0; i < amountOfNumbers; ++i)
	{
		wartosc[i] = d.wartosc[i];
	}
}

DuzaLiczba::DuzaLiczba(const string & a)
{
	if (a[0] == '-')
	{
		amountOfNumbers = a.size();

		wartosc = new char[amountOfNumbers];

		wartosc[0] = '-';

		for (int i = 1; i < amountOfNumbers; ++i)
		{
			wartosc[i] = a[i];
		}
	}
	else
	{
		amountOfNumbers = a.size();

		++amountOfNumbers;

		wartosc = new char[amountOfNumbers];

		wartosc[0] = '+';

		for (int i = 1; i < amountOfNumbers; ++i)
		{
			wartosc[i] = a[i - 1];
		}
	}
}

DuzaLiczba::~DuzaLiczba()
{
	delete[] wartosc;
}

void DuzaLiczba::printNumber()
{
	for (int i = 0; i < amountOfNumbers; ++i)
		cout << wartosc[i];
		cout << endl;
}

int main()
{
	DuzaLiczba *temp = new DuzaLiczba(1000);
	
	DuzaLiczba temp1(*temp);

	DuzaLiczba temp2("10000");

	delete temp;

	temp2.printNumber();

	getchar();

    return 0;
}

