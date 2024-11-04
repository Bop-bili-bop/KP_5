#ifndef STR_GENERATOR_H
#define STR_GENERATOR_H
#include <stdio.h>
#include <stdlib.h>
char random_int(int range_min, int range_max)
{
    return range_min + rand() % (range_max - range_min + 1);
}
void print_array(char **array, int size, char *prompt)
{
    printf(prompt);
    for (int i = 0; i < size; i++)
    {
        printf("String #%d: %s\n", i+1, array[i]);
    }
}
#endif
