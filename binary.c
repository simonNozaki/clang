#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    
    if (n == 1) {
    	printf("引数が整数ではありません。プログラムを終了します。");
    } else if (n > 255 || n < 0) {
    	printf("引数が0以上255以下ではありません。プログラムを終了します。");
    }
    
    int AND = n | 0x80;
    
    return 0;
}