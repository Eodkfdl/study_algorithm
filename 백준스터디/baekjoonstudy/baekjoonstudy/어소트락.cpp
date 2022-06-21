#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Create Base" << endl;
	}
	virtual ~Base()
	{
		cout << "Delete Base" << endl;
	}
	void FuncA()
	{
		cout << "FuncA - Base" << endl;
	}
	virtual void FuncB()
	{
		cout << "FuncB - Base" << endl;
	}
};
class Derived : public Base
{
public:
	Derived()
	{
		cout << "Create Derived" << endl;
	}
	virtual ~Derived()
	{
		cout << "Delete Derived" << endl;
	}
	void FuncA()
	{
		cout << "FuncA - Derived" << endl;
	}
	virtual void FuncB()
	{
		cout << "FuncB - Derived" << endl;
	}
};
class temp
{
	char m_strName;
	int m_iValue;
	double m_dValue;

public:
	virtual void print() {};
};
class temp2
{
	int* m_iSize;

	virtual void print() {};
};
class temp3 {
	virtual void print() {};
};
template <class T>
bool Store(T money, T count, T price) {
	return money >= price * count;
}

double pow_int(double base, int exp)
{
	double result = 1.;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1; //0000 0000
		base *= base;
	}
	return result;
}

void main()
{
	Derived A;
	Base* B = static_cast<Base*>(&A);
	temp t;
	cout << "temp "<<sizeof(temp) <<"temp3"<<sizeof(temp3);
	A.FuncA();
	B->FuncA();

	A.FuncB();
	B->FuncB();
	cout << pow(2, 4);
	cout << Store(1, 2147483649, 2);
}
