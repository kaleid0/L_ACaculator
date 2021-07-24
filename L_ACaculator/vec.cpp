#include "vec.h"
//#include "fraction.h"
//#include "fraction.cpp"

vec::vec(int n):length(n) {
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
	length = list.size();
}

void vec::setVec(int n) {
	cout << "输入" << n << "个整数" << endl;
	for (int i = 0; i < n; i++) {
		cin >> (*this)[i];
	}
}

void vec::showVec() {
	cout << '[';
	for (int i = 0; i < length; i++) {
		cout << (*this)[i];
		if (i != length - 1)
			cout << ',';
	}
	cout << ']';
}

bool vec::iszero() {
	for (auto i : *this)
		if (i.value() != 0)
			return false;
	return true;
}

vec vec::operator+(const vec &v) {
	vec res;
	for (int i = 0; i < v.getLength(); i++) {
		res.push_back((*this)[i] + v[i]);
	}
	res.setLength(v.getLength());
	return res;
}

vec vec::operator-(const vec& v) {
	vec res;
	for (int i = 0; i < v.getLength(); i++) {
		res.push_back((*this)[i] - v[i]);
	}
	res.setLength(v.getLength());
	return res;
}

//vec vec::operator*(const vec& v) {
//	vec res;
//
//}

vec vec::operator%(const vec& v) {
	vec res;
	for (int i = 0; i < v.getLength(); i++) {
		res.push_back((*this)[i] * v[i]);
	}
	res.setLength(v.getLength());
	return res;
}

vec vec::operator*(int k) {
	vec res;
	for (auto &i : *this) {
		res.push_back(i * k);
	}
	res.setLength((*this).getLength());
	return res;
}

vec vec::operator*(fraction k)
{
	vec res;
	for (auto& i : *this) {
		res.push_back(i * k);
	}
	res.setLength((*this).getLength());
	return res;
}
