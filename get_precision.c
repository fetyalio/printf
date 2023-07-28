#include "main.h"

/**
 * get_precision - Calculates the precision for printing based on the format string.
 * @format: The formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 * @list: The list of arguments for va_arg when the precision is '*'.
 *
 * Return: The precision value.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_index = *i + 1;
    int precision = -1;

    if (format[curr_index] != '.')
        return precision;

    precision = 0;

    for (curr_index += 1; format[curr_index] != '\0'; curr_index++)
    {
        if (is_digit(format[curr_index]))
        {
            precision *= 10;
            precision += format[curr_index] - '0';
        }
        else if (format[curr_index] == '*')
        {
            curr_index++;
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_index - 1;

    return precision;
}
