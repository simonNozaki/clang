#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 0から255までの整数を入力させ、その数値を二進数に変換する
 */
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    
    if (n == 0) {
    	printf("引数が整数ではありません。プログラムを終了します。\n");
        exit(1);
    } else if (n > 255 || n < 0) {
    	printf("引数が0以上255以下ではありません。プログラムを終了します。\n");
        exit(1);
    }
    
    // (2) 0x80との論理積
    int AND = n & 0x80;
    printf("AND: %d\n", AND);
    
    if(AND == 0) {
        printf("0");
    } else if (AND == 1) {
        printf("1");
    }
    
    // (3) 1ビット左にシフトする
    n = n << 1;
    printf("shifted: %d\n", n);
    
    if(n == 0){
        printf("\n");
        exit(0);
    }
    
    return 0;
}
