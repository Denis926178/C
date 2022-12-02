#include "my_snprintf.h"

void reverse(char *data, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        char temp = data[i];
        data[i] = data[len - i - 1];
        data[len - i - 1] = temp;
    }
}

void input_minus_long(long int *data, size_t max_len, size_t *index, char *buffer)
{
    if (*data < 0 && max_len > *index)
        buffer[(*index)] = '-';
    if (*data < 0)
    {
        *data *= -1;
        (*index)++;
    }
}

void input_minus(int *data, size_t max_len, size_t *index, char *buffer)
{
    if (*data < 0 && max_len > *index)
        buffer[(*index)] = '-';
    if (*data < 0)
    {
        *data *= -1;
        (*index)++;
    }
}

void input_minus_short(short int *data, size_t max_len, size_t *index, char *buffer)
{
    if (*data < 0 && max_len > *index)
        buffer[(*index)] = '-';
    if (*data < 0)
    {
        *data *= -1;
        (*index)++;
    }
}

void parse_d_i_long(long int data, size_t max_len, size_t *index, char *buffer, int sys)
{    
    int i = 0;
    char string_data[1000];

    input_minus_long(&data, max_len, index, buffer);
    parse_to_sys_long(data, string_data, &i, sys);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_d_i(int data, size_t max_len, size_t *index, char *buffer, int sys)
{   
    int i = 0;
    char string_data[1000];

    input_minus(&data, max_len, index, buffer);
    parse_to_sys(data, string_data, &i, sys);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_d_i_short(short int data, size_t max_len, size_t *index, char *buffer, int sys)
{    
    int i = 0;
    char string_data[1000];

    input_minus_short(&data, max_len, index, buffer);
    parse_to_sys_short(data, string_data, &i, sys);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_to_sys_long(unsigned long int data, char *string_data, int *i, int sys)
{
    if (data == 0)
        string_data[(*i)++] = '0';

    while (data > 0)
    {
        int rest = data % sys;

        if (rest > 9)
            string_data[(*i)++] = rest + 'a' - 10;
        else
            string_data[(*i)++] = rest + '0';

        data /= sys;
    }
}

void parse_to_sys(unsigned int data, char *string_data, int *i, int sys)
{
    if (data == 0)
        string_data[(*i)++] = '0';

    while (data > 0)
    {
        int rest = data % sys;

        if (rest > 9)
            string_data[(*i)++] = rest + 'a' - 10;
        else
            string_data[(*i)++] = rest + '0';

        data /= sys;
    }
}

void parse_to_sys_short(unsigned short int data, char *string_data, int *i, int sys)
{
    if (data == 0)
        string_data[(*i)++] = '0';

    while (data > 0)
    {
        int rest = data % sys;

        if (rest > 9)
            string_data[(*i)++] = rest + 'a' - 10;
        else
            string_data[(*i)++] = rest + '0';

        data /= sys;
    }
}

void copy_to_buffer(int i, size_t *index, char *buffer, char *string_data, size_t max_len)
{
    for (int j = 0; j < i; j++, ++*(index))
        if (max_len > *index)
            buffer[(*index)] = string_data[j];
}

void parse_o_x_long(unsigned long int data, size_t max_len, size_t *index, char *buffer, int sys)
{
    int i = 0;
    char string_data[1000];

    parse_to_sys_long(data, string_data, &i, sys);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_o_x(unsigned int data, size_t max_len, size_t *index, char *buffer, int sys)
{
    int i = 0;
    char string_data[1000];

    parse_to_sys(data, string_data, &i, sys);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_o_x_short(unsigned short int data, size_t max_len, size_t *index, char *buffer, int sys)
{
    int i = 0;
    char string_data[1000];

    parse_to_sys_short(data, string_data, &i, sys);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_c(char data, size_t max_len, size_t *index, char *buffer)
{
    if (max_len > *index)
        buffer[*(index)] = data;
    
    (*index)++;
}

void parse_s(char *data, size_t max_len, size_t *index, char *buffer)
{
    while (*data != '\0')
    {
        if (max_len > *index)
            buffer[(*index)] = (*data);
        (*index)++;
        data++;
    }
}

int my_snprintf(char *buffer, size_t num, char *format, ...)
{
    va_list args_list;
    size_t index = 0;
    va_start(args_list, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'l')
            {
                format++;
                if (*format == 'd')
                    parse_d_i_long((long int)va_arg(args_list, long int), num, &index, buffer, 10);
                else if (*format == 'i')
                    parse_d_i_long((long int)va_arg(args_list, long int), num, &index, buffer, 10);
                else if (*format == 'o')
                    parse_o_x_long((unsigned long int)va_arg(args_list, unsigned long int), num, &index, buffer, 8);
                else if (*format == 'x')
                    parse_o_x_long((unsigned long int)va_arg(args_list, unsigned long int), num, &index, buffer, 16);
            }
            else if (*format == 'h')
            {
                format++;
                if (*format == 'd')
                    parse_d_i_short((int)va_arg(args_list, int), num, &index, buffer, 10);
                else if (*format == 'i')
                    parse_d_i_short((int)va_arg(args_list, int), num, &index, buffer, 10);
                else if (*format == 'o')
                    parse_o_x_short((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 8);
                else if (*format == 'x')
                    parse_o_x_short((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 16);
            }
            else
            {
                if (*format == 'c')
                    parse_c(va_arg(args_list, int), num, &index, buffer);
                else if (*format == 's')
                    parse_s(va_arg(args_list, char *), num, &index, buffer);
                else if (*format == 'd')
                    parse_d_i((int)va_arg(args_list, int), num, &index, buffer, 10);
                else if (*format == 'i')
                    parse_d_i((int)va_arg(args_list, int), num, &index, buffer, 10);
                else if (*format == 'o')
                    parse_o_x((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 8);
                else if (*format == 'x')
                    parse_o_x((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 16);
                else if (*format == '%')
                    parse_c('%', num, &index, buffer);
            }
        }
        else 
        {
            if (num > index)
                buffer[index] = *format;
            index++;
        }
        format++;
    }

    if (num == index && num != 0)
        *(buffer + index - 1) = '\0';
    else if (num > index)
        *(buffer + index) = '\0';
    else if (num < index && num != 0)
        *(buffer + num - 1) = '\0';
    else if (buffer != NULL)
        *buffer = '\0';
    
    va_end(args_list);

    return index;
}
