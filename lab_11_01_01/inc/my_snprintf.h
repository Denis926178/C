#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void reverse(char *data, int len);
void parse_d_i(long int data, int max_len, int *index, char *buffer, int type);
int my_snprintf(char *buf, int num, char *format, ...);
void input_minus(long int *data, int max_len, int *index, char *buffer, int *count, int type);
void create_string(long int data, char *string_data, int *i, int type);
void parse_o_x(unsigned long int data, int max_len, int *index, char *buffer, int sys, int type);
void copy_to_buffer(int i, int *index, char *buffer, char *string_data, int max_len);
void parse_to_sys(unsigned long int data, char *string_data, int *i, int sys, int type);
void parse_c(char data, int max_len, int *index, char *buffer);
void parse_s(char *data, int max_len, int *index, char *buffer);

#endif
