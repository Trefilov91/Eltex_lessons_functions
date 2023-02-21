#include "my_add.h"
#include "cli/cli_input.h"
#include <stdio.h>

void do_addition(void)
{
    long result, number1, number2;

    printf("\n Ведите первое слагаемое\n");
    number1 = get_user_number();
    printf("\n Ведите второе слагаемое\n");
    number2 = get_user_number();

    result = number1 + number2;
    printf("\n %ld + %ld = %ld\n", number1, number2, result);
}
