#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// プロトタイプ宣言
// -----------------------------
char* getLine();
char* trim(char *phrase);
void displayArray(int arr[], int size);


int main()
{
    int vector[5] = { 1,2,3,4,5 };
    int *pv;
    pv = vector;
    int value = 3;
    
    // ベクトルのスカラー倍
    for(int i=0;i < sizeof(vector)/sizeof(int);i++) {
        *pv++ *= value;
    }
    
    displayArray(vector, 5);
    
    char *word = (char *)malloc(strlen(" cat")+1);
    strcpy(word, " cat");
    printf("%s\n", trim(word));
    
    return 0;
}

/**
 * 標準入力された文字列をも読み込みます。
 */
char* getLine()
{
    const size_t sizeIncrement = 10;
    // 読み込んだ入力文字を格納するメモリへのポインタ
    char *buffer = malloc(sizeIncrement);
    char *currentPosition = buffer;
    size_t maxLength = sizeIncrement;
    size_t length = 0;
    // 読み込んだ文字
    int character;
    
    if (currentPosition == NULL) {
        return NULL;
    }
    
    while (1) {
        // 標準入力から文字を読み込む
        character = fgetc(stdin);
        if (character == '\n') {
            break;
        }
        
        // 最大文字数を超過している場合、確保領域を拡張する
        if (++length >= maxLength) {
            char *newBuffer = realloc(buffer, maxLength += sizeIncrement);
            if (newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
            
            currentPosition = newBuffer + (currentPosition - buffer);
            // 新しく割り当てたメモリ領域をバッファが指すよう代入する
            buffer = newBuffer;
        }
        *currentPosition += character;
    }
    *currentPosition = '\0';
    return buffer;
    
}

/**
 * 文字列の先頭にある空白を取り除きます。
 */
char* trim(char *phrase)
{
    char *old = phrase;
    char *new = phrase;
    
    while (*old == ' ') {
        old++;
    }
    // 前の文字列から一つづつ新しい配列に割当直す
    while (*old) {
        *(new++) = *(old++);
    }
    *new = 0;
    return (char *)realloc(phrase, strlen(phrase)+1);
}


void displayArray(int *arr, int size)
{
    for (int i=0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
}
