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
	char* recurencyOneAdder(int, char*, char*, int *, bool &);

public:
	DuzaLiczba();
	DuzaLiczba(int);
	DuzaLiczba(const string &);
	DuzaLiczba(const DuzaLiczba &d);
	~DuzaLiczba();

	friend istream& operator>> (istream&, DuzaLiczba &);
	friend ostream& operator<< (ostream&, DuzaLiczba const&);
	DuzaLiczba& operator= (DuzaLiczba const&);
	DuzaLiczba operator+ (DuzaLiczba const&);

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
	if (sizeof(*tempArray) > 1)
		delete[] tempArray;
}

istream& operator>> (istream &input, DuzaLiczba & e)
{
	string temp;

	delete[] e.wartosc;

	input >> temp;

	cin.clear();

cin.ignore(numeric_limits<streamsize>::max(), '\n');

e.changeStringToCharArray(temp);

return input;
}

ostream& operator<< (ostream &output, DuzaLiczba const& e)
{

	for (int i = 0; i < e.amountOfNumbers; ++i)
		output << e.wartosc[i];

	output << endl;

	return output;
}

DuzaLiczba& DuzaLiczba::operator= (DuzaLiczba const& e)
{

	amountOfNumbers = e.amountOfNumbers;

	delete[] wartosc;

	wartosc = new char[amountOfNumbers];

	for (int i = 0; i < amountOfNumbers; ++i)
	{
		wartosc[i] = e.wartosc[i];
	}


	return *this;
}

DuzaLiczba DuzaLiczba::operator+ (DuzaLiczba const& e)
{
	int size1 = amountOfNumbers;
	int size2 = e.amountOfNumbers;
	
	DuzaLiczba temp;

	if (size1 == size2)
	{
		delete[] temp.wartosc;

		temp.wartosc = new char[amountOfNumbers];
		temp.amountOfNumbers = amountOfNumbers;

		for (int i = 0; i < temp.amountOfNumbers; ++i)
		{
			temp.wartosc[i] = wartosc[i];
		}

		if ((e.wartosc[0] == '-') && (temp.wartosc[0] == '-') || (e.wartosc[0] == '+') && (temp.wartosc[0] == '+'))
		{
			for (int i = size1 - 1; i > 0; --i)
			{
				if (((temp.wartosc[i] - 48) + (e.wartosc[i] - 48)) > 9)
				{
					bool checker = false;

					temp.wartosc[i] = ((temp.wartosc[i] - 48) + (e.wartosc[i] - 48) - 10) + 48;

					temp.wartosc = recurencyOneAdder(i - 1, temp.wartosc, e.wartosc, &temp.amountOfNumbers, checker);
				}
				else
				{
					temp.wartosc[i] = ((temp.wartosc[i] - 48) + (e.wartosc[i] - 48) + 48);
				}
			}
		}
	}

	return temp;
}

char* DuzaLiczba::recurencyOneAdder(int i, char* firstArray, char* secondArray, int *amountOfNumbers, bool &checker)
{
	if (checker == true)
	{
		return firstArray;
	}
	else if(i == 0)
	{
		delete[] tempArray;

		tempArray = NULL;

		tempArray = firstArray;

		++*amountOfNumbers;

		firstArray = NULL;

		firstArray = new char[*amountOfNumbers];

		firstArray[0] = tempArray[0];
		firstArray[1] = '1';

		for (int i = 1; i < (*amountOfNumbers - 1); ++i)
		{
			firstArray[i + 1] = tempArray[i];
		}

		checker = true;
		return firstArray;
	}
	else if (((firstArray[i] - 48) + 1) > 9)
	{
		firstArray[i] = '0';
		recurencyOneAdder(i - 1, firstArray, secondArray, amountOfNumbers, checker);
	}
	else
	{
		firstArray[i] = (firstArray[i]+ 1);
		checker = true;
		return firstArray;
	}

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

int main()
{
	DuzaLiczba *temp = new DuzaLiczba(1000);
	
	DuzaLiczba temp1(*temp);

	DuzaLiczba temp2("10000");

	DuzaLiczba temp3;

	delete temp;

	cin >> temp3;

	cout << temp3 << endl;

	cin >> temp2;

	cout << temp2 << endl;

	temp3 = temp3 + temp2;

	cout << temp3 << endl;

	getchar();

    return 0;
}

