#include "pch.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct stack {
	int num;
	stack *next;
};

class Stack
{
	stack *top; //указатель на вершину стека
public:
	Stack() { top = nullptr; };
	Stack(string text);
	Stack(const Stack&st);
	~Stack();
	void push(int a);
	void del();
	void show();
	bool check();
	Stack operator+(Stack st);
	void write(string path);
};

void Stack::write(string path)
{
	ofstream file;
	file.open(path, fstream::app);
	file << " \n";
	stack *t = top;
	while (t)
	{
		file << t->num << " ";
		t = t->next;
	}
	file << " \n";
	file.close();
}

Stack::Stack(string text)
{
	top = nullptr;
	string arr[5];
	istringstream ss(text);
	string word;
	int i = 0;
	while (ss >> word)
	{
		arr[i] = word;
		i++;
	}
	for (int i = 0; i < 5; i++)
		this->push(atoi(arr[i].c_str()));
};

Stack::Stack(const Stack&st)
{
	stack *moveA, *moveB, *temp;
	moveA = st.top;
	top = nullptr;
	temp = nullptr;
	while (moveA)
	{
		moveB = new stack;
		moveB->num = moveA->num;
		moveB->next = nullptr;
		if (top == nullptr)
		{
			top = moveB;
			temp = moveB;
		}
		else
		{
			temp->next = moveB;
			temp = temp->next;
		}
		moveA = moveA->next;
	}
}

Stack::~Stack()
{
	stack*p, *temp;
	p = top;
	while (p)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
}

void Stack::show()
{
	stack *t = top;
	while (t)
	{
		cout << t->num << " ";
		t = t->next;
	}
}

void Stack::push(int a)
{
	stack *q = new stack;
	q->num = a;
	q->next = top;
	top = q;
}

bool Stack::check()
{
	stack *q = top;
	stack *p;
	while (q)
	{
		p = q->next;
		if (!p) break;
		if (q->num > p->num)
			return false;
		q = q->next;
	}
	return true;
}

Stack Stack::operator+(Stack st)
{
	Stack a;
	stack*temp, *p, *q, *s, *k;
	if (!(this->check() && st.check()))
	{
		cout << "Not satisf. conditions" << endl;
		return a;
	}
	a.top = nullptr;
	temp = nullptr;
	k = nullptr;
	p = top;
	q = st.top;
	while (p&&q)
	{
		s = new stack;
		if (p->num < q->num)
		{
			s->num = p->num;
			p = p->next;
		}
		else
		{
			s->num = q->num;
			q = q->next;
		}
		s->next = nullptr;
		if (a.top == nullptr)
		{
			a.top = s;
			temp = s;
		}
		else
		{
			temp->next = s;
			temp = temp->next;
		}
	}
	if (p != nullptr)
		k = p;
	if (q != nullptr)
		k = q;
	while (k)
	{
		s = new stack;
		s->num = k->num;
		s->next = nullptr;
		temp->next = s;
		temp = temp->next;
		k = k->next;
	}
	return a;
}

void Stack::del()
{
	stack *p;
	p = top;
	top = top->next;
	delete p;
}

int main()
{
	string text1, text2;
	int s = 0, i = 0;
	string path = "C:/Users/diens/OneDrive/Рабочий стол/text4.txt";
	try
	{
		ifstream file;
		file.open(path);
		if (!file) throw 20;
	}
	catch (int exp)
	{
		cout << "This file cant be found";
		exit(1);
	}
	Stack *ab = (Stack*)operator new(sizeof(Stack) * 2);
	ifstream file2(path);
	while (getline(file2, text1))
	{
		new(&ab[i]) Stack(text1);
		i++;
	}
	file2.close();
	ab[0].show();
	cout << endl;
	ab[1].show();
	cout << endl;
	cout << "m3: ";
	(ab[0] + ab[1]).show();
	(ab[0] + ab[1]).write(path);
}


