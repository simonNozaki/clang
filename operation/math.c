#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 数字の構造体
 */
struct Numbers {
    int _0;
    int _1;
    int _2;
    int _3;
    int _4;
};

/**
 * プロトタイプ宣言
 */
void printRandomNumber(struct Numbers *nums);
void printMaxAndMin(struct Numbers *nums);
void printSelectedNumbers(struct Numbers *nums);


int main(void)
{
    // ------------------------
    // 構造体の初期化
    // ------------------------
    srand((unsigned)time(NULL));
    //  構造体のメモリを初期化
    struct Numbers numbers;
    numbers._0 = (rand()%10) + 1;
    numbers._1 = (rand()%10) + 1;
    numbers._2 = (rand()%10) + 1;
    numbers._3 = (rand()%10) + 1;
    numbers._4 = (rand()%10) + 1;
    
    struct Numbers bigNumbers;
    bigNumbers._0 = (rand() % 100) + 1;
    bigNumbers._1 = (rand() % 100) + 1;
    bigNumbers._2 = (rand() % 100) + 1;
    bigNumbers._3 = (rand() % 100) + 1;
    bigNumbers._4 = (rand() % 100) + 1;
    
    // 標準出力処理
    printRandomNumber(&numbers);
    // 最大値および最小値を表示する
    printMaxAndMin(&numbers);
    // 特定の値の個数を表示する
    printSelectedNumbers(&bigNumbers);
    
    return 0;
}

/**
 * 乱数を５つ標準出力する
 */
void printRandomNumber(struct Numbers *nums)
{
    printf("%d, ", nums->_0);
    printf("%d, ", nums->_1);
    printf("%d, ", nums->_2);
    printf("%d, ", nums->_3);
    printf("%d, ", nums->_4);
    
    printf("\n");
}

/**
 * 最大値と最小値を表示する
 */
void printMaxAndMin(struct Numbers *nums)
{
    int max = 1;
    int min = 10;
    int array[6] = { nums->_0,nums->_1,nums->_2,nums->_3,nums->_4,0 };
    // 配列の要素用ポインタ
    int *p;
    p = array;
    
    while (1) {
        if (*p == 0) { break; }
        
        // maximize
        if(max < *p) {
            max= *p;
            continue;
        }
        // minimum
        if (min > *p) {
            min = *p;
        }
        p++;
    }
    
    printf("max : %d\n", max);
    printf("min : %d\n", min);
    
}

/**
 * 特定の値の個数を表示する
 */
void printSelectedNumbers(struct Numbers *nums)
{
    int array[6] = { nums->_0,nums->_1,nums->_2,nums->_3,nums->_4,0 };
    int *p;
    p = array;
    int between20and50 = 0;
    int over80 = 0;
    int under10 = 0;
    
    while (1) {
        if (*p == 0) { break; }
        if (*p >= 20 && *p <= 50 ) { between20and50++; }
        if (*p > 80) { over80++; }
        if (*p < 10) { under10++; }
        p++;
    }
    
    printf("20以上50以下の数 : %d\n", between20and50);
    printf("80より大きい数 : %d\n", over80);
    printf("0以上10未満の数 : %d\n", under10);
}
