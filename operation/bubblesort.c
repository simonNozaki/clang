#include <stdio.h>
#include <stdlib.h>

/**
 * ノードの構造体
 */
struct ListNode {
    int value;
    struct ListNode *next;
};


int main(int argc, char *argv[])
{
    // カウンタ
    int i;
    // 入力値
    int n;
    // 先頭ノードのポインタ
    struct ListNode *head = NULL;
    // データをたどるためのポインタ
    struct ListNode *tmp[2] = {NULL, NULL};
    // メモリ確保用ポインタ、カーソル
    struct ListNode *cursor;
    
    for (i=0; i < argc-1; i++) {
        n = atoi(argv[i+1]);
        // カーソル用メモリサイズの確保
        cursor = (struct ListNode *)malloc(sizeof(struct ListNode));
        
        if (cursor == NULL){
            printf("カーソルのメモリ確保に失敗しました。\n");
            exit(1);
        }
        
        cursor->value = n;
        
        // 先頭ノードの処理
        if(i == 0){
            head = cursor;
            head->next = NULL;
            continue;
        }
        
        // 挿入用の空(null)のポインタ
        tmp[0] = NULL;
        // 比較対象のポインタ
        tmp[1] = head;
        
        // 入力値とカーソルを比較する
        while (1) {
            // 入力値が比較対象より小さい
            if (n <= tmp[1]->value) {
                if (tmp[0] == NULL) {
                    cursor->next = head;
                    head = cursor;
                } else {
                    cursor->next = tmp[1];
                    tmp[0]->next = cursor;
                }
                break;
            }
            
            tmp[0] = tmp[1];
            if (tmp[0]->next == NULL) {
                cursor->next = NULL;
                tmp[0]->next = cursor;
                break;
            } else {
                tmp[1] = tmp[0]->next;
            }
        }
    }
    
    // ------------------------
    // 標準出力
    // ------------------------
    tmp[1] = head;
    // ノードの参照がなくなるまで
    while (tmp[1] != NULL) {
        printf("%d, ", tmp[1]->value);
        
        // 表示いたノード分のメモリを解放する
        tmp[0] = tmp[1];
        tmp[1] = tmp[0]->next;
        free(tmp[0]);
    }
    printf("\n");
    
    return 0;
}
