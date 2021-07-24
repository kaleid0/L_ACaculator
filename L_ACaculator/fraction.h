#pragma once
#include <iostream>

using namespace std;

class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction():numerator(0),denominator(1){}
	fraction(int m,int n):numerator(m),denominator(n){}

	double value()const{ return (double)numerator / (double)denominator; }

	friend ostream& operator << (ostream& os, fraction& f); //使用友元函数就可以不用类名.的方式使用函数
	friend istream& operator >> (istream& in, fraction& f);
	friend fraction tofraction(int n);

	fraction operator+(const fraction f);
	fraction operator-(const fraction f);
	fraction operator*(const fraction f);
	fraction operator/(const fraction f);

	fraction operator+(const int f);
	fraction operator-(const int f);
	fraction operator*(const int f);
	fraction operator/(const int f);

	void operator+=(const int f);
	void operator+=(const fraction f);
	void operator-=(const int f);
	void operator-=(const fraction f);
	void operator*=(const int f);
	void operator*=(const fraction f);
	void operator/=(const int f);
	void operator/=(const fraction f);

	fraction& operator-();

	fraction adjust();
};

//fraction tofraction(int n)
//{
//	fraction result(n, 1);
//	return result;
//}
