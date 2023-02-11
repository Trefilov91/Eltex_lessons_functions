#include "cli_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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