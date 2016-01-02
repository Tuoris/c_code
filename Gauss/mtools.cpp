#include "stdio.h"
#include "mtools.h"
#include "stdlib.h"

double *create_array(int len) {
	return (double *)malloc(len*sizeof(double));
}

double **create_matrix(int m, int n) {
	double **ret;
	ret = (double **)malloc(m*sizeof(double *));
	for (int i = 0; i < m; i++) {
		ret[i] = create_array(n);
	}
	return ret;
}

void c_free(double **matr, int m) {
	for (int i = 0; i < m; i++)
		free(matr[i]);
}

void display_matrix(double **matr, int m, int n) {
	for (int j = 0; j < m; j++)	{
		for (int i = 0; i < n; i++)
			printf("%3.3lf ", matr[j][i]);
		printf("\n");
	}
	return;
}

void display_matrix(double *matr, int m) {
	for (int j = 0; j < m; j++)	{
		printf("%3.3lf ", matr[j]);
	}
	printf("\n");
	return;
}

void fill_matrix(double **matr, int m, int n) {
	for (int j = 0; j < m; j++)	{
		printf("\trow #%d:  ", j + 1);
		for (int i = 0; i < n; i++)
			scanf("%lf", &matr[j][i]);
		fflush(stdin);
	}
}

void fill_matrix(double *matr, int m) {
	printf("\t");
	for (int j = 0; j < m; j++) {
			scanf("%lf", &matr[j]);
	}
	fflush(stdin);
}