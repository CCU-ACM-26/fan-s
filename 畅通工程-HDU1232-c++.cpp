/*
 * HDU 1232 畅通工程 —— C++ 版（并查集 + 路径压缩）
 * 来源：浙大计算机研究生复试上机考试-2005年
 */
#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> fa;

    DSU(int n) {                 // 构造时初始化：每人自己当根
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++) fa[i] = i;
    }

    int find(int x) {            // 查根（带路径压缩）
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);   // 找到根后，沿途所有人都直接挂到根上
    }

    void unite(int x, int y) {   // 并
        int fx = find(x), fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }

    int countBlocks(int n) {     // 数连通块个数
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (find(i) == i) cnt++;
        return cnt;
    }
};

int main() {
    int n, m;
    while (cin >> n && n != 0) {
        cin >> m;
        DSU dsu(n);
        while (m--) {
            int x, y;
            cin >> x >> y;
            dsu.unite(x, y);
        }
        cout << dsu.countBlocks(n) - 1 << endl;
    }
    return 0;
}
