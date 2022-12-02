#include "process.h"

#define ERROR_OPEN_FILE         -1
#define ERROR_INPUT_FILE        -3
#define ERROR_CLOSE_FILE        -5

#define ARGS_NUMBER              2
#define INDEX_FILE               1

int execute(const char *const filename)
{
    FILE *const f = fopen(filename, "r");

    if (f == NULL)
        return ERROR_OPEN_FILE;

    int counter_number;
    int code_return = find_count_numbers(f, &counter_number);

    if (fclose(f) == EOF)
        return ERROR_CLOSE_FILE; 

    if (!code_return)
        printf("%d\n", counter_number);
    
    return code_return;
}

int main(int argc, char *argv[])
{
    if (argc != ARGS_NUMBER)
        return ERROR_INPUT_FILE;

    int code_return = execute(argv[INDEX_FILE]);

    return code_return;
}
