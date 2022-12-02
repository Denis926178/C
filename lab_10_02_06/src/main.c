#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "execute_modes.h"

#define READ_COMMAND    1
#define LEN_COMMAND     4

#define ERROR_OPTION    1

int main(void)
{
    char command[LEN_COMMAND];

    if (scanf("%s", command) != READ_COMMAND)
        return EXIT_FAILURE;

    int code_return;

    if (!strcmp(command, "out"))
        code_return = execute_print();
    else if (!strcmp(command, "add"))
        code_return = execute_summarize();
    else if (!strcmp(command, "mul"))
        code_return = execute_multiply();
    else if (!strcmp(command, "lin"))
        code_return = execute_delete_element();
    else
        return ERROR_OPTION;

    return code_return;
}