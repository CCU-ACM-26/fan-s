// ============================================================
// DFS（深度优先搜索）三套常用模板 —— 洛谷 P2392 同款风格
// 编译测试：g++ -std=c++17 DFS模板.cpp -o dfs && ./dfs
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// 模板一：子集枚举型（每个元素"选/不选"，2^n 种方案）
// 适用：n <= 20 左右，求所有组合中的最优解 / 方案数
// 例题：P2392 烹饪方案
// ------------------------------------------------------------
int n1;
long long s1[15], b1[15];
long long ans1 = 1e18;

void dfs_subset(int i, long long sour, long long bitter, int cnt) {
    if (i == n1 + 1) {                    // 出口：n 个决定都做完了
        if (cnt >= 1)                     // 按题意排除空方案
            ans1 = min(ans1, llabs(sour - bitter));
        return;
    }
    dfs_subset(i + 1, sour, bitter, cnt);                 // 不选第 i 种
    dfs_subset(i + 1, sour * s1[i], bitter + b1[i], cnt + 1); // 选第 i 种
}

void demo_subset() {
    n1 = 2;
    s1[1] = 2; b1[1] = 3;   // 食材1：酸2 苦3
    s1[2] = 5; b1[2] = 1;   // 食材2：酸5 苦1
    dfs_subset(1, 1, 0, 0); // 乘积初值 1，和初值 0
    cout << "模板一(子集枚举) 最小差值 = " << ans1 << "\n";  // 应输出 1
}

// ------------------------------------------------------------
// 模板二：网格型 / 洪水填充（把相连的整块找出来）
// 适用：二维地图上数连通块、染色、岛屿问题
// 例题：P1596 水坑、P1451 求细胞数量、P1683 入门题
// ------------------------------------------------------------
char g2[105][105];
bool vis2[105][105];
int R, C;
int dr[] = {1, -1, 0, 0};    // 四个方向：上下左右
int dc[] = {0, 0, 1, -1};

void dfs_grid(int r, int c) {
    vis2[r][c] = true;                       // 标记走过（防死循环）
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        // 三个"不能走"：越界、访问过、不是目标格子
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (vis2[nr][nc] || g2[nr][nc] != 'W') continue;
        dfs_grid(nr, nc);
    }
}

void demo_grid() {
    R = 4; C = 5;
    const char *rows[] = {"WW..W", "W..W.", "..WW.", "W...."};
    for (int r = 0; r < R; r++) strcpy(g2[r], rows[r]);
    memset(vis2, 0, sizeof(vis2));

    int blocks = 0;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (g2[r][c] == 'W' && !vis2[r][c]) {   // 每发现一个没访问过的 W
                dfs_grid(r, c);                     // 就把整个连通块填掉
                blocks++;
            }
    cout << "模板二(洪水填充) 连通块个数 = " << blocks << "\n";  // 应输出 4
}

// ------------------------------------------------------------
// 模板三：回溯型（生成排列/组合，需要"撤销"）
// 适用：输出所有排列、N皇后、走迷宫计路径数
// 例题：P1706 全排列问题、P1605 迷宫
// ------------------------------------------------------------
int n3;
bool used3[15];
int path3[15];

void dfs_perm(int depth) {
    if (depth == n3 + 1) {                   // 填满了 n 个位置，输出一种排列
        for (int i = 1; i <= n3; i++)
            cout << setw(5) << path3[i];     // 洛谷要求场宽5
        cout << "\n";
        return;
    }
    for (int v = 1; v <= n3; v++) {          // 每个位置尝试放每个数
        if (used3[v]) continue;              // 已经被前面用过 → 跳过
        used3[v] = true;                     // 做选择
        path3[depth] = v;
        dfs_perm(depth + 1);                 // 递归填下一个位置
        used3[v] = false;                    // ★撤销选择（回溯的灵魂）
    }
}

void demo_perm() {
    n3 = 3;
    memset(used3, 0, sizeof(used3));
    cout << "模板三(回溯全排列) n=3 的所有排列：\n";
    dfs_perm(1);
}

int main() {
    demo_subset();
    demo_grid();
    demo_perm();
    return 0;
}
