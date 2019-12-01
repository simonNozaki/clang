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

// -----------------------------
// static変数宣言
// -----------------------------
// ヒープの大きさ
int *heap_size;
// 配列ポインタ
int *pa;


int main()
{
    int array[] = { 23, 17, 14, 6, 13, 10, 1 };
    
    pa = array;
    heap_size = (int *)sizeof(array);
    
    heap_sort(array);
    
}


void heap_sort(int *array)
{
    build_max_heap(array);
    
    for (int i=*heap_size; i > 1; i--) {
        heap_size -= 1;
        max_heapify(array, 1);
    }
}

void build_max_heap(int *array)
{
    for (int i=*heap_size; i > 0; i--) {
        max_heapify(array, i);
    }
}

void max_heapify(int *array, int index)
{
    int l = left(array, index);
    int r = right(array, index);
    int largest = 0;
    
    if (l <= *heap_size && array[l] > array[index]) {
        largest = l;
    } else {
        largest = index;
    }
    
    if (r <= *heap_size && array[r] > array[largest]) {
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
