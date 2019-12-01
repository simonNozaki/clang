#include <stdio.h>
#include <stdlib.h>

// プロトタイプ宣言
void swap(int *x, int *y);

int main(int argc, char *argv[])
{
	int a,b;

	// 引数の数を検査
	if(argc != 3) {
		printf("Usage : %s <number1> <number2>¥n", argv[0]);
		return 0;
	}
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	// 値ではなく、値のあるアドレスを渡す
	swap(&a, &b);
	
	printf("%d %d¥n", a, b);
	
	return 0;
}


/**
 * x, yの値を入れ替える。
 * 呼び出し元の変数の値を直接書き換えたい場合、ポインタを利用することで、呼び出し元の情報を直接書き換えられる
 * @param *x 数字のポインタ
 * @param *y 数字のポインタ
 */
void swap(int *x, int *y)
{
	int tmp;
        
	tmp = *x;
	*x = *y;
	*y = tmp;
}
