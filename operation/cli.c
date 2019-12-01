#include <stdio.h>

/**
 * コマンドライン引数を順番に表示するアプリケーション
 */
int main(int argc, char **argv)
{
    for (int i=0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    
    return 0;
}
