#include "pch.h"
#include <iostream>
using namespace std;

struct stack{
	int num;
	stack *next;
};

class Stack
{
	stack *top; //указатель на вершину стека
public:
	Stack() { top = nullptr; };
	Stack(const Stack&st);
	~Stack();
	void push(int a);
	void del();
	void show();
	bool check();
	Stack operator+(Stack st);
};

Stack::Stack(const Stack&st)
{
	stack *moveA,*moveB,*temp;
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
	stack*p,*temp;
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
	stack*temp, *p, *q, *s,*k;
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
	Stack a;
	int n, m, *m1, *m2;
	cout << "Enter n" << endl;
	cin >> n;
	m1 = new int[n];
	cout << "Enter elements for m1" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> m1[i];
		a.push(m1[i]);
	}

	cout << endl;
	a.show();
	Stack b;
	cout << "Enter m" << endl;
	cin >> m;
	m2 = new int[m];
	cout << "Enter elements for m2" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> m2[i];
		b.push(m2[i]);
	}
	cout << endl;
	b.show();
	//b.del();
	cout << endl;
	b.show();
	cout << " m3: ";
	(a + b).show();
	delete[]m1;
	delete[]m2;
}

