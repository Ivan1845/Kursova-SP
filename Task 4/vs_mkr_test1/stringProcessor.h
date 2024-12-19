#ifndef STRING_PROCESSOR
#define STRING_PROCESSOR

#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

#define STRING_MAX 512ull

size_t strlenn(const char* str)
{
    const char* s = str;
    while (*s != '\0')
        ++s;
    return s - str;
}

int32_t get_str(const char* msg, char* str, int32_t limit)
{
    std::cout << msg << "\n";
    if (fgets(str, limit, stdin) != NULL)
    {
        size_t len = strlenn(str);
        if (len > 0 && str[len - 1] == '\n')
            str[len - 1] = '\0';
        return 0;
    }
    return -1;
}

void strcopy(char* fStr, const char* sStr, size_t until)
{
    for (size_t i = 0; i < until; i++)
    {
        fStr[i] = sStr[i];
        if (sStr[i] == '\0')
            break;
    }
}

int32_t strcmpp(const char* fStr, const char* sStr)
{
    while (*fStr && (*fStr == *sStr))
    {
        fStr++;
        sStr++;
    }
    return (unsigned char)*fStr - (unsigned char)*sStr;
}

char* strcatt(char* fStr, const char* sStr)
{
    char* ptr = fStr + strlenn(fStr);
    while (*sStr != '\0')
    {
        *ptr++ = *sStr++;
    }
    *ptr = '\0';
    return fStr;
}

bool is_string_valid(const char* str)
{
    bool isThereString = false;
    bool isThereColon = false;
    const size_t size = strlenn(str);
    for (size_t i = 0; i < size; i++)
    {
        if ((str[i] == ':' || str[i] == ';' || str[i] == ',') && i == 0ull)
        {
            return false;
        }
        if (str[i] == ':')
        {
            isThereColon = true;
        }
        else if (isThereColon)
        {
            if (str[i] == ',')
            {
                if (!isalpha(str[i - 1ull]) && str[i - 1ull] != ' ')
                {
                    return false;
                }
                else
                {
                    isThereString = true;
                }
            }
            if (str[i] == ';')
            {
                if (!isThereString || (!isalpha(str[i - 1ull]) && str[i - 1ull] != ' '))
                {
                    return false;
                }
                else
                {
                    isThereColon = false;
                }
            }
            if (str[i] == ':')
            {
                return false;
            }
        }
        else
        {
            isThereString = false;
        }
    }
    return true;
}

#endif
