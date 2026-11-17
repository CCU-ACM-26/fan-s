#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int elemtype;
typedef struct node {
    elemtype data;
    struct node *next;
} linklist;

linklist* CreateLinkListTail() {
    linklist *head, *tail, *p;
    int val;

    head = (linklist *)malloc(sizeof(linklist));
    if (head == NULL) return NULL;         
    head->next = NULL;
    tail = head;

    printf("请输入若干个整数建立单链表 (输入 -1 结束):\n");
    while (1) {
        if (scanf("%d", &val) != 1) break;  
        if (val == -1) break;

        p = (linklist *)malloc(sizeof(linklist));
        if (p == NULL) break;              
        p->data = val;
        p->next = NULL;

        tail->next = p;
        tail = p;
    }
    return head;
}

int InsLinkList(linklist *head, int i, elemtype e) {
    linklist *p = head;
    linklist *newNode;
    int j = 0;

    if (i < 1) {                            
        printf("插入位置不合法！\n");
        return ERROR;
    }
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        printf("插入位置不合法！\n");
        return ERROR;
    }

    newNode = (linklist *)malloc(sizeof(linklist));
    if (newNode == NULL) return ERROR;      
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

int DelLinkList(linklist *head, int i, elemtype *e) {
    linklist *p = head;
    linklist *q;
    int j = 0;

    if (i < 1) {                           
        printf("删除位置不合法！\n");
        return ERROR;
    }
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) {
        printf("删除位置不合法！\n");
        return ERROR;
    }

    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

void PrintLinkList(linklist *head) {
    linklist *p = head->next;
    printf("当前单链表元素为: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    elemtype delData, insData;
    int i;

    printf("========== 单链表实验 ==========\n");

    printf("1. 建立单链表：\n");
    linklist *L = CreateLinkListTail();
    if (L == NULL) { printf("建立失败！\n"); return 1; }
    PrintLinkList(L);

    printf("\n2. 请测试【插入】功能：\n");
    printf("请输入要插入的位置 i (从1开始): ");
    if (scanf("%d", &i) != 1) i = -1;
    printf("请输入要插入的元素值: ");
    if (scanf("%d", &insData) != 1) insData = 0;
    if (InsLinkList(L, i, insData) == OK) {
        printf("插入成功！\n");
        PrintLinkList(L);
    }

    printf("\n3. 请测试【删除】功能：\n");
    printf("请输入要删除的位置 i (从1开始): ");
    if (scanf("%d", &i) != 1) i = -1;
    if (DelLinkList(L, i, &delData) == OK) {
        printf("删除成功！被删除的元素是: %d\n", delData);
        PrintLinkList(L);
    }

    linklist *temp;
    while (L != NULL) {
        temp = L;
        L = L->next;
        free(temp);
    }
    return 0;
}
