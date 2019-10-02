#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    if (argc != 3) {
        printf("2つの文字列を入力してください。プログラムを終了します。\n");
        exit(1);
    }
    // 配列の大きさ
    int size;
    
    char *arg1 = argv[1];
    char *arg2 = argv[2];
    
    size = (int)sizeof(arg1) + (int)sizeof(arg2);
    // 結果文字配列
    char output[size];
    
    
    return 0;
}
