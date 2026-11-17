/*
 * HDU 1232 畅通工程
 * 来源：浙大计算机研究生复试上机考试-2005年
 * 算法：并查集（查 + 并），求连通块个数，答案 = 连通块数 - 1
 */
#include <stdio.h>

int bin[1002];              /* bin[i] 表示 i 的"上级"，bin[i]==i 表示 i 是根 */

int findx(int x)            /* 查：找 x 所在集合的根 */
{
    int r = x;
    while (bin[r] != r)     /* 顺着上级一路往上找，直到找到根 */
        r = bin[r];
    return r;
}

void merge(int x, int y)    /* 并：把两个集合合成一个 */
{
    int fx, fy;
    fx = findx(x);
    fy = findx(y);
    if (fx != fy)           /* 不在同一个集合才需要合并 */
        bin[fx] = fy;       /* 让一个根认另一个根当上级 */
}

int main()
{
    int n, m, i, x, y, count;
    while (scanf("%d", &n) == 1 && n != 0)   /* n=0 结束 */
    {
        scanf("%d", &m);
        for (i = 1; i <= n; i++)
            bin[i] = i;             /* 初始化：每人自己就是一个集合 */
        for (i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            merge(x, y);            /* 每条路把两城合并 */
        }
        /* 数根的个数 = 连通块个数；从 -1 开始数，正好得到 块数-1 = 还需修的路数 */
        for (count = -1, i = 1; i <= n; i++)
            if (bin[i] == i)
                count++;
        printf("%d\n", count);
    }
    return 0;
}
