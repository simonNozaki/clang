#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----------------------------
// プロトタイプ宣言
// -----------------------------
void realloction();
float average(int *arr, int size);
int square(int num);


int main()
{
    // int用メモリを動的に確保する
    // ヒープ領域で確保できたメモリへのポインタが戻り値
    int *pi = (int *)malloc(sizeof(int));
    memset(pi, 0, sizeof(int));
    
    if (pi == NULL) exit(1);
    
    *pi = 5;
    
    printf("%d\n", *pi);
    
    free(pi);
    
    // ----------------------------- //
    
    // 同じポインタ変数に、mallocで上書きを行うとアドレスの紛失となる
    int *qi = (int *)malloc(sizeof(int));
    *qi = 5;
    // アドレスの上書き
    qi = (int *)malloc(sizeof(int));
    
    printf("%d\n", *qi);
    // 最初に確保したメモリは忘れているので、解放できない
    free(qi);
    
    realloction();
    
    // 解放したメモリ（どこからも参照されない）に、値を書き込み
    *qi = 30;
    
    // ----------------------------- //
    
    int array[] = {28, 4, 17, 5};
    int *pa;
    pa = array;
    printf("average: %f\n", average(pa, 4));
    
    // ----------------------------- //
    // 関数ポインタ宣言
    int (*fptr)(int);
    int n = 5;
    fptr = square;
    printf("Squared: %d\n", fptr(n));
    
    return 0;
}

void realloction()
{
    char *string1;
    char *string2;
    
    string1 = (char *)malloc(16);
    // 確保した16バイトのうち、13バイトを使う
    strcpy(string1, "0123456789AB");
    
    string2 = realloc(string1, 8);
    printf("string1 Value: %p [%s]\n", string1, string1);
    printf("string2 Value: %p [%s]\n", string2, string2);
    
}


float average(int *arr, int size)
{
    int sum;
    printf("arr: %p\n", &arr);
    printf("size: %p\n", &size);
    printf("sum: %p\n", &sum);
    
    for (int i=0; i<size; i++) {
        sum += arr[i];
    }
    
    return (sum * 1.0f) / size;
}


int square(int num)
{
    return num*num;
}
