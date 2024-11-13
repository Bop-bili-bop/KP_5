#include <stdio.h>
#include <string.h>
#include "validation.h"
#include "randomize_output.h"
#include "sort.h"
#include <time.h>
#include <conio.h>
#define STR_SIZE_MIN 1
#define STR_SIZE_MAX 100
#define STR_N_MIN 3
#define STR_N_MAX 1000
#define RANDOM_RANGE_MIN 65
#define RANDOM_RANGE_MAX 122
int main()
{
    do
    {
        printf("This program sorts inputed or randomly generated strings (3 - 1000 strings)\n");
        printf("WARNING!!! This program only works with LATIN symbols\n");
        srand(time(NULL));
        int str_size = 0;
        int n_str = 0;
        str_size = validate_arraysize_input("Enter string size:\n", STR_SIZE_MIN, STR_SIZE_MAX);
        n_str = validate_arraysize_input("Enter number of strings:\n", STR_N_MIN, STR_N_MAX);
        char string_value[n_str][str_size+1] = {};
        char *string_address[n_str] = {};
        char user_choice = 0;
        user_choice = validate_char_input("Type 'r' for random 'm' to enter strings manually\n", 'r', 'm');
        if (user_choice == 'm')
        {
            int i = 0;
            while(i < n_str)
            {
                do
                {
                    printf("Enter string[%d]:\n", i + 1);
                    fgets(string_value[i], str_size + 2, stdin);
                    if (string_value[i][strcspn(string_value[i], "\n")] != '\n' || is_whitespace_only(string_value[i]) == 1)
                    {
                        printf("Invalid input. Please enter a string with no more than %d characters.\n", str_size);
                        strcpy(string_value[i], "\n");
                        fflush(stdin);

                    }
                    else
                    {
                        trim_whitespace(string_value[i]);
                        string_value[i][strcspn(string_value[i], "\n")] = '\0';
                        string_address[i] = string_value[i];
                    }
                }
                while(string_value[i][strcspn(string_value[i], "\n")] != '\0');
                i++;
            }
        }
        else
        {
            for (int i = 0; i < n_str; i++)
            {
                for (int j = 0; j < str_size; j++)
                {
                    string_value[i][j] = random_char(RANDOM_RANGE_MIN, RANDOM_RANGE_MAX);
                    string_address[i] = string_value[i];
                }
                string_value[i][str_size] = '\0';
                fflush(stdin);
            }
        }
        do
        {
            print_array(string_address, n_str, "---BEFORE SORTING---\n");
            user_choice = validate_char_input("Type 'a' for ascending sort 'd' for descending sort\n", 'a', 'd');
            user_choice == 'a'
                        ? string_sort_ascending(string_address, n_str)
                        : string_sort_descending(string_address, n_str);
            print_array(string_address, n_str, "---AFTER SORTING---\n");
            printf("Press r to repeat, any other key to continue\n");
        }
        while (getch() == 'r');
        printf("Press Q to exit, any other key to continue...\n");
    }
    while (getch() != 'Q');
    return 0;
}