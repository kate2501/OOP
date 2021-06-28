#include "pch.h"
#include <iostream>
using namespace std;

class Polygon
{
protected:
	double **x;
	int q;
	double *l;
public:
	Polygon(int n)
	{
		cout << "Enter ordered vertices" << endl;
		q = n;
		l = new double[q];
		x = new double*[n];
		for (int i = 0; i < n; i++)
		{
			x[i] = new double[2];
			for (int j = 0; j < 2; j++)
				cin >> x[i][j];
		}
	};
	void Show() { 
		for (int i = 0; i < q; i++)
		{
			cout << x[i][0] << " " << x[i][1] << endl;
		}
			
	}
	double findper();
	double findsq();
	double ** getx() { return x; }
	~Polygon()
	{
		delete[] l;
		for (int i = 0; i < q; i++)
			delete[]x[i];
		delete[]x;

	}
};

double Polygon::findper()
{
	double p = 0;
	for (int i = 1; i < q; i++)
	{
		l[i - 1] = sqrt(pow(x[i][0] - x[i - 1][0], 2) + pow(x[i][1] - x[i - 1][1], 2));
		p += l[i-1];
	}
	l[q - 1] = sqrt(pow(x[q - 1][0] - x[0][0], 2) + pow(x[q - 1][1] - x[0][1], 2));
	p += l[q-1];
	return p;
}

double Polygon::findsq()
{
	double s = 0;
	for (int i = 0; i < q - 1; i++)
		s += x[i][0] * x[i + 1][1] - x[i + 1][0] * x[i][1];
	s += x[q - 1][0] * x[0][1] - x[0][0] * x[q - 1][1];
	s /= 2;
	return s;
}

class Triangle :public Polygon
{
public:
	Triangle() :Polygon(3) {};
	double *intmed();
	double *intbis();
	double *inthei();
	double * bislength();
	double * medlength();
};

double *Triangle::bislength()
{
	double *len = new double[3];
	double p = this->findper() / 2;
	len[0] = 2 * sqrt(l[0] * l[1] * p*(p - l[2])) / (l[0] + l[1]);
	len[1] = 2 * sqrt(l[0] * l[2] * p*(p - l[1])) / (l[0] + l[2]);
	len[2] = 2 * sqrt(l[1] * l[2] * p*(p - l[0])) / (l[1] + l[2]);
	return len;
}

double *Triangle::medlength()
{
	double *len = new double[3];
	len[0] = sqrt(2 * pow(l[0], 2) + 2 * pow(l[1], 2) - pow(l[2], 2)) / 2;
	len[1] = sqrt(2 * pow(l[1], 2) + 2 * pow(l[2], 2) - pow(l[0], 2)) / 2;
	len[2] = sqrt(2 * pow(l[0], 2) + 2 * pow(l[2], 2) - pow(l[1], 2)) / 2;
	return len;
}

double * Triangle::intmed()
{
	double p[2];
	double xx = 0, yy = 0;
	for (int i = 0; i < 3; i++)
	{
		xx += x[i][0];
		yy += x[i][1];
	}
	p[0] = xx / 3;
	p[1] = yy / 3;
	cout << p[0] << " " << p[1] << endl;
	return p;
}

double *Triangle::intbis()
{
	double *p = new double[2];
	double per = this->findper();
	p[0] = (x[0][0] * l[1] + x[1][0] * l[2] + x[2][0] * l[0]) / per;
	p[1]= (x[0][1] * l[1] + x[1][1] * l[2] + x[2][1] * l[0]) / per;
	return p;
}

double *Triangle::inthei()
{
	double t, num, den;
	double *p = new double[2];
	num = (x[1][0] - x[0][0]) / (x[2][1] - x[1][1]);
	num -= (x[1][1] - x[0][1]) / (x[1][0] - x[2][0]);
	den = (x[0][0] - x[2][0]) / (x[1][0] - x[2][0]);
	den -= (x[2][1] - x[0][1]) / (x[2][1] - x[1][1]);
	t = num / den;
	p[0] = x[1][0] + (x[2][1] - x[0][1])*t;
	p[1] = x[1][1] + (x[0][0] - x[2][0])*t;
	cout << p[0] << " " << p[1];
	return p;
}


int main()
{
	Polygon *p;
	Triangle t;
	p = &t;
	p->Show();
	double * intp = new double[2];
	intp = t.inthei();
	cout << endl;
	cout<<t.findsq();
};

