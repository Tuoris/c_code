#include "stdio.h"
#include "stdlib.h"
#include "mtools.h"


int main(void)
{
	double **a, *b;
	int m, n;
	/*
		Data for testing
	*/
	
	/*m = n = 3;
	double d_unknown[3][3] = {
		{ 2,  1, -1}, 
		{-3, -1,  2},
		{-2,  1,  2}
	};

	double d_solution[3] = {8, -11, -3};

	a = create_matrix(m, n);
	b = create_array(m);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = d_unknown[i][j];
		}
		b[i] = d_solution[i];
	}*/

	printf("Enter size of quadric matrix: ");
	scanf("%d", &m);
	n = m;

	a = create_matrix(m, n);
	b = create_array(m);

	puts("Please fill matrix A:");
	fill_matrix(a, m, n);
	puts("Please fill matrix B:");
	fill_matrix(b, m);
	
	puts("A, B matrices:");
	display_matrix(a, m, n);
	display_matrix(b, m);

	/*
		Direct move
	*/
	double **v, **c;
	double *p, *y;
	v = create_matrix(m, n);
	c = create_matrix(m, n);
	p = create_array(m);
	y = create_array(m);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = a[i][j];
			c[i][j] = 0;
		}
		p[i] = b[i];
	}
	puts("V, P matrices:");
	display_matrix(v, m, n);
	display_matrix(p, m);
	for (int k = 0; k < m; k++) {
		y[k] = p[k] / v[k][k];
		for (int i = k + 1; i < m; i++) {
			p[i] = p[i] - v[i][k] * y[k];
			for (int j = k + 1; j < m; j++) {
				c[k][j] = v[k][j] / v[k][k];
				v[i][j] = v[i][j] - v[i][k] * c[k][j];
			}
		}
	}
	/*
		Indirect move
	*/
	double *x;
	x = create_array(m);
	for (int i = 0; i < m; i++) {
		x[i] = y[i];
	}
	double summ;
	for (int i = n - 2; i >= 0; i--) {
		summ = 0.0;
		for (int j = i + 1; j < n; j++) {
			summ += c[i][j] * x[j];
		}
		x[i] = y[i] - summ;
	}
	puts("Solutions: ");
	display_matrix(x, m);
	/*
		Cleaning memory
	*/
	c_free(a, m);
	c_free(c, m);
	c_free(v, m);
	free(b);
	free(p);
	free(y);
	free(x);
	return 0;
}
