#include "func.h"
#include "mycstring.h"

//#include <string.h>
#include <assert.h>

char *my_realloc(char **str, int n, int new_n)
{
    char *new_str = malloc(new_n * sizeof(char));
    if (new_str)
        memcpy(new_str, *str, n * sizeof(char));
    if(n != 0)
        free(*str);
    return new_str;
}
char *from_file_to_string(FILE *f)
{
	char* str = NULL;
	char buf[BUF_SIZE];
	int i = 0, j = 0;
	while(fgets(buf, BUF_SIZE, f))
	{
	    str = my_realloc(&str, i, i + strlen(buf) + 1);
        if(!str)
        {
            MEMORY_ERROR;
            return NULL;
        }
	    j = i;
	    while(buf[j - i] != '\n' && buf[j - i])
        {
            str[j] = buf[j - i];
            j++;
        }
        str[j] = '\0';
        if(buf[j - i] == '\n')
            break;
	    i = j;
	}
	return str;
/*//	char* str = malloc(sizeof(char) * BUF_SIZE);
	char* str = NULL;
	char buf[BUF_SIZE];
	printf("!!!");
	int i = 0, j = 0;
	while(fgets(buf, BUF_SIZE, f))
	{
	    str = my_realloc(&str, i, i + strlen(buf));
        if(!str)
        {
            printf("Cannot allocate memory!\n");
            return NULL;
        }
	    j = i;
	    while(buf[j - i] != '\n' && buf[j - i]) //for(j = i; j < i + BUF_SIZE && buf[j - i]; j++)
        {
            str[j] = buf[j - i];
            j++;
        }
        str[j] = '\0';
        printf("%s-%s-\n", str, buf);
        if(buf[j - i] == '\n')
        {
            //str[j] = '\0';
            break;
        }
	    //if(str[my_strlen(str) - 1] == '\0') { break; } //???
	    i = j; //strlen(buf); //j; //strlen(buf); //BUF_SIZE - 1;
	}
	//if(i != 0)
	//str[i] = '\0';
	return str;
*/
/*	printf("!!!");
	if(!str)
    {
        return NULL;
	}
	int i = 1;
	while(fgets(str + i - 1, BUF_SIZE, f))
	{
	    str = my_realloc(&str, i - 1 + BUF_SIZE, i - 1 + 2 * BUF_SIZE); //написать свою!
        //str = realloc(str, (i + 2 * BUF_SIZE) * sizeof(char));
        if(!str)
        {
            printf("Cannot allocate memory!\n");
            return NULL;
        }
        printf("%s--%s\n", str, str + i);
	    if(str[my_strlen(str) - 1] == '\0') { break; } //???
	    i += BUF_SIZE;
	}
	if(i == 1)
        return NULL;
	return str;
*/
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
    memcpy(new_str, str, n * sizeof(char)); //memcpy
    memcpy(new_str + n, rep_str, my_strlen(rep_str) * sizeof(char)); //memcpy
    int new_start = n + my_strlen(rep_str);
    int start = n + my_strlen(substr);
    for(i = 0; str[i + start]; i++)
        new_str[new_start + i] = str[i + start];
    new_str[new_start + i] = str[i + start];
    return new_str;
}
char *replace_all(const char *str, const char *substr, const char *rep_str)
{
    assert(strlen(substr) != 0);
    int i = 0, j = 0;
    char *str_copy = my_strdup(str);
    while((j = search_str(str_copy + i, substr)) >= 0) //
    {
        i += j;
        //printf("%d ", i);
        char *s = replace_str(str_copy, i, substr, rep_str);
        if (!s)
            return NULL;
        free(str_copy);
        str_copy = s;
        i += my_strlen(rep_str);
        //i++;// need;
    }
    //printf("\n");
    return str_copy;
}
