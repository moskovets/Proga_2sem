#include "func.h"
double** allocate_matrix_rows(int n, int m)
{
    double **data = calloc(n, sizeof(double*));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof(double));
        if (!data[i])
        {
            free_matrix_rows(data, i); // was n, why???
            return NULL;
        }
    }
    return data;
}

void free_matrix_rows(double **data, int n)
{
    if(data)
    {
        for (int i = 0; i < n; i++)
           // free можно передать NULL
           free(data[i]);
        free(data);
    }
}

double **add(const double **a, const double **b, const int n, const int m)
{
	double **c = allocate_matrix_rows(n, m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			c[i][j] = a[i][j] + b[i][j];
            //printf("%lf ", c[i][j]);
		}
        //printf("\n");
	}

	return c;
}

double **mult(const double **a, const double **b, const int n, const int m, const int l)
{
	double **c = allocate_matrix_rows(n, l);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < l; j++)
            c[i][j] = 0;
    //printf("ye\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < l; k++)
            {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    //printf("ye\n");
    return c;
}
void my_swap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}
void find_col(const double **a_copy, int i_col, int n, double* col)
{
	double **a = allocate_matrix_rows(n, n+1);
	for(int i = 0; i < n; i++)
		col[i] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			a[i][j] = a_copy[i][j];
		a[i][n] = (double) (i == i_col);
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i][i] == 0)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(a[j][j] != 0)
                {
                    for(int k = 0; k <= n; k++)
                        my_swap(&a[i][k], &a[j][k]);
                    break;
                }
            }
		}
		for(int j = i + 1; j < n; j++)
		{
			double d = - a[j][i] / a[i][i];
			for(int k = 0; k <= n; k++)
				a[j][k] += d * a[i][k];
		}
	}
	/*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%lf ", a[i][j]);
        }
        printf("\n");
	}*/
	for(int i = n - 1; i >= 0; i--)
	{
		double res = 0;
		for(int j = 0; j < n; j++)
			res += a[i][j] * col[j];
		col[i] = (a[i][n] - res) / a[i][i];
		//printf("%d %lf \n", i, col[i]);
	}
	//printf("\n");
	free_matrix_rows(a, n);
}
double **inverse_matrix(const double **a, const int n)
{
	double **res = allocate_matrix_rows(n, n);
	double *col = malloc(n * sizeof(double));

	for(int i = 0; i < n; i++)
	{
		find_col(a, i, n, col);
		for(int j = 0; j < n; j++)
			res[j][i] = col[j];
	}
	free(col);
	return res;
}

void from_matrix_to_file(FILE *f, const double **arr, const int n, const int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            fprintf(f, "%.3lf ", arr[i][j]);
        }
        fprintf(f, "\n");
    }
}
double **from_file_to_arr(FILE *f, int *n, int *m)
{
    if(fscanf(f, "%d %d", n, m) != 2)
        return NULL;
    double **arr = allocate_matrix_rows(*n, *m);
    for(int i = 0; i < *n; i++)
    {
        for(int j = 0; j < *m; j++)
        {
            if(fscanf(f, "%lf", &arr[i][j]) != 1)
            {
                free_matrix_rows(arr, *n);
                return NULL;
            }
        }
    }
    return arr;
}



