#ifndef STR_GENERATOR_H
#define STR_GENERATOR_H
#include <stdio.h>
#include <stdlib.h>
char random_char(int range_min, int range_max)
{
    char generated_char = range_min + rand() % (range_max - range_min + 1);
    if (generated_char > 90 && generated_char < 97)
    {
        generated_char += 6;
    }
    return generated_char;
}
void print_array(char **array, int size, char *prompt)
{
    printf("%s", prompt);
    for (int i = 0; i < size; i++)
    {
        printf("String #%d ->%s\n", i+1, array[i]);
    }
}
#endif
