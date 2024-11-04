#ifndef VALIDATION_H
#define VALIDATION_H
unsigned validate_arraysize_input(const char *prompt)
{
    int value = 0 ;
    int input = 0;
    do
    {
        printf("%s", prompt);
        input = scanf("%d", &value);
        if (input != 1 || value < 2 || value > 10000)
        {
            printf("Invalid input. Please enter a valid number.\n");
            value = 0;
        }
        fflush(stdin);
    }
    while (input != 1 || value < 2 || value > 10000);
    return value;
}
#endif
