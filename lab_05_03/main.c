#include <string.h>

#include "process.h"

#define ERROR_OPEN_FILE         -3
#define ERROR_CLOSE_FILE        -4
#define ERROR_INVALID_ARGS      -6

#define INDEX_OPTION            1
#define CREATE_ARGS_NUMBER      4
#define PRINT_ARGS_NUMBER       3
#define SORT_ARGS_NUMBER        3
#define CREATE_INDEX_FILE       3
#define PRINT_INDEX_FILE        2
#define SORT_INDEX_FILE         2
#define INDEX_COUNT_NUMBERS     2
#define EXECUTE_MODE_C          1
#define EXECUTE_MODE_P          2
#define EXECUTE_MODE_S          3

int select_mode(int const argc, char **argv, int *const mode)
{
    if (argc == CREATE_ARGS_NUMBER && strcmp(argv[INDEX_OPTION], "c") == 0)
        *mode = EXECUTE_MODE_C;
    else if (argc == PRINT_ARGS_NUMBER &&strcmp(argv[INDEX_OPTION], "p") == 0)
        *mode = EXECUTE_MODE_P;
    else if (argc == SORT_ARGS_NUMBER && strcmp(argv[INDEX_OPTION], "s") == 0)
        *mode = EXECUTE_MODE_S;
    else
        return ERROR_INVALID_ARGS;
    
    return EXIT_SUCCESS;
}

int execute_mode_c(const char *const filename, char *const count_number)
{
    FILE *const f = fopen(filename, "wb");
        
    if (f == NULL)
        return ERROR_OPEN_FILE;

    int code_return = input_numbers(f, count_number);

    if (fclose(f) == EOF)
        return ERROR_CLOSE_FILE;
    
    return code_return;
}

int execute_mode_p(const char *const filename)
{
    FILE *const f = fopen(filename, "rb");
    
    if (f == NULL)
        return ERROR_OPEN_FILE;
    
    int code_return = print_numbers(f);

    if (fclose(f) == EOF)
        return ERROR_CLOSE_FILE;
    
    return code_return;
}

int execute_mode_s(const char *const filename)
{
    FILE *const f = fopen(filename, "r+b");

    if (f == NULL)
        return ERROR_OPEN_FILE;

    int code_return = sort_bubble_numbers(f);

    if (fclose(f) == EOF)
        return ERROR_CLOSE_FILE;

    return code_return;
}

int main(int argc, char *argv[])
{
    int mode = 0;
    int code_return = select_mode(argc, argv, &mode);

    switch (mode)
    {
        case EXECUTE_MODE_C:
            code_return = execute_mode_c(argv[CREATE_INDEX_FILE], argv[INDEX_COUNT_NUMBERS]);
            break;
        case EXECUTE_MODE_P:
            code_return = execute_mode_p(argv[PRINT_INDEX_FILE]);
            break;
        case EXECUTE_MODE_S:
            code_return = execute_mode_s(argv[SORT_INDEX_FILE]);
            break;
    }

    return code_return;
}
