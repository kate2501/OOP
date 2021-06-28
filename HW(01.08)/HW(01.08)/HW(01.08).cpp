#include "pch.h"
#include <string.h>
#include <iostream>
using namespace std;

struct Name
{
	char fname[20], pname[20], lname[20];
};

class Abiturient
{
	Name name;
	char address[30];
	int *marks;
public:
	Abiturient();
	void show();
	int *getmarks();
};

Abiturient::Abiturient()
{
	cout << "Input first name: "; cin >> name.fname;
	cout << "Input patronymic: "; cin >> name.pname;
	cout << "Input surname: "; cin >> name.lname;
	cout << "Input address: "; cin >> address;
	cout << "Input marks: ";
	marks = new int[4];
	for (int i = 0; i < 4; i++) 
		cin >> marks[i];
	cout << "------------------------------------------------";
	cout << endl;
}

void Abiturient::show()
{
	cout << "Name: " << name.lname << " " << name.fname << " " << name.pname << endl;
	cout << "Address: " << address << endl;
	cout << "Marks: ";
	for (int i = 0; i < 4; i++)
		cout<< marks[i]<<" ";
	cout << endl;
	cout << "------------------------------------------------";
	cout << endl;
}

int *Abiturient::getmarks()
{
	return marks;
}

bool checkunsat(int *a, int n)
{
	for (int i = 0; i < n; i++)
		if (*(a + 1) <= 10)
			return true;
	return false;
}
int sum(int *a, int n) 
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += *(a + i);
	return sum;
}
bool checksum(int *a, int n, int k)
{
	if (sum(a, n) >= k) return true;
	else return false;
}

void unsatmarks(Abiturient *ab, int n)
{
	cout << "They have marks lower than 4: " << endl;
	for (int i = 0; i < n; i++)
		if (checkunsat((ab + i)->getmarks(), 4)) (ab + i)->show();
}

void lmarks(Abiturient *ab, int n, int k)
{
	cout << "The sum is more than " << k << " : " << endl;
	for (int i = 0; i < n; i++)
		if (checksum((ab + i)->getmarks(), 4, k)) (ab + i)->show();
}

void sortandshow(Abiturient *ab, int n, int q)
{
	bool exit = false;
	while (!exit)
	{
		exit = true;
		for (int i = 0; i < n - 1; i++)
			if (sum((ab + i)->getmarks(), 4) < sum((ab + i + 1)->getmarks(), 4))
			{
				Abiturient temp = ab[i];
				ab[i] = ab[i + 1];
				ab[i + 1] = temp;
				exit = false;
			}
	}
	cout << "They have max sum" << endl;
	for (int i = 0; i < q; i++)
		(ab + i)->show();
	cout << "They have the same sum" << endl;
	int i = 0;
	int s = sum((ab + q - 1)->getmarks(),4);
	for(int i = 0; i < n; i++)
		if (sum((ab + i)->getmarks(), 4) == s) (ab + i)->show();
}


int main()
{
	int num;
	cout << "Input number of abiturients: "; cin >> num;
	Abiturient *ab = new Abiturient[num];
	for(int i=0;i<num;i++)
		(ab + i)->show();
	unsatmarks(ab, num);
	lmarks(ab, num, 200);
	sortandshow(ab, num, 2);
	delete[] ab;
}

