#include <stdio.h>

int main(){
    //  サイズSIZEの配列を用意する。
    int nums[] = { 1,2,3,4,5 };
    int *p = NULL;
    int i;

    p = &nums[4]; //  pにnumsのアドレスを入力
    for( i = 5 ; i > 0; i--){
        printf("%d ", *p);
        p--;   //  pのアドレスをデクリメント
    }
    printf("\n");
    
    return 0;
}
