#include "equation.h"

matrix equationsolve(matrix& mat) {
	int r = mat.rank();
	int x = mat.getwide();
	int s = mat.getwide() - r;
	if (s == 0) {
		matrix result(1, x);
		return result;
	}
	matrix result(s, x);
	matrix tr = mat.guassianElimination();
	int l = r - 1;
	for (int i = 0; i < s; i++) {
		result[i][x - 1] = fraction(1, 1);
		for (int j = x - s - 1; j >= 0; j--) {
			fraction sum;
			for (int k = x - 1; k > j; k--) {
				sum += result[i][k] * tr[l][k];
			}
			fraction temp = -sum / tr[l--][j];
			result[i][j] = temp;
		}
	}
	return result;
}

matrix equationsolve(matrix& mat, vec& v) {
	int s = mat.getwide() - 1 - mat.rank();

	matrix equation = mat.guassianElimination();

	return equation;
}
