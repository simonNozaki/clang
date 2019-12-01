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

typedef void (*DISPLAY)(void *);
typedef int (*COMPARE)(void *, void *);

// -----------------------------
// プロトタイプ宣言
// -----------------------------
int compareEmployee(Employee *e1, Employee *e2);
void displayEmployee(Employee *e);

void initializeLinkedList(LinkdList *list);
void addAtHead(LinkdList *list, void *data);
void addAtTail(LinkdList *list, void *data);
void delete(LinkdList *list, Node *node);
Node* getNode(LinkdList *list, COMPARE comparingOp, void *data);
void displayLinkedList(LinkdList *list, DISPLAY displayOp);


int main()
{
    // リスト構造体の初期化
    LinkdList *linkedList = (LinkdList *)malloc(sizeof(LinkdList));
    initializeLinkedList(linkedList);
    
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
    
    addAtHead(linkedList, mz);
    addAtTail(linkedList, em);
    addAtHead(linkedList, jb);
    
    Node *target = getNode(linkedList, (int (*)(void *, void *))compareEmployee, "Eron Musk");
    Employee *etarget = target->data;
    
    displayLinkedList(linkedList, (void (*)(void *))displayEmployee);
    
    free(mz);
    free(jb);
    free(em);

    return 0;
}

/**
 * 従業員の名前を比較します。
 */
int compareEmployee(Employee *e1, Employee *e2)
{
    return strcmp(e1->name, e2->name);
}

/**
 * 従業員の情報を表示します。
 */
void displayEmployee(Employee *e)
{
    printf("%s, %d\n", e->name, e->age);
}

/**
 * 連結リストを初期化します
 */
void initializeLinkedList(LinkdList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

/**
 * 先頭にノードを追加します.
 */
void addAtHead(LinkdList *list, void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    
    // リストサイズが0の時
    if (list->head == NULL) {
        list->tail = node;
        list->head = node;
        node->next = NULL;
    } else {
        node->next = list->head;
    }
	list->head = node;
}

/**
 * リスト末尾にノードを追加します
 */
void addAtTail(LinkdList *list, void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
	list->tail = node;
}

/**
 * リストからノードを削除します。
 */
void delete(LinkdList *list, Node *node)
{
    if (list == NULL) {
        printf("リストが空です。削除操作は実行できません。");
    }
    
    // 対象が先頭である場合
    if (node == list->head) {
        // 要素数1の場合
        if (list->head->next == NULL) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->head = list->head->next;
        }
    } else {
        Node *tmp = list->head;
        while (tmp != NULL && tmp->next != NULL) {
            if (tmp != NULL) {
                tmp->next = node->next;
            }
            if (list->tail == node) {
                list->tail = tmp;
            }
        }
    }
    free(node);
}

/**
 * ノードのデータに一致するノードのポインタを返します。
 */
Node* getNode(LinkdList *list, COMPARE comparingOp, void *data)
{
    list->current = list->head;
    
    while (list->current != NULL) {
        if(comparingOp(list->current->data,data) == 0){
            return list->current;
        }
        list->current = list->current->next;
    }
    return NULL;
}

void displayLinkedList(LinkdList *list, DISPLAY displayOp)
{
    // カーソルを初期化
    list->current = list->head;
    
    while (list->current != NULL) {
        displayOp(list->current);
        list->current = list->current->next;
    }
}
