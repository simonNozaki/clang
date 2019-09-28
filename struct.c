#include <stdio.h>
#include <stdlib.h>

/**
 * プロトタイプ宣言
 */
void printArray(int subject[]);


/**
 * 従業員の構造体
 */
struct Employee
{
    int number;
    char name[52];
    int salaly;
};


int main(int argc, char *argv[])
{
    // 処理対象の配列
    struct Employee e[] = {
        {100, "Jeff Bezos", 2000},
        {101, "Rary Page", 1500},
        {102, "Sundar Pichai", 3000},
        {0, "", 0}
    };
    // 構造体へのポインタのメモリサイズ
    int size;
    // 処理対象の数値配列
    int array[6] = {2, 4, 6, 8, 10, 0};
    
    // ------------------------
    // メモリ操作
    // ------------------------
    // 構造体へのポインタを宣言
    struct Employee *pe;
    // 構造体のアドレスをポインタに設定
    pe = e;
    
    size = sizeof(pe);
    printf("size of : %d\n", size);
    
    while (1) {
        // エンドレコードなら処理を終了
        if(pe->number == 0){
            break;
        }
        
        printf("%d, %s, %d\n", pe->number, pe->name, pe->salaly);
        
        // ポインタをインクリメントし、次の配列要素を指し示す
        pe++;
    }
    
    printArray(array);
    
    return 0;
}

/**
 * 配列の要素を標準出力
 */
void printArray(int subject[])
{
    // 処理対象配列の初期化
    int array[6] = {2, 4, 6, 8, 10, 0};
    int *p;
    // 各値へのポインタを代入
    p = subject;
    
    while (1) {
        if(*p == 0) { break; }
        
        printf("%d\n", *p);
        p++;
    }
}

