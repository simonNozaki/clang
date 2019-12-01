#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------
// プロトタイプ宣言
// -------------------------
int count(char *s);
int equals(char *arg1, char *arg2);


int main(int argc, char *argv[])
{
    
    if (argc != 3) {
        printf("入力文字列は一つのみです。プログラムを終了します。\n");
        exit(1);
    }
    
    if (equals(argv[1], argv[2]) == 0) {
        printf("入力文字列は同一です。");
    } else {
        printf("入力文字列は同一ではありません。");
    }
    
    printf("\n");
    
    return 0;
}

/**
 * ２つの文字列ｈが等しいことを確認します。
 * @param arg1
 * @param arg2
 * @return 0/1
 */
int equals(char *arg1, char *arg2)
{
    if (count(arg1) != count(arg2)) return -1;
    
    int i = 0;
    while (*arg1++ != '\0') {
        if (arg1[i] != arg2[i]) {
            break;
        }
        i++;
    }
    
    return 0;
}

/**
 * 文字列の大きさをカウントします。
 * @param s 文字ポインタ
 * @return 文字数
 */
int count(char *s)
{
    int counter = 0;
    
    while (*s++ != '\0') {
        counter++;
    }
    return counter;
}
