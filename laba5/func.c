#include "func.h"

int my_strcat(char *s, int n, const char* str)
{
    int i;
    for(i = 0; str[i] && i < n; i++)
    {
        s[i] = str[i];
    }
    return i;
}
int convert_ll_to_o_str(char *s, int n, long long number)
{
    if(number == 0)
    {
        s[0] = '0';
        return 1;
    }
    long long num = labs(number);
    int *res = malloc(sizeof(int) * MAX_NUMBER_LEN);
    int ires = 0;
    int is = 0;
    for(int i = 0; i < MAX_NUMBER_LEN; i++)
        res[i] = 0;
    while(num > 0)
    {
        res[ires] = num % 8;
        num /= 8;
        ires++;
    }
    if(number < 0)
    {
        int *max_number = malloc(sizeof(int) * MAX_NUMBER_LEN);
        for(int i = 0; i < MAX_NUMBER_LEN; i++)
        {
            max_number[i] = 7;
        }
        for(int i = 0; i < MAX_NUMBER_LEN; i++)
        {
            res[i] -= 1;
            if(res[i] < 0)
                res[i] = 7;
            else
                break;
        }
        for(int i = 0; i < MAX_NUMBER_LEN; i++)
        {
            res[i] = max_number[i] - res[i];
        }
        s[is] = '1';
        is++;
    }
    int i;
    for(i = MAX_NUMBER_LEN - 1; i >= 0 && res[i] == 0; --i) { ; }
    for( ;is < n && i >= 0; i--)
    {
        s[is++] = '0' + res[i];
    }
    return is;
}

int my_snprintf (char *s, size_t n, const char *format, ... )
{
    const char *f = format;
    int i = 0;
    va_list vl;
    va_start(vl, format);
    char *str;
    char ch;
    int new_size;
    long long number;


    while(*f && i < n)
    {
        if(*f == '%')
        {
            f++;
            switch(*f)
            {
            case 's':
                str = va_arg(vl, char*);
                new_size = my_strcat(s + i, n - i, str);
                i += new_size;
                f++;
                break;
            case 'c':
                ch = va_arg(vl, int);
                s[i++] = ch;
                f++;
                break;
            case 'l':
                if(*(f+1) == 'l' && *(f+2) == 'o')
                {
                    f += 3;
                    number = va_arg(vl, long long);
                    i += convert_ll_to_o_str(s, n - i, number);
                    break;
                }
            default:
                s[i++] = '%';
                s[i++] = *f;
                f++;
                break;

            }
        }
        else
        {
            s[i++] = *f;
            f++;
        }
    }
    if(i < n) {
        s[i] = '\0';
    }
    return i < n ? i : (-1); //djghskdjgsghfdjdf
}
