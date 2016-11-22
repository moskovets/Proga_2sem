#include "mycstring.h"
/*
������� strchr() ���������� ��������� �� ������ ��������� ������� ch � ������, �� ������� ��������� str.
���� ������ ch �� ������, ������������ NULL.
*/
char *my_strchr(char *str, int ch)
{
    char *tmp = str;
    int flag = 1;
    while (tmp && flag)
    {
        if (*tmp == ch)
            return tmp;
        if (*tmp == '\0')
            flag = 0;
        tmp++;
    }
    return NULL;
}
int my_strlen(const char *str)
{
    int i = 0;
    while ((str + i) && *(str + i) != '\0')
        ++i;
    return i;
}
/*
������� strdup() ����� ��������� � ������� malloc() �������� ������, ����������� ��� �������� ��������� ������,
�� ������� ��������� str, � ����� ���������� ����������� ���� ������ � ���������� ������� � ���������� ��������� �� ���.
*/
char *my_strdup(const char *str)
{
    if (!str)
        return NULL;
    int i = my_strlen(str);
    char *tmp = (char *) malloc((i + 1) * sizeof(char));
    if (!tmp)
        return NULL;
    i = 0;
    int flag = 1;
    while ((str + i) && flag)
    {
        *(tmp + i) = *(str + i);
        if(*(str + i) == '\0')
            flag = 0;
        i++;
    }
    return tmp;
}
