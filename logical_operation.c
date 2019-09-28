#include <stdio.h>
#include <stdlib.h>

/*
 
 入力された文字列をを16進数表記で出力する
 */
int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("引数が足りません。プログラムを終了します。\n");
        return 1;
    }
    
    char *in = argv[1];
    
    while (1) {
        if (in == "\0") { break; } 
        printf("%x ", *in);
        in++;
    }
    
    return 0;
}
