#include <stdio.h>
#include <string.h>
#include "validation.h"
#include "randomize_output.h"
#include "sort.h"
#include <time.h>
int main()
{
    do
    {
        printf("This program sorts inputed or randomly generated strings\n");
        srand(time(NULL));
        unsigned str_size = 0;
        unsigned n_str = 0;
        str_size = validate_arraysize_input("Enter string size:\n");
        n_str = validate_arraysize_input("Enter number of strings:\n");
        str_size++;
        char string_value[n_str][str_size];
        char *string_address[n_str];
        char output_type = 0;
        do
        {
            printf("Type 'r' for random 'h' to enter strings by hand\n");
            output_type = getchar();
            if (output_type != 'r' && output_type != 'h')
            {
                printf("Invalid input.\n");
            }
            fflush(stdin);
        }
        while (output_type != 'r' && output_type != 'h');
        if (output_type == 'h')
        {
            for (unsigned i = 0; i < n_str; i++)
            {
                printf("Enter string[%d]:\n", i+1);
                if (fgets(string_value[i], str_size, stdin) != NULL)
                {
                    string_value[i][strcspn(string_value[i], "\n")] = '\0';
                    string_address[i] = string_value[i];
                    fflush(stdin);
                }
                else
                {
                    printf("Inputed string is longer than input size\n");
                    fflush(stdin);
                }
            }
        }
        else
        {
            for (int i = 0; i < n_str; i++)
            {
                for (int j = 0; j < str_size-1; j++)
                {
                    string_value[i][j] = random_int(67, 90);
                    string_address[i] = string_value[i];
                }
                string_value[i][str_size] = '\0';
                printf("Random:%s\n", string_value[i]);
                fflush(stdin);
            }
        }
        print_array(string_address,n_str, "---BEFORE SORTING---\n");
        do
        {
            printf("Type 'a' for ascending sort 'd' for descending sort\n");
            output_type = getchar();
            if (output_type != 'a' && output_type != 'd')
            {
                printf("Invalid input.\n");
            }
            fflush(stdin);
        }
        while (output_type != 'a' && output_type != 'd');
        output_type == 'a'
        ? string_sort_ascending(string_address, n_str)
        : string_sort_descending(string_address, n_str);
        print_array(string_address,n_str, "---AFTER SORTING---\n");
    }
    while (getchar() != 'Q');
    return 0;
}
