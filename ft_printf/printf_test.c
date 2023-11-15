#include "include/ft_printf_bonus.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value;
    int real;

    printf("Test 1:\n");
    value = ft_printf("1. [%5c %-10.5s %+d]\n", 'A', "Hello", 123);
    real = printf("1. [%5c %-10.5s %+d]\n", 'A', "Hello", 123);
    printf("returned: %d, real: %d\n", value, real);

    int nbr = 42;
    printf("Test 2:\n");
    value = ft_printf("2. [Pointer: %p, Unsigned: %010u]\n", &value, 98765);
    real = printf("2. [Pointer: %p, Unsigned: %010u]\n", &value, 98765);
    printf("returned: %d, real: %d\n", value, real);

    printf("Test 3:\n");
    value = ft_printf("3. [Lower: %#x, Upper: %#X, Integer: %+i]\n", 0xABCD, 0x1234, -9876);
    real = printf("3. [Lower: %#x, Upper: %#X, Integer: %+i]\n", 0xABCD, 0x1234, -9876);
    printf("returned: %d, real: %d\n", value, real);

    printf("Test 4:\n");
    value = ft_printf("4. [String: %.6s, Char: %c]\n", NULL, '\0');
    real = printf("4. [String: %.6s, Char: %c]\n", NULL, '\0');
    printf("returned: %d, real: %d\n", value, real);


    printf("Test 5:\n");
    int *null_ptr = NULL;
    value = ft_printf("5. [Integer: %+06d, Pointer: %-.5p]\n", 123, null_ptr);
    real = printf("5. [Integer: %+06d, Pointer: %-.5p]\n", 123, null_ptr);
    printf("returned: %d, real: %d\n", value, real);

    printf("Test 6:\n");
    value = ft_printf("6. [Unsigned: %10.5u, Hex: %#08x]\n", 98765, 0xABCD);
    real = printf("6. [Unsigned: %10.5u, Hex: %#08x]\n", 98765, 0xABCD);
    printf("returned: %d, real: %d\n", value, real);

    printf("Test 7:\n");
    value = ft_printf("7. [Integer: %-8.4i, String: %.3s]\n", 12345, "Testing123");
    real = printf("7. [Integer: %-8.4i, String: %.3s]\n", 12345, "Testing123");
    printf("returned: %d, real: %d\n", value, real);

    printf("Test 8:\n");
    value = ft_printf("8. [Uppercase Hex: %15.8X, Char: %2c]\n", 0x1234, 'Z');
    real = printf("8. [Uppercase Hex: %15.8X, Char: %2c]\n", 0x1234, 'Z');
    printf("returned: %d, real: %d\n", value, real);

    printf("Test 9:\n");
    value = ft_printf("9. [Integer: %+d, Unsigned: %#u]\n", 0, 0);
    real = printf("9. [Integer: %+d, Unsigned: %#u]\n", 0, 0);
    printf("returned: %d, real: %d\n", value, real);

    char *str = "Hello, World!";
    printf("Test 10:\n");
    value = ft_printf("10. [String: %15.8s, Pointer: %p]\n", str, str);
    real = printf("10. [String: %15.8s, Pointer: %p]\n", str, str);
    printf("returned: %d, real: %d\n", value, real);
}