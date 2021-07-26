#include "fraction.h"

ostream& operator << (ostream& os, fraction& f){
	if (f.denominator == 1 || f.denominator == 0)
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

//-------------------------------------------------------------------------------------------------------------------

double fraction::value()const {
	return (*this).denominator ? (*this).numerator / (double)(*this).denominator : (*this).numerator;
}

//-------------------------------------------------------------------------------------------------------------------

fraction fraction::operator+(const fraction f) {
	if ((*this).denominator == 0 || f.denominator == 0) {
		return fraction((*this).value() + f.value(), 0);
	}
	fraction result((*this).numerator * f.denominator + (*this).denominator * f.numerator, (*this).denominator * f.denominator);
	result.adjust();
	return result;
}

fraction fraction::operator-(const fraction f) {
	if ((*this).denominator == 0 || f.denominator == 0) {
		return fraction((*this).value() - f.value(), 0);
	}
	fraction result((*this).numerator * f.denominator - (*this).denominator * f.numerator, (*this).denominator * f.denominator);
	result.adjust();
	return result;
}

fraction fraction::operator*(const fraction f) {
	if ((*this).denominator == 0 || f.denominator == 0) {
		return fraction((*this).value() * f.value(), 0);
	}
	fraction result((*this).numerator * f.numerator, (*this).denominator * f.denominator);
	result.adjust();
	return result;
}

fraction fraction::operator/(const fraction f) {
	if (f.value() == 0) {
		cout << "³ýÊýÎª0" << endl;
		return *this;
	}
	if ((*this).denominator == 0 || f.denominator == 0) {
		return fraction((*this).value() / f.value(), 0);
	}
	fraction result((*this).numerator * f.denominator, (*this).denominator * f.numerator);
	result.adjust();
	return result;
}

//-------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------

void fraction::operator+=(const fraction f) {
	(*this) = (*this) + f;
}

void fraction::operator-=(const fraction f) {
	(*this) = (*this) - f;
}

void fraction::operator*=(const fraction f) {
	(*this) = (*this) * f;
}

void fraction::operator/=(const fraction f)	{
	(*this) = (*this) / f;
}

//-------------------------------------------------------------------------------------------------------------------

void fraction::fsqrt() {
	(*this).denominator ? (*this).numerator = sqrt((*this).numerator / (*this).denominator) : (*this).numerator = sqrt((*this).numerator);
	(*this).denominator = 0;
}

void fraction::power(int n) {
	fraction temp = (*this);
	n--;
	while (n != 0) {
		(*this) *= temp;
		n--;
	}
}

fraction& fraction::operator-()
{
	(*this).numerator = -(*this).numerator;
	return *this;
}

//-------------------------------------------------------------------------------------------------------------------

void fraction::adjust() {
	if ((*this).numerator != (int)(*this).numerator) {
		(*this).numerator /= (*this).denominator;
		(*this).denominator = 0;
		return;
	}
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
}
