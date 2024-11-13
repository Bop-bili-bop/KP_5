#ifndef VALIDATION_H
#define VALIDATION_H
#include <conio.h>
#include <ctype.h>
int validate_arraysize_input(char *prompt, int min, int max)
{
    int value = 0 ;
    int input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%d", &value);
        if (input != 1 || value < min || value > max)
        {
            printf("Invalid input. Please enter a valid number.\n");
            value = 0;
        }
        fflush(stdin);
    }
    while (input != 1 || value < min || value > max);
    return value;
}
double validate_char_input(char *prompt, char choice_1, char choice_2)
{
    char user_choice = 0;
    do
    {
        printf("%s", prompt);
        user_choice = getch();
        if (user_choice != choice_1 && user_choice != choice_2)
        {
            printf("Invalid input.\n");
        }
        fflush(stdin);
    }
    while (user_choice != choice_1 && user_choice != choice_2);
    return user_choice;
}
int is_whitespace_only( char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        {
        if (!isspace(str[i]))
        {
            return 0;  // Found a non-whitespace character
        }
    }
    return 1;  // Only whitespace characters
}
void trim_whitespace(char *str)
{
    int start = 0;
    while (isspace(str[start]))
    {
        start++;
    }

    // Trim trailing whitespace
    int end = strlen(str) - 1;
    while (end >= start && isspace(str[end]))
    {
        end--;
    }
    int length = end - start + 1;
    memmove(str, str + start, length);
    str[length] = '\0';
}
#endif
