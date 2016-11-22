#ifndef MYCSTRING_H_INCLUDED
#define MYCSTRING_H_INCLUDED

#include <stdlib.h>
//#include <assert.h>

int my_strlen(const char *str);

/*
Функция strchr() возвращает указатель на первое вхождение символа ch в строку, на которую указывает str.
Если символ ch не найден, возвращается NULL.
*/
char *my_strchr(char *str, int ch);
/*
Функция strdup() путем обращения к функции malloc() выделяет память, достаточную для хранения дубликата строки,
на которую указывает str, а затем производит копирование этой строки в выделенную область и возвращает указатель на нее.
*/
char *my_strdup(const char *str);


#endif // WRITE_H_INCLUDED
