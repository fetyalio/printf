#include "main.h"

/**
 * get_width - Calculates the width for printing based on the format string.
 * @format: The formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 * @list: The list of arguments for va_arg when the width is '*'.
 *
 * Return: The width value.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_index;
    int width = 0;

    for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
    {
        if (is_digit(format[curr_index]))
        {
            width *= 10;
            width += format[curr_index] - '0';
        }
        else if (format[curr_index] == '*')
        {
            curr_index++;
            width = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_index - 1;

    return width;
}
