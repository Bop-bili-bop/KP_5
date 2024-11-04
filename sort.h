#ifndef SORT_H
#define SORT_H
#include <string.h>
void string_sort_ascending (char **mass, int num)
{
    int j = 0;
    for(int i=0;i<num-1;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if (strcmp(mass[i],mass[j]) > 0)
            {
                char *tmp = 0;
                tmp=mass[i];
                mass[i]=mass[j];
                mass[j]=tmp;
            }
        }
    }
}
void string_sort_descending (char **mass, int num)
{
    int j = 0;
    for(int i=0;i<num-1;i++)
    {
        for(j=i+1;j<num;j++)
        {
            if (strcmp(mass[i],mass[j]) < 0)
            {
                char *tmp = 0;
                tmp=mass[i];
                mass[i]=mass[j];
                mass[j]=tmp;
            }
        }
    }
}
#endif
