#include "calculator.h"
#include "my_add.h"
#include "my_div.h"
#include "my_mul.h"
#include "my_sub.h"
#include "cli/cli_input.h"
#include <dlfcn.h>
#include <stdio.h>

void *add_so;
void *sub_so;
void *mul_so;
void *div_so;

void (*addition)(void) = NULL;
void (*subtraction)(void) = NULL;
void (*multiplication)(void) = NULL;
void (*division)(void) = NULL;

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
                if(addition == NULL){
                    add_so = dlopen ("libmy_add.so", RTLD_LAZY);
                    addition = dlsym(add_so, "do_addition");
                }
                addition();
                break;

            case '2':
                if(subtraction == NULL){
                    sub_so = dlopen ("libmy_sub.so", RTLD_LAZY);
                    subtraction = dlsym(sub_so, "do_subtraction");
                }
                subtraction();
                break;

            case '3':
                if(multiplication == NULL){
                    mul_so = dlopen ("libmy_mul.so", RTLD_LAZY);
                    multiplication = dlsym(mul_so, "do_multiplication");
                }
                multiplication();
                break;

            case '4':
                if(division == NULL){
                    div_so = dlopen ("libmy_div.so", RTLD_LAZY);
                    division = dlsym(div_so, "do_division");
                }
                division();
                break;

            case '5':
                if(add_so != NULL)
                    dlclose(add_so);
                if(sub_so != NULL)
                    dlclose(sub_so);
                if(mul_so != NULL)
                    dlclose(mul_so);
                if(div_so != NULL)
                    dlclose(div_so);
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


