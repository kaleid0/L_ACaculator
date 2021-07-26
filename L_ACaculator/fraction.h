#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class fraction
{
private:
	double numerator;
	int denominator;
public:
	fraction():numerator(0),denominator(1){}
	fraction(double m,int n):numerator(m),denominator(n){}

	double value()const;

	friend ostream& operator << (ostream& os, fraction& f); //使用友元函数就可以不用类名.的方式使用函数
	friend istream& operator >> (istream& in, fraction& f);
	friend fraction tofraction(int n);

	fraction operator+(const fraction f);
	fraction operator-(const fraction f);
	fraction operator*(const fraction f);
	fraction operator/(const fraction f);

	void operator+=(const fraction f);
	void operator-=(const fraction f);
	void operator*=(const fraction f);
	void operator/=(const fraction f);

	template<typename T>
	fraction operator+(T f);
	template <typename T>
	fraction operator-(T f);
	template <typename T>
	fraction operator*(T f);
	template <typename T>
	fraction operator/(T f);

	

	template <typename T>
	void operator+=(T f);
	template <typename T>
	void operator-=(T f);
	template <typename T>
	void operator*=(T f);
	template <typename T>
	void operator/=(T f);

	void fsqrt();
	void power(int n);
	
	fraction& operator-();

	void adjust();
};



//fraction tofraction(int n)
//{
//	fraction result(n, 1);
//	return result;
//}





//模板函数的bug？？？？在cpp里实现就会报错，无法解析符号
template <typename T>
fraction fraction::operator+(T f)
{
	if ((*this).denominator == 0) {
		return fraction((*this).numerator + f, 0);
	}
	fraction result((*this).numerator + f * (*this).denominator, (*this).denominator);
	result.adjust();
	return result;
}

template <typename T>
fraction fraction::operator-(T f)
{
	if ((*this).denominator == 0) {
		return fraction((*this).numerator - f, 0);
	}
	fraction result((*this).numerator - f * (*this).denominator, (*this).denominator);
	result.adjust();
	return result;
}

template <typename T>
fraction fraction::operator*(T f)
{
	if ((*this).denominator == 0) {
		return fraction((*this).numerator * f, 0);
	}
	fraction result((*this).numerator * f, (*this).denominator);
	result.adjust();
	return result;
}

template <typename T>
fraction fraction::operator/(T f)
{
	if (f == 0) {
		cout << "除数为0" << endl;
		return *this;
	}
	if ((*this).denominator == 0) {
		return fraction((*this).numerator / f, 0);
	}
	fraction result((*this).numerator / f, (*this).denominator);
	result.adjust();
	return result;
}


template <typename T>
void fraction::operator+=(T f) {
	(*this) = (*this) + f;
}

template <typename T>
void fraction::operator-=(T f) {
	(*this) = (*this) - f;
}

template <typename T>
void fraction::operator*=(T f) {
	(*this) = (*this) * f;
}

template <typename T>
void fraction::operator/=(T f) {
	(*this) = (*this) / f;
}