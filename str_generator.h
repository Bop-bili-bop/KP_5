#ifndef STR_GENERATOR_H
#define STR_GENERATOR_H
#include <stdio.h>
#include <stdlib.h>
int random_int(int range_min, int range_max)
{
    return range_min + rand() % (range_max - range_min + 1);
}
char **random_string_array(int n_str, int str_size)
{
    char string_arr[n_str][str_size+1];
    char *string_addr[n_str];
    for(int i = 0; i < str_size; i ++)
    {
        for(int j = 0; j < str_size; j++)
        {
            string_arr[i][j] = random_int(48, 122);

        }
        printf("Random:%s\n", string_arr[i]);
    }
    return string_arr;
}
#endif
