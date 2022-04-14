#include <stdio.h>
#include <string.h>


int intexp(const int base, int n)
{
    int i, p = 1;

    for (i = 1; i < n; i++)
        p *= base;
    return p;
}


int parse(char* str)
{
    int num, i;
    int len = strlen(str);
    
    for (i = 0; i < len; i++)
    {
        int parsed = str[i] - '0';
        num += parsed * intexp(10, len - i);
    }
    return num;
}


int main(int argc, char* argv[])
{
    if (argc == 1)
        return 1;
    // Parse the input from the user. Expected input is something that represents an integer.
    printf("%i\n", parse(argv[1]));
    return 0;
}

