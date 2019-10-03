#include <stdio.h>

int main(){
    //  サイズSIZEの配列を用意する。
    int nums[] = { 1,2,3,4,5 };
    int *p = NULL;
    int i;
    p = nums; //  pにnumsのアドレスを入力
    for( i = 4 ; i > 0; i--){
        printf("%d ",*p);
        p--;   //  p2のアドレスをインクリメント
    }
    printf("\n");
    
    return 0;
}
