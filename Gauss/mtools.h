#ifndef MTOOLS_H_
#define MTOOLS_H_

double *create_array(int);
double **create_matrix(int, int);
void c_free(double **, int);
void display_matrix(double **, int, int);
void display_matrix(double *, int);
void fill_matrix(double **, int, int);
void fill_matrix(double *, int);

#endif