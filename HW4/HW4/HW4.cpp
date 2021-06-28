#include "pch.h"
#include <iostream>
using namespace std;

template <class T> class myVector
{
	T* arr;
	int size;
public:
	myVector() { size = 0; arr = new T[size]; }
	myVector(int size);
	~myVector() { size = 0; delete[] arr; arr = new T[size]; }
	void push(T d);
	void show();
	T operator [](int ind) { return arr[ind]; }
	int sizearr() { return size; }
	void bubblesort();
	void insertsort();
	void quicksort(int l, int h);
	int findind(int l, int h);
	void swap(T *a, T*b) 
	{
		T temp; 
		temp = *a;
		*a = *b;
		*b = temp;
	}

};

template <class T> 
void myVector<T>::push(T d)
{
	T * temp = new T[size+1];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	temp[size] = d;
	delete[] arr;
	arr = temp;
	size++;
}

template <class T> 
myVector <T>::myVector(int s)
{
	T* temp = new T[s];
	size = s;
	cout << "Enter " << s << " elements" << endl;
	for (int i = 0; i < s; i++) 
	{
		T t;
		cin >> t;
		temp[i] = t;
	}
	arr = temp;
}

template <class T> 
void myVector<T>::bubblesort()
{
	T temp;
	for(int i=0;i<size;i++)
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

template <class T> 
void myVector<T>::insertsort()
{
	for (int i = 1; i < size; i++)
	{
		T temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp <= arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}


template <class T> 
int myVector<T>::findind(int l, int h)
{
	T p = arr[h];
	int i = l-1;
	for (int j = l; j < h; j++)
	{
		if (arr[j] <= p)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[h]);
	return i + 1;
}

template <class T>
void myVector<T>::quicksort(int l, int h)
{
	if(l<h)
	{
		int p = findind(l, h);
		quicksort(l, p - 1);
		quicksort(p + 1, h);
	}
}

template <class T> 
void myVector<T>::show()
{
	for (int i = 0; i < size; i++)
		cout << arr[i]<<" ";
}

int main()
{
	myVector<char> vec(5);
	vec.push('a');
	vec.show();
	cout << endl;
	vec.quicksort(0, 5);
	vec.show();
	cout << endl;
	myVector<int> vec1(6);
	vec1.bubblesort();
	vec1.show();
	cout << endl;
	myVector<double> vec2(4);
	vec2.insertsort();
	vec2.show();
}

