#include <stdio.h>
#include <string.h>
#include "validation.h"
#include "str_generator.h"
#include "sort.h"
#include <time.h>
int main() {
    srand(time(NULL));
    unsigned str_size = 0;
    unsigned n_str = 0;
    str_size = validate_arraysize_input("Enter string size:\n");
    n_str = validate_arraysize_input("Enter number of strings:\n");
    char string_value[n_str][str_size+1];
    char *string_address[n_str];
    /*for (unsigned i = 0; i < n_str; i++)
    {
        printf("Enter string[%d]:\n", i+1);
        if (fgets(string_value[i], str_size+1, stdin) != NULL)
        {
            string_value[i][strcspn(string_value[i], "\n")] = '\0';
            string_address[i] = string_value[i];
            fflush(stdin);
        }
        else
        {
            printf("Error");
        }
    }
    printf("---BEFORE SORTING---\n");
    for (int i = 0; i < n_str; i++)
    {
        printf("String #%d:%s\n", i+1, string_address[i]);
    }
    string_sort_ascending(string_address, n_str);
    printf("---AFTER SORTING---\n");
    for (int i = 0; i < n_str; i++)
    {
        printf("String #%d:%s\n", i+1, string_address[i]);
    }
    string_sort_descending(string_address, n_str);
    printf("---AFTER SORTING---\n");
    for (int i = 0; i < n_str; i++)
    {
        printf("String #%d:%s\n", i+1, string_address[i]);
    }*/
    char random_array_value[n_str][str_size+1];
    char *random_array_addr[n_str];
    for(int i = 0; i < str_size; i ++)
    {
        for(int j = 0; j < str_size; j++)
        {
            random_array_value[i][j] = random_int(48, 122);
        }
        printf("Random:%s\n", random_array_value[i]);
        string_sort_ascending(random_array_addr , str_size);
    }
    return 0;
}
