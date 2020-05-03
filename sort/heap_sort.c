#include <stdio.h>
#include <stdlib.h>

// -----------------------------
// 構造体宣言
// -----------------------------
typedef struct _node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// -----------------------------
// プロトタイプ宣言
// -----------------------------
void max_heapify(int*array, int index);
void build_max_heap(int *array);
void heap_sort(int *array);

int left(int *array, int index);
int right(int *array, int index);

void printArray(int *array);

// -----------------------------
// static変数宣言
// -----------------------------
// ヒープの大きさ
int size;
// 配列ポインタ
int *pa;


int main()
{
    int array[] = { 23, 17, 14, 6, 13, 10, 1 };
    
    printArray(array);
    
    pa = array;
    size = sizeof(array) / sizeof(int);
    
    heap_sort(array);
    
    printArray(array);
}


void printArray(int *array)
{
    for (int i=0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void heap_sort(int *array)
{
    build_max_heap(array);
    
    for (int i=size; i > 1; i--) {
        size -= 1;
        max_heapify(array, 1);
    }
}

void build_max_heap(int *array)
{
    for (int i=size; i > 0; i--) {
        max_heapify(array, i);
    }
}

void max_heapify(int *array, int index)
{
    int l = left(array, index);
    int r = right(array, index);
    int largest = 0;
    
    if (l <= size && array[l] > array[index]) {
        largest = l;
    } else {
        largest = index;
    }
    
    if (r <= size && array[r] > array[largest]) {
        largest = r;
    }
    
    if (largest != index) {
        array[index] = array[largest];
        max_heapify(array, largest);
    }
}

int left(int *array, int index)
{
    return 2 * array[index];
}

int right(int *array, int index)
{
    return (2 * array[index]) + 1;
}
