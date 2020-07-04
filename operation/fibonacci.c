#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------
// プロトタイプ関数
// -------------------
void printFibonacciSequence(int *max);

void printFibonacciSequence(int *max) {
    int f0, f1, f2;
    f0 = 0;
    f1 = 1;
    f2 = 0;
    
    while (f2 < *max) {
        
        printf("%d \n", f2);
        
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
        
    }

}

int main() {
    
    int *max = malloc(sizeof(int));
    *max = 10000;
    
    printFibonacciSequence(max);
    
}
