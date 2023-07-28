#include "main.h"

/**
 * get_size - Calculates the size specifier for the printf format string.
 * @format: The formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 *
 * Return: The size specifier value (S_LONG or S_SHORT) or 0 if no size specifier found.
 */
int get_size(const char *format, int *i)
{
    int curr_index = *i + 1;
    int size = 0;

    if (format[curr_index] == 'l')
        size = S_LONG;
    else if (format[curr_index] == 'h')
        size = S_SHORT;

    if (size == 0)
        *i = curr_index - 1;
    else
        *i = curr_index;

    return size;
}

