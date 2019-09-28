#include <stdio.h>
#include <stdlib.h>

int main(void)
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
    
    return 0;
}
