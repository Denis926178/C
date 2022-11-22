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

void create_string(long int data, char *string_data, int *i, int type)
{
    if (type == 1)
        data = (int)data;
    else if (type == 2)
        data = (short int)data;

    if (data == 0)
        string_data[(*i)++] = '0';
    
    while (data > 0)
    {
        string_data[(*i)++] = data % 10 + '0';
        data /= 10;
    }
}

void input_minus(long int *data, int max_len, int *index, char *buffer, int *count, int type)
{
    if (type == 1)
        *data = (int)*data;
    else if (type == 2)
        *data = (short int)*data;

    if (*data < 0 && max_len > *index)
    {
        buffer[(*index)++] = '-';
        (*count)++;
        *data *= -1;
    }
    else if (*data < 0)
    {
        (*count)++;
        *data *= -1;
        (*index)++;
    }
}

void parse_d_i(long int data, int max_len, int *index, char *buffer, int type)
{
    if (type == 1)
        data = (int)data;
    else if (type == 2)
        data = (short int)data;
    
    int count = 0, i = 0;
    char string_data[1000];

    input_minus(&data, max_len, index, buffer, &count, type);
    create_string(data, string_data, &i, type);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_to_sys(unsigned long int data, char *string_data, int *i, int sys, int type)
{
    if (data == 0)
        string_data[(*i)++] = '0';
    
    if (type == 1)
        data = (unsigned int)data;
    else if (type == 2)
        data = (unsigned short int)data;

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

void copy_to_buffer(int i, int *index, char *buffer, char *string_data, int max_len)
{
    for (int j = 0; j < i; j++, ++*(index))
        if (max_len > *index)
            buffer[(*index)] = string_data[j];
}

void parse_o_x(unsigned long int data, int max_len, int *index, char *buffer, int sys, int type)
{
    int i = 0;

    if (type == 1)
        data = (unsigned int)data;
    else if (type == 2)
        data = (unsigned short int)data;

    char string_data[1000];

    parse_to_sys(data, string_data, &i, sys, type);
    reverse(string_data, i);
    copy_to_buffer(i, index, buffer, string_data, max_len);
}

void parse_c(char data, int max_len, int *index, char *buffer)
{
    if (max_len > *index)
        buffer[*(index)] = data;
    
    (*index)++;
}

void parse_s(char *data, int max_len, int *index, char *buffer)
{
    while (*data != '\0')
    {
        if (max_len > *index)
            buffer[(*index)] = (*data);
        (*index)++;
        data++;
    }
}

int my_snprintf(char *buffer, int num, char *format, ...)
{
    va_list args_list;
    int index = 0;
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
                    parse_d_i((long int)va_arg(args_list, long int), num, &index, buffer, 0);
                else if (*format == 'i')
                    parse_d_i((long int)va_arg(args_list, long int), num, &index, buffer, 0);
                else if (*format == 'o')
                    parse_o_x((unsigned long int)va_arg(args_list, unsigned long int), num, &index, buffer, 8, 0);
                else if (*format == 'x')
                    parse_o_x((unsigned long int)va_arg(args_list, unsigned long int), num, &index, buffer, 16, 0);
            }
            else if (*format == 'h')
            {
                format++;
                if (*format == 'd')
                    parse_d_i((int)va_arg(args_list, int), num, &index, buffer, 2);
                else if (*format == 'i')
                    parse_d_i((int)va_arg(args_list, int), num, &index, buffer, 2);
                else if (*format == 'o')
                    parse_o_x((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 8, 2);
                else if (*format == 'x')
                    parse_o_x((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 16, 2);
            }
            else
            {
                if (*format == 'c')
                    parse_c(va_arg(args_list, int), num, &index, buffer);
                else if (*format == 's')
                    parse_s(va_arg(args_list, char *), num, &index, buffer);
                else if (*format == 'd')
                    parse_d_i((int)va_arg(args_list, int), num, &index, buffer, 1);
                else if (*format == 'i')
                    parse_d_i((int)va_arg(args_list, int), num, &index, buffer, 1);
                else if (*format == 'o')
                    parse_o_x((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 8, 1);
                else if (*format == 'x')
                    parse_o_x((unsigned int)va_arg(args_list, unsigned int), num, &index, buffer, 16, 1);
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
    else if (num < index)
        *(buffer + num) = '\0';

    va_end(args_list);

    return index;
}
