#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SYS_NUM 10
#define INPUT_NUMBER 1

int find_temp_figure(int number, int counter)
{   
    while (number > pow(SYS_NUM, counter))
        number /= SYS_NUM;

    int last_figure = number % SYS_NUM;

    return last_figure;
}

void print_number(int number)
{
    int counter = 1;
    int current_figure, part_number;
    int clone_number = number;

    while (number > 0)
    {
        part_number = clone_number;
        current_figure = find_temp_figure(part_number, counter);

        printf("%d", current_figure);

        number /= SYS_NUM;
        counter++;
    }
}

int main(void)
{
    int number;

    if (scanf("%d", &number) != INPUT_NUMBER || number <= 0)
        return EXIT_FAILURE;
    
    print_number(number);

    return EXIT_SUCCESS;
}
