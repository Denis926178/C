#include "check_errors.h"
#include "execute_modes.h"

#define SUMMARIZE           1
#define MULTIPLY            2
#define DETERMINANT         3

#define ERROR_MODE          4

int main(int argc, char *argv[])
{   
    int code_return = 0;

    if ((code_return = check_files_errors(argc, argv)))
        return code_return;

    int mode = 0;
    select_mode(argc, argv, &mode);

    switch (mode)
    {
        case SUMMARIZE:
            code_return = execute_summarize(argv);
            break;
        case MULTIPLY:
            code_return = execute_mupltiply(argv);
            break;
        case DETERMINANT:
            code_return = execute_determinant(argv);
            break;
        default:
            code_return = ERROR_MODE;
            break;
    }

    return code_return;
}
