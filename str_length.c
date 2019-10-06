#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count(char *operand);


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("入力文字列は一つのみです。プログラムを終了します。\n");
        exit(1);
    }
    
    printf("length: %d\n", (int)strlen(argv[1]));
    
    printf("length: %d\n", count(argv[1]));
    
    return 0;
        
}


/**
 * 文字列の長さをカウントする
 */
int count(char *operand)
{
    int counter = 0;
    
    // 渡された文字ポインタをインクリメントして判定する
    while (*operand++ != '\0') {
        counter++;
    }
    
    return counter;
    
}
