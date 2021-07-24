#include "fraction.h"

ostream& operator << (ostream& os, fraction& f){
	if (f.denominator == 1)
		os << f.numerator;
	else
		os << f.numerator << '/' << f.denominator;
	return os;
}

istream& operator >> (istream& in, fraction& f) {
	in >> f.numerator;
	f.denominator = 1;
	return in;
}

fraction fraction::operator+(const fraction f) {
	int i = (*this).numerator * f.denominator + (*this).denominator * f.numerator;
	int j = (*this).denominator * f.denominator;
	fraction result(i, j);
	return result.adjust();
}

fraction fraction::operator-(const fraction f) {
	int i = (*this).numerator * f.denominator - (*this).denominator * f.numerator;
	int j = (*this).denominator * f.denominator;
	fraction result(i, j);
	return result.adjust();
}

fraction fraction::operator*(const fraction f) {
	fraction result((*this).numerator * f.numerator, (*this).denominator * f.denominator);
	return result.adjust();
}

fraction fraction::operator/(const fraction f) {
	if (f.value() == 0) {
		cout << "³ýÊýÎª0" << endl;
		return *this;
	}
	fraction result((*this).numerator * f.denominator, (*this).denominator * f.numerator);
	return result.adjust();
}

fraction fraction::operator+(const int f)
{
	fraction result((*this).numerator + f * (*this).denominator, (*this).denominator);
	return result.adjust();
}

fraction fraction::operator-(const int f)
{
	fraction result((*this).numerator - f * (*this).denominator, (*this).denominator);
	return result.adjust();
}

fraction fraction::operator*(const int f)
{
	fraction result((*this).numerator * f, (*this).denominator);
	return result.adjust();
}

fraction fraction::operator/(const int f)
{
	fraction result((*this).numerator / f, (*this).denominator);
	return result.adjust();
}

void fraction::operator+=(const int f) {
	(*this).numerator += f * (*this).denominator;
	(*this).adjust();
}

void fraction::operator+=(const fraction f) {
	(*this).numerator = (*this).numerator * f.denominator + (*this).denominator * f.numerator;
	(*this).denominator *= f.denominator;
	(*this).adjust();
}

void fraction::operator-=(const int f) {
	(*this).numerator -= f * (*this).denominator;
	(*this).adjust();
}

void fraction::operator-=(const fraction f) {
	(*this).numerator = (*this).numerator * f.denominator - (*this).denominator * f.numerator;
	(*this).denominator *= f.denominator;
	(*this).adjust();
}

void fraction::operator*=(const int f) {
	(*this).numerator *= f;
	(*this).adjust();
}

void fraction::operator*=(const fraction f) {
	(*this).numerator *= f.numerator;
	(*this).denominator *= f.denominator;
	(*this).adjust();
}

void fraction::operator/=(const int f) {
	(*this).numerator /= f;
	(*this).adjust();
}

void fraction::operator/=(const fraction f)	{
	(*this).numerator *= f.denominator;
	(*this).denominator *= f.numerator;
	(*this).adjust();
}

fraction& fraction::operator-()
{
	(*this).numerator = -(*this).numerator;
	return *this;
}

fraction fraction::adjust() {
	int i = (*this).numerator;
	int j = (*this).denominator;
	while (1) {
		int d = i % j;
			i = j;
			j = d;
			if (j == 0)
				break;
	}
	(*this).numerator /= i;
	(*this).denominator /= i;
	if ((*this).numerator > 0 && (*this).denominator < 0) {
		(*this).numerator = -(*this).numerator;
		(*this).denominator = -(*this).denominator;
	}
	return *this;
}
