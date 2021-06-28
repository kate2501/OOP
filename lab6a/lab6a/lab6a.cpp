#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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
	Abiturient(string fn);
	void show();
	int *getmarks();
	void rem(string str);
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

Abiturient::Abiturient(string fn="0")
{

	this->rem(fn);
}

void Abiturient::show()
{
	cout << "Name: " << name.lname << " " << name.fname << " " << name.pname << endl;
	cout << "Address: " << address << endl;
	cout << "Marks: ";
	for (int i = 0; i < 4; i++)
		cout << marks[i] << " ";
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
	int s = sum((ab + q - 1)->getmarks(), 4);
	for (int i = 0; i < n; i++)
		if (sum((ab + i)->getmarks(), 4) == s) (ab + i)->show();
}

void Abiturient::rem(string str)
{
	string arr[8];
	istringstream ss(str);
	string word; 
	int i = 0;
	while (ss >> word)
	{
		arr[i] = word;
		i++;
	}
	strcpy_s(name.fname, 20, arr[0].c_str());
	strcpy_s(name.pname, 20, arr[1].c_str());
	strcpy_s(name.lname,20, arr[2].c_str());
	strcpy_s(address, 30, arr[3].c_str());
	marks = new int[4];
	for (int i = 0; i < 4; i++)
		marks[i] = atoi(arr[4 + i].c_str());
}

int main()
{
	//int num;
	//cout << "Input number of abiturients: "; cin >> num;
	string text;
	int s = 0;
	
	ifstream file("C:/Users/diens/OneDrive/Рабочий стол/text.txt");
	while (getline(file, text))
	{
		++s;
	}
	Abiturient *ab = (Abiturient*)operator new(sizeof(Abiturient) * s);
	int i = 0;
	while (getline(file, text))
	{
		new(&ab[i]) Abiturient(text);
		i++;
	}
	file.close();

	//ab[0] = Abiturient("C:/Users/diens/OneDrive/Рабочий стол/text.txt");
	//ab[1]= Abiturient("C:/Users/diens/OneDrive/Рабочий стол/text.txt");
	//for (int i = 0; i < num; i++)
		//(ab + i)->show();
	//unsatmarks(ab, num);s
	//lmarks(ab, num, 200);
	//sortandshow(ab, num, 2);
	//delete[] ab;
	ab[1].show();
	for (int i = 0; i < s; ++i)
		ab[i].~Abiturient();
	//Abiturient ab("katya arturovna belskaya tut 10 10 10 10");

	//ab[1].show();
}


