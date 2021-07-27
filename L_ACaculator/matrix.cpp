#include "matrix.h"

matrix::matrix(int n, int m) :length(n), wide(m) {
	for (int i = 0; i < n; i++) {
		vec temp(m);
		(*this).push_back(temp);
	}
}

matrix::matrix(int n, int m, int k) :length(n), wide(m) { 
	int s = 0;
	for (int i = 0; i < n; i++) {
		vec temp(m);
		fraction f(1, 1);
		temp[s++] = f;
		(*this).push_back(temp);
	}
}

matrix::matrix(initializer_list<vec> list) {
	length = list.size();
	wide = list.begin()->dimension;
	for (auto i :list) {
		(*this).push_back(i);
	}
}

void matrix::setMatrix(int n, int m) {
	cout << "按行输入" << n * m << "个整数" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			fraction f(temp, 1);
			(*this)[i][j] = f;
		}
	}
}

void matrix::showMatrix() {               //各行位数不同时需要优化打印函数，对齐列
	for(int i=0;i<length;i++){
		for (int j=0; j < wide; j++) {
			if (j == 0) {
				cout << "|\t";
			}
			cout << (*this)[i][j];
			if (j < wide-1) {
				cout << "\t";
			}
			if (j == wide - 1) {
				cout << "\t|" << endl;
			}
		}
	}
	cout << endl;
}

void matrix::numbermult(int n) {
	for (auto &i : *this) {
		for (auto &j : i) {
			j *= n;
		}
	}
}

matrix matrix::mreverse()
{
	matrix res((*this).getwide(), (*this).getlength());
	for (int i = 0; i < (*this).getwide(); i++) {
		for (int j = 0; j < (*this).getlength(); j++) {
			res[i][j] = (*this)[j][i];
		}
	}
	return res;
}

fraction matrix::det() {
	int l = (*this).length;
	int w = (*this).wide;
	vector<fraction> res1;
	vector<fraction> res2;
	fraction res;
	for (int i = 0; i < l; i++) {
		fraction temp(1, 1);
		res1.push_back(temp);
		res2.push_back(temp);
	}

	if (l != w) {
		cout << "该矩阵无行列式" << endl;
		fraction temp;
		return temp;
	}
	else if (l == 1) {
		return (*this)[0][0];
	}
	else if (l == 2) {
		return ((*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0]);
	}
	else {
		for (int i = 0; i < l; i++) {
			int m = i;
			int n = l-1+i;
			for (int j = 0; j < l; j++) {
				res1[i] *= (*this)[j][m % l];
				res2[i] *= (*this)[l - 1 - j][m % l];
				m++;
				n--;
			}
		}
		for (int i = 0; i < l; i++) {
			res += res1[i];
			res -= res2[i];
		}
	}
	return res;
}

int matrix::rank() {
	int n = 0;
	matrix temp = (*this).guassianElimination();
	for (auto i : temp) {
		if (i.iszero())
			break;
		n++;
	}
	return n;
}

matrix matrix::guassianElimination() {	//高斯消元,化为上三角矩阵.逐列找首个不为0的元素,换到首行
	matrix temp((*this).length, (*this).wide);
	temp.assign((*this).begin(), (*this).end());	//复制一份原矩阵,不改变原矩阵
	for (int i = 0; i < temp.length; i++) {
		for (int j = i; j < temp.length; j++) {
			if (temp[j][i].value() != 0) {
				temp.lineSwitch(i, j);
				temp.showMatrix();
				break;
			}
		}
		for (int j = i+1; j < temp.length; j++) {
			if (temp[j][i].value() != 0) {
				fraction k = temp[j][i] / temp[i][i];
				temp[j] = temp[j] - temp[i] * k;
				temp.showMatrix();
			}
		}
	}
	return temp;
}

matrix matrix::adjugate() {	//基于伴随矩阵的性质，但是首先需要一个随意求解余子式的函数,此处用删除行列形成新的行列式来求。
	int l = (*this).length;
	int w = (*this).wide;
	matrix res(l,w);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			matrix temp(l-1,w-1);
			temp = (*this).lineDelete(i);
			temp = temp.columnDelete(j);
			(i + j) % 2 == 0 ? res[j][i] = temp.det() : res[j][i] = -temp.det();
		}
	}
	return res;
}

matrix matrix::inversion() {	//逆矩阵,A-1 = A* / |A|
	matrix temp = (*this).adjugate();
	fraction r = (*this).det();
	matrix res = temp / r;
	return res;
}

void matrix::lineSwitch(int n, int m) {
	if (m == n || n > ((*this).length) || m > ((*this).length)) {
		return;
	}
	vec temp;
	temp.assign((*this)[n-1].begin(), (*this)[n-1].end());	//复制n行
	(*this)[n] = (*this)[m];
	(*this)[m] = temp;
}

matrix matrix::lineDelete(int n) {
	matrix res;
	for (int i = 0; i < (*this).size(); i++) {
		if (i == n)	continue;
		res.push_back((*this)[i]);
	}
	res.length = (*this).length - 1;
	res.wide = (*this).wide;
	return res;
}

matrix matrix::columnDelete(int m) {
	matrix res;
	for (int i = 0; i < (*this).size(); i++) {
		vec temp;
		for (int j = 0; j < (*this)[0].size(); j++) {
			if (j == m)	continue;
			temp.push_back((*this)[i][j]);
		}
		res.push_back(temp);
	}
	res.length = (*this).length;
	res.wide = (*this).wide - 1;
	return res;
}

matrix matrix::addline(vec& v, int n) {
	if (v.dimension != (*this).wide) {
		cout << "长度不符合要求" << endl;
		return *this;
	}
	if (n > (*this).length + 1) {
		cout << "插入行：" << n << "超出范围：" << "l+1" << endl;
		return *this;
	}
	matrix result = (*this);
	if (n <= (*this).length)
		result.emplace(result.begin() + n - 1, v);
	else
		result.push_back(v);
	result.length++;
	return result;
}

matrix matrix::addcolumn(vec& v, int n) {
	if (v.dimension != (*this).length) {
		cout << "长度不符合要求" << endl;
		return *this;
	}
	if (n > (*this).wide + 1) {
		cout << "插入列：" << n << "超出范围：" << "l+1" << endl;
		return *this;
	}
	matrix result = (*this);
	if(n <= (*this).wide)
		for (int i = 0; i < result.length; i++) {
			result[i].emplace(result[i].begin() + n - 1, v[i]);
			result[i].dimension++;
		}
	else
		for (int i = 0; i < result.length; i++) {
			result[i].push_back(v[i]);
			result[i].dimension++;
		}
	result.wide++;
	return result;
}

matrix matrix::operator*(matrix& mat){
	int w = mat.wide;
	int l = (*this).length;
	if (w != (*this).length || l != mat.wide) {
		cout << "无法做乘法运算" << endl;
		return *this;
	}
	matrix res(l,w);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			res[i][j] = cross((*this), mat, i, j);
		}
	}
	return res;
}

fraction cross(matrix& mat1, matrix& mat2, int i, int j) {
	fraction res;
	for (int k = 0; k < mat1.getwide(); k++) {
		res += mat1[i][k] * mat2[k][j];
	}
	return res;
}

matrix matrix::operator*(int k) {
	int l = (*this).length;
	int w = (*this).wide;
	matrix res(l, w);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			res[i][j] = (*this)[i][j] * k;
		}
	}
	return res;
}

matrix matrix::operator/(int k) {
	int l = (*this).length;
	int w = (*this).wide;
	matrix res(l,w);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			res[i][j] = (*this)[i][j] / k;
		}
	}
	return res;
}

matrix matrix::operator*(fraction k) {
	int l = (*this).length;
	int w = (*this).wide;
	matrix res(l, w);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			res[i][j] = (*this)[i][j] * k;
		}
	}
	return res;
}

matrix matrix::operator/(fraction k) {
	int l = (*this).length;
	int w = (*this).wide;
	matrix res(l, w);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			res[i][j] = (*this)[i][j] / k;
		}
	}
	return res;
}

//matrix& matrix::operator*=(const matrix& mat) {
//	(*this)* mat;
//}


matrix matrix::equationsolve() {
	int r = (*this).rank();
	int x = (*this).getwide();
	int s = (*this).getwide() - r;
	if (s == 0) {
		matrix result(1, x);
		return result;
	}
	matrix result(s, x);
	matrix tr = (*this).guassianElimination();
	for (int i = 0; i < s; i++) {
		int l = r - 1;
		result[i][x - i - 1] = fraction(1, 1);
		for (int j = x - s - 1; j >= 0; j--) {
			fraction sum;
			for (int k = x - 1; k > j; k--) {
				sum += result[i][k] * tr[l][k];
			}
			fraction temp = -sum / tr[l][j];
			l--;
			result[i][j] = temp;
		}
	}
	return result;
}

matrix matrix::equationsolve(vec& v) {	//1.判断解的类型，
	int r1 = (*this).rank();
	int x = (*this).getwide();
	matrix ad = (*this).addcolumn(v, x+1);
	int r2 = ad.rank();
	if (r2 > r1) {
		cout << "方程无解" << endl;
		return *this;
	}
	matrix result;
	if (r2 < x) {
		result = (*this).equationsolve();
	}
	vec t;
	int k = x;
	matrix tr = ad.guassianElimination();
	for (int i = r1-1; i >= 0; i--) {
		if (v[i].value() == 0) {
			for (int j = i; j < k; j++)
				t.push_back(fraction());
			k = i;
		}
		else {
			fraction sum;
			for (int j = i + 1; j < k; j++) {
				t.push_back(fraction(1, 1));
			}
			int y = t.size()-1;
			for (int j = i + 1; j < x; j++) {
				sum += tr[i][j]*t[y--];
			}
			k = i;
			t.push_back((v[i] - sum) / tr[i][k]);
		}
	}
	reverse(t.begin(), t.end());
	result.push_back(t);
	result.length++;
	return result;
}



void matrix::lineSchmidt() {
	int n = (*this).size();
	int d = (*this)[0].dimension;
	if (n > d) {
		cout << "向量数大于维数，不存在都两两正交的向量组" << endl;
		return;
	}
	if ((*this).rank() < n) {
		cout << "向量组线性相关，不可正交化" << endl;
		return;
	}
	for (int i = 1; i < n; i++) {
		vec temp(d);
		for (int j = i; j > 0; j--) {
			fraction k = ((*this)[i] % (*this)[j - 1]) / ((*this)[j - 1] % (*this)[j - 1]);
			temp += (*this)[j - 1]* k;
		}
		(*this)[i] -= temp;
		(*this)[i].dimension = d;
	}
}

void matrix::columnSchmidt() {
	(*this)=(*this).mreverse();
	(*this).lineSchmidt();
	(*this) = (*this).mreverse();
}

void matrix::lineUnitization() {
	for (int i = 0; i < (*this).length; i++) {
		(*this)[i].Unitization();
	}
}

void matrix::columnUnitization() {
	(*this) = (*this).mreverse();
	(*this).lineUnitization();
	(*this) = (*this).mreverse();
}

vec matrix::QRiteration()
{
	matrix Q;
	matrix R;
	matrix a = (*this);
	while (a[a.size()-1][0].value()>0.001) {
		a.QRdivide(Q, R);
		a = R * Q;
		a.showMatrix();
	}
	vec res;
	for (int i = 0; i < a.size(); i++) {
		res.push_back(a[i][i]);
	}
	res.dimension = a.size();
	return res;
}

void matrix::QRdivide(matrix& Q, matrix& R)//Q是列向量正交化单位化的矩阵，利用求Q的过程反推R矩阵
{
	int n = (*this).size();
	int d = (*this)[0].dimension;
	matrix q;
	matrix r(d, d);
	r[0][0] = fraction(1,1);
	q = (*this).mreverse();

	for (int i = 1; i < n; i++) {
		vec temp(d);
		//int c = 0;
		for (int j = i; j > 0; j--) {
			fraction k = (q[i] % q[j - 1]) / (q[j - 1] % q[j - 1]);
			temp += q[j - 1] * k;
			r[i][j - 1] = k;
		}
		r[i][i] = fraction(1, 1);
		q[i] -= temp;
		q[i].dimension = d;
	}
	r = r.mreverse();

	for (int i = 0; i < q.length; i++) {
		fraction sum;
		for (auto n : q[i]) {
			n.power(2);
			sum += n;
		}
		sum.fsqrt();
		r[i] *= sum;
		q[i] /= sum;
	}
	R = r;
	Q = q.mreverse();
}
