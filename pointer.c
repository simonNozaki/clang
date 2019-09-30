#include <stdio.h>
#include <stdlib.h>

/*
 プロトタイプ宣言
 */
void print();
void printAddressAndValue();


int main(void)
{
    
    void (*pprint)();
    
    pprint = print;
    
    printf("size of function pointer: %d\n", (int)sizeof(pprint));
    
    pprint();
    
    return 0;
}

/**
 * 標準出力
 */
void print()
{
    printf("standard output.\n");
}

/**
 * アドレスと値をそれぞれ出力
 */
void printAddressAndValue()
{
    int p, r;
    
    // ポインタ変数
    int *q;
    
    p = 10;
    
    printf("value of p : %d\n", p);
    printf("value of r : %d\n", r);
    
    printf("address of p : %p\n", &p);
    printf("address of q : %p\n", &q);
    printf("address of r : %p\n", &r);
    
    q = &r;
    
    r = 20;
    
    printf("value of p : %d\n", p);
    printf("value of q : %d\n", *q);
    printf("value of r : %d\n", r);
}


