#include "pch.h"
#include <iostream>
using namespace std;

class Transport
{
protected:
	float speed;
	float cost;
public:
	Transport()
	{
		cout << "Enter speed: ";
		cin >> speed;
		cout << endl; cout << "Enter cost per km: ";
		cin >> cost; cout << endl;
	}
	Transport(float speed, float cost)
	{
		this->speed = speed; this->cost = cost;
	}
	float get_s() { return speed; }
	float get_c() { return cost; }
	void show()
	{
		cout << "Transport speed: " << speed << ", cost: " << cost << endl;
	}
	void set(float s, float c) { speed = s; cost = c; }
	float time(float dist);
	float allcost(float dist);
};

float Transport::time(float dist)
{
	float t = dist / speed;
	cout << "Time: " << t << endl;
	return t;
}

float Transport::allcost(float dist)
{
	float c = dist * cost;
	cout << "Full cost: " << c << endl;
	return c;
}

class Plane :public Transport
{
public:
	Plane() :Transport() {};
	Plane(float sp, float cost) :Transport(sp, cost) {};
	void show()
	{
		cout << "Plane speed: " << speed << ", cost: " << cost << endl;
	};
};

class Train :public Transport
{
public:
	Train() :Transport() {};
	Train(float sp, float cost) :Transport(sp, cost) {};
	void show()
	{
		cout << "Train speed: " << speed << ", cost: " << cost << endl;
	};
};

class Car :public Transport
{
public:
	Car() :Transport() {};
	Car(float sp, float cost) :Transport(sp, cost) {};
	void show()
	{
		cout << "Car speed: " << speed << ", cost: " << cost << endl;
	};
};

int main()
{
	int n, c;
	float t, fc;
	cout << "Enter num of objects: ";
	cin >> n;
	Transport **tr = new Transport*[n];
	cout << endl;
	cout << "Plane - 1, Train - 2, Car - 3" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Choose obj";
		cin >> c;
		switch (c) 
		{
			case 1:
				tr[i] = new Plane();
				break;
			case 2:
				tr[i] = new Train();
				break;
			case 3:
				tr[i] = new Car();
				break;
			default:
				i--;
				break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		tr[i]->show();
		fc = tr[i]->allcost(300);
		t = tr[i]->time(300);
	}

	for (int i = 0; i < n; i++)
		delete tr[i];
	delete[] tr;
}

