#pragma once
#include "vec.h"
//#include <iostream>

//using namespace std;

class veclist :
    public vector<vec>
{
public:
	void showlist();
	void deleteVec(int n);
	void set(vec v, int i);

};



