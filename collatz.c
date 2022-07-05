#include<stdio.h>
#include<stdlib.h>

int collatz(int n)
{
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
    else
        return 1 + collatz(3 * n + 1);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 1;
    printf("%d\n", collatz(atoi(argv[1])));
	return 0;
}

