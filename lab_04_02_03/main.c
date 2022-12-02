#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN_STRING          256
#define MAX_SIZE_WORD           16
#define ERROR_TOO_LONG_WORD     20
#define ERROR_TOO_LONG_STRING   30
#define ERROR_READ_STRING       40
#define SEPARATORS              " .,;:?!-"

int is_separator(const char symbol, const char *const separators)
{
    for (size_t i = 0; i < strlen(separators); i++)
        if (symbol == separators[i])
            return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int split_to_words(const char *const string, char (*const array_words)[MAX_SIZE_WORD + 1], size_t *words_counter)
{
    size_t i = 0;

    while (i < strlen(string))
    {
        while (string[i] && !is_separator(string[i], SEPARATORS))
            i++;

        size_t string_len = strcspn(&string[i], SEPARATORS);
    
        if (string_len)
        {
            if (string_len > MAX_SIZE_WORD)
                return ERROR_TOO_LONG_WORD;

            size_t symbols_word_counter = 0;

            for (size_t j = i; j < i + string_len; j++)
                array_words[*words_counter][symbols_word_counter++] = string[j];

            array_words[(*words_counter)++][symbols_word_counter] = '\0';
            i += string_len;
        }
    }

    return EXIT_SUCCESS;
}

int input_string(char *const string, size_t *const size)
{
    char *code = fgets(string, MAX_LEN_STRING + 1, stdin);

    if (code == NULL)
        return ERROR_READ_STRING;

    *size = strlen(string);

    if (string[*size - 1] != '\n')
        return ERROR_TOO_LONG_STRING;
    
    string[*size - 1] = '\0'; 

    return EXIT_SUCCESS;
}

void create_new_string(char *const new_string,
char (*const array_words1)[MAX_SIZE_WORD + 1],
char (*const array_words2)[MAX_SIZE_WORD + 1],
const size_t number_words1,
const size_t number_words2,
size_t *const counter)
{
    int flag = 0;
    
    for (size_t i = 0; i < number_words1; i++)
    {
        for (size_t j = 0; j < number_words2; j++)
            if (strcmp(array_words1[i], array_words2[j]) == EXIT_SUCCESS)
                flag = 1;

        for (size_t j = 0; j < number_words1; j++)
            if (strcmp(array_words1[i], array_words1[j]) == EXIT_SUCCESS && i != j)
                flag = 1;

        if (!flag)
        {
            new_string[(*counter)++] = ' ';
            for (size_t j = 0;j < strlen(array_words1[i]); j++)
                new_string[(*counter)++] = array_words1[i][j];
        }

        flag = 0;
    }
}

int main(void)
{
    char string1[MAX_LEN_STRING + 1];
    char string2[MAX_LEN_STRING + 1];
    size_t size1, size2;

    int code_return = input_string(string1, &size1);

    if (code_return)
        return code_return;

    code_return = input_string(string2, &size2);

    if (code_return)
        return code_return;

    char array_words1[MAX_LEN_STRING / 2][MAX_SIZE_WORD + 1];
    char array_words2[MAX_LEN_STRING / 2][MAX_SIZE_WORD + 1];
    size_t number_words1 = 0, number_words2 = 0;

    code_return = split_to_words(string1, array_words1, &number_words1);
    
    if (code_return)
        return code_return;

    code_return = split_to_words(string2, array_words2, &number_words2);

    if (code_return)
        return code_return;

    char new_string[MAX_LEN_STRING * 2 + 1];
    size_t counter = 0;

    create_new_string(new_string, array_words1, array_words2, number_words1, number_words2, &counter);
    create_new_string(new_string, array_words2, array_words1, number_words2, number_words1, &counter);    
    new_string[counter] = '\0';

    if (strlen(new_string))
        printf("Result:%s", new_string);
    else
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
