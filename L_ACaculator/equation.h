#pragma once
#include "matrix.h"
#include "vec.h"
#include <iostream>

using namespace std;

class equation
{
public:
	matrix equationsolve(matrix& mat);
	matrix equationsolve(matrix& mat, vec& v);

};

