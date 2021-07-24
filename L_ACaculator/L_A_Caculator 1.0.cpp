//1.计算矩阵的秩,高斯消元,要使用double型数据	^^
//2.改进交互界面
//3.大部分输入和计算未考虑非法情况,要设置条件阻止非法输入
//4.特征值，特征向量，相似对角化
//5.解方程

//1.1更新,增加求矩阵的秩,将数据类型改为double
//可使用={1,2,3}的方式对向量和矩阵初始化
//1.2改double类型为自定义的分数类型，便于查看

#include <iostream>
#include "Interface.h"
#include "equation.h"
//#include "test.cpp"

using namespace std;

int main()
{

	Interface i;
	i.start();

	/*matrix a = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	vec b = { 1,1,1 };

	a.equationsolve(b).showMatrix();*/


	//vector<vector<int>> v = {
	//	{1,2},
	//	{3,4}
	//};
	/*matrix a1{ {1,2,3,4 } };
	matrix a2{
		{1},
		{2},
		{3},
		{4}
	};
	a1.showMatrix();
	a2.showMatrix();
	cout << a1.getlength() << "  " << a1.getwide() << endl;
	cout << a2.getlength() << "  " << a2.getwide() << endl;
	matrix q1 = a1 * a2;
	matrix q2 = a2 * a1;
	q1.showMatrix();
	q2.showMatrix();*/


	/*matrix a = {
		{1,2,3,1,0,1},
		{0,5,6,5,2,2},
		{0,0,4,4,2,2},
		{0,0,0,0,0,0},
	};
	vec c = { 1,2,3,4,5,6 };
	vec b = { 1,2,3,0 };
	matrix result = a.equationsolve(b);
	result.showMatrix();
	*/

	//
	//fraction t1(-4, 5);
	//fraction t2(2, 3);
	//fraction f = a.det();
	//cout << f << endl;
	//a.adjugate().showMatrix();
	//matrix b = a.inversion();
	//matrix c = a * b;
	//c.showMatrix();

//text

	/*matrix mat(3, 3);
	mat.setMatrix(3, 3);
	matrix temp = mat.inversion();
	temp.showMatrix();

    return 0;*/

}

