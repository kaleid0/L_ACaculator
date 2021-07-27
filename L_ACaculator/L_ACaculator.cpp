//1.计算矩阵的秩,高斯消元,要使用double型数据	^^
//2.改进交互界面
//3.大部分输入和计算未考虑非法情况,要设置条件阻止非法输入
//4.特征值，特征向量，相似对角化
//5.解方程

//1.1更新,增加求矩阵的秩,将数据类型改为double
//可使用={1,2,3}的方式对向量和矩阵初始化
//1.2改double类型为自定义的分数类型fraction，便于查看

//增加fraction类型根号操作之后可以转换成double的功能，

//求特征值，QR分解
//（1）对需要求解的特征值的矩阵进行QR分解
//（2）对分解出来的结果进行逆向相乘
//（3）将相乘得到的矩阵进行QR分解
//（4）对分解出来的结果进行逆向相乘
// 
//求特征向量，用得到的特征值和原矩阵高斯消元，解方程
//
//施密特正交化,单位化
//
//

#include <iostream>
#include "Interface.h"
#include "equation.h"
//#include "test.cpp"

using namespace std;

int main()
{
	/*Interface i;
	i.start();*/


	

	//vec v1 = { 1,2,3 };
	//vec v2 = { 2,3,4 };
	//fraction f = v1 % v2;
	//cout << f << endl;
	//



	matrix a = {
		{1,2,2},
		{2,1,2},
		{1,2,1}
	};

	matrix b = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	matrix c = {
		{2,1,0,1},
		{0,3,1,0},
		{1,0,4,0},
		{1,0,1,5}
	};

	matrix Q;
	matrix R;
	c.showMatrix();
	vec v = c.QRiteration();
	v.showVec();
	
	//b.columnUnitization();
	//b.showMatrix();


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

