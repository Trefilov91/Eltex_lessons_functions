#include "calculator.h"
#include "my_math.h"
#include "cli_input.h"
#include <stdio.h>


int main()
{
    char menu_user_input;

    while(1)
    {    
        print_main_menu();

        menu_user_input = get_user_input_simbol();
        
        switch(menu_user_input)
        {
            case '1':
                do_addition();
                break;

            case '2':
                do_subtraction();
                break;

            case '3':
                do_multiplication();
                break;

            case '4':
                do_division();
                break;

            case '5':
                return 0;

            default:
                printf("\n Пожалуйста, выберете действие из списка\n\n");
                break;
        }
    }

    return 0;
}



void print_main_menu(void)
{
    printf("\n Выберете пунткт меню:\n\
            1. Сложение\n\
            2. Вычитание\n\
            3. Умножение\n\
            4. Деление\n\
            5. Выход\n");
}


