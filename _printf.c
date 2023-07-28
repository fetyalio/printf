#include "main.h"

void custom_print_buffer(char buffer[], int *buff_ind);

/**
 * custom_printf - Custom Printf function
 * @format_string: Format string.
 * Return: Number of characters printed.
 */
int custom_printf(const char *format_string, ...)
{
    int i, num_printed = 0, printed_chars = 0;
    int custom_flags, custom_width, custom_precision, custom_size, buff_ind = 0;
    va_list arg_list;
    char output_buffer[BUFF_SIZE];

    if (format_string == NULL)
        return (-1);

    va_start(arg_list, format_string);

    for (i = 0; format_string && format_string[i] != '\0'; i++)
    {
        if (format_string[i] != '%')
        {
            output_buffer[buff_ind++] = format_string[i];
            if (buff_ind == BUFF_SIZE)
                custom_print_buffer(output_buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            custom_print_buffer(output_buffer, &buff_ind);
            custom_flags = get_custom_flags(format_string, &i);
            custom_width = get_custom_width(format_string, &i, arg_list);
            custom_precision = get_custom_precision(format_string, &i, arg_list);
            custom_size = get_custom_size(format_string, &i);
            ++i;
            num_printed = custom_handle_print(format_string, &i, arg_list, output_buffer,
                                              custom_flags, custom_width, custom_precision, custom_size);
            if (num_printed == -1)
                return (-1);
            printed_chars += num_printed;
        }
    }

    custom_print_buffer(output_buffer, &buff_ind);

    va_end(arg_list);

    return (printed_chars);
}

/**
 * custom_print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void custom_print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}
