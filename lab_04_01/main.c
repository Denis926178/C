#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR    255
#define MIN_CHAR    0

char *my_strpbrk(char *string, const char *accept)
{
    size_t len_string = strlen(string);
    size_t len_accept = strlen(accept);

    for (size_t i = 0; i < len_string; i++)
        for (size_t j = 0; j < len_accept; j++)
            if (string[i] == accept[j])
                return &string[i];

    return (NULL);
}

size_t my_strspn(const char *string, const char *accept)
{
    const char *pointer_string;
    const char *pointer_accept;
    size_t counter = 0;

    for (pointer_string = string; *pointer_string != '\0'; pointer_string++)
    {
        for (pointer_accept = accept; *pointer_accept != '\0'; pointer_accept++)
            if (*pointer_string == *pointer_accept)
            {
                counter++;
                break;
            }
            
        if (*pointer_accept == '\0')
            return counter;
    }
            
    return counter;
}

size_t my_strcspn(const char *string, const char *reject)
{
    size_t counter = 0;
    size_t len_string = strlen(string);
    size_t len_reject = strlen(reject);
    
    if (len_reject == 0)
        return len_string;

    for (size_t i = 0; i < len_string; i++)
        for (size_t j = 0; j < len_reject; j++)
        {
            if (string[i] == reject[j])
                return counter;
            
            if (reject[j + 1] == '\0')
                counter++;
        }

    return counter;
}

char *my_strchr(char *string, int search_symbol)
{
    if (string == NULL)
        return (NULL);

    if (search_symbol == 0)
        return &string[strlen(string)];

    if (search_symbol > MAX_CHAR || search_symbol < MIN_CHAR)
        return (NULL);

    size_t string_len = strlen(string);

    for (size_t i = 0; i < string_len; i++)
        if ((char) search_symbol == string[i])
            return &string[i];

    return (NULL);
}

char *my_strrchr(char *string, int search_symbol)
{
    if (string == NULL)
        return (NULL);

    if (search_symbol == 0)
        return &string[strlen(string)];

    if (search_symbol > MAX_CHAR || search_symbol < MIN_CHAR)
        return (NULL);

    size_t string_len = strlen(string);
    //int i = string_len;

    for (int i = string_len; i > -1; i--)
        if ((char) search_symbol == string[i])
            return &string[i];
    
    //while (i != -1)
    //{
    //    if ((char) search_symbol == string[i])
    //        return &string[i];
    //    i--;
    //}

    return (NULL);
}

int main(void)
{
    char string[] = "Hello, world!";
    char accept[] = "o";
    int counter_compares = 0;
    
    if (strpbrk(string, accept) == my_strpbrk(string, accept))
        counter_compares++;

    if (strspn(string, accept) == my_strspn(string, accept))
        counter_compares++;

    if (strcspn(string, accept) == my_strcspn(string, accept))
        counter_compares++;

    if (strchr(string, '\0') == my_strchr(string, '\0'))
        counter_compares++;

    if (strrchr(string, '\0') == my_strrchr(string, '\0'))
        counter_compares++;

    printf("%d\n", counter_compares);

    return EXIT_SUCCESS;
}
