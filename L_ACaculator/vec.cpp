#include "vec.h"
//#include "fraction.h"
//#include "fraction.cpp"

vec::vec(int n):dimension(n) {
	for (int i = 0; i < n; i++) {
		fraction temp;
		(*this).push_back(temp);
	}
}

vec::vec(initializer_list<int> list) {
	for (auto i :list) {
		fraction f(i, 1);
		(*this).push_back(f);
	}
	dimension = list.size();
}

void vec::setVec(int n) {
	cout << "输入" << n << "个整数" << endl;
	for (int i = 0; i < n; i++) {
		cin >> (*this)[i];
	}
}

void vec::showVec() {
	cout << '[';
	for (int i = 0; i < dimension; i++) {
		cout << (*this)[i];
		if (i != dimension - 1)
			cout << ',';
	}
	cout << ']';
}

bool vec::iszero() {
	for (auto &i : *this)
		if (i.value() != 0)
			return false;
	return true;
}

vec vec::operator+(const vec &v) {
	vec res;
	for (int i = 0; i < (*this).dimension; i++) {
		res.push_back((*this)[i] + v[i]);
	}
	res.dimension= (*this).dimension;
	return res;
}

vec vec::operator-(const vec& v) {
	vec res;
	for (int i = 0; i < (*this).dimension; i++) {
		res.push_back((*this)[i] - v[i]);
	}
	res.dimension = (*this).dimension;
	return res;
}

//vec vec::operator*(const vec& v) {
//	vec res;
//	for (int i = 0; i < (*this).dimension; i++) {
//		res.push_back()
//	}
//
//}

fraction vec::operator%(const vec& v) {
	if ((*this).dimension != v.dimension) {
		cout << "两向量维度不同，不能点乘" << endl;
		return fraction(0,1);
	}
	fraction res;
	for (int i = 0; i < (*this).dimension; i++) {
		res += (*this)[i] * v[i];
	}
	return res;
}

vec vec::operator*(int k) {
	vec res;
	for (auto &i : *this) {
		res.push_back(i * k);
	}
	res.dimension = (*this).dimension;
	return res;
}

vec vec::operator*(fraction k)
{
	vec res;
	for (auto& i : *this) {
		res.push_back(i * k);
	}
	res.dimension = (*this).dimension;
	return res;
}

void vec::operator+=(const vec& v)
{
	(*this) = (*this) + v;
}

void vec::operator-=(const vec& v)
{
	(*this) = (*this) - v;
}



void vec::Unitization() {
	fraction sum;
	for (auto i:(*this)) {
		i.power(2);
		sum += i;
	}
	sum.fsqrt();
	for (auto& i : (*this)) {
		i /= sum;
	}
}
