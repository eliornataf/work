#include <string.h> /* strlen, strcmp, strcpy */
#include "stringFunc.h" /* String Function Header */

size_t Strlen(const char *_str)
{
    size_t countChars = 0;
    
    if (NULL == _str)
    {
        return STRLEN_POINTER_NOT_INITIALIZE; 
    }

    while (*_str++ != '\0')
    {   
        ++countChars;
    }

    return countChars;
}

size_t StrlenRec(const char *_str)
{
    if (NULL == _str)
    {
        return STRLEN_POINTER_NOT_INITIALIZE; 
    }

    if (*_str == '\0')
    {
        return 0;
    }

    return 1 + StrlenRec(++_str);
}

int Strcmp(const char *_s1, const char *_s2)
{
    if (NULL == _s1 || NULL == _s2)
    {
        return STRCMP_POINTER_NOT_INITIALIZE; 
    }

    while (*_s1 != '\0' && *_s2 != '\0' && *_s1 == *_s2)
    {
        ++_s1;
        ++_s2;
    }

    return *_s1 - *_s2;
}

int StrcmpRecu(const char *_s1, const char *_s2)
{
    if (NULL == _s1 || NULL == _s2)
    {
        return STRCMP_POINTER_NOT_INITIALIZE; 
    }

    if (*_s1 == '\0' || *_s1 != *_s2)
    {
        return *_s1 - *_s2;
    }

    return StrcmpRecu(++_s1, ++_s2);
}

char *Strcpy(char *_dest, const char *_src)
{
    if (NULL == _dest || NULL == _src)
    {
        return NULL; 
    }

    while (*_src != '\0')
    {
        *_dest++ = *_src++;
    }

    *_dest = '\0';

    return _dest;
}

char *StrcpyRecu(char *_dest, const char *_src)
{
    if (NULL == _dest || NULL == _src)
    {
        return NULL; 
    }

    if (*_src == '\0')
    {
        *_dest = '\0';
        return _dest;
    }

    *_dest = *_src;

    return StrcpyRecu(++_dest, ++_src);
}

char *Strncpy(char *_dest, const char *_src, size_t _n)
{
    if (NULL == _dest || NULL == _src)
    {
        return NULL; 
    }

    while (*_src != '\0' && _n--)
    {
        *_dest++ = *_src++;
    }

    *_dest = '\0';

    return _dest;
}

char *StrncpyRecu(char *_dest, const char *_src, size_t _n)
{
    if (NULL == _dest || NULL == _src)
    {
        return NULL; 
    }

    if (*_src == '\0' || !_n)
    {
        *_dest = '\0';
        return _dest;
    }

    *_dest = *_src;

    return StrncpyRecu(++_dest, ++_src, --_n);
}

char *Strcat(char *_dest, const char *_src)
{
    if (NULL == _dest || NULL == _src)
    {
        return NULL; 
    }

    _dest += strlen(_dest);

    strcpy(_dest, _src);

    return _dest;
}

char *Strstr(const char *_haystack, const char *_needle)
{
    if (NULL == _haystack || NULL == _needle)
    {
        return NULL; 
    }

    while (*_haystack != '\0')
    {
        if (!(strncmp(_haystack, _needle, strlen(_needle))))
        {
            return (char*)_haystack;
        }

        ++_haystack;
    }

    return NULL;
}