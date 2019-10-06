#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isWithin16(char *s);


int main(int argc, char *argv[])
{
    if(isWithin16(argv[1]) == 0) {
        printf("入力された文字列は16文字以上です。プログラムを終了します。\n");
        exit(1);
    }
    // メモリ確保
    char *pi = (char *)malloc(sizeof(char) * (int)strlen(argv[1]+1));
    if (pi == NULL) {
        printf("メモリを確保できません。\n");
        exit(1);
    }
    pi = argv[1];
    
    while (1) {
        if (*pi == '\0') {
            break;
        }
        printf("%c\n", *pi);
        pi++;
    }
    
    while (pi != NULL) {
        free(pi);
    }
    
    return 0;
    
}

int isWithin16(char *s)
{
    int counter;
    while (*s++ != '\0') {
        counter++;
    }
    if (counter > 16) {
        return -1;
    }
    return 0;
}
