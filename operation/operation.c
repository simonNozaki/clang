#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// 型定義
// -----------------------------
typedef int (*fptrOperation)(int, int);
typedef int (*operation)(int, int);
typedef int (*fptrChar)(const char*, const char*);

// -----------------------------
// プロトタイプ宣言
// -----------------------------
int add(int num1, int num2);
int sub(int num1, int num2);
int compute(fptrOperation operation, int num1, int num2);
fptrOperation select(char opcode);
int evaluate(char opcode, int num1, int num2);
void initializeOperationArray();
int evaluateArray(char opcode, int num1, int num2);

void sort(char *array[], int size, fptrChar operation);
int compare(const char *char1, const char *char2);
void displayNames(char *names[], int size);

// -----------------------------
// グローバル変数宣言
// -----------------------------
// 関数ポインタの配列
operation operations[128] = { NULL };


int main(int argc, char *argv[])
{
    
    if (argc != 2) {
        printf("引数を一つ指定してください。プログラムを終了します。\n");
        exit(1);
    }
    
    initializeOperationArray();
    
    printf("ADD: %d\n", compute(add, 5, 6));
    printf("SUB: %d\n", compute(sub, 5, 6));
    // printf("OPE: %d\n", evaluate('+', 4, 3));
    printf("OPE: %d\n", evaluateArray('+', 4, 3));
    
    // --------------------------- //
    char *persons[] = { "Bob", "Alice", "Sam", "Mike", "Carol" };
    displayNames(persons, 5);
    sort(persons, 5, compare);
    displayNames(persons, 5);
    
    return 0;
}


// -----------------------------
// 関数定義
// -----------------------------
int add(int num1, int num2)
{
    return num1 + num2;
}


int sub(int num1, int num2)
{
    return num1 - num2;
}

/**
 * 引数の関数を実行して、演算を行います。
 * @param 演算関数
 * @param 値1
 * @param 値2
 * @return 演算結果
 */
int compute(fptrOperation operation, int num1, int num2)
{
    return operation(num1, num2);
}

/**
 * 演算を選択します。
 */
fptrOperation select(char opcode)
{
    switch (opcode) {
        case '+':
            return add;
            break;
        case '-':
            return sub;
        default:
            return NULL;
    }
}

/**
 * 評価した演算を実行します。
 */
int evaluate(char opcode, int num1, int num2)
{
    fptrOperation operation = select(opcode);
    return operation(num1, num2);
}

/**
 * 関数ポインタの配列を初期化します。
 */
void initializeOperationArray()
{
    operations['+'] = add;
    operations['-'] = sub;
}

/**
 * 関数ポインタの配列を評価し、演算を実行します。
 */
int evaluateArray(char opcode, int num1, int num2)
{
    fptrOperation operation = operations[opcode];
    if(operation != NULL) {
        return operation(num1, num2);
    }
    return 0;
}

/**
 * ２つの文字列を比較します。
 */
int compare(const char *char1, const char *char2)
{
    return strcmp(char1, char2);
}

/**
 * バブルソート
 */
void sort(char *array[], int size, fptrChar operation)
{
    int swap = 1;
    while (swap) {
        swap = 0;
        for (int i=0; i<size-1; i++) {
            if (operation(array[i], array[i+1]) > 0) {
                swap = 1;
                char *tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
    }
}


void displayNames(char *names[], int size)
{
    for (int i=0; i < size; i++) {
        printf("%s ", names[i]);
    }
    printf("\n");
}
