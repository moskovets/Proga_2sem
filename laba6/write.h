#ifndef WRITE_H_INCLUDED
#define WRITE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mylist.h"
#include "my_struct.h"

int from_file_to_database(FILE *f, Data **arr, const int n);
list *from_database_to_list(const Data *arr, const int n);
void write_from_list_to_file(FILE *f, const list *head);

#endif // WRITE_H_INCLUDED

