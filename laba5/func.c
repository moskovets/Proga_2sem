#include "func.h"

int my_strcat(char *s, int n, const char* str)
{
    int i;
    for(i = 0; str[i] && i < n; i++)
    {
        s[i] = str[i];
    }
    while(str[i]) i++;
    return i;
}
int convert_ll_to_o_str(char *s, int n, unsigned long long number) //unsigned int
{
    if(number == 0)
    {
        s[0] = '0';
        return 1;
    }
    int res[MAX_NUMBER_LEN] = {0};
    int ires = 0;
    int is = 0;
    while(number > 0)
    {
        res[ires] = number % 8;
        number /= 8;
        ires++;
    }
    int i;
    for(i = MAX_NUMBER_LEN - 1; i >= 0 && res[i] == 0; --i) { ; }
    for( ; is < n && i >= 0; i--)
    {
        s[is++] = '0' + res[i];
    }
    return is + i + 1;
}
//всегда выводить 0 в конце, возвращать возможное кол-во символов
//переделать соответствующие тесты...

int my_snprintf (char *s, size_t n, const char *format, ... )
{
    const char *f = format;

    int i = 0;
    va_list vl;
    va_start(vl, format);
    char *str;
    char ch;
    int new_size;
    unsigned long long number;
    while(*f)
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
                if(i < n)
                    s[i] = ch;
                i++;
                f++;
                break;
            case 'l':
                if(*(f+1) == 'l' && *(f+2) == 'o')
                {
                    f += 3;
                    number = va_arg(vl, unsigned long long);
                    i += convert_ll_to_o_str(s, n - i, number);
                    break;
                }
            default:
                if(i < n)
                    s[i] = '%';
                i++;
                if(i < n)
                    s[i] = *f;//ne vlezlo
                i++;
                f++;
                break;
            }
        }
        else
        {
            if(i < n)
                s[i] = *f;
            i++;
            f++;
        }
    }
    if(i >= n)
        s[n - 1] = '\0';
    else
        s[i] = '\0';
    return i;
}
