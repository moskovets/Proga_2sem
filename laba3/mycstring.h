#ifndef MYCSTRING_H_INCLUDED
#define MYCSTRING_H_INCLUDED

#include <stdlib.h>
//#include <assert.h>

int my_strlen(const char *str);

/*
������� strchr() ���������� ��������� �� ������ ��������� ������� ch � ������, �� ������� ��������� str.
���� ������ ch �� ������, ������������ NULL.
*/
char *my_strchr(char *str, int ch);
/*
������� strdup() ����� ��������� � ������� malloc() �������� ������, ����������� ��� �������� ��������� ������,
�� ������� ��������� str, � ����� ���������� ����������� ���� ������ � ���������� ������� � ���������� ��������� �� ���.
*/
char *my_strdup(const char *str);


#endif // WRITE_H_INCLUDED
