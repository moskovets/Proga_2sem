#include "my_struct.h"

void print_struct_to_file(FILE *f, const void *p)
{
    assert(f);
    Data *data = (Data *) p;
    fprintf(f, "%s %s %d\n", data->town_name, data->country_name, data->population);
}
void print_struct(const void *p)
{
    Data *data = (Data *) p;
    printf("%s %s %d\n", data->town_name, data->country_name, data->population);
}

int funccmp_Data(const void *val1, const void *val2)
{
    Data *a = (Data *) val1;
    Data *b = (Data *) val2;
    return b->population - a->population;
}
int scan_struct_from_file(FILE *f, Data *a)
{
    assert(f);
    if(fscanf(f, "%s %s %d", (*a).town_name, (*a).country_name, &(a->population)) != 3)
        return 1;
    //print_struct(a);
    return 0;
}

