#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE_STRING         256
#define ERROR_TOO_LONG_WORD     20
#define ERROR_TOO_LONG_STRING   30
#define ERROR_READ_STRING       40
#define MAX_SIZE_WORD           16
#define SEPARATORS              " .,;:?!-"

int is_separator(const char symbol, const char *const separators)
{
    for (size_t i = 0; i < strlen(separators); i++)
        if (symbol == separators[i])
            return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int split_to_words(const char *const string, char (*array_words)[MAX_SIZE_WORD + 1], size_t *const words_counter)
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
    char *code = fgets(string, MAX_SIZE_STRING + 1, stdin);

    if (code == NULL)
        return ERROR_READ_STRING;

    *size = strlen(string); 

    if (string[*size - 1] != '\n')
        return ERROR_TOO_LONG_STRING;

    string[*size - 1] = '\0';

    return EXIT_SUCCESS;
}

size_t modify_word(char *const word)
{   
    size_t len_word = strlen(word);

    for (size_t i = 0; i < len_word; i++)
    {
        int flag = 1;

        for (size_t j = 0; j < i; j++)
            if (word[i] == word[j] && flag)
            {
                for (size_t k = i; k < len_word - 1; k++)
                    word[k] = word[k + 1];

                len_word--;
                i--;
                flag = 0;
            }
    }

    return len_word;
}

void create_new_string(char *const new_string,
char (*const array_words)[MAX_SIZE_WORD + 1],
size_t *const counter,
size_t const number_words)
{
    for (int i = number_words - 1; i > -1; i--)
        if (strcmp(array_words[i], array_words[number_words - 1]))
        {
            new_string[(*counter)++] = ' ';
            size_t len_word = modify_word(array_words[i]);

            for (size_t j = 0; j < len_word; j++)
                new_string[(*counter)++] = array_words[i][j];
        }
}

int main(void)
{
    char string[MAX_SIZE_STRING + 1];
    size_t size;
    int code_return = input_string(string, &size);

    if (code_return)
        return code_return;

    char array_words[MAX_SIZE_STRING / 2][MAX_SIZE_WORD + 1];
    size_t number_words = 0;
    code_return = split_to_words(string, array_words, &number_words);
    
    if (code_return)
        return code_return;

    char new_string[MAX_SIZE_STRING + 1];
    size_t counter = 0;  
    create_new_string(new_string, array_words, &counter, number_words);
    new_string[counter] = '\0';
 
    if (strlen(new_string))
        printf("Result:%s\n", new_string);
    else
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
