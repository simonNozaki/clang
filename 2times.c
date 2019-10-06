#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ------------------------
// プロトタイプ宣言
// ------------------------
void printArray(int *parray);
void multiple(int *parray);


int main()
{
    srand((unsigned)time(NULL));
    // 配列
    int array[5];
    // 配列操作用ポインタ
    int *pa;
    
    // ポインタを配列で初期化
    pa = array;
    
    // 配列の標準出力
    printArray(pa);
    
    printf("\n");

    return 0;
}

/**
 * 配列の要素を標準出力する
 * @param *parray 配列のポインタ
 */
void printArray(int *parray)
{
    int i;
    
    for (i=0;i<5;i++){
        *parray = rand()%100 + 1;
        printf("original : %d | ", *parray);
        // 2倍する
        multiple(parray);
        printf("mutiplied : %d\n", *parray);
        
        parray++;
    }
}

/**
 * 配列の要素を2倍する
 * @param *parray 配列のポインタ
 */
void multiple(int *parray)
{
    *parray = 2 * *parray;
}
