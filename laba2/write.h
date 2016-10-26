#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mylist.h"

list *from_file_to_list(FILE *f);
void write_from_list_to_file(FILE *f, const list *head);


