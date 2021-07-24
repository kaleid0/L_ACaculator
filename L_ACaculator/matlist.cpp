#include "matlist.h"

void matlist::showlist() {
	int j = 0;
	for (auto i : *this) {
		cout << ++j << ". " << endl;
		i.showMatrix();
		cout << endl;
	}
}

void matlist::deleteMat(int n) {
	int s = (*this).size();
	if (s == 1) {
		(*this).clear();
	}
	else {
		if (n != s)
			for (int i = n - 1; i < s - 1; i++)
				(*this)[i] = (*this)[i + 1];
		(*this).pop_back();
	}
}