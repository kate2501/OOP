// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


using namespace std;

class ClassA

{

public:

	ClassA() { cout << "one"; };

	ClassA(int) { cout << "two"; };

	ClassA(ClassA&) { cout << "tree"; };

};

//Какое из следующих выражений противоречит синтаксису С++

int main() {

	// your code goes here

	ClassA A;//1

	ClassA B = ClassA(2);//2

	ClassA C(2);//3

	ClassA D();//4.


}
