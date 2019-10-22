#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----------------------------
// 型定義
// -----------------------------
/**
 * 従業員構造体
 */
typedef struct _employee {
    char name[32];
    unsigned char age;
} Employee;

/**
 * ツリーのノード構造体
 */
typedef struct _treeNode {
    void *data;
    struct _treeNode *left;
    struct _treeNode *right;
} TreeNode;

typedef int (*COMPARE)(void *, void *);
typedef void (*DISPLAY)(void *);

// -----------------------------
// プロトタイプ宣言
// -----------------------------
int compareEmployee(Employee *e1, Employee *e2);
void displayEmployee(Employee *e);

void insertNode(TreeNode **realRoot, COMPARE compare, void *data);
void inOrder(TreeNode *root, DISPLAY display);
void preOrder(TreeNode *root, DISPLAY display);
void postOrder(TreeNode *root, DISPLAY display);


int main() {
    
    // ツリーを初期化
    TreeNode *tree = NULL;
    
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
    
    insertNode(&tree, (COMPARE)compareEmployee, mz);
    insertNode(&tree, (COMPARE)compareEmployee, jb);
    insertNode(&tree, (COMPARE)compareEmployee, em);
    
    preOrder(tree, (DISPLAY)displayEmployee);
    inOrder(tree, (DISPLAY)displayEmployee);
    postOrder(tree, (DISPLAY)displayEmployee);
    
    return 0;
    
}

/**
 * 従業員の名前を比較します。
 */
int compareEmployee(Employee *e1, Employee *e2)
{
    return strcmp(e1->name, e2->name);
}

void displayEmployee(Employee *e)
{
    printf("%s, %d\n", e->name, e->age);
}

/**
 * ノードを二分探索木に追加します。
 */
void insertNode(TreeNode **realRoot, COMPARE compare, void *data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    TreeNode *root = *realRoot;
    
    if (root == NULL) {
        *realRoot = node;
        return;
    }
    
    while (1) {
        if (compare((root)->data, data) > 0) {
            if ((root)->left != NULL) {
                root = (root)->left;
            } else {
                (root)->left = node;
                break;
            }
        } else {
            if ((root)->right != NULL) {
                root = (root)->right;
            } else {
                (root)->right = node;
                break;
            }
        }
    }
}

/**
 * 通りがけ順
 */
void inOrder(TreeNode *root, DISPLAY display)
{
    if (root != NULL) {
        inOrder(root->left, display);
        display(root->data);
        inOrder(root->left, display);
    }
}

/**
 * 行きがけ順
 */
void preOrder(TreeNode *root, DISPLAY display)
{
    if (root != NULL) {
        display(root->data);
        preOrder(root->left, display);
        preOrder(root->right, display);
    }
}

/**
 * 帰りがけ順
 */
void postOrder(TreeNode *root, DISPLAY display)
{
    if (root != NULL) {
        postOrder(root->left, display);
        postOrder(root->right, display);
        display(root->data);
    }
}
