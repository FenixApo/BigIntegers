// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class DuzaLiczba
{
private:
	char *wartosc;
	char *tempArray;

	int amountOfNumbers = 0;

	void changeStringToCharArray(const string &);

public:
	DuzaLiczba();
	DuzaLiczba(int);
	DuzaLiczba(const string &);
	DuzaLiczba(const DuzaLiczba &d);
	~DuzaLiczba();

	friend istream& operator>> (istream&, DuzaLiczba &);

	void printNumber();
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
	changeStringToCharArray(a);
}

DuzaLiczba::~DuzaLiczba()
{
	delete[] wartosc;
}

istream& operator>> (istream &input, DuzaLiczba & e)
{
	string temp;

	delete[] e.wartosc;

	input >> temp;

	cout << "a" <<temp << "a" << endl;

	getchar();

	e.changeStringToCharArray(temp);
	
	return input;
}

void DuzaLiczba::changeStringToCharArray(const string & a)
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

	DuzaLiczba temp3;

	delete temp;

	cin >> temp3;

	

	temp3.printNumber();

	getchar();
	getchar();

    return 0;
}

