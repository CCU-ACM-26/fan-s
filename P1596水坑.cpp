// P1596 湖计数 Lake Counting —— 模板二：洪水填充
// 题意：数有多少个连通的水坑；注意这里是 8 个方向（含斜角）相连！
#include <bits/stdc++.h>
using namespace std;

int R, C;
char g[105][105];
bool vis[105][105];

// 8 个方向：上下左右 + 四个斜角
int dr[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int r, int c) {
    vis[r][c] = true;                        // 标记，防止走回头路
    for (int d = 0; d < 8; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;  // 越界
        if (vis[nr][nc] || g[nr][nc] != 'W') continue;         // 访问过 / 不是水
        dfs(nr, nc);
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) cin >> g[i];

    int cnt = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (g[i][j] == 'W' && !vis[i][j]) {  // 发现新水坑的"种子"
                dfs(i, j);                       // 把整个水坑染掉
                cnt++;
            }

    cout << cnt << "\n";
    return 0;
}
