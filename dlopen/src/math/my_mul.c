#include "my_mul.h"
#include "cli/cli_input.h"
#include <stdio.h>

void do_multiplication(void)
{
    long result, number1, number2;

    printf("\n Ведите первый множитель\n");
    number1 = get_user_number();
    printf("\n Ведите второй множитель\n");
    number2 = get_user_number();

    result = number1 * number2;
    printf("\n %ld * %ld = %ld\n", number1, number2, result);
}
