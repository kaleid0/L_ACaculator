#pragma once
#include <iostream>
#include <vector>
#include "veclist.h"
#include "vec.h"
#include <stdlib.h>
#include "matlist.h"
#include "matrix.h"
#include "fraction.h"

using namespace std;

class Interface {
public:
	veclist vl;
	matlist ml;

	void start();

	void vector_cacul();
	void vector_cacul2();

	void matrix_cacul();
	void matrix_cacul2();

	void equation_cacul();
};




