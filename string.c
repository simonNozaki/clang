#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -----------------------------
// プロトタイプ宣言
// -----------------------------
void printCombinedStringByLib(int size, char *param1[], char *param2[]);

void printCombinedString(int size, char *param1[], char *param2[]);


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
    // 組み合わせた、文字列を表示する
    printCombinedStringByLib(size, &arg1, &arg2);
    // 自作の結合文字列
    printCombinedString(size, &arg1, &arg2);
    
    return 0;
}

/**
 * 標準ライブラリを用いた文字列の結合
 * @param 文字列の大きさ
 * @param 複写前の文字列1
 * @param 複写前の文字列2
 */
void printCombinedStringByLib(int size, char *param1[], char *param2[])
{
    // 結果文字配列
    char output[size];
    
    strcat(output, *param1);
    strcat(output, *param2);
    
    printf("combined: %s\n", output);
}


/**
 * 自作の結合関数
 * @param 文字列の大きさ
 * @param 複写前の文字列1
 * @param 複写前の文字列2
 */
void printCombinedString(int size, char *param1[], char *param2[])
{
    char output[size+2];
    // 結合文字列用ポインタ
    char *ps;
    
    ps = output;
    
    for (int j=0;j < (int)sizeof(*param1)/(int)sizeof(char); j++) {
        output[j] = *param1[j];
        ps++;
    }
    
    printf("%s\n", output);
    
}
