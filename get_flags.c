#include "main.h"

/**
 * get_flags - Calculates the active flags for the printf format string.
 * @format: The formatted string in which to print the arguments.
 * @i: Pointer to the current index in the format string.
 * Return: Integer representing the active flags.
 */
int get_flags(const char *format, int *i)
{
    /* The characters corresponding to the flags: - + 0 # ' ' */
    const char FLAGS_CH[] = { '-', '+', '0', '#', ' ', '\0' };

    /* The corresponding integer values for each flag: F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE */
    const int FLAGS_ARR[] = { F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0 };

    int flags = 0;
    int curr_index;

    for (curr_index = *i + 1; format[curr_index] != '\0'; curr_index++)
    {
        for (int j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[curr_index] == FLAGS_CH[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        if (FLAGS_CH[j] == 0)
            break;
    }

    *i = curr_index - 1;

    return flags;
}

