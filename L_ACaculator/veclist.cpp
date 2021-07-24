#include "veclist.h"

//using namespace std;

void veclist::showlist() {
	int j = 0;
	for (auto i : *this) {
		cout << ++j << ". ";
		i.showVec();
		cout << endl;
	}
}

void veclist::deleteVec(int n) {
	int s = (*this).size();
	if (s == 1) {
		(*this).clear();
	}
	else {
		if(n!=s)
			for (int i = n-1; i < s-1; i++)
				(*this)[i] = (*this)[i + 1];
		(*this).pop_back();
	}
}

