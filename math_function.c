#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void convertAbsolute(int *val);

/**
 * 数字の構造体
 */
struct Numbers {
    int _0;
    int _1;
    int _2;
    int _3;
};

int main(void)
{
    srand((unsigned)time(0));
    struct Numbers numbers;
    numbers._0 = rand() % 10;
    numbers._1 = rand() % 10;
    numbers._2 = rand() % 10;
    numbers._3 = rand() % 10;
    int array[5] = { numbers._0,numbers._1,numbers._2,numbers._3,0 };
    int *p = array;
    while (1) {
        if (*p == 0) { break; }
        printf("もとの値 : %d, ", *p);
        convertAbsolute(p);
        printf("絶対値 : %d\n", *p);
    }
    
}

void convertAbsolute(int *val)
{
    if (*val < 0) {
        *val *= -1;
    }
}
