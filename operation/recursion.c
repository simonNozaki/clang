#include <stdio.h>
#include <stdlib.h>

unsigned int factorial(unsigned int number);

int main(int argc, char *argv[])
{
    
    int in = atoi(argv[1]);
    if (in == 0) {
        exit(0);
    }
    
    int result = factorial(in);
    
    printf("%d\n", result);
}

unsigned int factorial(unsigned int number)
{
    if (number != 1) {
        number = number * factorial(number - 1);
        return number;
    }
    
    return number;
}
