/**
 * 標準入出力ユーティリティ
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <execinfo.h>
#include "stdio_utils.h"

// -----------------------------
// プロトタイプ宣言
// -----------------------------
void printBackTrace();
void printStackFrame(const char message);
char** initializeBackTrace(int count);
void finalizeBackTrace(char** strings);


/**
 * バックトレースを表示する
 */
void printBackTrace() {

    const int count = 10;
    char** backtraces;
    backtraces = initializeBackTrace(count);

    for (size_t i = 0; i < count; i++)
    {
        printf("%s", backtraces[i]);
    }
    
    finalizeBackTrace(backtraces);

}

/**
 * メソッドのスタックフレームを表示する
 * @param message トレース文字列
 */ 
void printStackFrame(const char message) {

}


/**
 * バックトレースを初期化する
 */ 
char** initializeBackTrace(int count) {

    void *backtraces[count];
    size_t size;
    char **strings;

    size = backtrace(backtraces, 10);
    strings = backtrace_symbols(backtraces, size);

    return strings;

}

/**
 * バックトレース文字列のメモリを解放する
 */ 
void finalizeBackTrace(char** strings) {

    free(strings);

}