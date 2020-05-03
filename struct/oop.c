#include <stdio.h>
#include <stdlib.h>

// -----------------------------
// 構造体、関数ポインタ宣言
// -----------------------------
typedef void (*fptrSet)(void*, int);
typedef int (*fptrGet)(void*);
typedef void (*fptrDisplay)();

/**
 * 隠蔽用基本関数ポインタ群の構造体
 */
typedef struct _functions{
    fptrSet setX;
    fptrGet getX;
    
    fptrSet setY;
    fptrGet getY;
    
    fptrDisplay display;
} vFunctions;

/**
 * ベースクラス構造体
 */
typedef struct _shape {
    int x;
    int y;
    vFunctions functions;
} Shape;

typedef struct _rectangle{
    Shape base;
    int width;
    int height;
} Rectangle;

// -----------------------------
// Shapeクラスメソッド
// -----------------------------
void shapeSetX(Shape *shape, int x){
    shape->x = x;
}
void shapeSetY(Shape *shape, int y){
    shape->y = y;
}
int shapeGetX(Shape *shape){
    return shape->x;
}
int shapeGetY(Shape *shape){
    return shape->y;
}
void displayShape(Shape *shape) {
    printf("Shape\n");
}
Shape* getShape() {
    Shape *shape = (Shape *)malloc(sizeof(Shape));
    shape->functions.setX = shapeSetX;
    shape->functions.setY = shapeSetY;
    shape->functions.getX = shapeGetX;
    shape->functions.getX = shapeGetY;
    shape->functions.display = displayShape;
    // デフォルトコンストラクタ
    shape->x = 100;
    shape->y = 100;
    return shape;
}


// -----------------------------
// Rectangleクラスメソッド
// -----------------------------
void rectangleSetX(Rectangle *rectangle, int x) {
    rectangle->base.x = x;
}
void rectangleSetY(Rectangle *rectangle, int y) {
    rectangle->base.y = y;
}
int rectangleGetX(Rectangle *rectangle) {
    return rectangle->base.x;
}
int rectangleGetY(Rectangle *rectangle) {
    return rectangle->base.y;
}
void rectangleDisplay() {
    printf("Rectangle\n");
}
Rectangle* getRectange() {
    Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));
    rectangle->base.functions.setX = rectangleSetX;
    rectangle->base.functions.getX = rectangleGetX;
    rectangle->base.functions.setY = rectangleSetY;
    rectangle->base.functions.getY = rectangleGetY;
    rectangle->base.functions.display = rectangleDisplay;
    // デフォルトコンストラクタ
    rectangle->base.x = 200;
    rectangle->base.y = 200;
    rectangle->width = 500;
    rectangle->height = 300;
    return rectangle;
}


int main() {
    // 親クラス
    Shape *sptr = getShape();
    sptr->functions.setX(sptr, 35);
    sptr->functions.display();
    printf("%d\n", sptr->functions.getX(sptr));
    
    // 継承クラス
    Rectangle *rptr = getRectange();
    rptr->base.functions.setX(rptr,45);
    rptr->base.functions.display();
    printf("%d\n", rptr->base.functions.getX(rptr));
}
