#include "my_sub.h"
#include "cli/cli_input.h"
#include <stdio.h>

void do_subtraction(void)
{
    long result, number1, number2;

    printf("\n Ведите уменьшаемое\n");
    number1 = get_user_number();
    printf("\n Ведите вычитаемое\n");
    number2 = get_user_number();

    result = number1 - number2;
    printf("\n %ld - %ld = %ld\n", number1, number2, result);
}
