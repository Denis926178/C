#include "process.h"

int main(void)
{
    int position = 0;
    int code_return = process(stdin, &position);
     
    if (code_return == EXIT_SUCCESS)
        printf("%d\n", position);

    return code_return;
}
