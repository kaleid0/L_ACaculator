#pragma once
#include <vector>
#include <iostream>
#include "fraction.h"
//#include "fraction.cpp"

using namespace std;

class vec :
    public vector<fraction>    
{
private:
    //vector<int> vv; //�洢����
   //��������

public:
    vec() :dimension(0) {}
    vec(int i);
    vec(initializer_list<int> list);

    int dimension;

    void setVec(int i);
    void showVec();

    bool iszero();

    vec operator+(const vec &v);
    vec operator-(const vec &v);
    //vec operator*(const vec &v);//���
    fraction operator%(const vec &v);//���
    vec operator*(int k);
    vec operator*(fraction k);

    void operator+=(const vec& v);
    void operator-=(const vec& v);

    void Unitization();

};

