#include<stdio.h>

char *mallocTest()
{
    char *str = malloc(10 * sizeof(char));

    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = '\0';

    return str;
}

int main()
{
    char *str = mallocTest();

    printf("%s\n", str);

    free(str);
    str = NULL;
    return 1;
}