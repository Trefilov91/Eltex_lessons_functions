#include "my_math.h"
#include "cli_input.h"
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