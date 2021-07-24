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
    //vector<int> vv; //存储向量
   //向量长度

public:
    vec() :length(0) {}
    vec(int i);
    vec(initializer_list<int> list);

    int length;

    void setVec(int i);
    void showVec();
    void setLength(int i) { length = i; }
    int getLength() const{ return length; }

    bool iszero();

    vec operator+(const vec &v);
    vec operator-(const vec &v);
    vec operator*(const vec &v);
    vec operator%(const vec &v);
    vec operator*(int k);
    vec operator*(fraction k);

};

