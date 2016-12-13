#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define BUF_SIZE 5
#define MEMORY_ERROR printf("Cannot allocate memory!\n");

void free_matrix_rows(double **data, int n);
double **allocate_matrix_rows(int n, int m);
double **add(const double **a, const double **b, const int n, const int m);
double **mult(const double **a, const double **b, const int n, const int m, const int l);
void find_col(const double **a_copy, int i_col, int n, double* col);
double **inverse_matrix(const double **a, const int n);
void from_matrix_to_file(FILE *f, const double **arr, const int n, const int m);
double **from_file_to_arr(FILE *f, int *n, int *m);
#endif // FUNC_H_INCLUDED


