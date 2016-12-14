#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#define MAX_NUMBER_LEN 21
int my_strcat(char *s, int n, const char* str);

int convert_ll_to_o_str(char *s, int n, long long number);

int my_snprintf (char *s, size_t n, const char *format, ... );

#endif // FUNC_H_INCLUDED



