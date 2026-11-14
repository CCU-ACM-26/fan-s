// 青蛙邻里 POJ 1659 Frogs' Neighborhood
// Havel-Hakimi 定理：每次取度数最大的点，让它与剩余度数最大的 x 个点相连
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node {
    int deg;   // 剩余度数
    int id;    // 原始编号
};

bool cmp(const Node &a, const Node &b) { return a.deg > b.deg; }

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int tc = 0; tc < T; tc++) {
        int n;
        scanf("%d", &n);

        Node a[15];
        int g[15][15];
        memset(g, 0, sizeof(g));

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i].deg);
            a[i].id = i;
        }

        bool ok = true;
        for (int k = 0; k < n; k++) {
            sort(a, a + n, cmp);          // 按剩余度数降序
            if (a[0].deg == 0) break;     // 全部为 0，构造成功
            if (a[0].deg > n - 1) {       // 一个点最多连 n-1 个点
                ok = false;
                break;
            }

            int u = a[0].id;
            int d = a[0].deg;
            a[0].deg = 0;                 // 该点已处理完，摘掉

            for (int j = 1; j <= d; j++) {
                a[j].deg--;               // 被连的点剩余度数减 1
                if (a[j].deg < 0) {       // 出现负数：无法构造
                    ok = false;
                    break;
                }
                g[u][a[j].id] = 1;
                g[a[j].id][u] = 1;
            }
            if (!ok) break;
        }

        if (tc > 0) printf("\n");         // 相邻两组数据之间空一行

        if (!ok) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) printf(" ");
                printf("%d", g[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
