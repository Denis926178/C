#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE_STRING         256
#define ERROR_TOO_LONG_STRING   30 
#define ERROR_READ_STRING       40
#define NUMBER_DIGITS_CENTER    3
#define NUMBER_DIGITS_END       2
#define NUMBER_PAIRS_DIGITS     2

int input_string(char *const string, size_t *const size)
{
    char *code = fgets(string, MAX_SIZE_STRING + 1, stdin);

    if (code == NULL)
        return ERROR_READ_STRING;

    *size = strlen(string);

    if (string[*size - 1] != '\n')
        return ERROR_TOO_LONG_STRING;

    return EXIT_SUCCESS;
}

void skip_space(const char *const string, size_t *const i)
{
    while (isspace(string[*i]))
        (*i)++;
}

void skip_code_country(const char *const string, size_t *const i)
{
    if (string[*i] == '+')
        (*i)++;

    while (isdigit(string[*i]))
        (*i)++;
}

int check_digits(const char *const string, size_t *const i, const size_t number_digits)
{
    size_t counter = 0;
    
    while (isdigit(string[(*i)]))
    {
        (*i)++;
        counter++;
    }

    if (number_digits != counter)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int check_code_operator(const char *const string, size_t *const i)
{
    if (string[(*i)] != '(')
        return EXIT_FAILURE;

    (*i)++;
    int code_return = check_digits(string, i, NUMBER_DIGITS_CENTER);

    if (code_return)
        return code_return;

    if (string[(*i)] != ')')
        return EXIT_FAILURE;
     
    (*i)++;

    return EXIT_SUCCESS;
}


int check_phone_number(char *const string, size_t const len_string)
{
    size_t i = 0;

    skip_space(string, &i);
    skip_code_country(string, &i);

    int code_return = check_code_operator(string, &i);
    
    if (code_return)
        return code_return;
    
    if (string[i] != '-')
        return EXIT_FAILURE;
    
    i++;
    code_return = check_digits(string, &i, NUMBER_DIGITS_CENTER);
    
    if (code_return)
        return code_return;

    for (int j = 0; j < NUMBER_PAIRS_DIGITS; j++)
    {
        if (string[i] != '-')
            return EXIT_FAILURE;
        
        i++;
        code_return = check_digits(string, &i, NUMBER_DIGITS_END);

        if (code_return)
            return code_return;
    }
    
    while (isspace(string[i]) && i < len_string)
        i++;
    
    if (i != len_string)
        return EXIT_FAILURE;
    
    return EXIT_SUCCESS;
}

int main(void)
{
    char string[MAX_SIZE_STRING + 1];
    size_t size;
    int code_return = input_string(string, &size);
    
    if (code_return)
        return code_return;

    code_return = check_phone_number(string, size);

    if (code_return == EXIT_SUCCESS)
        printf("YES\n");
    else
        printf("NO\n");

    return EXIT_SUCCESS;
}
