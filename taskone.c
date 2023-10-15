#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - entry point
 * @format: variables
 *
 * Return: the counting
 * */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++;  // Move past '%'
            switch (*format) {
                case 'c':
                    // Handle character
                    count += printf("%c", va_arg(args, int));
                    break;
                case 's':
                    // Handle string
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    // Handle '%'
                    count += printf("%%");
                    break;
                case 'd':
                case 'i':
                    // Handle integer
                    count += printf("%d", va_arg(args, int));
                    break;
                default:
                    // Invalid specifier, ignore for simplicity
                    break;
            }
        } else {
            // Regular character, print as is
            putchar(*format);
            count++;
        }
        format++;  // Move to the next character in the format string
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Integer: %d, Character: %c\n", 42, 'A');
    return 0;
}
