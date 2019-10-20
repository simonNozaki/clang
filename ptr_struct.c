#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------
// 構造体宣言
// -----------------------------
typedef struct _person {
    char *firstName;
    char *secondName;
    char *title;
    unsigned int age;
} Person;

// -----------------------------
// プロトタイプ宣言
// -----------------------------
void initializePerson(Person *person, const char *firstName, const char *secondName, const char *title, unsigned int age);
void finalizePerson(Person *person);
void initializeAllocatingList();
Person* getPerson();
Person* setPerson(Person *person);
void displayPerson();

// -----------------------------
// 定数定義
// -----------------------------
#define LIST_SIZE 10
Person *list[LIST_SIZE];



int main() {
 
    Person *pp;
    pp = (Person *)malloc((int)sizeof(Person));
    // 構造体内のフィールドも手動でメモリを確保する
    pp->firstName = (char *)malloc((int)strlen("Emily")+1);
    strcpy(pp->firstName, "Emily");
    pp->age = 23;
    
    // ジェフ・ベゾス、インスタンス確保
    Person jb;
    // Person構造体の初期化
    initializePerson(&jb, "Jeff", "Bezos", "CEO", 45);
    finalizePerson(&jb);
    
    // スンダル・ピチャイ、ポインタ宣言
    Person *sp;
    sp = (Person *)malloc((int)sizeof(Person));
    initializePerson(sp, "Sundar", "Picahi", "CEO", 45);
    finalizePerson(sp);
    free(sp);
    
    initializeAllocatingList();
    // リストからの空のPersonインスタンスを取得
    Person *mz = getPerson();
    initializePerson(mz, "Mark", "Zuckerberg", "CEO", 35);
    setPerson(mz);
    displayPerson();
    
    return 0;
}

/**
 * Person構造体イニシアライザ
 */
void initializePerson(Person *person, const char *firstName, const char *secondName, const char *title, unsigned int age)
{
    person->firstName = (char *)malloc(sizeof(firstName)+1);
    person->secondName = (char *)malloc(sizeof(secondName)+1);
    person->title = (char *)malloc(sizeof(title)+1);
    
    strcpy(person->firstName, firstName);
    strcpy(person->secondName, secondName);
    strcpy(person->title, title);
    person->age = age;
}

/**
 * Person構造体に確保したメモリを解放します。
 */
void finalizePerson(Person *person)
{
    free(person->firstName);
    free(person->secondName);
    free(person->title);
}

/**
 * メモリ管理リストを要素NULLで初期化します。
 * NOTE メモリ確保解放を繰り返し行うことで発生するオーバーヘッドを最小化する
 */
void initializeAllocatingList()
{
    for (int i=0; i < LIST_SIZE; i++) {
        list[i] = NULL;
    }
}

/**
 * NULLではない単一Personインスタンスを返します。
 * 配列要素がNすべてNULLの場合、空のPインスタンスを返します。
 * @return Personインスタンスの参照
 */
Person* getPerson()
{
    for (int i=0; i < LIST_SIZE; i++) {
        if (list[i] != NULL) {
            Person *pp;
            pp = list[i];
            list[i] = NULL;
            return pp;
        }
    }
    Person *person = (Person *)malloc(sizeof(Person));
    return person;
}

/**
 * 引数で参照しているPersonインスタンスを確保します。
 * 管理配列に空きがない場合は引数が参照するインスタンスを解放し、NULLを返します。
 */
Person* setPerson(Person *person)
{
    for (int i=0; i < LIST_SIZE; i++) {
        if (list[i] == NULL) {
            list[i] = person;
            return person;
        }
    }
    finalizePerson(person);
    free(person);
    return NULL;
}

/**
 * 管理されているインスタンスの情報を表示します
 */
void displayPerson()
{
    for (int i=0; i < LIST_SIZE; i++) {
        if (list[i] != NULL) {
            printf("%s %s, %s\n", list[i]->firstName, list[i]->secondName, list[i]->title);
        }
    }
}
