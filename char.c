#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// プロトタイプ宣言
// -----------------------------
void setCase(char *subject);
void operate();
void scan();
void copy();
size_t countLength(const char string[]);
char* format(char *buffer, size_t size, const char *name, size_t quantity, size_t weight);


int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("引数が足りません。プログラムを終了します。\n");
        return 1;
    }
    
    // 引数の文字列分ループ
    for (int i=0; i < argc; i++){
        // 入力文字列のポインタ
        char *in = argv[i];
        setCase(in);
    }
    
    // ----------------------------- //
    
    // 文字列リテラル分メモリを確保して、ポインタにコピー
    char simpleArray[] = "simple string";
    char *simplePtr = (char *)malloc(strlen(simpleArray)+1);
    strcpy(simplePtr, simpleArray);
    
    // 以下を採用すると、ヒープにメモリを確保した状態でポインタを操作する
    // char *simplePtr = (char *)malloc(strlen(simpleArray)+1);
    // 以下を採用すると、リテラルプールにあるメモリを参照して文字列をカウントする
    // char *simplePtr = simpleArray;
    
    printf("length: %d\n", (int)countLength(simplePtr));
    
    // ----------------------------- //
    
    // 第一引数がNULLの場合動的にメモリを確保する
    printf("%s\n", format(NULL, 0, "Axle", 25, 45));
    
    return 0;
}

/**
 * 大文字、小文字に変換して出力
 */
void setCase(char *subject)
{
    // スペースの文字コード
    char space = 0x20;
    // 半角半濁点
    char semi_turbid_point = 0xDF;
    // 出力用文字配列を初期化
    char lower[strlen(subject)];
    char upper[strlen(subject)];
    
    for (int j=0; j < strlen(subject); j++) {
        // 小文字変換、論理和
        char SUM = subject[j] | space;
        // 大文字変換、論理積
        char AND = subject[j] & semi_turbid_point;
        // アウトプットに追加
        lower[j] = SUM;
        upper[j] = AND;
    }
    
    printf("UPPER to lower: %s\n", lower);
    printf("lower to UPPER: %s\n", upper);
}


void operate()
{
    // 文字列リテラルの初期化
    char header[] = "Media Player";
    
    // 文字列ポインタの初期化(ヒープにコピーが作られない)
    char *character = "Media Player";
    
    // 文字列ポインタに、文字定数を代入して初期化する
    // 動的にメモリをヒープで確保し、値を格納する
    char *prefix;
    prefix = (char *)malloc(2);
    *prefix = '+';
    *(prefix+1) = '\0';
}


void scan()
{
    char command[16];
    printf("Enter a command: ");
    scanf("%s", command);
    
    if (strcmp(command, "Quit") == 0) {
        printf("Command is Quit.\n");
    } else {
        printf("Command is not Quit.\n");
    }
}


void copy()
{
    char name[32];
    char *names[30];
    size_t count = 0;
    char *cursor;
    cursor = name;
    
    printf("Enter a name: ");
    scanf("%s", name);
    
    while (*cursor != '\0') {
        names[count] = (char *)malloc(sizeof(char));
        strcpy(names[count], name);
        count++;
    }
    
    printf("names: %s\n", *names);
}

/**
 * 文字列リテラルの文字数をカウントします。
 */
size_t countLength(const char string[]) {
    size_t length = 0;
    
    while (*(string++)) {
        length++;
    }
    return length;
}

/**
 * 文字列をフォーマットします。
 * @param 書き込み用バッファ
 * @param バッファのメモリサイズ
 * @param 名前
 * @param 数量
 * @param 重さ
 * @return フォーマットした文字列のポインタ
 */
char* format(char *buffer, size_t size, const char *name, size_t quantity, size_t weight)
{
    
    char formatString[] = "Item: %s, Quantity: %zu, Weight: %zu";
    size_t formatStringLength = strlen(formatString) - 6;
    size_t nameLength = strlen(name);
    size_t length = formatStringLength + nameLength + 10 + 10 + 1;
    
    if (buffer == NULL) {
        buffer = (char *)malloc(length);
        size = length;
    }
    
    snprintf(buffer, size, formatString, name, quantity, weight);
    return buffer;
}
