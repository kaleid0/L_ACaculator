#pragma once
#include <vector>
#include <iostream>
#include "vec.h"

using namespace std;

class matrix :
	public vector<vec>
{
	friend class equation;
private:
	//vector<vector<int>>  mat;
	int length, wide;
public:
	matrix():length(0),wide(0){}
	matrix(int n, int m); //0����
	matrix(int n, int m, int k); //��λ����
	matrix(initializer_list<vec> list);	//={}�ĳ�ʼ������ʵ��

	void setMatrix(int n, int m);
	void showMatrix();
	void setlw(int n, int m) { length = n; wide = m; }
	int getlength() { return length; }
	int getwide() { return wide; }
	//void pushback(int n, int x) { this[n].push_back() }


	void numbermult(int n);	//����
	matrix mreverse();//ת��
	fraction det(); //����ʽ
	int rank();	//��
	matrix guassianElimination();	//��˹��Ԫ
	matrix adjugate();	//����
	matrix inversion();	//��

	friend fraction cross(matrix& mat1, matrix& mat2, int i, int j);

	void lineSwitch(int n, int m);	//�н���
	matrix lineDelete(int n);
	matrix columnDelete(int m);
	matrix addline(vec& v, int n);
	matrix addcolumn(vec& v, int n);




	matrix operator*(matrix& mat);
	matrix operator-(const matrix& mat) const;
	matrix operator%(const matrix& mat) const;
	matrix& operator*=(matrix& mat);
	matrix operator*(int k);
	matrix operator/(int k);
	matrix operator*(fraction k);
	matrix operator/(fraction k);



	matrix equationsolve();
	matrix equationsolve(vec& v);


	void lineSchmidt();
	void columnSchmidt();
	void lineUnitization();
	void columnUnitization();

	vec QRiteration();
	fraction diagonal();
	void QRdivide(matrix& Q,matrix& R);

};

//matrix reverse(matrix& mat);

