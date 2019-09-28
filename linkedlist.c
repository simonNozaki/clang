#include <stdio.h>
#include <stdlib.h>

// ------------------------
// プロトタイプ宣言
// ------------------------
void addAtHead(int target);


/**
 * ノード構造体
 */
struct ListNode {
    int value;
    struct ListNode *next;
};

int main(void)
{
    // 先頭ノードのポインタ
    struct ListNode *head;
    // カーソルノードのポインタ
    struct ListNode *cursor;
    
    addAtHead(1);
    
}


/**
 * 先頭にノードを追加する
 */
void addAtHead(int target)
{
    
}
