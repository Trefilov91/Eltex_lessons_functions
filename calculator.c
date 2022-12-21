#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DECIMAL_DIGIT 5

void print_main_menu(void);
char get_user_input_simbol(void);
int get_user_input_string(char *, int);

long get_user_number(void);

void do_addition(void);
void do_subtraction(void);
void do_multiplication(void);
void do_division(void);

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

char get_user_input_simbol(void)
{
    char ret = 0, current_simbol = 0;
    int valid_iterations = 2;

    while(1){    
        ret = current_simbol;
        current_simbol = fgetc(stdin);
        valid_iterations--;

        if(current_simbol == '\n'){
            if(!valid_iterations){
                return ret;
            }
            else{
                printf("\n Введите корректное значение\n");
                valid_iterations = 2;
            }
        }    
    }    
}

int get_user_input_string(char *str, int max_string_size)
{
    int str_lenght = 0, valid_itteraton = 1;

    while(fgets(str, max_string_size, stdin) != NULL){
        str_lenght = strlen(str);
        valid_itteraton--;
        if(str[str_lenght - 1] == '\n'){
            if(!valid_itteraton && str_lenght > 1){
                return str_lenght;
            }
            else{
                printf("\n Введите от 1 до %d символов\n", max_string_size-2);
                memset(str, 0, max_string_size);
                valid_itteraton = 1;
            }
        }
    }
    return 0;
}

long get_user_number(void)
{
    char str[MAX_DECIMAL_DIGIT];
    char * end;
    long ret;
    
    get_user_input_string(str, MAX_DECIMAL_DIGIT);
    ret = strtol(str, &end, 0);
     
    return ret;
}

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
