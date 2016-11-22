#ifndef WRITE_H_INCLUDED
#define WRITE_H_INCLUDED

#include <stdio.h>
#include <assert.h>

int scan_file_for_amount(FILE *f);
int scan_to_arr(FILE *f, int n, int *a);

void print_to_file(FILE *f, int n, int *a);

#endif // WRITE_H_INCLUDED
