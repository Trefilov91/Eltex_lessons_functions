#include "my_div.h"
#include "cli/cli_input.h"
#include <stdio.h>

void do_division(void)
{
    long result, number1, number2;

    printf("\n Ведите делимое\n");
    number1 = get_user_number();
    printf("\n Ведите делитель\n");
    number2 = get_user_number();

    result = number1 / number2;
    printf("\n %ld / %ld = %ld\n", number1, number2, result);
}