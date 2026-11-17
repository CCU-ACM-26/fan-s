#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1024
#define OK 1
#define ERROR 0

typedef int elemtype;
typedef struct {
    elemtype vec[MAXSIZE];
    int len;
} sequenlist;

void InitList(sequenlist *L) {
    L->len = 0;
}

int InsList(sequenlist *L, int i, elemtype e) {
    int k;
    if (i < 1 || i > L->len + 1) {
        printf("插入位置不合法！\n");
        return ERROR;
    }
    if (L->len >= MAXSIZE) {              
        printf("顺序表已满，无法插入！\n");
        return ERROR;
    }
    for (k = L->len - 1; k >= i - 1; k--) {
        L->vec[k + 1] = L->vec[k];
    }
    L->vec[i - 1] = e;
    L->len++;
    return OK;
}

int DelList(sequenlist *L, int i, elemtype *e) {
    int k;
    if (i < 1 || i > L->len) {
        printf("删除位置不合法！\n");
        return ERROR;
    }
    *e = L->vec[i - 1];
    for (k = i; k < L->len; k++) {
        L->vec[k - 1] = L->vec[k];
    }
    L->len--;
    return OK;
}

void PrintSeqList(sequenlist *L) {
    printf("当前顺序表长度: %d，元素为: ", L->len);
    for (int j = 0; j < L->len; j++) {
        printf("%d ", L->vec[j]);
    }
    printf("\n");
}

int main() {
    sequenlist L;
    elemtype delData;
    int i, val, op;

    InitList(&L);

    printf("========== 顺序表实验 ==========\n");

    int arr[] = {21, 23, 14, 5, 56, 17, 31};
    for (int j = 0; j < 7; j++) {
        InsList(&L, j + 1, arr[j]);
    }
    printf("1. 已建立初始顺序表:\n");
    PrintSeqList(&L);

    while (1) {
        printf("\n请选择操作：1-插入  2-删除  0-退出\n");
        if (scanf("%d", &op) != 1) break;
        if (op == 0) break;

        if (op == 1) {
            printf("请输入要插入的位置 i (1~%d): ", L.len + 1);
            if (scanf("%d", &i) != 1) break;
            printf("请输入要插入的元素值: ");
            if (scanf("%d", &val) != 1) break;
            if (InsList(&L, i, val) == OK) {
                printf("插入成功！\n");
                PrintSeqList(&L);
            }
        } else if (op == 2) {
            printf("请输入要删除的位置 i (1~%d): ", L.len);
            if (scanf("%d", &i) != 1) break;
            if (DelList(&L, i, &delData) == OK) {
                printf("删除成功！被删除的元素是: %d\n", delData);
                PrintSeqList(&L);
            }
        } else {
            printf("无效操作！\n");
        }
    }

    return 0;                            
}
