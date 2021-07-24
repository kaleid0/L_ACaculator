#pragma once
#include "matrix.h"

class matlist :
    public vector<matrix>
{
public:
    void showlist();
    void deleteMat(int n);
};
