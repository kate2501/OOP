﻿//Определить класс «Дробь» – Fraction в виде пары. 
//Класс должен содержать несколько конструкторов. 
//Реализовать методы для сложения, вычитания, умножения и деления дробей. 
//Перегрузить операции сложения, вычитания, умножения, деления, присваивания и операции отношения. 
//Создать массив объектов и передать его в функцию, 
//которая изменяет каждый элемент массива с четным индексом путем добавления следующего за ним элемента массива.

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

class Fraction
{
	int m;
	int n;
public:
	Fraction();
	Fraction(int m, int n);
	Fraction(string path);
	Fraction(const Fraction&fr);
	~Fraction() { cout << ""; }
	int getnum() { return n; }
	int getdenom() { return m; }
	void reducing();
	Fraction add(Fraction a, Fraction b);
	Fraction mult(Fraction a, Fraction b);
	Fraction divis(Fraction a, Fraction b);
	Fraction sub(Fraction a, Fraction b);
	Fraction operator+(Fraction fr);
	Fraction operator-(Fraction fr);
	Fraction operator*(Fraction fr);
	Fraction operator/(Fraction fr);
	Fraction& operator=(Fraction fr);
	bool operator<(Fraction fr);
	bool operator<=(Fraction fr);
	bool operator>(Fraction fr);
	bool operator>=(Fraction fr);
	bool operator==(Fraction fr);
	bool operator!=(Fraction fr);
	friend ostream& operator<<(ostream& mystream, Fraction &fr);
	friend istream& operator>>(istream& mystream, Fraction &fr);
};

int nod(int m, int n)
{
	if (n == 1 || m == 1) return 1;
	if (n > m)
	{
		int temp = m;
		m = n;
		n = temp;
	}
	int rem = m % n;
	while (rem)
	{
		m = n;
		n = rem;
		rem = m % n;
	}
	return n;
};

int nok(int m, int n)
{
	return m * n / nod(m, n);
}

void Fraction::reducing()
{
	int n = nod(m, (this->n));
	m /= n;
	(this->n) /= n;
	if (this->n < 0)
	{
		m *= -1;
		this->n *= -1;
	}
}

Fraction::Fraction() 
{
	m = rand() % 5 + 1;
	n = rand() % 10 + 1;
	this->reducing();
}

Fraction::Fraction(int m, int n)
{
	m = m;
	n = n;
	//this->reducing();
}

Fraction::Fraction(const Fraction&fr)
{
	m = fr.m;
	n = fr.n;
}

Fraction Fraction::operator+(Fraction fr)
{
	Fraction rab;
	int cd = nok(n, fr.n);
	rab.n = cd;
	rab.m = cd / n * m + cd / fr.n*fr.m;
	return rab;
}

Fraction Fraction::add(Fraction a, Fraction b)
{
	Fraction rab;
	int cd = nok(a.n, b.n);
	rab.n = cd;
	rab.m = cd / a.n * a.m + cd / b.n*b.m;
	return rab;
}

Fraction Fraction::operator-(Fraction fr)
{
	Fraction rab;
	int cd = nok(n, fr.n);
	rab.n = cd;
	rab.m = cd / n * m - cd / fr.n*fr.m;
	return rab;
}

Fraction Fraction::sub(Fraction a, Fraction b)
{
	Fraction rab;
	int cd = nok(a.n, b.n);
	rab.n = cd;
	rab.m = cd / a.n * a.m - cd / b.n*b.m;
	return rab;
}

Fraction Fraction::operator*(Fraction fr)
{
	Fraction rab;
	rab.n = n*fr.n;
	rab.m =m*fr.m;
	rab.reducing();
	return rab;
}

Fraction Fraction::mult(Fraction a, Fraction b)
{
	Fraction rab;
	rab.n = a.n * b.n;
	rab.m = a.m * b.m;
	rab.reducing();
	return rab;
}

Fraction Fraction::operator/(Fraction fr)
{
	Fraction rab;
	rab.n = n * fr.m;
	rab.m = m * fr.n;
	rab.reducing();
	return rab;
}

Fraction Fraction::divis(Fraction a, Fraction b)
{
	Fraction rab;
	rab.n = a.n * b.m;
	rab.m = a.m * b.n;
	rab.reducing();
	return rab;
}

Fraction& Fraction::operator=(Fraction fr)
{
	if (&fr == this)return *this;
	this->m = fr.m;
	this->n = fr.n;
	return *this;
}

bool Fraction::operator<(Fraction fr)
{
	int cd = nok(n, fr.n);
	int temp1 = cd / n * m;
	int temp2 = cd / fr.n * fr.m;
	if (temp1 < temp2) return true;
	return false;
}

bool Fraction::operator>(Fraction fr)
{
	int cd = nok(n, fr.n);
	int temp1 = cd / n * m;
	int temp2 = cd / fr.n * fr.m;
	if (temp1 > temp2) return true;
	return false;
}

bool Fraction::operator>=(Fraction fr)
{
	int cd = nok(n, fr.n);
	int temp1 = cd / n * m;
	int temp2 = cd / fr.n * fr.m;
	if (temp1 >= temp2) return true;
	return false;
}

bool Fraction::operator<=(Fraction fr)
{
	int cd = nok(n, fr.n);
	int temp1 = cd / n * m;
	int temp2 = cd / fr.n * fr.m;
	if (temp1 <= temp2) return true;
	return false;
}

bool Fraction::operator==(Fraction fr)
{
	int cd = nok(n, fr.n);
	int temp1 = cd / n * m;
	int temp2 = cd / fr.n * fr.m;
	if (temp1 == temp2) return true;
	return false;
}

bool Fraction::operator!=(Fraction fr)
{
	int cd = nok(n, fr.n);
	int temp1 = cd / n * m;
	int temp2 = cd / fr.n * fr.m;
	if (temp1 != temp2) return true;
	return false;
}

void change(Fraction*fr, int n)
{
	int temp;
	if (n != 1)
	{
		if (n % 2 == 0) temp = n;
		else temp = n - 1;
		for (int i = 0; i < temp; i += 2)
			fr[i] = fr[i + 1]+fr[i];
	}	
}


ostream& operator<<(ostream& mystream, Fraction &fr)
{
	mystream << fr.m << "/" << fr.n << endl;
	return mystream;
}

istream& operator>>(istream& mystream, Fraction &fr)
{
	cout << "Enter m";
	cin >> fr.m;
	cout << "Enter n";
	cin >> fr.n;
	cout << endl;
	fr.reducing();
	return mystream;
}

int main()
{
	/*int n;
	cout << "Enter n " << endl;
	cin >> n;
	Fraction *fr = new Fraction[n];
	for (int i = 0; i < n; i++)
		cout << fr[i];
	change(fr, n);
	cout << "------" << endl;
	for (int i = 0; i < n; i++)
		cout << fr[i];
	delete[] fr;*/
	//Fraction fr1(1,5);
	
	//cout << fr1;
	string text;
	int s = 0, i = 0;
	string path = "C:/Users/diens/OneDrive/Рабочий стол/text.txt";
	ifstream file(path);
	while (getline(file, text))
		++s;
	file.close();
	Fraction *fr = (Fraction*)operator new(sizeof(Fraction) * s);
	ifstream file1(path);
	while (getline(file1, text))
	{
		new(&fr[i]) Fraction(text);
		i++;
	}
	file1.close();
	for (int i = 0; i < n; i++)
		cout << fr[i];
}


