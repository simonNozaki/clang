#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * プロトタイプ宣言
 */
void setCase(char *subject);

/*
 
 入力された文字列をを16進数表記で出力する
 */
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
