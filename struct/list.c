#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// 構造体宣言
// -----------------------------
/**
 * 従業員構造体
 */
typedef struct _employee {
    char name[32];
    unsigned char age;
} Employee;

/**
 * 連結リストのノード構造体
 */
typedef struct _node {
    void *data;
    struct _node *next;
} Node;

/**
 * 連結リスト
 */
typedef struct _linkedList {
    Node *head;
    Node *tail;
    Node *current;
} LinkdList;

/**
 * キュー定義
 */
typedef LinkdList Queue;
typedef LinkdList Stack;

typedef void (*DISPLAY)(void *);

// -----------------------------
// プロトタイプ宣言
// -----------------------------
void displayEmployee(Employee *e);

void initializeLinkedList(LinkdList *list);
void addAtHead(LinkdList *list, void *data);
void displayLinkedList(LinkdList *list, DISPLAY displayOp);

void initializeQueue(Queue *queue);
void enqueue(Queue *queue, void *node);
void* dequue(Queue *queue);

void initializeStack(Stack *stack);
void push(Stack *stack, void *node);
void* pop(Stack *stack);
void* peek(Stack *stack);

int main() {
    
    // -----------------------------
    // キュー
    // -----------------------------
    
    // キューの初期化
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    initializeQueue(queue);
    
    // 従業員情報を初期化
    Employee *mz = (Employee *)malloc(sizeof(Employee));
    strcpy(mz->name, "Mark Zuckerberg");
    mz->age = 35;
    
    Employee *jb = (Employee *)malloc(sizeof(Employee));
    strcpy(jb->name, "Jeff Bezos");
    jb->age = 55;
    
    Employee *em = (Employee *)malloc(sizeof(Employee));
    strcpy(em->name, "Eron Musk");
    em->age = 48;
    
    enqueue(queue, mz);
    enqueue(queue, jb);
    enqueue(queue, em);
    
    void *data = dequue(queue);
    printf("%sはデキューされました。\n", ((Employee *)data)->name);
    data = dequue(queue);
    printf("%sはデキューされました。\n", ((Employee *)data)->name);
    
    // -----------------------------
    // スタック
    // -----------------------------
    
    // スタックの初期化
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    initializeStack(stack);
    
    push(stack, mz);
    push(stack, jb);
    push(stack, em);
    
    Node *target = peek(stack);
    
    printf("peek: %s\n", ((Employee *)target->data)->name);
    
    Employee *e;
    
    for (int i=0; i < 3; i++) {
        e = (Employee *)pop(stack);
        printf("%sはポップされました。\n", e->name);
    }
    
    return 0;
}

/**
 * 連結リストをそ初期化します。
 */
void initializeLinkedList(LinkdList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

/**
 * 連結リストの先頭にノードを追加します。
 */
void addAtHead(LinkdList *list, void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->tail->next = NULL;
    } else {
        node->next = list->head;
    }
    list->head = node;
    
}

/**
 * キューを初期化します。
 */
void initializeQueue(Queue *queue)
{
    initializeLinkedList(queue);
}

/**
 * スタックを初期化します。
 */
void initializeStack(Stack *stack)
{
    initializeLinkedList(stack);
}

/**
 * スタックに要素を追加します。
 */
void push(Stack *stack, void *node)
{
    addAtHead(stack, node);
}

/**
 * スタックから要素を一つ取り除きます。
 */
void* pop(Stack *stack)
{
    Node *cursor = stack->head;
    
    if (stack == NULL) {
        return NULL;
    } else if(cursor == stack->tail) {
        stack->head = NULL;
        stack->tail = NULL;
        void *data = cursor->data;
        free(cursor);
        return data;
    } else {
        stack->head = stack->head->next;
        void *data = cursor->data;
        free(cursor);
        return data;
    }
    
    return NULL;
}

/**
 * スタックの先頭の要素を返します。
 */
void* peek(Stack *stack)
{
    if (stack == NULL) {
        return NULL;
    }
    return stack->head;
    
}

/**
 * キューに要素を追加します。
 */
void enqueue(Queue *queue, void *node)
{
    addAtHead(queue, node);
}

/**
 * キューから削除します。
 */
void* dequue(Queue *queue)
{
    // 返却用カーソル
    Node *cursor = (Node *)malloc(sizeof(Node));
    cursor = queue->head;
    
    if (queue == NULL) {
        cursor = NULL;
    } else if(queue->head == queue->tail) {
        // 要素が一つの場合、先頭ノードを確保
        cursor = queue->head;
        queue->tail = NULL;
        queue->head = NULL;
    } else {
        // カーソルをインクリメント
        while (cursor->next != queue->tail) {
            cursor = cursor->next;
        }
        queue->tail = cursor;
        cursor = cursor->next;
        queue->tail->next = NULL;
    }
    
    return cursor;
}
