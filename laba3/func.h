#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <assert.h>

#include <stdlib.h>
#define BUF_SIZE 5
#define MEMORY_ERROR printf("Cannot allocate memory!\n");
char *from_file_to_string(FILE *f);
/*����� ������� ��������� ��������� � ������, ��� -1*/
int search_str(const char *str, const char *substr);
char *replace_str(char *str, int n, const char *substr, const char *rep_str);
char *replace_all(const char *str, const char *substr, const char *rep_str);
#endif // FUNC_H_INCLUDED


