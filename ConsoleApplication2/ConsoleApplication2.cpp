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

		cout << amountOfNumbers << endl << endl;

		for (int i = 0, multiplicationValue = 1; i < (amountOfNumbers - 1); ++i, multiplicationValue = 1)
		{
			for (int j = 0; j < (amountOfNumbers - 1 - i); ++j)
				multiplicationValue *= 10;
			
			temp /= multiplicationValue;

			wartosc[i + 1] = temp + 48;
			/*
			cout << wartosc[i + 1] << endl;
			cout << temp << endl;
			cout << endl;
			*/
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
	DuzaLiczba temp(1000);
	DuzaLiczba temp1(temp);



	temp1.printNumber();

	getchar();

    return 0;
}

