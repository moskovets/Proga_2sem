#ifndef MY_STRUCT_H_INCLUDED
#define MY_STRUCT_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAX_NAME_LEN 40
typedef struct Data_town
{
    char town_name[MAX_NAME_LEN];
    char country_name[MAX_NAME_LEN];
    int population;
} Data;

void print_struct_to_file(FILE *f, const void *p);
int scan_struct_from_file(FILE *f, Data *a);
int funccmp_Data(const void *val1, const void *val2);
void print_struct(const void *p);
#endif // MY_STRUCT_H_INCLUDED


