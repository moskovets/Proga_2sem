#include "func.h"
#include "mycstring.h"

//#include <string.h>
#include <assert.h>

char *from_file_to_string(FILE *f)
{
	char* str = malloc(sizeof(char) * BUF_SIZE);
	if(!str)
    {
        return NULL;
	}
	int i = 0;
	while(fgets(str + i, BUF_SIZE, f))
	{
	    str = realloc(str, (i + BUF_SIZE) * sizeof(char)); //написать свою!
        if(!str)
        {
            printf("Cannot allocate memory!\n");
            return NULL;
        }
	    if(str[my_strlen(str) - 2] == '\n') { break; } //???
	    i += BUF_SIZE;

	}
	return str;
}

/*поиск первого вхождения подстроки в строке, или -1*/
int search_str(const char *str, const char *substr)
{
    int n_str = my_strlen(str);
    int n_substr = my_strlen(substr);
    for(int i = 0; i <= n_str - n_substr; i++)
    {
        int j = 0;
        for(j = 0; substr[j] && str[i + j] == substr[j]; j++);
        if(j == n_substr)
            return i;
    }
    return -1;
}
char *replace_str(char *str, int n, const char *substr, const char *rep_str)
{
    int i = 0;
    char *new_str = malloc((my_strlen(str) + my_strlen(rep_str) - my_strlen(substr) + 1) * sizeof(char));
    if(!new_str)
        return NULL;
    for(i = 0; i < n; i++) //memcpy
        new_str[i] = str[i];
    for(i = 0; rep_str[i]; i++)
        new_str[n + i] = rep_str[i];
    int new_start = n + my_strlen(rep_str);
    int start = n + my_strlen(substr);
    for(i = 0; str[i + start]; i++)
        new_str[new_start + i] = str[i + start];
    new_str[new_start + i] = str[i + start];
    return new_str;
}
char *replace_all(char *str, const char *substr, const char *rep_str)
{
    int i = 0, j = 0;
    while((j = search_str(str + i, substr)) && j > 0) //
    {
        i += j;
        char *s = replace_str(str, i, substr, rep_str);
        if(!s)
            return NULL;
        free(str);
        str = s;
    }
    return str;
}
